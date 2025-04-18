/**
 * This source code ("the Software") is provided by Bridgetek Pte Ltd
 * ("Bridgetek") subject to the licence terms set out
 *   http://brtchip.com/BRTSourceCodeLicenseAgreement/ ("the Licence Terms").
 * You must read the Licence Terms before downloading or using the Software.
 * By installing or using the Software you agree to the Licence Terms. If you
 * do not agree to the Licence Terms then do not download or use the Software.
 *
 * Without prejudice to the Licence Terms, here is a summary of some of the key
 * terms of the Licence Terms (and in the event of any conflict between this
 * summary and the Licence Terms then the text of the Licence Terms will
 * prevail).
 *
 * The Software is provided "as is".
 * There are no warranties (or similar) in relation to the quality of the
 * Software. You use it at your own risk.
 * The Software should not be used in, or for, any medical device, system or
 * appliance. There are exclusions of Bridgetek liability for certain types of loss
 * such as: special loss or damage; incidental loss or damage; indirect or
 * consequential loss or damage; loss of income; loss of business; loss of
 * profits; loss of revenue; loss of contracts; business interruption; loss of
 * the use of money or anticipated savings; loss of information; loss of
 * opportunity; loss of goodwill or reputation; and/or loss of, damage to or
 * corruption of data.
 * There is a monetary cap on Bridgetek's liability.
 * The Software may have subsequently been amended by another user and then
 * distributed by that other user ("Adapted Software").  If so that user may
 * have additional licence terms that apply to those amendments. However, Bridgetek
 * has no liability in relation to those amendments.
 */

#ifdef __cplusplus
extern "C" {
#endif

#ifndef EVE_PLATFORM__H
#define EVE_PLATFORM__H

/* Include all public headers. */
#include "EVE_Config.h"
#if defined(_WIN32)
#include "EVE_Platform_WIN32.h"
#endif
#if defined(__linux__)
#include "EVE_Platform_LINUX.h"
#endif
#include "EVE_Platform_FT9XX.h"
#include "EVE_GpuTypes.h"
#include "EVE_HalDefs.h"
#include "EVE_Cmd.h"
#include "EVE_MediaFifo.h"
#include "EVE_CoCmd.h"
#include "EVE_CoDl.h"
#include "EVE_GpuDefs.h"
#include "EVE_Util.h"
#include "EVE_LoadFile.h"


#define eve_noop() \
	do             \
	{              \
	} while (false)

#ifdef EVE_DEBUG_BREAK_SIGABRT
/* Used by LittleFS tests */
#include <signal.h>
#define eve_debug_break() \
	do                    \
	{                     \
		fflush(NULL);     \
		raise(SIGABRT);   \
	} while (false)
#else
#if defined(_DEBUG)
#if defined(_MSC_VER)
#define eve_debug_break() __debugbreak()
#elif defined(__GCC__)
#define eve_debug_break() __builtin_trap()
#else
#define eve_debug_break() eve_noop()
#endif
#else
#define eve_debug_break() eve_noop()
#endif
#endif

#if defined(__GNUC__) || defined(__clang__)
#define eve_deprecated(msg) __attribute__((deprecated(msg)))
#elif defined(_MSC_VER)
#define eve_deprecated(msg) __declspec(deprecated(msg))
#elif (__cplusplus >= 201402L)
#define eve_deprecated(msg) [[deprecated(msg)]]
#else
#define eve_deprecated(msg)
#endif

#ifndef eve_printf
#define eve_printf(fmt, ...) printf(fmt, ##__VA_ARGS__)
#endif

#ifndef eve_sprintf
#define eve_sprintf(str, fmt, ...) sprintf(str, fmt, ##__VA_ARGS__)
#endif

#if defined(_MSC_VER) && !defined(__clang__)
#define eve_assume(cond) __assume(cond)
#else
#define eve_assume(cond) eve_noop()
#endif

#if defined(_DEBUG)
#define eve_printf_debug_once(fmt, ...)                 \
	do                                                  \
	{                                                   \
		static bool eve_printf_debug_once_flag = false; \
		if (!eve_printf_debug_once_flag)                \
		{                                               \
			eve_printf(fmt, ##__VA_ARGS__);             \
			eve_printf_debug_once_flag = true;          \
		}                                               \
	} while (false)
#define eve_printf_debug(fmt, ...) eve_printf(fmt, ##__VA_ARGS__)
#define eve_assert(cond)                                                                                                           \
	do                                                                                                                             \
	{                                                                                                                              \
		if (!(cond))                                                                                                               \
		{                                                                                                                          \
			const char *str = #cond;                                                                                               \
			const char *sf = __FILE__;                                                                                             \
			eve_printf("EVE Assert Failed: %s (in file '%s' on line '%i')\n", str ? str : "<NULL>", sf ? sf : "<NULL>", __LINE__); \
			eve_debug_break();                                                                                                     \
		}                                                                                                                          \
		eve_assume(cond);                                                                                                          \
	} while (false)
#define eve_assert_ex(cond, ex)                                                                                                                             \
	do                                                                                                                                                      \
	{                                                                                                                                                       \
		if (!(cond))                                                                                                                                        \
		{                                                                                                                                                   \
			const char *str = #cond;                                                                                                                        \
			const char *sf = __FILE__;                                                                                                                      \
			eve_printf("EVE Assert Failed: %s (%s) (in file '%s' on line '%i')\n", ex ? ex : "<NULL>", str ? str : "<NULL>", sf ? sf : "<NULL>", __LINE__); \
			eve_debug_break();                                                                                                                              \
		}                                                                                                                                                   \
		eve_assume(cond);                                                                                                                                   \
	} while (false)
#define eve_assert_do(cond) eve_assert(cond)
#define eve_trace(str)                                                                                                     \
	do                                                                                                                     \
	{                                                                                                                      \
		const char *sc = __FILE__;                                                                                         \
		eve_printf("EVE Trace: %s (in file '%s' on line '%i')\n", (str) ? (str) : "<NULL>", sf ? sf : "<NULL>", __LINE__); \
	} while (false)
#else
#define eve_printf_debug_once(fmt, ...) eve_noop()
#define eve_printf_debug(fmt, ...) eve_noop()
#define eve_assert(cond) eve_assume(cond)
#define eve_assert_ex(cond, ex) eve_assume(cond)
#define eve_assert_do(cond)      \
	do                           \
	{                            \
		bool r__assert = (cond); \
		r__assert = r__assert;   \
		eve_assume(r__assert);   \
	} while (false)
#define eve_trace(cond) eve_noop()
#endif

#ifndef NOMINMAX
#ifndef max
#define max(a, b) (((a) > (b)) ? (a) : (b))
#endif
#ifndef min
#define min(a, b) (((a) < (b)) ? (a) : (b))
#endif
#endif

/* Custom scope keyword (to avoid tripping the auto-formatter on scopes) */
#ifndef eve_scope
#define eve_scope() if (true)
#endif

#endif /* #ifndef EVE_PLATFORM__H */

#ifdef __cplusplus
}
#endif

/* end of file */