#ifndef __GUIOBJECT_H__
#define __GUIOBJECT_H__

#include "global.h"

class Container;

class GUIObject
{
 private:
 protected:
  int Left,Top,Width,Height;
  char Caption[50];
  void far* imageBack;
  void (*funcClickHandler)();
  void (*funcClickHandlerEx)(GUIObject*);
 protected:
  Container* m_pParent;
  bool bEnabled;
 public:
  GUIObject(int left,int top,int width,int height,char* caption=0);
  bool MouseInside(int x,int y);
  void SetParent(Container* pParent);
  virtual void Move(int x,int y);
  virtual void MoveRelative(int x,int y);
  virtual void Draw();
  virtual void Erase();
  virtual void MouseDown(BUTTON button,int x,int y);
  virtual void MouseMove(BUTTON button,int x,int y);
  virtual void MouseUp(BUTTON button,int x,int y);
  virtual void OnClick();
  virtual void SetClickHandler(void (*func)());
  virtual void SetClickHandler(void (*func)(GUIObject*));
  virtual void CaptureEvents();
  virtual void SetCaption(char* Cap);
  virtual char* GetCaption();
  bool Enabled();
  void Enable(bool enable);
  ~GUIObject();
};

#endif