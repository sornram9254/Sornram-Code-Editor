#ifndef __BUTTON_H__
#define __BUTTON_H__

#include "GObject.h"

enum BUTTON_STATUS
{
 BUTTON_STATUS_NORMAL,
 BUTTON_STATUS_DOWN,
};

class Button:public GUIObject
{
 private:
  BUTTON_STATUS btnStatus;
 public:
  Button(int left,int top,int width,int height,char* caption=0);
  void Draw();
  void MouseDown(BUTTON button,int x,int y);
  void MouseMove(BUTTON button,int x,int y);
  void MouseUp(BUTTON button,int x,int y);
};

#endif