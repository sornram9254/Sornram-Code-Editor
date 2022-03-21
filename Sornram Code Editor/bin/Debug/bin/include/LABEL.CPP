#ifndef __LABEL_CPP__
#define __LABEL_CPP__

#include <graphics.h>
#include "label.h"

Label::Label(int left,int top,int width,int height,char* caption)
	:GUIObject(left,top,width,height,caption)
{
}

void Label::Draw()
{
 GUIObject::Draw();

 setcolor(BLACK);
 settextjustify(LEFT_TEXT,TOP_TEXT);
 outtextxy(Left+(Width/2)-(textwidth(Caption)/2)+1,
	   Top+(Height/2)-(textheight(Caption)/2)+1,Caption);
}

#endif