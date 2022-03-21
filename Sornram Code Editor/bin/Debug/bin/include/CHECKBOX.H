#ifndef __CHECK_BOX_H__
#define __CHECK_BOX_H__

#include "gobject.h"

#define CHK_BOX_HEIGHT	10
#define CHK_BOX_WIDTH	10

class CheckBox:public GUIObject
{
 private:
  int Alignment;
  bool bReadOnly;
  bool State;

 public:
  CheckBox(int left,int top,int width,int height,char* caption=0,bool state=false);
  void SetAlignment(int Align);
  int GetAlignment();
  void SetReadOnly(bool ReadOnly);
  void Draw();
  void DrawCheckBox();
  bool GetState();
  bool Checked();
  void SetState(bool state);
  void MouseDown(BUTTON button,int x,int y);
};

#endif