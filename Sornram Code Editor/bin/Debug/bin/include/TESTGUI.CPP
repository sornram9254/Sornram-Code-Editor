#include "turbogui.h"

#include <conio.h>
#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

Desktop desktop("C:\\TC\\BGI\\");


//*********** Calculator Related Declarations and Functions *************

TextBox *pDisplay;
char sDisplay[20]={"0"},Operation;
long Oper1,Oper2,Result;
bool IsOper2=false,ContOper=false;

void OnNumberPressed(GUIObject *pObject)
{
 if(strlen(sDisplay)<10)
 {
  if(strcmp(sDisplay,"0")==0)
   strcpy(sDisplay,pObject->GetCaption());
  else
   strcat(sDisplay,pObject->GetCaption());
  pDisplay->SetText(sDisplay);
 }
}

void OnControlPressed(GUIObject *pObject)
{
 char Caption[20];

 strcpy(Caption,pObject->GetCaption());

 if(strlen(Caption)==1)
 {
  if(Caption[0]!='=')
  {
   Operation=Caption[0];
   if(ContOper)
   {
	ContOper=false;
	Oper2=0;
	strcpy(sDisplay,"0");
	pDisplay->SetText(sDisplay);
	return;
   }
  }
  else
   ContOper=true;

  if(!IsOper2)
  {
   Oper1=atol(sDisplay);
   strcpy(sDisplay,"0");
   IsOper2=true;
  }
  else
  {
   if(!ContOper || Oper2==0)
	Oper2=atol(sDisplay);
   switch (Operation)
   {
	case '+':
		Result=Oper1+Oper2;
		break;
	case '-':
		Result=Oper1-Oper2;
		break;
	case '*':
		Result=Oper1*Oper2;
		break;
	case '/':
		Result=Oper1/Oper2;
		break;
   }
   Oper1=Result;
   ltoa(Result,sDisplay,10);
  }
 }
 else
 {
  if(strcmp(Caption,"AC")==0)
  {
   IsOper2=false;
   Oper1=0;
   Oper2=0;
   strcpy(sDisplay,"0");
  }
 }
 pDisplay->SetText(sDisplay);
}


void OnCalculator()
{
 int i,x=5,y=40;
 char no[2],btnText[][2]={"+","-","*","/"};

 Window *pWindow=new Window(0,0,110,140,"Calculator");
 Button *pButtons[20];
 pDisplay=new TextBox(5,20,100,10,sDisplay);

 pDisplay->SetAlignment(RIGHT_TEXT);
 pDisplay->SetReadOnly(true);

 pWindow->AddObject(pDisplay);
 no[1]=0;
 for(i=0;i<9;i++)
 {
  no[0]='9'-i;
  pButtons[i]=new Button(x,y,20,20,no);
  pButtons[i]->SetClickHandler(&OnNumberPressed);
  pWindow->AddObject(pButtons[i]);

  x+=25;
  if((i+1)%3==0)
  {
   y+=25;
   x=5;
  }
 }

 for(i=0;i<4;i++)
 {
  pButtons[9+i]=new Button(85,40+(i*25),20,20,btnText[i]);
  pButtons[9+i]->SetClickHandler(&OnControlPressed);
  pWindow->AddObject(pButtons[9+i]);
 }

 y+25;
 x=5;
 pButtons[13]=new Button(x,y,20,20,"AC");
 pButtons[13]->SetClickHandler(&OnControlPressed);
 pWindow->AddObject(pButtons[13]);

 x+=25;
 pButtons[14]=new Button(x,y,20,20,"0");
 pButtons[14]->SetClickHandler(&OnNumberPressed);
 pWindow->AddObject(pButtons[14]);

 x+=25;
 pButtons[15]=new Button(x,y,20,20,"=");
 pButtons[15]->SetClickHandler(&OnControlPressed);
 pWindow->AddObject(pButtons[15]);

 desktop.AddObject(pWindow);
}


//****** Simple Window Related Declarations and Functions *********

TextBox *ptxtName;
void OnSimpleWindowOK()
{
 char msg[20];
 strcpy(msg,"Welcome ");
 strcat(msg,ptxtName->GetText());
 Window *pWindow=new Window(200,200,200,50,"Hello");
 Label *plblWelcome=new Label(205,220,200,20,msg);

 pWindow->AddObject(plblWelcome);

 desktop.AddObject(pWindow);
}

void OnSimpleWindow()
{
 Window *pWindow=new Window(100,100,240,40,"Simple Window");
 Label *plblName=new Label(101,120,85,15,"Your Name:");
 ptxtName=new TextBox(190,120,100,15,"Shiva");
 Button *pbtnOK=new Button(300,120,30,15,"OK");

 pbtnOK->SetClickHandler(&OnSimpleWindowOK);

 pWindow->AddObject(plblName);
 pWindow->AddObject(ptxtName);
 pWindow->AddObject(pbtnOK);
 desktop.AddObject(pWindow);

}

void OnAllControls()
{
 Window* pWindow=new Window(50,50,180,120,"All Controls");

 pWindow->AddObject(new Button(60,70,150,20,"Button"));

 pWindow->AddObject(new TextBox(60,100,150,10,"Left Aligned"));

 TextBox* pTextBox=new TextBox(60,115,150,10,"Center Aligned");
 pTextBox->SetAlignment(CENTER_TEXT);
 pTextBox->SetReadOnly(true);
 pWindow->AddObject(pTextBox);

 pTextBox=new TextBox(60,130,150,10,"Right Aligned");
 pTextBox->SetAlignment(RIGHT_TEXT);
 pTextBox->SetReadOnly(true);
 pWindow->AddObject(pTextBox);

 pWindow->AddObject(new CheckBox(60,145,150,10,"Check Box"));

 desktop.AddObject(pWindow);
}

void OnAbout()
{
 Window* pWindow=new Window(50,50,380,120,"About");
 char about[][50]={
		   "TurboGUI is a framework",
		   "Developed for Turbo C/C++ 3.0",
		   "The first version provides you",
		   "* Desktop & Mouse Object",
		   "* Window,Button,TextBox & Label Objects",
		   "-: Developed & Designed by Siva Chandran.P :-",
		  };
 int i=0;

 for(i=0;i<6;i++)
  pWindow->AddObject(new Label(60,70+(i*15),360,10,about[i]));

 desktop.AddObject(pWindow);
}

int main()
{

 Window *pWindow=new Window(450,10,140,140,"Demo");
 Button *pButton;

 pButton=new Button(460,30,120,20,"Calculator");
 pButton->SetClickHandler(&OnCalculator);
 pWindow->AddObject(pButton);

 pButton=new Button(460,60,120,20,"Simple Window");
 pButton->SetClickHandler(&OnSimpleWindow);
 pWindow->AddObject(pButton);

 pButton=new Button(460,90,120,20,"All Controls");
 pButton->SetClickHandler(&OnAllControls);
 pWindow->AddObject(pButton);

 pButton=new Button(460,120,120,20,"About");
 pButton->SetClickHandler(&OnAbout);
 pWindow->AddObject(pButton);

 /*pWindow->AddObject(new CheckBox(460,120,40,20,"Test",true));*/

 desktop.AddObject(pWindow);

 int ret=desktop.Run();

 return ret;
}