/*
This file is automatically generated
DO NOT MODIFY BY HAND
Usr_Widget
Header
*/

#ifndef Usr_Widget__H
#define Usr_Widget__H

#include "Esd_Base.h"
#include "Esd_BitmapInfo.h"
#include "Esd_Core.h"
#include "Ft_Esd.h"
#include "Ft_Esd_BitmapInfo.h"
#include "Ft_Esd_Image.h"
#include "Ft_Esd_Layout_Fixed.h"
#include "Ft_Esd_Math.h"
#include "Ft_Esd_TouchArea.h"
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

#define Usr_Widget_CLASSID 0xF7D1B401
ESD_SYMBOL(Usr_Widget_CLASSID, Type = esd_classid_t)

ESD_WIDGET(Usr_Widget, Include = "Usr_Widget.h", Callback, X = -1, Y = 32, Width = 799, Height = 383)
typedef struct
{
	union
	{
		void *Owner;
		Ft_Esd_Widget Widget;
	};
	ESD_VARIABLE(img1, Type = Esd_BitmapCell, Private)
	Esd_BitmapCell img1;
	ESD_VARIABLE(x1, Type = int, Default = 80, Private)
	int x1;
	ESD_VARIABLE(y1, Type = int, Default = 120, Private)
	int y1;
	ESD_VARIABLE(w1, Type = int, Default = 240, Private)
	int w1;
	ESD_VARIABLE(h1, Type = int, Default = 160, Private)
	int h1;
	ESD_VARIABLE(img2, Type = Esd_BitmapCell, Private)
	Esd_BitmapCell img2;
	ESD_VARIABLE(x2, Type = int, Default = 240, Private)
	int x2;
	ESD_VARIABLE(y2, Type = int, Default = 80, Private)
	int y2;
	ESD_VARIABLE(w2, Type = int, Default = 320, Private)
	int w2;
	ESD_VARIABLE(h2, Type = int, Default = 240, Private)
	int h2;
	ESD_VARIABLE(img3, Type = Esd_BitmapCell, Private)
	Esd_BitmapCell img3;
	ESD_VARIABLE(x3, Type = int, Default = 480, Private)
	int x3;
	ESD_VARIABLE(y3, Type = int, Default = 120, Private)
	int y3;
	ESD_ARRAY_INPUT(ImageArray, Type = Esd_BitmapCell, Array = true, Static = false)
	const Esd_BitmapCell* (* ImageArray)(void *context, size_t *size);
	int ImageArray_ArraySize;
	ESD_VARIABLE(w3, Type = int, Default = 240, Private)
	int w3;
	ESD_VARIABLE(h3, Type = int, Default = 160, Private)
	int h3;
	Ft_Esd_TouchArea Touch_Area_2;
	Ft_Esd_TouchArea Touch_Area;
	Ft_Esd_Layout_Fixed Fixed_Positioning;
	Ft_Esd_Image ESD_Image_3;
	Ft_Esd_Image ESD_Image_2;
	Ft_Esd_Image ESD_Image;
} Usr_Widget;

void Usr_Widget__Initializer(Usr_Widget *context);

ESD_SLOT(Start)
void Usr_Widget_Start(Usr_Widget *context);

ESD_SLOT(Update)
void Usr_Widget_Update(Usr_Widget *context);

ESD_SLOT(Render)
void Usr_Widget_Render(Usr_Widget *context);

ESD_SLOT(Idle)
void Usr_Widget_Idle(Usr_Widget *context);

ESD_SLOT(End)
void Usr_Widget_End(Usr_Widget *context);

#endif /* Usr_Widget__H */

/* end of file */
