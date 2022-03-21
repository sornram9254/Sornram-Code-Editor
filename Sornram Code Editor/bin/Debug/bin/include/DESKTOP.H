#ifndef __DESKTOP_H__
#define __DESKTOP_H__

#include "mouse.h"
#include "gobject.h"
#include "turbogui.h"
#include "contain.h"

class Desktop:public Container
{
 private:
  int graphDriver,graphMode;
  void InitGraphics(char *DriverPath);
  int Width, Height;
  int BkColor;

 public:
  Desktop(char *DriverPath="C:\\TC\\BGI");
  Desktop(char *DriverPath,int GraphDriver, int GraphMode);
  void DrawBackground();
  void Init();
  int Run();
  void Draw();
  void AddObject(GUIObject* pObject);
  ~Desktop();
};

#endif