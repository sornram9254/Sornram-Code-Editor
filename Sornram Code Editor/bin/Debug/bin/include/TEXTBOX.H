#ifndef __TEXT_BOX_H__
#define __TEXT_BOX_H__

#include "gobject.h"

class TextBox:public GUIObject
{
 private:
  int Alignment;
  bool bReadOnly;

 public:
  TextBox(int left,int top,int width,int height,char* caption=0);
  void SetAlignment(int Align);
  int GetAlignment();
  void SetText(char *str);
  char* GetText();
  void SetReadOnly(bool ReadOnly);
  bool GetReadOnly();
  void Draw();
  void DrawTextBox();
  void MouseDown(BUTTON button,int x,int y);
};

#endif