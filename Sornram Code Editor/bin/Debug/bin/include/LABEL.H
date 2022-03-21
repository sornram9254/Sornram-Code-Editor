#ifndef __LABEL_H__
#define __LABEL_H__

#include "gobject.h"

class Label:public GUIObject
{
 public:
  Label(int left,int top,int width,int height,char* caption=0);
  void Draw();
};

#endif