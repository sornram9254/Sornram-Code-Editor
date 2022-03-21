#ifndef __WINDOW_H__
#define __WINDOW_H__

#include "turbogui.h"
#include "contain.h"
#include "button.h"

#define TITLEBARHEIGHT	13
#define BORDERWIDTH	1

enum WindowStatus
{
 WINDOW_STATUS_NORMAL=0,
 WINDOW_STATUS_MOVING=1
};

class CloseButton;

class Window:public Container
{
 private:
  WindowStatus wndStatus;
  int distanceX,distanceY;
  CloseButton *pbtnClose;
 protected:
  void CaptureEvents();
 public:
  Window(int left,int top,int width,int height,char* caption=0);
  virtual void MouseDown(BUTTON button,int x,int y);
  virtual void MouseMove(BUTTON button,int x,int y);
  virtual void MouseUp(BUTTON button,int x,int y);
  virtual void Move(int x,int y);
  virtual void Draw();
  virtual void Erase();
  virtual void OnClose();
  ~Window();
};

class CloseButton:public Button
{
 public:
  CloseButton(int left,int top,int width,int height,Window* pWindow);
 private:
  Window* m_pWindow;
  void OnClick();
};


#endif