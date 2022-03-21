#ifndef __MOUSE_H__
#define __MOUSE_H__

#include <dos.h>
#include "global.h"

class Mouse
{
 private:
  union REGS inregs,outregs;
  int mouseX,mouseY;
  BUTTON mouseBtn;
 public:
  void Install();
  void Show();
  void Hide();
  void GetStatus();
  BUTTON GetButton();
  int GetPosX();
  int GetPosY();
  bool IsDown(BUTTON button);
  bool IsUp(BUTTON button);
};

#endif