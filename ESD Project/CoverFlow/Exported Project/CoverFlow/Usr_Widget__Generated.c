/*
This file is automatically generated
DO NOT MODIFY BY HAND
Usr_Widget
C Source
*/

#include "Usr_Widget.h"

#include "Esd_Context.h"

ESD_CORE_EXPORT void Esd_Noop(void *context);
int Usr_Widget_ImageArray__Default(void *context, size_t *size) { *size = 0; return NULL; }

static int Usr_Widget_Touch_Area_2_X__Property(void *context) { return 80L; }
static int Usr_Widget_Touch_Area_2_Y__Property(void *context);
static int Usr_Widget_Touch_Area_2_Width__Property(void *context) { return 160L; }
static int Usr_Widget_Touch_Area_2_Height__Property(void *context) { return 160L; }
static int Usr_Widget_Touch_Area_X__Property(void *context) { return 560L; }
static int Usr_Widget_Touch_Area_Y__Property(void *context);
static int Usr_Widget_Touch_Area_Width__Property(void *context) { return 160L; }
static int Usr_Widget_Touch_Area_Height__Property(void *context) { return 160L; }
static Ft_Esd_BitmapCell Usr_Widget_ESD_Image_3_BitmapCell__Property(void *context);
static Ft_Esd_BitmapCell Usr_Widget_ESD_Image_2_BitmapCell__Property(void *context);
static Ft_Esd_BitmapCell Usr_Widget_ESD_Image_BitmapCell__Property(void *context);

static Ft_Esd_WidgetSlots s_Usr_Widget__Slots = {
	(void(*)(void *))Ft_Esd_Widget_Initialize,
	(void(*)(void *))Usr_Widget_Start,
	(void(*)(void *))Ft_Esd_Widget_Enable,
	(void(*)(void *))Usr_Widget_Update,
	(void(*)(void *))Usr_Widget_Render,
	(void(*)(void *))Usr_Widget_Idle,
	(void(*)(void *))Ft_Esd_Widget_Disable,
	(void(*)(void *))Usr_Widget_End,
};

static void Usr_Widget_Touch_Area_2_Down__Signal(void *context);
static void Usr_Widget_Touch_Area_Down__Signal(void *context);

void Usr_Widget__Touch_Area_2__Initializer(Usr_Widget *context)
{
	Ft_Esd_TouchArea *object = (Ft_Esd_TouchArea *)&context->Touch_Area_2;
	Ft_Esd_TouchArea__Initializer(object);
	object->Owner = (void *)context;
	object->X = Usr_Widget_Touch_Area_2_X__Property;
	object->Y = Usr_Widget_Touch_Area_2_Y__Property;
	object->Width = Usr_Widget_Touch_Area_2_Width__Property;
	object->Height = Usr_Widget_Touch_Area_2_Height__Property;
	object->Down = Usr_Widget_Touch_Area_2_Down__Signal;
}

void Usr_Widget__Touch_Area__Initializer(Usr_Widget *context)
{
	Ft_Esd_TouchArea *object = (Ft_Esd_TouchArea *)&context->Touch_Area;
	Ft_Esd_TouchArea__Initializer(object);
	object->Owner = (void *)context;
	object->X = Usr_Widget_Touch_Area_X__Property;
	object->Y = Usr_Widget_Touch_Area_Y__Property;
	object->Width = Usr_Widget_Touch_Area_Width__Property;
	object->Height = Usr_Widget_Touch_Area_Height__Property;
	object->Down = Usr_Widget_Touch_Area_Down__Signal;
}

void Usr_Widget__Fixed_Positioning__Initializer(Usr_Widget *context)
{
	Ft_Esd_Layout_Fixed *object = (Ft_Esd_Layout_Fixed *)&context->Fixed_Positioning;
	Ft_Esd_Layout_Fixed__Initializer(object);
	object->Owner = (void *)context;
	object->Widget.Active = 1;
	object->Widget.LocalX = 0;
	object->Widget.LocalY = 0;
	object->Widget.LocalWidth = 800;
	object->Widget.LocalHeight = 480;
	Ft_Esd_Widget_InsertBottom((Ft_Esd_Widget *)object, (Ft_Esd_Widget *)context);
}

void Usr_Widget__ESD_Image_3__Initializer(Usr_Widget *context)
{
	Ft_Esd_Image *object = (Ft_Esd_Image *)&context->ESD_Image_3;
	Ft_Esd_Image__Initializer(object);
	object->Owner = (void *)context;
	object->Widget.Active = 1;
	object->Widget.LocalX = 240;
	object->Widget.LocalY = 80;
	object->Widget.LocalWidth = 320;
	object->Widget.LocalHeight = 240;
	object->BitmapCell = Usr_Widget_ESD_Image_3_BitmapCell__Property;
	object->Scaling = ESD_SCALING_FIT;
	Ft_Esd_Widget_InsertBottom((Ft_Esd_Widget *)object, (Ft_Esd_Widget *)&context->Fixed_Positioning);
}

void Usr_Widget__ESD_Image_2__Initializer(Usr_Widget *context)
{
	Ft_Esd_Image *object = (Ft_Esd_Image *)&context->ESD_Image_2;
	Ft_Esd_Image__Initializer(object);
	object->Owner = (void *)context;
	object->Widget.Active = 1;
	object->Widget.LocalX = 480;
	object->Widget.LocalY = 120;
	object->Widget.LocalWidth = 240;
	object->Widget.LocalHeight = 160;
	object->BitmapCell = Usr_Widget_ESD_Image_2_BitmapCell__Property;
	object->Scaling = ESD_SCALING_FIT;
	Ft_Esd_Widget_InsertBottom((Ft_Esd_Widget *)object, (Ft_Esd_Widget *)&context->Fixed_Positioning);
}

void Usr_Widget__ESD_Image__Initializer(Usr_Widget *context)
{
	Ft_Esd_Image *object = (Ft_Esd_Image *)&context->ESD_Image;
	Ft_Esd_Image__Initializer(object);
	object->Owner = (void *)context;
	object->Widget.Active = 1;
	object->Widget.LocalX = 80;
	object->Widget.LocalY = 120;
	object->Widget.LocalWidth = 240;
	object->Widget.LocalHeight = 160;
	object->BitmapCell = Usr_Widget_ESD_Image_BitmapCell__Property;
	object->Scaling = ESD_SCALING_FIT;
	Ft_Esd_Widget_InsertBottom((Ft_Esd_Widget *)object, (Ft_Esd_Widget *)&context->Fixed_Positioning);
}

void Usr_Widget__Initializer(Usr_Widget *context)
{
	Ft_Esd_Widget__Initializer((Ft_Esd_Widget *)context);
	context->Widget.ClassId = Usr_Widget_CLASSID;
	context->Widget.Slots = &s_Usr_Widget__Slots;
	context->Widget.LocalX = -1;
	context->Widget.LocalY = 32;
	context->Widget.LocalWidth = 799;
	context->Widget.LocalHeight = 383;
	context->img1 = (Esd_BitmapCell){ 0 };
	context->x1 = 80L;
	context->y1 = 120L;
	context->w1 = 240L;
	context->h1 = 160L;
	context->img2 = (Esd_BitmapCell){ 0 };
	context->x2 = 240L;
	context->y2 = 80L;
	context->w2 = 320L;
	context->h2 = 240L;
	context->img3 = (Esd_BitmapCell){ 0 };
	context->x3 = 480L;
	context->y3 = 120L;
	context->ImageArray = Usr_Widget_ImageArray__Default;
	context->w3 = 240L;
	context->h3 = 160L;
	Usr_Widget__Touch_Area_2__Initializer(context);
	Usr_Widget__Touch_Area__Initializer(context);
	Usr_Widget__Fixed_Positioning__Initializer(context);
	Usr_Widget__ESD_Image_3__Initializer(context);
	Usr_Widget__ESD_Image_2__Initializer(context);
	Usr_Widget__ESD_Image__Initializer(context);
}

void Usr_Widget_Start_Signal(Usr_Widget *context);
void Usr_Widget_Update_Signal(Usr_Widget *context);
void Usr_Widget_LeftTouch(Usr_Widget *context);
void Usr_Widget_RightTouch(Usr_Widget *context);

void Usr_Widget_Update__Builtin(Usr_Widget *context)
{
	void *owner = context->Owner;
	Ft_Esd_TouchArea_Update(&context->Touch_Area_2);
	Ft_Esd_TouchArea_Update(&context->Touch_Area);
	int update_variable = context->x2;
	Ft_Esd_Widget_SetX((Ft_Esd_Widget *)&context->ESD_Image_3, update_variable);
	int update_variable_1 = context->y2;
	Ft_Esd_Widget_SetY((Ft_Esd_Widget *)&context->ESD_Image_3, update_variable_1);
	int update_variable_2 = context->w2;
	Ft_Esd_Widget_SetWidth((Ft_Esd_Widget *)&context->ESD_Image_3, update_variable_2);
	int update_variable_3 = context->h2;
	Ft_Esd_Widget_SetHeight((Ft_Esd_Widget *)&context->ESD_Image_3, update_variable_3);
	int update_variable_4 = context->x3;
	Ft_Esd_Widget_SetX((Ft_Esd_Widget *)&context->ESD_Image_2, update_variable_4);
	int update_variable_5 = context->y3;
	Ft_Esd_Widget_SetY((Ft_Esd_Widget *)&context->ESD_Image_2, update_variable_5);
	int update_variable_6 = context->w3;
	Ft_Esd_Widget_SetWidth((Ft_Esd_Widget *)&context->ESD_Image_2, update_variable_6);
	int update_variable_7 = context->h3;
	Ft_Esd_Widget_SetHeight((Ft_Esd_Widget *)&context->ESD_Image_2, update_variable_7);
	int update_variable_8 = context->x1;
	Ft_Esd_Widget_SetX((Ft_Esd_Widget *)&context->ESD_Image, update_variable_8);
	int update_variable_9 = context->y1;
	Ft_Esd_Widget_SetY((Ft_Esd_Widget *)&context->ESD_Image, update_variable_9);
	int update_variable_10 = context->w1;
	Ft_Esd_Widget_SetWidth((Ft_Esd_Widget *)&context->ESD_Image, update_variable_10);
	int update_variable_11 = context->h1;
	Ft_Esd_Widget_SetHeight((Ft_Esd_Widget *)&context->ESD_Image, update_variable_11);
	Ft_Esd_Widget_Update((Ft_Esd_Widget *)context);
}

void Usr_Widget_End__Builtin(Usr_Widget *context)
{
	void *owner = context->Owner;
	Ft_Esd_Widget_End((Ft_Esd_Widget *)context);
	Ft_Esd_Widget_Detach((Ft_Esd_Widget *)&context->Fixed_Positioning); 
	Ft_Esd_Widget_Detach((Ft_Esd_Widget *)&context->ESD_Image_3); 
	Ft_Esd_Widget_Detach((Ft_Esd_Widget *)&context->ESD_Image_2); 
	Ft_Esd_Widget_Detach((Ft_Esd_Widget *)&context->ESD_Image); 
}

void Usr_Widget_Start(Usr_Widget *context)
{
	void *owner = context->Owner;
	Ft_Esd_Widget_Start((Ft_Esd_Widget *)context); 
	Usr_Widget_Start_Signal(context);
}

void Usr_Widget_Update(Usr_Widget *context)
{
	void *owner = context->Owner;
	Usr_Widget_Update_Signal(context);
	Usr_Widget_Update__Builtin(context);
}

void Usr_Widget_Render(Usr_Widget *context)
{
	void *owner = context->Owner;
	Ft_Esd_Widget_Render((Ft_Esd_Widget *)context); 
}

void Usr_Widget_Idle(Usr_Widget *context)
{
	void *owner = context->Owner;
	Ft_Esd_Widget_Idle((Ft_Esd_Widget *)context); 
}

void Usr_Widget_End(Usr_Widget *context)
{
	void *owner = context->Owner;
	Usr_Widget_End__Builtin(context);
}

int Usr_Widget_Touch_Area_2_Y__Property(void *c)
{
	Usr_Widget *context = (Usr_Widget *)c;
	void *owner = context->Owner;
	int left = 120L;
	ft_int16_t right = context->Widget.GlobalY;
	return left + right;
}

void Usr_Widget_Touch_Area_2_Down__Signal(void *c)
{
	Usr_Widget *context = (Usr_Widget *)c;
	void *owner = context->Owner;
	Usr_Widget_LeftTouch(context);
}

int Usr_Widget_Touch_Area_Y__Property(void *c)
{
	Usr_Widget *context = (Usr_Widget *)c;
	void *owner = context->Owner;
	int left_1 = 120L;
	ft_int16_t right_1 = context->Widget.GlobalY;
	return left_1 + right_1;
}

void Usr_Widget_Touch_Area_Down__Signal(void *c)
{
	Usr_Widget *context = (Usr_Widget *)c;
	void *owner = context->Owner;
	Usr_Widget_RightTouch(context);
}

Ft_Esd_BitmapCell Usr_Widget_ESD_Image_3_BitmapCell__Property(void *c)
{
	Usr_Widget *context = (Usr_Widget *)c;
	void *owner = context->Owner;
	return context->img2;
}

Ft_Esd_BitmapCell Usr_Widget_ESD_Image_2_BitmapCell__Property(void *c)
{
	Usr_Widget *context = (Usr_Widget *)c;
	void *owner = context->Owner;
	return context->img3;
}

Ft_Esd_BitmapCell Usr_Widget_ESD_Image_BitmapCell__Property(void *c)
{
	Usr_Widget *context = (Usr_Widget *)c;
	void *owner = context->Owner;
	return context->img1;
}


/* end of file */
