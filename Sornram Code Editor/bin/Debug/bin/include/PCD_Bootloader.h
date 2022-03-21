///////////////////////////////////////////////////////////////////////////
////                       pcd_bootloader.h                            ////
////                                                                   ////
////  This include file must be included by any application loaded     ////
////  by the example bootloader (ex_pcd_bootloader.c).                 ////
////                                                                   ////
////  The directives in this file relocate the reset and interrupt     ////
////  vectors as well as reserving space for the bootloader.           ////
///////////////////////////////////////////////////////////////////////////
////        (C) Copyright 1996,2008 Custom Computer Services           ////
//// This source code may only be used by licensed users of the CCS    ////
//// C compiler.  This source code may only be distributed to other    ////
//// licensed users of the CCS C compiler.  No other use,              ////
//// reproduction or distribution is permitted without written         ////
//// permission.  Derivative programs created using this software      ////
//// in object code form are not restricted in any way.                ////
///////////////////////////////////////////////////////////////////////////

#ifndef __BOOTLOADER_H__
#define __BOOTLOADER_H__

#define __BOOTLOADER_INCLUDED__ TRUE

#if defined(__PCM__)
   #define LOADER_SIZE   0x3FF
#elif defined(__PCH__)
   #define LOADER_SIZE   0x3FF
#elif defined(__PCD__)
   #if (getenv("PROGRAM_MEMORY")%0x100==0)
      #define LOADER_SIZE   0x3FF
   #elif ((getenv("PROGRAM_MEMORY")+4)%0x100==0)
      #define LOADER_SIZE   0x3FB
   #elif ((getenv("PROGRAM_MEMORY")+8)%0x100==0)
      #define LOADER_SIZE   0x3F9
   #endif
#endif
#endif
//BOOTLOADER AT END
// LOADER_END - This is the end of the general purpose bootload code.
#ifndef LOADER_END
#define LOADER_END      (getenv("PROGRAM_MEMORY")-1)
#define LOADER_ADDR     (LOADER_END-LOADER_SIZE)
#endif

#ifndef _bootloader
#org LOADER_ADDR, LOADER_END {}
#endif

#ifdef _bootloader
#include "loader_pcd.c"
#endif

