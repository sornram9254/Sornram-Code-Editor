#ifndef DESKTOP_CPP
#define DESKTOP_CPP

#include "Desktop.h"
#include <graphics.h>
#include <iostream.h>
#include <conio.h>
#include <stdlib.h>

Desktop::Desktop(char *DriverPath)
	:Container(0,0,0,0,NULL)
{
 graphDriver=DETECT;
 InitGraphics(DriverPath);
 Init();
}

Desktop::Desktop(char *DriverPath,int GraphDriver, int GraphMode)
	:Container(0,0,0,0,NULL)
{
 graphDriver=GraphDriver;
 graphMode=GraphMode;
 InitGraphics(DriverPath);
 Init();
}

void Desktop::DrawBackground()
{
 struct fillsettingstype fillinfo;

 getfillsettings(&fillinfo);
 setfillstyle(SOLID_FILL,BkColor);
 bar(0,0,Width,Height);
 setfillstyle(fillinfo.pattern,fillinfo.color);
}

void Desktop::InitGraphics(char *DriverPath)
{
 int errorcode;
 initgraph(&graphDriver, &graphMode, DriverPath);
 errorcode=graphresult();

 if(errorcode!=grOk)
 {
  cout<<endl<<"Graphics error:"<<grapherrormsg(errorcode);
  cout<<endl<<"Press any key to halt:";
  getch();
  exit(1);
 }
}

int Desktop::Run()
{
 int ch;
 GUIObject* pObject;

 DrawBackground();
 Draw();
 mouse.Show();

 do{
  do{
   mouse.GetStatus();
   pObject=0;
   for(int i=0;i<nObjects;i++)
    if(pObjects[i]->MouseInside(mouse.GetPosX(),mouse.GetPosY()))
	{
	 pObject=pObjects[i];
	 break;
	}
   if(pObject!=0)
   {
	pObject->MouseMove(mouse.GetButton(),mouse.GetPosX(),mouse.GetPosY());

	if(mouse.IsDown(MOUSE_LBUTTON))
	   pObject->MouseDown(MOUSE_LBUTTON,mouse.GetPosX(),mouse.GetPosY());
	if(mouse.IsUp(MOUSE_LBUTTON))
	   pObject->MouseUp(MOUSE_LBUTTON,mouse.GetPosX(),mouse.GetPosY());

	if(mouse.IsDown(MOUSE_RBUTTON))
	   pObject->MouseDown(MOUSE_RBUTTON,mouse.GetPosX(),mouse.GetPosY());
	if(mouse.IsUp(MOUSE_RBUTTON))
	   pObject->MouseUp(MOUSE_RBUTTON,mouse.GetPosX(),mouse.GetPosY());

	/*if(mouse.IsDown(MOUSE_MBUTTON))
	   pObject->MouseDown(MOUSE_MBUTTON,mouse.GetPosX(),mouse.GetPosY());
	if(mouse.IsUp(MOUSE_MBUTTON))
	  pObject->MouseUp(MOUSE_MBUTTON,mouse.GetPosX(),mouse.GetPosY());
	*/
   }
   else
   {
	mouse.IsDown(MOUSE_LBUTTON);
	mouse.IsUp(MOUSE_LBUTTON);
	mouse.IsDown(MOUSE_RBUTTON);
	mouse.IsUp(MOUSE_RBUTTON);
	mouse.IsDown(MOUSE_MBUTTON);
	mouse.IsUp(MOUSE_MBUTTON);
   }
  }while(!kbhit());
  ch=getch();
 }while(ch!=27);
 return 0;
}

void Desktop::Init()
{
 nObjects=0;
 Width=getmaxx();
 Height=getmaxy();
 BkColor=CYAN;
 mouse.Install();
}

void Desktop::Draw()
{
 Container::DrawControls();
}

void Desktop::AddObject(GUIObject* pObject)
{
 mouse.Hide();
 Container::EraseControls();
 Container::AddObject(pObject);
 Container::DrawControls();
 mouse.Show();
}

Desktop::~Desktop()
{
 mouse.Hide();
 for(int i=0;i<nObjects;i++)
  delete pObjects[i];

 closegraph();
}

#endif