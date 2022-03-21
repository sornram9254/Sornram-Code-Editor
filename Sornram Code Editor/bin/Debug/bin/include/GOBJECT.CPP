#ifndef GUIOBJECT_CPP
#define GUIOBJECT_CPP

#include "gobject.h"
#include <graphics.h>
#include <string.h>
#include <iostream.h>
#include <stdlib.h>
#include <alloc.h>

GUIObject::GUIObject(int left,int top,int width,int height,char* caption)
{
 Left=left;Top=top;
 Width=width;Height=height;
 strcpy(Caption,caption);
 if(Width!=0 && Height!=0)
 {
  imageBack=farmalloc(imagesize(Left,Top,Left+Width,Top+Height));
  if(imageBack==NULL)
  {
   closegraph();
   cout<<"Couldn't allocate memory for TurboGUI object";
   exit(1);
  }
 }
 else
  imageBack=NULL;

 funcClickHandler=NULL;
 funcClickHandlerEx=NULL;
 bEnabled=true;
}

void GUIObject::SetParent(Container* pParent)
{
 m_pParent=pParent;
}

void GUIObject::Draw()
{
 getimage(Left,Top,Left+Width,Top+Height,imageBack);
}

void GUIObject::Erase()
{
 if(imageBack!=NULL)
  putimage(Left,Top,imageBack,COPY_PUT);
}

bool GUIObject::MouseInside(int x,int y)
{
 if(x>=Left && y>=Top && x<=Left+Width && y<=Top+Height)
  return true;
 else
  return false;
}

void GUIObject::Move(int x,int y)
{
 Left=x;
 Top=y;
}

void GUIObject::MoveRelative(int x,int y)
{
 Left+=x;
 Top+=y;
}

void GUIObject::MouseDown(BUTTON button,int x,int y){}
void GUIObject::MouseMove(BUTTON button,int x,int y){}
void GUIObject::MouseUp(BUTTON button,int x,int y){}

void GUIObject::OnClick()
{
 if(funcClickHandler!=NULL)
  (*funcClickHandler)();
 if(funcClickHandlerEx!=NULL)
  (*funcClickHandlerEx)(this);
}

void GUIObject::SetClickHandler(void (*func)())
{
 funcClickHandler=func;
}

void GUIObject::SetClickHandler(void (*func)(GUIObject*))
{
 funcClickHandlerEx=func;
}

void GUIObject::CaptureEvents(){}

void GUIObject::SetCaption(char* Cap)
{
 strcpy(Caption,Cap);
}

char* GUIObject::GetCaption()
{
 return Caption;
}

bool GUIObject::Enabled()
{
 return bEnabled;
}

void GUIObject::Enable(bool enable)
{
 bEnabled=enable;
}

GUIObject::~GUIObject()
{
 farfree(imageBack);
}


#endif