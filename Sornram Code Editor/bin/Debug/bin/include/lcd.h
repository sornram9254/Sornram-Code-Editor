/*****************************************************

        Plug n Play Library for Nokia 3310 LCD

        Author:  Ajay Bhargav
		Email :  contact@rickeyworld.info
		WWW   :  www.8051projects.net

		File  :  LCD.H

*****************************************************/

#ifndef __NOKIA3310
#define __NOKIA3310

#include <AT89X51.H>
//change the header file you need for your controller

#define SCK P2_1
#define DAT P2_2
#define DC P2_3
#define CE P2_4
#define RES P2_5

void spisend(unsigned char);
void wrdata(unsigned char);
void wrcmd(unsigned char);
void pixelxy(unsigned char, unsigned char);
void cursorxy(unsigned char, unsigned char);
void clearram(void);
void initlcd(void);
void putchar(unsigned char);
void putstr (unsigned char*);

#endif