////////////////////////////////////////////////////////////////////////////////
////                      Virtual EEPROM Driver                             ////
////                                                                        ////
////  This driver uses two flash erase pages in program memory as virtual   ////
////  eeprom memory. The number of available eeprom addresses for use is    ////
////  the lesser of 254 and MAX_EEPROM_MEMORY.  This number varies from PIC ////
////  to PIC.  This driver uses write-balancing to avoid excessive erasing  ////
////  of program memory.  This driver is optimized to use lower eeprom      ////
////  addresses first; however, it is not a requirement to use the          ////
////  available addresses in any particular order. The four functions       ////
////  which drive operation of the driver are detailed below:               ////
////                                                                        ////
////  init_virtual_eeprom()       Initializes pointer and global variable   ////
////                              for use with write and read.  Does NOT    ////
////                              clear previous virtual eeprom memory.     ////
////                              Must be called at beginning of program    ////
////                              before write and read are used.           ////
////                                                                        ////
////  data = read_virtual_eeprom(addy)      Reads one byte from virtual     ////
////                                        eeprom address "addy". Default  ////
////                                        return is 0xFF if no data is    ////
////                                        found for given address.        ////
////                                                                        ////
////  ok = write_virtual_eeprom(addy,data)  Writes "data" byte to virtual   ////
////                                        eeprom address "addy". Returns  ////
////                                        true if write is successful,    ////
////                                        returns false if memory is full ////
////                                                                        ////
////  clear_virtual_eeprom()      Clears and reinitializes all virtual      ////
////                              eeprom.                                   ////
////                                                                        ////
////////////////////////////////////////////////////////////////////////////////
////        (C) Copyright 1996,2010 Custom Computer Services                ////
//// This source code may only be used by licensed users of the CCS C       ////
//// compiler.  This source code may only be distributed to other           ////
//// licensed users of the CCS C compiler.  No other use, reproduction      ////
//// or distribution is permitted without written permission.               ////
//// Derivative programs created using this software in object code         ////
//// form are not restricted in any way.                                    ////
////////////////////////////////////////////////////////////////////////////////

#ifndef  VIRTUAL_EEPROM_C
#define  VIRTUAL_EEPROM_C

#define PAGE_SIZE getenv("FLASH_ERASE_SIZE") //RETURNS BYTES, NOT WORDS
#define PROGRAM_MEM_SIZE getenv("PROGRAM_MEMORY")

#if ((PROGRAM_MEM_SIZE % PAGE_SIZE) != 0)
#define PROGRAM_MEM_REAL_SIZE (PROGRAM_MEM_SIZE+(PAGE_SIZE-(PROGRAM_MEM_SIZE%PAGE_SIZE)))   //RETURNS BYTES, NOT WORDS
#else
#define PROGRAM_MEM_REAL_SIZE PROGRAM_MEM_SIZE
#endif

#if defined(__PCH__)
#define MAX_EEPROM_MEMORY ((PAGE_SIZE/2)-1)
#elif defined(__PCD__)
#define MAX_EEPROM_MEMORY ((PAGE_SIZE/4)-2)
#endif

#define PAGE0_START (PROGRAM_MEM_REAL_SIZE-(2*PAGE_SIZE))
#define PAGE0_END (PROGRAM_MEM_REAL_SIZE - PAGE_SIZE)
#define PAGE1_START (PROGRAM_MEM_REAL_SIZE-(4*PAGE_SIZE))
#define PAGE1_END (PROGRAM_MEM_REAL_SIZE-(3*PAGE_SIZE))

#org PAGE0_START,PAGE0_END {}
#org PAGE1_START,PAGE1_END {}

unsigned int32 next;
unsigned int8 max;
unsigned int1 page;

#if defined(__PCH__)

/////////////////////////////
////                     ////
//// Function Prototypes ////
////                     ////
/////////////////////////////

/*
void init_virtual_eeprom()
This initializes virtual eeprom for use
PARAMS: none
RETURNS: nothing
*/
void init_virtual_eeprom(void);

/*
unsigned int1 write_virtual_eeprom(int8 addy, int8 val)
This writes one byte ("val") to an 8-bit address (addy)
PARAMS: The byte address, the byte data
RETURNS: unsigned int1 write_ok
*/
unsigned int1 write_virtual_eeprom(int8 addy, int8 val);

/*
int8 read_virtual_eeprom(int8 addy)
This reads one byte from an 8-bit address (addy)
PARAMS: The 8-bit address
RETURNS: The 8-bit data at the address
*/
int8 read_virtual_eeprom(int8 addy);

/*
void clear_virtual_eeprom(void)
This clears and reinitializes all virtual eeprom
PARAMS: None
RETURNS: Nothing
*/
void clear_virtual_eeprom(void);

/*
static void clean_up_memory()
Private helper function for virtual eeprom
DO NOT CALL
*/
static void clean_up_memory(void);

//////////////////////////////////
////                          ////
//// Function Implementations ////
////                          ////
//////////////////////////////////

/*
void init_virtual_eeprom()
This initializes virtual eeprom for use
PARAMS: none
RETURNS: nothing
*/
void init_virtual_eeprom(){
   int1 page0_empty=0,page1_empty=0,page0_full=0,page1_full=0;
   int8 data[2];
   int32 i;
   max = 0;
   
   read_program_memory(PAGE1_START,data,2);
   if (data[0] == 0xFF)
      page1_empty = 1;
   read_program_memory(PAGE0_START,data,2);
   if (data[0] == 0xFF)
      page0_empty = 1;
   read_program_memory(PAGE0_END-2,data,2);
   if (data[0] != 0xFF)
      page0_full = 1;
   read_program_memory(PAGE1_END-2,data,2);
   if (data[0] != 0xFF)
      page1_full = 1;
  
   if(page0_full){                                    //if page0 is full
      page = 0;
      next = PAGE0_END;
      for (i = PAGE0_START; i < PAGE0_END; i=i+2){
         read_program_memory(i,data,2);
         if((data[0] != 0xFF) && (data[0] > max))
            max = data[0];
      }
      clean_up_memory();
   }
   else if(page1_full){                               //else if page1 is full
      page = 1;
      next = PAGE1_END;
      for (i = PAGE1_START; i < PAGE1_END; i=i+2){
         read_program_memory(i,data,2);
         if((data[0] != 0xFF) && (data[0] > max))
            max = data[0];
      }
      clean_up_memory();
   }
   else if(!page0_empty){                             //else if neither are full but page0 is not empty
      next = PAGE0_START;
      page = 0;
      for (i = PAGE0_START; i < PAGE0_END; i=i+2){
         read_program_memory(i,data,2);
         if(data[0] != 0xFF) {
            next = i;
            if(data[0] > max)
               max = data[0];
         }
      }
      next += 2;
      erase_program_eeprom(PAGE1_START);
      erase_program_eeprom(PAGE1_START+PAGE_SIZE/2);
      
   }
   else if(!page1_empty){                             //else if neither are full but page1 is not empty
      next = PAGE1_START;
      page = 1;
      for (i = PAGE1_START; i < PAGE1_END; i=i+2){
         read_program_memory(i,data,2);
         if(data[0] != 0xFF) {
            next = i;
            if(data[0] > max)
               max = data[0];
         }
      }
      next += 2;
      erase_program_eeprom(PAGE0_START);
      erase_program_eeprom(PAGE0_START+PAGE_SIZE/2);
   }
   else if ((page0_empty) && (page1_empty)){           //else if both pages are empty
      next = PAGE0_START;
      page = 0;
      max = 0;
   }
}

/*
static void clean_up_memory()
Private helper function for virtual eeprom
DO NOT CALL
*/
static void clean_up_memory(){
   unsigned int8 data,wrt_data[2];
   unsigned int32 ptr;
   unsigned int16 i;
   
   if(page == 0){
      ptr = PAGE1_START;
      for (i = 0; i <= max; i++) {
         data = read_virtual_eeprom(i);
         if(data != 0xFF){
            wrt_data[0] = i;
            wrt_data[1] = data;
            write_program_memory(ptr,wrt_data,2);
            ptr+=2;
         }
      }
   
      erase_program_eeprom(PAGE0_START);
      erase_program_eeprom(PAGE0_START+PAGE_SIZE/2);
      page = 1;
      next = ptr;
   }
   else {
      ptr = PAGE0_START;
      for (i = 0; i <= max; i++) {
         data = read_virtual_eeprom(i);
         if(data!=0xFF){
            wrt_data[0] = i;
            wrt_data[1] = data;
            write_program_memory(ptr,wrt_data,2);
            ptr+=2;
         }
      }
   
      erase_program_eeprom(PAGE1_START);
      erase_program_eeprom(PAGE1_START+PAGE_SIZE/2);
      page = 0;
      next = ptr;
   }
}

/*
unsigned int1 write_virtual_eeprom(int8 addy, int8 val)
This writes one byte ("val") to an 8-bit address (addy)
PARAMS: The byte address, the byte data
RETURNS: unsigned int1 write_ok
*/
unsigned int1 write_virtual_eeprom(int8 addy, int8 val) {
   int8 mem[2];
   mem[0] = addy;
   if (addy>max)
      max = addy;
   mem[1] = val;
   write_program_memory(next,mem,2);
   next+=2;
   if (page == 0){
      if (next >= PAGE0_END){
         clean_up_memory();
         if (next >= PAGE1_END)
            return FALSE;
      }
      return TRUE;
   }
   else {
      if (next >= PAGE1_END){
         clean_up_memory();
         if (next >= PAGE0_END)
            return FALSE;
      }
      return TRUE;
   }
}

/*
int8 read_virtual_eeprom(int8 addy)
This reads one byte from an 8-bit address (addy)
PARAMS: The 8-bit address
RETURNS: The 8-bit data at the address
*/
int8 read_virtual_eeprom(int8 addy) {
   int32 i;
   int8 data[2];
   if (page == 0){
      for (i = PAGE0_END; i > PAGE0_START-1; i=i-2){
         read_program_memory(i,data,2);
         if (data[0]==addy)
            return data[1];
      }
      return 0xFF;
   }
   else {
      for (i = PAGE1_END; i > PAGE1_START-1; i=i-2){
         read_program_memory(i,data,2);
         if (data[0]==addy)
            return data[1];
      }
      return 0xFF;
   }
}

/*
void clear_virtual_eeprom(void)
This clears and reinitializes all virtual eeprom
PARAMS: None
RETURNS: Nothing
*/
void clear_virtual_eeprom(void){
   erase_program_eeprom(PAGE0_START);
   erase_program_eeprom(PAGE0_START+PAGE_SIZE/2);
   erase_program_eeprom(PAGE1_START);
   erase_program_eeprom(PAGE1_START+PAGE_SIZE/2);
   next = PAGE0_START;
   max = 0;
}

#elif defined(__PCD__)

/////////////////////////////
////                     ////
//// Function Prototypes ////
////                     ////
/////////////////////////////

/*
void init_virtual_eeprom()
This initializes virtual eeprom for use
PARAMS: none
RETURNS: nothing
*/
void init_virtual_eeprom(void);

/*
unsigned int1 write_virtual_eeprom(int8 addy, int8 val)
This writes one byte ("val") to an 8-bit address (addy)
PARAMS: The byte address, the byte data
RETURNS: unsigned int1 write_ok
*/
unsigned int1 write_virtual_eeprom(int8 addy, int8 val);

/*
int8 read_virtual_eeprom(int8 addy)
This reads one byte from an 8-bit address (addy)
PARAMS: The 8-bit address
RETURNS: The 8-bit data at the address
*/
unsigned int8 read_virtual_eeprom(int8 addy);

/*
void clear_virtual_eeprom(void)
This clears and reinitializes all virtual eeprom
PARAMS: None
RETURNS: Nothing
*/
void clear_virtual_eeprom(void);

/*
static void clean_up_memory()
Private helper function for virtual eeprom
DO NOT CALL
*/
static void clean_up_memory(void);

//////////////////////////////////
////                          ////
//// Function Implementations ////
////                          ////
//////////////////////////////////

/*
void init_virtual_eeprom()
This initializes virtual eeprom for use
PARAMS: none
RETURNS: nothing
*/
void init_virtual_eeprom(){
   int1 page0_empty=0,page1_empty=0,page0_full=0,page1_full=0;
   unsigned int8 data[4];
   unsigned int32 i;
   max = 0;
   
   read_program_memory(PAGE1_START,data,4);
   if (data[0] == 0xFF)
      page1_empty = 1;
   read_program_memory(PAGE0_START,data,4);
   if (data[0] == 0xFF)
      page0_empty = 1;
   read_program_memory(PAGE0_END-4,data,4);
   if (data[0] != 0xFF)
      page0_full = 1;
   read_program_memory(PAGE1_END-4,data,4);
   if (data[0] != 0xFF)
      page1_full = 1;
  
   if(page0_full){                                    //if page0 is full
      page = 0;
      next = PAGE0_END;
      for (i = PAGE0_START; i < PAGE0_END; i=i+4){
         read_program_memory(i,data,4);
         if((data[0] != 0xFF) && (data[0] > max))
            max = data[0];
      }
      clean_up_memory();
   }
   else if(page1_full){                               //else if page1 is full
      page = 1;
      next = PAGE1_END;
      for (i = PAGE1_START; i < PAGE1_END; i=i+4){
         read_program_memory(i,data,4);
         if((data[0] != 0xFF) && (data[0] > max))
            max = data[0];
      }
      clean_up_memory();
   }
   else if(!page0_empty){                             //else if neither are full but page0 is not empty
      next = PAGE0_START;
      page = 0;
      for (i = PAGE0_START; i < PAGE0_END; i=i+4){
         read_program_memory(i,data,2);
         if(data[0] != 0xFF) {
            next = i;
            if(data[0] > max)
               max = data[0];
         }
      }
      next += 4;
      erase_program_memory(PAGE1_START);
      erase_program_memory(PAGE1_START+PAGE_SIZE/2);
      
   }
   else if(!page1_empty){                             //else if neither are full but page1 is not empty
      next = PAGE1_START;
      page = 1;
      for (i = PAGE1_START; i < PAGE1_END; i=i+4){
         read_program_memory(i,data,4);
         if(data[0] != 0xFF) {
            next = i;
            if(data[0] > max)
               max = data[0];
         }
      }
      next += 4;
      erase_program_memory(PAGE0_START);
      erase_program_memory(PAGE0_START+PAGE_SIZE/2);
   }
   else if ((page0_empty) && (page1_empty)){           //else if both pages are empty
      next = PAGE0_START;
      page = 0;
      max = 0;
   }
}

/*
static void clean_up_memory()
Private helper function for virtual eeprom
DO NOT CALL
*/
static void clean_up_memory(){
   unsigned int8 data,wrt_data[4];
   unsigned int32 ptr;
   unsigned int16 i;
   
   if(page == 0){
      ptr = PAGE1_START;
      for (i = 0; i <= max; i++) {
         data = read_virtual_eeprom(i);
         if(data != 0xFF){
            wrt_data[0] = i;
            wrt_data[1] = data;
            write_program_memory(ptr,wrt_data,4);
            ptr+=4;
         }
      }
   
      erase_program_memory(PAGE0_START);
      erase_program_memory(PAGE0_START+PAGE_SIZE/2);
      page = 1;
      next = ptr;
   }
   else {
      ptr = PAGE0_START;
      for (i = 0; i <= max; i++) {
         data = read_virtual_eeprom(i);
         if(data!=0xFF){
            wrt_data[0] = i;
            wrt_data[1] = data;
            write_program_memory(ptr,wrt_data,4);
            ptr+=4;
         }
      }
   
      erase_program_memory(PAGE1_START);
      erase_program_memory(PAGE1_START+PAGE_SIZE/2);
      page = 0;
      next = ptr;
   }
}

/*
unsigned int1 write_virtual_eeprom(int8 addy, int8 val)
This writes one byte ("val") to an 8-bit address (addy)
PARAMS: The byte address, the byte data
RETURNS: unsigned int1 write_ok
*/
unsigned int1 write_virtual_eeprom(int8 addy, int8 val) {
   unsigned int8 mem[4];
   mem[0] = addy;
   if (addy>max)
      max = addy;
   mem[1] = val;
   write_program_memory(next,mem,4);
   next+=4;
   if (page == 0){
      if (next >= PAGE0_END){
         clean_up_memory();
         if (next >= PAGE1_END)
            return FALSE;
      }
      return TRUE;
   }
   else {
      if (next >= PAGE1_END){
         clean_up_memory();
         if (next >= PAGE0_END)
            return FALSE;
      }
      return TRUE;
   }
}

/*
int8 read_virtual_eeprom(int8 addy)
This reads one byte from an 8-bit address (addy)
PARAMS: The 8-bit address
RETURNS: The 8-bit data at the address
*/
unsigned int8 read_virtual_eeprom(int8 addy) {
   unsigned int32 i;
   unsigned int8 data[4];
   if (page == 0){
      for (i = PAGE0_END; i > PAGE0_START-1; i=i-4){
         read_program_memory(i,data,4);
         if (data[0]==addy)
            return data[1];
      }
      return 0xFF;
   }
   else {
      for (i = PAGE1_END; i > PAGE1_START-1; i=i-4){
         read_program_memory(i,data,4);
         if (data[0]==addy)
            return data[1];
      }
      return 0xFF;
   }
}

/*
void clear_virtual_eeprom(void)
This clears and reinitializes all virtual eeprom
PARAMS: None
RETURNS: Nothing
*/
void clear_virtual_eeprom(void){
   erase_program_memory(PAGE0_START);
   erase_program_memory(PAGE0_START+PAGE_SIZE/2);
   erase_program_memory(PAGE1_START);
   erase_program_memory(PAGE1_START+PAGE_SIZE/2);
   next = PAGE0_START;
   max = 0;
}

#endif
#endif
