#ifndef __CHECK_BOX_CPP__
#define __CHECK_BOX_CPP__

#include "checkbox.h"
#include "turbogui.h"
#include <graphics.h>
#include <conio.h>
#include <string.h>

CheckBox::CheckBox(int left,int top,int width,int height,char* caption,bool state)
	:GUIObject(left,top,width,height,caption)
{
 State=state;
 Alignment=LEFT_TEXT;
}

void CheckBox::Draw()
{
 GUIObject::Draw();

 int TopAlign=(Height/2)-(CHK_BOX_HEIGHT/2);
 int LeftAlign=0;

 GUIObject::Draw();

 if(Alignment==RIGHT_TEXT)
  LeftAlign=Width-CHK_BOX_WIDTH;

 setfillstyle(SOLID_FILL,LIGHTGRAY);
 bar(Left,Top,Left+Width,Top+Height);

 setfillstyle(SOLID_FILL,WHITE);
 bar(Left+LeftAlign+1,Top+TopAlign+1,Left+LeftAlign+CHK_BOX_WIDTH,Top+TopAlign+CHK_BOX_HEIGHT);

 setcolor(DARKGRAY);
 line(Left+LeftAlign,Top+TopAlign,Left+LeftAlign+CHK_BOX_WIDTH,Top+TopAlign);
 line(Left+LeftAlign,Top+TopAlign,Left+LeftAlign,Top+TopAlign+CHK_BOX_HEIGHT);

 setcolor(BLACK);
 line(Left+LeftAlign+1,Top+TopAlign+1,Left+LeftAlign+(CHK_BOX_WIDTH-1),Top+TopAlign+1);
 line(Left+LeftAlign+1,Top+TopAlign+1,Left+LeftAlign+1,Top+TopAlign+(CHK_BOX_HEIGHT-1));

 setcolor(LIGHTGRAY);
 line(Left+LeftAlign+(CHK_BOX_WIDTH-1),Top+TopAlign+1,Left+LeftAlign+(CHK_BOX_WIDTH-1),Top+TopAlign+(CHK_BOX_HEIGHT-1));
 line(Left+LeftAlign+1,Top+TopAlign+(CHK_BOX_HEIGHT-1),Left+LeftAlign+(CHK_BOX_WIDTH-1),Top+TopAlign+(CHK_BOX_HEIGHT-1));

 setcolor(WHITE);
 line(Left+LeftAlign,Top+TopAlign+CHK_BOX_HEIGHT,Left+LeftAlign+CHK_BOX_WIDTH,Top+TopAlign+CHK_BOX_HEIGHT);
 line(Left+LeftAlign+CHK_BOX_WIDTH,Top+TopAlign,Left+LeftAlign+CHK_BOX_WIDTH,Top+TopAlign+CHK_BOX_HEIGHT);

 setcolor(BLACK);
 if(Alignment==LEFT_TEXT)
 {
  settextjustify(LEFT_TEXT,CENTER_TEXT);
  outtextxy(Left+CHK_BOX_WIDTH+3,Top+(Height/2)+1,Caption);
 }
 else
 {
  settextjustify(RIGHT_TEXT,CENTER_TEXT);
  outtextxy(Left+Width-(CHK_BOX_WIDTH+3),Top+(Height/2)+1,Caption);
 }

 DrawCheckBox();
}

void CheckBox::DrawCheckBox()
{
 int TopAlign=(Height/2)-(CHK_BOX_HEIGHT/2);
 int LeftAlign=0;

 setfillstyle(SOLID_FILL,WHITE);
 bar(Left+LeftAlign+2,Top+TopAlign+2,Left+LeftAlign+(CHK_BOX_WIDTH-2),Top+TopAlign+(CHK_BOX_HEIGHT-2));

 if(State)
 {
  setlinestyle(SOLID_LINE,0,3);
  setcolor(BLACK);
  line(Left+LeftAlign+2,Top+TopAlign+2,Left+LeftAlign+(CHK_BOX_WIDTH-2),Top+TopAlign+(CHK_BOX_HEIGHT-2));
  line(Left+LeftAlign+(CHK_BOX_WIDTH-2),Top+TopAlign+2,Left+LeftAlign+2,Top+TopAlign+(CHK_BOX_HEIGHT-2));
  setlinestyle(SOLID_LINE,0,1);
 }
}

bool CheckBox::GetState()
{
 return State;
}

bool CheckBox::Checked()
{
 return State;
}

void CheckBox::SetState(bool state)
{
 State=state;
}

void CheckBox::SetAlignment(int Align)
{
 Alignment=Align;
}

int CheckBox::GetAlignment()
{
 return Alignment;
}

void CheckBox::MouseDown(BUTTON button,int x,int y)
{
 if(!Enabled()) return;

 State=!State;
 mouse.Hide();
 DrawCheckBox();
 mouse.Show();
}

#endif