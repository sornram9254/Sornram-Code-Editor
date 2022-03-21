#ifndef __CONTAINER_CPP__
#define __CONTAINER_CPP__

#include "contain.h"

void Container::Container(int left,int top,int width,int height,char* caption)
	:GUIObject(left,top,width,height,caption)
{
 nObjects=0;
}

void Container::AddObject(GUIObject *obj)
{
 obj->SetParent(this);
 pObjects[nObjects++]=obj;
}

void Container::RemoveObject(GUIObject *obj)
{
 for(int i=0;i<nObjects;i++)
  if(pObjects[i]==obj)
  {
   delete pObjects[i];

   for(int j=i+1;j<nObjects;j++)
    pObjects[j-1]=pObjects[j];

   nObjects--;
   break;
  }
}

void Container::Draw()
{
 GUIObject::Draw();
}

void Container::DrawControls()
{
 for(int i=0;i<nObjects;i++)
  pObjects[i]->Draw();
}

void Container::Move(int x,int y)
{
 for(int i=0;i<nObjects;i++)
  pObjects[i]->MoveRelative(x-Left,y-Top);
 GUIObject::Move(x,y);
}

void Container::Erase()
{
 GUIObject::Erase();
}

void Container::EraseControls()
{
 for(int i=0;i<nObjects;i++)
  pObjects[i]->Erase();
}

#endif