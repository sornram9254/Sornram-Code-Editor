////////////////////////////////////////////////////////////////////////////
////                              NJU6355.C                             ////
////                     Driver for Real Time Clock                     ////
////                                                                    ////
////  rtc_init()                                   Call after power up  ////
////                                                                    ////
////  rtc_set_datetime(day,mth,year,dow,hour,min)  Set the date/time    ////
////                                                                    ////
////  rtc_get_date(day,mth,year,dow)               Get the date         ////
////                                                                    ////
////  rtc_get_time(hr,min,sec)                     Get the time         ////
////                                                                    ////
////  rtc_get_bcd(data)                          Convert data to BCD    ////
////                                                                    ////
////  rtc_rm_bcd(data)                           Convert data to int    ////
////                                                                    ////
////////////////////////////////////////////////////////////////////////////
////        (C) Copyright 1996,2003 Custom Computer Services            ////
//// This source code may only be used by licensed users of the CCS C   ////
//// compiler.  This source code may only be distributed to other       ////
//// licensed users of the CCS C compiler.  No other use, reproduction  ////
//// or distribution is permitted without written permission.           ////
//// Derivative programs created using this software in object code     ////
//// form are not restricted in any way.                                ////
////////////////////////////////////////////////////////////////////////////

#ifndef RTC_DATA

#define RTC_DATA  PIN_B0
#define RTC_CLK   PIN_B1
#define RTC_CE    PIN_B2
#define RTC_IO    PIN_B4

#endif

void rtc_init() {
   output_low(RTC_CE);
   output_low(RTC_IO);
}

void write_rtc_byte(BYTE data_byte, BYTE number_of_bits) {
   BYTE i;

   for(i=0; i<number_of_bits; ++i) {
      if((data_byte & 1)==0)
        output_low(RTC_DATA);
      else
        output_high(RTC_DATA);
      data_byte=data_byte>>1;
      output_high(RTC_CLK);
      output_low(RTC_CLK);
   }
}

BYTE read_rtc_byte(BYTE number_of_bits) {
   BYTE i,data;

   for(i=0;i<number_of_bits;++i) {
      output_high(RTC_CLK);
      shift_right(&data,1,input(RTC_DATA));
      output_low(RTC_CLK);
   }
   return(data);
}

int rtc_get_bcd(BYTE data)
{
   int nibh;
   int nibl;

   nibh=data/10;
   nibl=data-(nibh*10);

   return((nibh<<4)|nibl);
}

int rtc_rm_bcd(BYTE data)
{
   int i;

   i=data;
   data=(i>>4)*10;
   data=data+(i<<4>>4);

   return data;
}

void rtc_set_datetime(BYTE day, BYTE mth, BYTE year, BYTE dow,
                      BYTE hour, BYTE min){

   output_low(RTC_CLK);
   output_high(RTC_IO);
   output_high(RTC_CE);
   write_rtc_byte(rtc_get_bcd(year),8);
   write_rtc_byte(rtc_get_bcd(mth),8);
   write_rtc_byte(rtc_get_bcd(day),8);
   write_rtc_byte(rtc_get_bcd(dow),4);
   write_rtc_byte(rtc_get_bcd(hour),8);
   write_rtc_byte(rtc_get_bcd(min),8);
   output_low(RTC_CE);
   output_low(RTC_IO);
}

void rtc_get_date(BYTE& day, BYTE& mth, BYTE& year, BYTE& dow) {
   output_low(RTC_CLK);
   output_low(RTC_IO);
   output_high(RTC_CE);
   year=rtc_rm_bcd(read_rtc_byte(8));
   mth=rtc_rm_bcd(read_rtc_byte(8));
   day=rtc_rm_bcd(read_rtc_byte(8));
   dow=rtc_rm_bcd(read_rtc_byte(4)>>4);

   read_rtc_byte(8*3);
   output_low(RTC_CE);
   output_low(RTC_IO);
}

void rtc_get_time(BYTE& hr, BYTE& min, BYTE& sec) {
   output_low(RTC_CLK);
   output_low(RTC_IO);
   output_high(RTC_CE);
   read_rtc_byte(8*3+4);
   hr=rtc_rm_bcd(read_rtc_byte(8));
   min=rtc_rm_bcd(read_rtc_byte(8));
   sec=rtc_rm_bcd(read_rtc_byte(8));

   output_low(RTC_CE);
   output_low(RTC_IO);
}
