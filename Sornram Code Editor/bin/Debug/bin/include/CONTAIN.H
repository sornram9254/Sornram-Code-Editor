#ifndef __CONTAINER_H__
#define __CONTAINER_H__

#include "global.h"
#include "gobject.h"

class Container:public GUIObject
{
 protected:
  int nObjects;
  GUIObject *pObjects[MAXOBJECTS];
 public:
  Container(int left,int top,int width,int height,char* caption=0);
  virtual void AddObject(GUIObject *obj);
  virtual void RemoveObject(GUIObject *obj);
  virtual void Draw();
  virtual void DrawControls();
  virtual void Move(int x,int y);
  virtual void Erase();
  virtual void EraseControls();
};

#endif