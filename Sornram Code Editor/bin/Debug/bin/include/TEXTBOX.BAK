#ifndef __TEXT_BOX_CPP__
#define __TEXT_BOX_CPP__

#include "textbox.h"
#include "turbogui.h"
#include <graphics.h>
#include <conio.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

TextBox::TextBox(int left,int top,int width,int height,char* caption)
	:GUIObject(left,top,width,height,caption)
{
 bReadOnly=false;
 Alignment=LEFT_TEXT;
}

void TextBox::Draw()
{
 GUIObject::Draw();
 DrawTextBox();
}

void TextBox::DrawTextBox()
{
 setfillstyle(SOLID_FILL,WHITE);
 bar(Left,Top,Left+Width,Top+Height);

 setcolor(DARKGRAY);
 rectangle(Left,Top,Left+Width,Top+Height);

 setcolor(BLACK);

 settextjustify(Alignment,TOP_TEXT);
 if(Alignment==LEFT_TEXT)
  outtextxy(Left+2,Top+1+((Height/2)-(textheight(Caption)/2)),Caption);
 else
  if(Alignment==RIGHT_TEXT)
   outtextxy(Left+Width-2,Top+1+((Height/2)-(textheight(Caption)/2)),Caption);
  else
   outtextxy(Left+(Width/2),Top+1+((Height/2)-(textheight(Caption)/2)),Caption);

}

void TextBox::SetAlignment(int Align)
{
 Alignment=Align;
}

int TextBox::GetAlignment()
{
 return Alignment;
}

void TextBox::SetText(char *str)
{
 strcpy(Caption,str);
 DrawTextBox();
}

char* TextBox::GetText()
{
 return Caption;
}

void TextBox::SetReadOnly(bool ReadOnly)
{
 bReadOnly=ReadOnly;
}

bool TextBox::GetReadOnly()
{
 return bReadOnly;
}

void TextBox::MouseDown(BUTTON button,int x,int y)
{

 if(bReadOnly) return;

 int ch;
 int len=strlen(Caption),curpos,curx;
 clock_t cbefore, cafter;

 mouse.Hide();
 curpos=len;
 do{
  curx=Left+textwidth(Caption)+1;

  if(!kbhit())
  {
   setwritemode(XOR_PUT);
   setcolor(WHITE);
   line(curx,Top+1,curx,Top+Height-1);
   do{
	 line(curx,Top+1,curx,Top+Height-1);
	 delay(100);
   }while(!kbhit());
   setwritemode(COPY_PUT);
  }


  ch=getch();
  if(ch==0) ch=getch();
  switch (ch)
  {
   case 8:
	if(len>0)
	{
	 Caption[curpos-1]=0;
	 curpos--;
	 len--;
	}
	break;
  }
  if(isprint(ch))
  {
	Caption[curpos]=ch;
	Caption[curpos+1]=0;
	if(Left+textwidth(Caption)>Left+Width)
	{
	 Caption[curpos]=0;
	 DrawTextBox();
	 break;
	}
	else
	{
	 curpos++;
	 len++;
	}
  }

  DrawTextBox();
 }while(ch!=13 && ch!=27);
 mouse.Show();
}

#endif