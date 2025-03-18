/*
This file is automatically generated
DO NOT MODIFY BY HAND
Ft_Esd_SpinBox
C Source
*/

/*
Comment :
Introduction:
This widget draws a spin box.
ESD Panel and Push Button are reused to build up this widget.
CMD_NUMBER is used internally to show the value number.
Font type and font size are customized.
Touch input is supported.
*/

#include "Ft_Esd_SpinBox.h"

#include "Esd_Context.h"
#include "Esd_BitmapHandle.h"
#include "Ft_Esd_BitmapHandle.h"
#include "Ft_Esd_CoCmd.h"
#include "Ft_Esd_Dl.h"
#include "Ft_Esd_Elements.h"

ESD_CORE_EXPORT void Esd_Noop(void *context);
Ft_Esd_Theme * Ft_Esd_SpinBox_Theme__Default(void *context) { return Ft_Esd_Theme_GetCurrent(); }
int Ft_Esd_SpinBox_Step__Default(void *context) { return 1L; }
uint8_t Ft_Esd_SpinBox_Font__Default(void *context) { return 31; }
Esd_FontInfo * Ft_Esd_SpinBox_FontResource__Default(void *context) { return 0; }
void Ft_Esd_SpinBox_Changed__Noop(void *context, int value) { }

static uint8_t Ft_Esd_SpinBox_Push_Up_Font__Property(void *context) { return 18; }
static const char * Ft_Esd_SpinBox_Push_Up_Text__Property(void *context);
static uint8_t Ft_Esd_SpinBox_Push_Down_Font__Property(void *context) { return 18; }
static const char * Ft_Esd_SpinBox_Push_Down_Text__Property(void *context);

static Ft_Esd_WidgetSlots s_Ft_Esd_SpinBox__Slots = {
	(void(*)(void *))Ft_Esd_Widget_Initialize,
	(void(*)(void *))Ft_Esd_SpinBox_Start,
	(void(*)(void *))Ft_Esd_Widget_Enable,
	(void(*)(void *))Ft_Esd_SpinBox_Update,
	(void(*)(void *))Ft_Esd_Widget_Render,
	(void(*)(void *))Ft_Esd_Widget_Idle,
	(void(*)(void *))Ft_Esd_Widget_Disable,
	(void(*)(void *))Ft_Esd_SpinBox_End,
};

static void Ft_Esd_SpinBox_Number_Position_ForwardRender__Signal(void *context);
static void Ft_Esd_SpinBox_Push_Up_Down__Signal(void *context);
static void Ft_Esd_SpinBox_Push_Down_Down__Signal(void *context);
static void Ft_Esd_SpinBox_ESD_Render_Forwarder_ForwardRender__Signal(void *context);

void Ft_Esd_SpinBox__Touch_Tag__Initializer(Ft_Esd_SpinBox *context)
{
	Ft_Esd_TouchTag *object = (Ft_Esd_TouchTag *)&context->Touch_Tag;
	Ft_Esd_TouchTag__Initializer(object);
	object->Owner = (void *)context;
}

void Ft_Esd_SpinBox__Horizontal_Layout__Initializer(Ft_Esd_SpinBox *context)
{
	Ft_Esd_Layout_Linear *object = (Ft_Esd_Layout_Linear *)&context->Horizontal_Layout;
	Ft_Esd_Layout_Linear__Initializer(object);
	object->Owner = (void *)context;
	object->Widget.Active = 1;
	object->Widget.LocalX = 142;
	object->Widget.LocalY = 46;
	object->Widget.LocalWidth = 50;
	object->Widget.LocalHeight = 50;
	object->Margin = 4;
	object->Orientation = ESD_ORIENTATION_HORIZONTAL;
	object->Align = ESD_ALIGN_FILLFILL;
	object->Overflow = ESD_OVERFLOW_FILL;
	Ft_Esd_Widget_InsertBottom((Ft_Esd_Widget *)object, (Ft_Esd_Widget *)context);
}

void Ft_Esd_SpinBox__Number_Position__Initializer(Ft_Esd_SpinBox *context)
{
	Ft_Esd_RenderForwarder *object = (Ft_Esd_RenderForwarder *)&context->Number_Position;
	Ft_Esd_RenderForwarder__Initializer(object);
	object->Owner = (void *)context;
	object->Widget.Active = 1;
	object->Widget.LocalX = 88;
	object->Widget.LocalY = 41;
	object->Widget.LocalWidth = 30;
	object->Widget.LocalHeight = 512;
	object->ForwardRender = Ft_Esd_SpinBox_Number_Position_ForwardRender__Signal;
	Ft_Esd_Widget_InsertBottom((Ft_Esd_Widget *)object, (Ft_Esd_Widget *)&context->Horizontal_Layout);
}

void Ft_Esd_SpinBox__Vertical_Layout__Initializer(Ft_Esd_SpinBox *context)
{
	Ft_Esd_Layout_Linear *object = (Ft_Esd_Layout_Linear *)&context->Vertical_Layout;
	Ft_Esd_Layout_Linear__Initializer(object);
	object->Owner = (void *)context;
	object->Widget.Active = 1;
	object->Widget.LocalX = 151;
	object->Widget.LocalY = 21;
	object->Widget.LocalWidth = 10;
	object->Widget.LocalHeight = 10;
	object->Align = ESD_ALIGN_FILLFILL;
	object->Overflow = ESD_OVERFLOW_FILL;
	Ft_Esd_Widget_InsertBottom((Ft_Esd_Widget *)object, (Ft_Esd_Widget *)&context->Horizontal_Layout);
}

void Ft_Esd_SpinBox__Push_Up__Initializer(Ft_Esd_SpinBox *context)
{
	Ft_Esd_PushButton *object = (Ft_Esd_PushButton *)&context->Push_Up;
	Ft_Esd_PushButton__Initializer(object);
	object->Owner = (void *)context;
	object->Widget.Active = 1;
	object->Widget.LocalX = 145;
	object->Widget.LocalY = 76;
	object->Widget.LocalWidth = 10;
	object->Widget.LocalHeight = 10;
	object->Font = Ft_Esd_SpinBox_Push_Up_Font__Property;
	object->Text = Ft_Esd_SpinBox_Push_Up_Text__Property;
	object->Down = Ft_Esd_SpinBox_Push_Up_Down__Signal;
	Ft_Esd_Widget_InsertBottom((Ft_Esd_Widget *)object, (Ft_Esd_Widget *)&context->Vertical_Layout);
}

void Ft_Esd_SpinBox__Push_Down__Initializer(Ft_Esd_SpinBox *context)
{
	Ft_Esd_PushButton *object = (Ft_Esd_PushButton *)&context->Push_Down;
	Ft_Esd_PushButton__Initializer(object);
	object->Owner = (void *)context;
	object->Widget.Active = 1;
	object->Widget.LocalX = -118;
	object->Widget.LocalY = -298;
	object->Widget.LocalWidth = 10;
	object->Widget.LocalHeight = 10;
	object->Font = Ft_Esd_SpinBox_Push_Down_Font__Property;
	object->Text = Ft_Esd_SpinBox_Push_Down_Text__Property;
	object->Down = Ft_Esd_SpinBox_Push_Down_Down__Signal;
	Ft_Esd_Widget_InsertBottom((Ft_Esd_Widget *)object, (Ft_Esd_Widget *)&context->Vertical_Layout);
}

void Ft_Esd_SpinBox__ESD_Render_Forwarder__Initializer(Ft_Esd_SpinBox *context)
{
	Ft_Esd_RenderForwarder *object = (Ft_Esd_RenderForwarder *)&context->ESD_Render_Forwarder;
	Ft_Esd_RenderForwarder__Initializer(object);
	object->Owner = (void *)context;
	object->Widget.Active = 1;
	object->Widget.LocalX = 108;
	object->Widget.LocalY = 18;
	object->Widget.LocalWidth = 512;
	object->Widget.LocalHeight = 512;
	object->ForwardRender = Ft_Esd_SpinBox_ESD_Render_Forwarder_ForwardRender__Signal;
	Ft_Esd_Widget_InsertBottom((Ft_Esd_Widget *)object, (Ft_Esd_Widget *)context);
}

void Ft_Esd_SpinBox__Initializer(Ft_Esd_SpinBox *context)
{
	Ft_Esd_Widget__Initializer((Ft_Esd_Widget *)context);
	context->Widget.ClassId = Ft_Esd_SpinBox_CLASSID;
	context->Widget.Slots = &s_Ft_Esd_SpinBox__Slots;
	context->Widget.LocalX = 24;
	context->Widget.LocalY = 18;
	context->Widget.LocalWidth = 180;
	context->Widget.LocalHeight = 60;
	context->Theme = Ft_Esd_SpinBox_Theme__Default;
	context->Step = Ft_Esd_SpinBox_Step__Default;
	context->Increased = Esd_Noop;
	context->Font = Ft_Esd_SpinBox_Font__Default;
	context->FontResource = Ft_Esd_SpinBox_FontResource__Default;
	context->Value = 0L;
	context->Changed = Ft_Esd_SpinBox_Changed__Noop;
	context->Decreased = Esd_Noop;
	context->Watch_Variables__0 = 0;
	context->Style = ESD_OPT_3D;
	context->SideButtons = 0;
	Ft_Esd_SpinBox__Touch_Tag__Initializer(context);
	Ft_Esd_SpinBox__Horizontal_Layout__Initializer(context);
	Ft_Esd_SpinBox__Number_Position__Initializer(context);
	Ft_Esd_SpinBox__Vertical_Layout__Initializer(context);
	Ft_Esd_SpinBox__Push_Up__Initializer(context);
	Ft_Esd_SpinBox__Push_Down__Initializer(context);
	Ft_Esd_SpinBox__ESD_Render_Forwarder__Initializer(context);
}

void Ft_Esd_Elements_Panel(Ft_Esd_Theme *, ft_int16_t, ft_int16_t, ft_int16_t, ft_int16_t, ft_int16_t, ft_bool_t);
ESD_CORE_EXPORT uint16_t Esd_GetFontXOffset(Esd_FontInfo *);
ESD_CORE_EXPORT Esd_FontInfo *Esd_GetRomFont(uint8_t);
void Ft_Esd_Widget_InsertTop(Ft_Esd_Widget *, Ft_Esd_Widget *);
void Ft_Esd_Widget_InsertBottom(Ft_Esd_Widget *, Ft_Esd_Widget *);

void Ft_Esd_SpinBox_Start(Ft_Esd_SpinBox *context)
{
	void *owner = context->Owner;
	Ft_Esd_Widget_Start((Ft_Esd_Widget *)context);
	Ft_Esd_TouchTag_Start(&context->Touch_Tag);
}

void Ft_Esd_SpinBox_Update__Builtin(Ft_Esd_SpinBox *context)
{
	void *owner = context->Owner;
	Ft_Esd_TouchTag_Update(&context->Touch_Tag);
	ft_uint8_t update_variable = context->Style;
	context->Push_Up.Style = update_variable;
	ft_uint8_t update_variable_1 = context->Style;
	context->Push_Down.Style = update_variable_1;
	Ft_Esd_Widget_Update((Ft_Esd_Widget *)context);
}

void Ft_Esd_SpinBox_End(Ft_Esd_SpinBox *context)
{
	void *owner = context->Owner;
	Ft_Esd_TouchTag_End(&context->Touch_Tag);
	Ft_Esd_Widget_End((Ft_Esd_Widget *)context);
	Ft_Esd_Widget_Detach((Ft_Esd_Widget *)&context->Horizontal_Layout); 
	Ft_Esd_Widget_Detach((Ft_Esd_Widget *)&context->Number_Position); 
	Ft_Esd_Widget_Detach((Ft_Esd_Widget *)&context->Vertical_Layout); 
	Ft_Esd_Widget_Detach((Ft_Esd_Widget *)&context->Push_Up); 
	Ft_Esd_Widget_Detach((Ft_Esd_Widget *)&context->Push_Down); 
	Ft_Esd_Widget_Detach((Ft_Esd_Widget *)&context->ESD_Render_Forwarder); 
}

void Ft_Esd_SpinBox_Update(Ft_Esd_SpinBox *context)
{
	void *owner = context->Owner;
	bool watched__0 = context->SideButtons;
	if (context->Watch_Variables__0 != watched__0)
	{
		context->Watch_Variables__0 = watched__0;
		bool if_1 = context->SideButtons;
		if (if_1)
		{
			Ft_Esd_PushButton * context_1 = &context->Push_Down;
			Ft_Esd_Layout_Linear * parent_1 = &context->Horizontal_Layout;
			Ft_Esd_Widget_InsertTop((Ft_Esd_Widget *)context_1, (Ft_Esd_Widget *)parent_1);
		}
		else
		{
			Ft_Esd_PushButton * context_2 = &context->Push_Down;
			Ft_Esd_Layout_Linear * parent_2 = &context->Vertical_Layout;
			Ft_Esd_Widget_InsertBottom((Ft_Esd_Widget *)context_2, (Ft_Esd_Widget *)parent_2);
		}
	}
	Ft_Esd_SpinBox_Update__Builtin(context);
}

void Ft_Esd_SpinBox_Increase(Ft_Esd_SpinBox *context)
{
	void *owner = context->Owner;
	int left = context->Value;
	int right = context->Step(owner);
	int increase_value = left + right;
	context->Value = increase_value;
	context->Changed(owner, increase_value);
	context->Increased(owner);
}

void Ft_Esd_SpinBox_Decrease(Ft_Esd_SpinBox *context)
{
	void *owner = context->Owner;
	int left_1 = context->Value;
	int right_1 = context->Step(owner);
	int decrease_value = left_1 - right_1;
	context->Value = decrease_value;
	context->Changed(owner, decrease_value);
	context->Decreased(owner);
}

void Ft_Esd_SpinBox_Number_Position_ForwardRender__Signal(void *c)
{
	Ft_Esd_SpinBox *context = (Ft_Esd_SpinBox *)c;
	void *owner = context->Owner;
	ft_bool_t if_2 = Ft_Esd_TouchTag_Touching(&context->Touch_Tag);
	ft_rgb32_t c_1;
	if (if_2)
	{
		Ft_Esd_Theme * theme = context->Theme(owner);
		c_1 = Ft_Esd_Theme_GetPrimaryColor(theme);
	}
	else
	{
		Ft_Esd_Theme * theme_1 = context->Theme(owner);
		c_1 = Ft_Esd_Theme_GetTextColor(theme_1);
	}
	Ft_Esd_Dl_COLOR_RGB(c_1);
	EVE_HalContext * phost = Ft_Esd_GetHost();
	ft_int16_t left_3 = Ft_Esd_RenderForwarder_GlobalX(&context->Number_Position);
	ft_int16_t right_2 = Ft_Esd_RenderForwarder_GlobalWidth(&context->Number_Position);
	int left_2 = left_3 + right_2;
	Esd_FontInfo * if_3 = context->FontResource(owner);
	Esd_FontInfo *fontInfo;
	if (if_3)
	{
		fontInfo = context->FontResource(owner);
	}
	else
	{
		uint8_t i = context->Font(owner);
		fontInfo = Esd_GetRomFont(i);
	}
	uint16_t right_3 = Esd_GetFontXOffset(fontInfo);
	int x = left_2 - right_3;
	ft_int16_t left_4 = Ft_Esd_RenderForwarder_GlobalY(&context->Number_Position);
	ft_int16_t left_5 = Ft_Esd_RenderForwarder_GlobalHeight(&context->Number_Position);
	int right_5 = 2L;
	int right_4 = left_5 / right_5;
	int y = left_4 + right_4;
	Esd_FontInfo * if_4 = context->FontResource(owner);
	Esd_FontInfo *fontInfo_1;
	if (if_4)
	{
		fontInfo_1 = context->FontResource(owner);
	}
	else
	{
		uint8_t i_1 = context->Font(owner);
		fontInfo_1 = Esd_GetRomFont(i_1);
	}
	uint8_t font = Ft_Esd_Dl_Font_Setup(fontInfo_1);
	uint16_t left_7 = OPT_CENTERY;
	uint16_t right_6 = OPT_RIGHTX;
	uint16_t left_6 = left_7 | right_6;
	uint16_t right_7 = OPT_SIGNED;
	uint16_t options = left_6 | right_7;
	int n = context->Value;
	Ft_Gpu_CoCmd_Number(phost, x, y, font, options, n);
}

const char * Ft_Esd_SpinBox_Push_Up_Text__Property(void *c)
{
	Ft_Esd_SpinBox *context = (Ft_Esd_SpinBox *)c;
	void *owner = context->Owner;
	bool if_5 = context->SideButtons;
	if (if_5)
	{
		return Ft_Esd_Char_RightTriangle();
	}
	else
	{
		return Ft_Esd_Char_UpTriangle();
	}
}

void Ft_Esd_SpinBox_Push_Up_Down__Signal(void *c)
{
	Ft_Esd_SpinBox *context = (Ft_Esd_SpinBox *)c;
	void *owner = context->Owner;
	int left_8 = context->Value;
	int right_8 = context->Step(owner);
	int increase_value_1 = left_8 + right_8;
	context->Value = increase_value_1;
	context->Changed(owner, increase_value_1);
	context->Increased(owner);
}

const char * Ft_Esd_SpinBox_Push_Down_Text__Property(void *c)
{
	Ft_Esd_SpinBox *context = (Ft_Esd_SpinBox *)c;
	void *owner = context->Owner;
	bool if_6 = context->SideButtons;
	if (if_6)
	{
		return Ft_Esd_Char_LeftTriangle();
	}
	else
	{
		return Ft_Esd_Char_DownTriangle();
	}
}

void Ft_Esd_SpinBox_Push_Down_Down__Signal(void *c)
{
	Ft_Esd_SpinBox *context = (Ft_Esd_SpinBox *)c;
	void *owner = context->Owner;
	int left_9 = context->Value;
	int right_9 = context->Step(owner);
	int decrease_value_1 = left_9 - right_9;
	context->Value = decrease_value_1;
	context->Changed(owner, decrease_value_1);
	context->Decreased(owner);
}

void Ft_Esd_SpinBox_ESD_Render_Forwarder_ForwardRender__Signal(void *c)
{
	Ft_Esd_SpinBox *context = (Ft_Esd_SpinBox *)c;
	void *owner = context->Owner;
	ft_uint8_t s = Ft_Esd_TouchTag_Tag(&context->Touch_Tag);
	Ft_Esd_Dl_TAG(s);
	ft_uint8_t alpha = 255;
	Ft_Esd_Dl_COLOR_A(alpha);
	Ft_Esd_Theme * theme_2 = context->Theme(owner);
	ft_int16_t x_1 = Ft_Esd_RenderForwarder_GlobalX(&context->ESD_Render_Forwarder);
	ft_int16_t y_1 = Ft_Esd_RenderForwarder_GlobalY(&context->ESD_Render_Forwarder);
	ft_int16_t width = Ft_Esd_RenderForwarder_GlobalWidth(&context->ESD_Render_Forwarder);
	ft_int16_t height = Ft_Esd_RenderForwarder_GlobalHeight(&context->ESD_Render_Forwarder);
	ft_int16_t radius = 4;
	ft_bool_t raised = 0;
	Ft_Esd_Elements_Panel(theme_2, x_1, y_1, width, height, radius, raised);
}


/* end of file */
