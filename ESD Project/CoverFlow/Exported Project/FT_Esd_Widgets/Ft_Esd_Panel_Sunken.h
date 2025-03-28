/*
This file is automatically generated
DO NOT MODIFY BY HAND
Ft_Esd_Panel_Sunken
Header
*/

#ifndef Ft_Esd_Panel_Sunken__H
#define Ft_Esd_Panel_Sunken__H

#include "Esd_Base.h"
#include "Ft_Esd.h"
#include "Ft_Esd_Math.h"
#include "Ft_Esd_Widget.h"

#ifndef ESD_LOGIC
#define ESD_LOGIC(name, ...)
#define ESD_ACTOR(name, ...)
#define ESD_WIDGET(name, ...)
#define ESD_PAGE(name, ...)
#define ESD_APPLICATION(name, ...)
#define ESD_INPUT(name, ...)
#define ESD_ARRAY_INPUT(name, ...)
#define ESD_OUTPUT(name, ...)
#define ESD_SLOT(name, ...)
#define ESD_SIGNAL(name, ...)
#define ESD_VARIABLE(name, ...)
#define ESD_WRITER(name, ...)
#endif

#define Ft_Esd_Panel_Sunken_CLASSID 0x4B0A3DBD
ESD_SYMBOL(Ft_Esd_Panel_Sunken_CLASSID, Type = esd_classid_t)

ESD_WIDGET(Ft_Esd_Panel_Sunken, Include = "Ft_Esd_Panel_Sunken.h", Callback, DisplayName = "ESD Panel Sunken", Category = _GroupHidden, X = 0, Y = 0, Width = 400, Height = 300)
typedef struct
{
	union
	{
		void *Owner;
		Ft_Esd_Widget Widget;
	};
	/* corner's radius */
	ESD_INPUT(radius, Type = int, Default = 36)
	int(* radius)(void *context);
	ESD_INPUT(color, Type = ft_argb32_t, Default = #fafafa)
	ft_argb32_t(* color)(void *context);
} Ft_Esd_Panel_Sunken;

void Ft_Esd_Panel_Sunken__Initializer(Ft_Esd_Panel_Sunken *context);

ESD_SLOT(Render)
void Ft_Esd_Panel_Sunken_Render(Ft_Esd_Panel_Sunken *context);

#endif /* Ft_Esd_Panel_Sunken__H */

/* end of file */
