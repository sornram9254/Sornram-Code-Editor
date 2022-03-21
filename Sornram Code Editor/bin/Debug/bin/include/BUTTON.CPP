#ifndef __BUTTON_CPP__
#define __BUTTON_CPP__

#include <graphics.h>
#include "Button.h"
#include "turbogui.h"

Button::Button(int left,int top,int width,int height,char* caption)
	:GUIObject(left,top,width,height,caption)
{
 btnStatus=BUTTON_STATUS_NORMAL;
}

void Button::Draw()
{
 GUIObject::Draw();
 setfillstyle(SOLID_FILL,LIGHTGRAY);
 bar(Left,Top,Left+Width,Top+Height);

 setcolor(WHITE);
 line(Left,Top,Left+Width,Top);
 line(Left,Top,Left,Top+Height);

 setcolor(BLACK);
 line(Left,Top+Height,Left+Width,Top+Height);
 line(Left+Width,Top,Left+Width,Top+Height);

 setcolor(BLACK);
 settextjustify(LEFT_TEXT,TOP_TEXT);
 outtextxy(Left+(Width/2)-(textwidth(Caption)/2)+1,
	   Top+(Height/2)-(textheight(Caption)/2)+1,Caption);
}

void Button::MouseDown(BUTTON button,int x,int y)
{
 if(!Enabled()) return;

 switch (button)
 {
  case MOUSE_LBUTTON:
	mouse.Hide();
	setcolor(BLACK);
	line(Left,Top,Left+Width,Top);
	line(Left,Top,Left,Top+Height);

	setcolor(WHITE);
	line(Left,Top+Height,Left+Width,Top+Height);
	line(Left+Width,Top,Left+Width,Top+Height);
	mouse.Show();
	btnStatus=BUTTON_STATUS_DOWN;
	break;
 }
}

void Button::MouseMove(BUTTON button,int x,int y)
{
}

void Button::MouseUp(BUTTON button,int x,int y)
{
 if(!Enabled()) return;

 switch (button)
 {
  case MOUSE_LBUTTON:
	if(btnStatus==BUTTON_STATUS_DOWN)
	{
	 mouse.Hide();
	 setcolor(WHITE);
	 line(Left,Top,Left+Width,Top);
	 line(Left,Top,Left,Top+Height);

	 setcolor(BLACK);
	 line(Left,Top+Height,Left+Width,Top+Height);
	 line(Left+Width,Top,Left+Width,Top+Height);
	 mouse.Show();
	 btnStatus=BUTTON_STATUS_NORMAL;
	 OnClick();
	}
	break;
 }
}

#endif