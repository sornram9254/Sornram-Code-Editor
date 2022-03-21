#ifndef WINDOW_CPP
#define WINDOW_CPP

#include "window.h"
#include <graphics.h>

Window::Window(int left,int top,int width,int height,char* caption):
	Container(left,top,width,height,caption)
{
 wndStatus=WINDOW_STATUS_NORMAL;
 pbtnClose=new CloseButton(Left+Width-14,Top+(BORDERWIDTH*2),11,11,this);
 AddObject(pbtnClose);
}

void Window::Draw()
{
 Container::Draw();
 setfillstyle(SOLID_FILL,LIGHTGRAY);
 bar(Left,Top,Left+Width,Top+Height);

 setcolor(WHITE);
 line(Left,Top,Left+Width,Top);
 line(Left,Top,Left,Top+Height);

 setcolor(BLACK);
 line(Left,Top+Height,Left+Width,Top+Height);
 line(Left+Width,Top,Left+Width,Top+Height);

 setfillstyle(SOLID_FILL,BLUE);
 bar(Left+BORDERWIDTH,Top+BORDERWIDTH,
	 Left+Width-(BORDERWIDTH*2),Top+TITLEBARHEIGHT);

 setcolor(WHITE);
 settextjustify(LEFT_TEXT,TOP_TEXT);
 outtextxy(Left+(BORDERWIDTH*2),
		   Top+(BORDERWIDTH*2)+(TITLEBARHEIGHT/2)-(textheight(Caption)/2),
		   Caption);
 Container::DrawControls();
}

void Window::Erase()
{
 Container::EraseControls();
 Container::Erase();
}

void Window::MouseDown(BUTTON button,int x,int y)
{
 switch (wndStatus)
 {
  case WINDOW_STATUS_NORMAL:
	if(button==MOUSE_LBUTTON &&
		x>=Left+BORDERWIDTH &&
		x<=Left+Width-(BORDERWIDTH*2) &&
		y>=Top+BORDERWIDTH &&
		y<=Top+TITLEBARHEIGHT &&
		button==MOUSE_LBUTTON &&
		!pbtnClose->MouseInside(x,y))
	{
	 distanceX=x-Left;distanceY=y-Top;
	 //wndStatus=WINDOW_STATUS_MOVING;
	 CaptureEvents();
	}
	else
	{
	 for(int i=0;i<nObjects;i++)
	  if(pObjects[i]->MouseInside(x,y))
	  {
	   pObjects[i]->MouseDown(button,x,y);
	   break;
	  }
	}
	break;
 }
}

void Window::MouseMove(BUTTON button,int x,int y)
{
 switch (wndStatus)
 {
  case WINDOW_STATUS_NORMAL:
	for(int i=0;i<nObjects;i++)
	if(pObjects[i]->MouseInside(x,y))
	{
	 pObjects[i]->MouseMove(button,x,y);
	 break;
	}
	break;
  case WINDOW_STATUS_MOVING:
	x-=distanceX;
	y-=distanceY;
	if(Left!=x && Top!=y)
	 Move(x,y);
	break;
 }
}

void Window::MouseUp(BUTTON button,int x,int y)
{
 switch (wndStatus)
 {
  case WINDOW_STATUS_NORMAL:
	for(int i=0;i<nObjects;i++)
	if(pObjects[i]->MouseInside(x,y))
	{
	 pObjects[i]->MouseUp(button,x,y);
	 break;
	}
	break;
  case WINDOW_STATUS_MOVING:
	wndStatus=WINDOW_STATUS_NORMAL;
	break;
 }
}

void Window::CaptureEvents()
{
 int x=Left,y=Top;

 setwritemode(XOR_PUT);
 setlinestyle(DOTTED_LINE,0,1);
 setcolor(WHITE);
 rectangle(x,y,x+Width,y+Height);
 while(!mouse.IsUp(MOUSE_LBUTTON))
 {
  if(x!=(mouse.GetPosX()-distanceX) && y!=(mouse.GetPosY()-distanceY))
  {
   mouse.Hide();
   rectangle(x,y,x+Width,y+Height);
   x=mouse.GetPosX()-distanceX;
   y=mouse.GetPosY()-distanceY;
   rectangle(x,y,x+Width,y+Height);
   mouse.Show();
  }
  mouse.GetStatus();
 }
 rectangle(x,y,x+Width,y+Height);
 setwritemode(COPY_PUT);
 setlinestyle(SOLID_LINE,0,1);
 Move(x,y);
}

void Window::Move(int x,int y)
{
 mouse.Hide();
 Erase();
 Container::Move(x,y);
 Draw();
 mouse.Show();
}

void Window::OnClose()
{
 mouse.Hide();
 Erase();
 m_pParent->RemoveObject(this);
 mouse.Show();
}


void Window::~Window()
{
 for(int i=0;i<nObjects;i++)
  delete pObjects[i];
}

CloseButton::CloseButton(int left,int top,int width,int height,Window* pWindow)
		:Button(left,top,width,height,"X")
{
 m_pWindow=pWindow;
}

void CloseButton::OnClick()
{
 m_pWindow->OnClose();
}

#endif