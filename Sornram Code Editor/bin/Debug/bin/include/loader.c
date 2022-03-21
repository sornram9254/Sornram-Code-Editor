///////////////////////////////////////////////////////////////////////////
////                         loader.c                                  ////
////                                                                   ////
//// This driver will take an Intel 8-bit Hex file over RS232 channels ////
//// and modify the flash program memory with the new code.  A proxy   ////
//// function is required to sit between the real loading function     ////
//// and the main code because the #org preprocessor command could     ////
//// possibly change the order of functions within a defined block.    ////
////                                                                   ////
//// After each good line, the loader sends an ACKLOD character.  The  ////
//// driver uses XON/XOFF flow control.  Also, any buffer on the PC    ////
//// UART must be turned off, or to its lowest setting, otherwise it   ////
//// will miss data.                                                   ////
////                                                                   ////
////                                                                   ////
///////////////////////////////////////////////////////////////////////////
////        (C) Copyright 1996,2003 Custom Computer Services           ////
//// This source code may only be used by licensed users of the CCS C  ////
//// compiler.  This source code may only be distributed to other      ////
//// licensed users of the CCS C compiler.  No other use, reproduction ////
//// or distribution is permitted without written permission.          ////
//// Derivative programs created using this software in object code    ////
//// form are not restricted in any way.                               ////
///////////////////////////////////////////////////////////////////////////

#ifndef LOADER_END

#define LOADER_END      getenv("PROGRAM_MEMORY")-1

#if defined(__PCM__)
   #define LOADER_SIZE   0x17F
#elif defined(__PCH__)
   #define LOADER_SIZE   0x3FF
#endif

#endif


#define LOADER_ADDR LOADER_END-LOADER_SIZE
#define BUFFER_LEN_LOD 64

int  buffidx;
char buffer[BUFFER_LEN_LOD];

#define ACKLOD 0x06
#define XON    0x11
#define XOFF   0x13

#SEPARATE
unsigned int atoi_b16(char *s);

#ORG LOADER_ADDR+10, LOADER_END auto=0 default

#use rs232(baud=9600, xmit=PIN_C6, rcv=PIN_C7)  // Jumpers: 8 to 11, 7 to 12

void real_load_program (void)
{
   int1  do_ACKLOD, done=FALSE;
   int8  checksum, line_type;
   int16 l_addr,h_addr=0;
   int32 addr;
   #if getenv("FLASH_ERASE_SIZE")>2
      int32 next_addr;
   #endif
   int8  dataidx, i, count;
   int8  data[32];

   while (!done)  // Loop until the entire program is downloaded
   {
      buffidx = 0;  // Read into the buffer until 0x0D ('\r') is received or the buffer is full
      do {
         buffer[buffidx] = getc();
      } while ( (buffer[buffidx++] != 0x0D) && (buffidx <= BUFFER_LEN_LOD) );

      putchar (XOFF);  // Suspend sender

      do_ACKLOD = TRUE;

      // Only process data blocks that start with ':'
      if (buffer[0] == ':') {
         count = atoi_b16 (&buffer[1]);  // Get the number of bytes from the buffer

         // Get the lower 16 bits of address
         l_addr = make16(atoi_b16(&buffer[3]),atoi_b16(&buffer[5]));

         line_type = atoi_b16 (&buffer[7]);

         addr = make32(h_addr,l_addr);

         #if defined(__PCM__)  // PIC16 uses word addresses
            addr /= 2;
         #endif

         // If the line type is 1, then data is done being sent
         if (line_type == 1) {
            done = TRUE;
         #if defined(__PCM__)
         } else if ((addr < LOADER_ADDR || addr > LOADER_END) && addr < 0x2000){
         #elif defined(__PCH__)
         } else if ((addr < LOADER_ADDR || addr > LOADER_END) && addr < 0x300000){
         #endif
            checksum = 0;  // Sum the bytes to find the check sum value
            for (i=1; i<(buffidx-3); i+=2)
               checksum += atoi_b16 (&buffer[i]);
            checksum = 0xFF - checksum + 1;

            if (checksum != atoi_b16 (&buffer[buffidx-3]))
               do_ACKLOD = FALSE;
            else   {
               if (line_type == 0) {
                  // Loops through all of the data and stores it in data
                  // The last 2 bytes are the check sum, hence buffidx-3
                  for (i = 9,dataidx=0; i < buffidx-3; i += 2)
                     data[dataidx++]=atoi_b16(&buffer[i]);

                  #if getenv("FLASH_ERASE_SIZE") > getenv("FLASH_WRITE_SIZE")
                     #if defined(__PCM__)
                        if ((addr!=next_addr)&&(addr&(getenv("FLASH_ERASE_SIZE")-1)!=0))
                     #else
                        if ((addr!=next_addr)&&(addr&(getenv("FLASH_ERASE_SIZE")/2-1)!=0))
                     #endif
                           erase_program_eeprom(addr);
                     next_addr = addr + 1;
                  #endif
                  write_program_memory(addr, data, count);
               }
               else if (line_type == 4)
                  h_addr = make16(atoi_b16(&buffer[9]), atoi_b16(&buffer[11]));
            }
         }
      }

      if (do_ACKLOD)
         putchar (ACKLOD);

      putchar(XON);
   }

   putchar (ACKLOD);
   putchar(XON);
   #ifndef _bootloader
   reset_cpu();
   #endif
}

unsigned int atoi_b16(char *s) {  // Convert two hex characters to a int8
   unsigned int result = 0;
   int i;

   for (i=0; i<2; i++,s++)  {
      if (*s >= 'A')
         result = 16*result + (*s) - 'A' + 10;
      else
         result = 16*result + (*s) - '0';
   }

   return(result);
}

#ORG default


#ORG LOADER_ADDR, LOADER_ADDR+9
void load_program(void)
{
   real_load_program();
}
