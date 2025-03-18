#include "Ft_Esd.h"
#include "Usr_Widget.h"


int pre = 0;
int next = 0;
int cur = 0;
int flaq = 0;

int mm = 1;    /// Set mm value is 2, then animation speed is high, Set mm value is 1, It is normal. 

ESD_METHOD(Usr_Widget_RightTouch, Context = Usr_Widget)
void Usr_Widget_RightTouch(Usr_Widget *context)
{
	next = next + 1;
	cur = 1;
}

ESD_METHOD(Usr_Widget_LeftTouch, Context = Usr_Widget)
void Usr_Widget_LeftTouch(Usr_Widget *context)
{
	next = next - 1;
	pre = 1;
}

ESD_METHOD(Usr_Widget_Update_Signal, Context = Usr_Widget)
void Usr_Widget_Update_Signal(Usr_Widget *context)
{
	flaq = 0;
	
	if(cur != 0)
	{
		//  First Image
		int x1 = context->x1;
		int xx = x1 + (mm*10);
		if(xx <= 480)
		{
			context->x1 = xx;
			flaq = 1;
		}
		
		// Second Image
		int x2 = context->x2;
		int y2 = context->y2;
		int w2 = context->w2;
		int h2 = context->h2;
		
		xx = x2 - (mm*4);
		if(xx >= 80)
		{
			context->x2 = xx;
			flaq = 1;
		}
		
		int yy = y2 + (mm*1);
		if(yy <= 120)
		{
			context->y2 = yy;
			flaq = 1;
		}
		
		int ww = w2 - (mm*2);
		if(ww >= 240)
		{
			context->w2 = ww;
			flaq = 1;
		}
		
		int hh = h2 - (mm*2);
		if(hh >= 160)
		{
			context->h2 = hh;
			flaq = 1;
		}
		
		// Third Image
		int x3 = context->x3;
		int y3 = context->y3;
		int w3 = context->w3;
		int h3 = context->h3;
		
		xx = x3 - (mm*6);
		if(xx >= 240)
		{
			context->x3 = xx;
			flaq = 1;
		}
		
		yy = y3 - (mm*1);
		if(yy >= 80)
		{
			context->y3 = yy;
			flaq = 1;
		}
		
		ww = w3 + (mm*2);
		if(ww <= 320)
		{
			context->w3 = ww;
			flaq = 1;
		}
		
		hh = h3 + (mm*2);
		if(hh <= 240)
		{
			context->h3 = hh;
			flaq = 1;
		}
	
		if( (flaq == 0) )
		{
			context->x1 = 80;
			context->y1 = 120;
			context->w1 = 240;
			context->h1 = 160;
		
			context->x2 = 240;
			context->y2 = 80;
			context->w2 = 320;
			context->h2 = 240;
		
			context->x3 = 480;
			context->y3 = 120;
			context->w3 = 240;
			context->h3 = 160;
		
			size_t size = 0;
			Esd_BitmapCell* bitmapArr = context->ImageArray(context, &size);
			if(size > 0 && bitmapArr)
			{
				int index = next % size;
				context->img1 = bitmapArr[index];
				index = (index+1) % size; 
				context->img2 = bitmapArr[index];
				index = (index+1) % size; 
				context->img3 = bitmapArr[index];
				cur = 0;
			}
		}
	}
	
	if(pre != 0)
	{
		//  First Image
		int x1 = context->x1;
		int y1 = context->y1;
		int w1 = context->w1;
		int h1 = context->h1;
		
		int xx = x1 + (mm*4);
		if(xx <= 240)
		{
			context->x1 = xx;
			flaq = 1;
		}
		
		int yy = y1 - (mm*1);
		if(yy >= 80)
		{
			context->y1 = yy;
			flaq = 1;
		}
		
		int ww = w1 + (mm*2);
		if(ww <= 320)
		{
			context->w1 = ww;
			flaq = 1;
		}
		
		int hh = h1 + (mm*2);
		if(hh <= 240)
		{
			context->h1 = hh;
			flaq = 1;
		}	
		
		// Second Image
		int x2 = context->x2;
		int y2 = context->y2;
		int w2 = context->w2;
		int h2 = context->h2;
		
		xx = x2 + (mm*6);
		if(xx <= 480)
		{
			context->x2 = xx;
			flaq = 1;
		}
		
		yy = y2 + (mm*1);
		if(yy <= 120)
		{
			context->y2 = yy;
			flaq = 1;
		}
		
		ww = w2 - (mm*2);
		if(ww >= 240)
		{
			context->w2 = ww;
			flaq = 1;
		}
		
		hh = h2 - (mm*2);
		if(hh >= 160)
		{
			context->h2 = hh;
			flaq = 1;
		}
		
		// Third Image
		int x3 = context->x3;
		xx = x3 - (mm*10);
		if(xx >= 80)
		{
			context->x3 = xx;
			flaq = 1;
		}
		
		if( (flaq == 0) )
		{
			context->x1 = 80;
			context->y1 = 120;
			context->w1 = 240;
			context->h1 = 160;
		
			context->x2 = 240;
			context->y2 = 80;
			context->w2 = 320;
			context->h2 = 240;
		
			context->x3 = 480;
			context->y3 = 120;
			context->w3 = 240;
			context->h3 = 160;
		
			size_t size = 0;
			Esd_BitmapCell* bitmapArr = context->ImageArray(context, &size);
			if(size > 0 && bitmapArr)
			{
				int index = next % size;
				context->img1 = bitmapArr[index];
				index = (index+1) % size; 
				context->img2 = bitmapArr[index];
				index = (index+1) % size; 
				context->img3 = bitmapArr[index];
				pre = 0;
			}
		}
		
	}
}

ESD_METHOD(Usr_Widget_Start_Signal, Context = Usr_Widget)
void Usr_Widget_Start_Signal(Usr_Widget *context)
{
	size_t size = 0;
	Esd_BitmapCell* bitmapArr = context->ImageArray(context, &size);
	if(size > 0 && bitmapArr)
	{
		next = size * 100;
		cur = 0;
		int index = next % size;
	    context->img1 = bitmapArr[index];
		index = (index+1) % size; 
		context->img2 = bitmapArr[index];
		index = (index+1) % size; 
		context->img3 = bitmapArr[index];
    }
}
