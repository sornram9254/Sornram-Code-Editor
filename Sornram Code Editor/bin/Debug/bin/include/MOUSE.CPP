#ifndef MOUSE_CPP
#define MOUSE_CPP

#include "Mouse.h"

void Mouse::Install()
{
 inregs.x.ax=0;
 int86(0x33,&inregs,&outregs);
}

void Mouse::Show()
{
 inregs.x.ax=1;
 int86(0x33,&inregs,&outregs);
}

void Mouse::Hide()
{
 inregs.x.ax=2;
 int86(0x33,&inregs,&outregs);
}

void Mouse::GetStatus()
{
 inregs.x.ax=3;
 int86(0x33,&inregs,&outregs);
 mouseBtn=outregs.x.bx;
 mouseX=outregs.x.cx;
 mouseY=outregs.x.dx;
}

BUTTON Mouse::GetButton()
{
 return mouseBtn;
}

int Mouse::GetPosX()
{
 return mouseX;
}

int Mouse::GetPosY()
{
 return mouseY;
}

bool Mouse::IsDown(BUTTON button)
{
 inregs.x.ax=5;
 inregs.x.bx=button;
 int86(0x33,&inregs,&outregs);
 return outregs.x.bx;
}

bool Mouse::IsUp(BUTTON button)
{
 inregs.x.ax=6;
 inregs.x.bx=button;
 int86(0x33,&inregs,&outregs);
 return outregs.x.bx;
}

#endif