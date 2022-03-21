/////////////////////////////////////////////////////////////////////////
////                        can-18xxx8.h                             ////
////                                                                 ////
//// Prototypes, definitions, defines and macros used for and with   ////
//// the CCS CAN library for PIC18Fxx8 and PIC18Cxx8.                ////
////                                                                 ////
//// (see can-18xxx8.c)                                              ////
////                                                                 ////
/////////////////////////////////////////////////////////////////////////
////        (C) Copyright 1996,2011 Custom Computer Services         ////
//// This source code may only be used by licensed users of the CCS  ////
//// C compiler.  This source code may only be distributed to other  ////
//// licensed users of the CCS C compiler.  No other use,            ////
//// reproduction or distribution is permitted without written       ////
//// permission.  Derivative programs created using this software    ////
//// in object code form are not restricted in any way.              ////
/////////////////////////////////////////////////////////////////////////

#ifndef __CCS_CAN18xxx8_LIB_DEFINES__
#define __CCS_CAN18xxx8_LIB_DEFINES__

#ifndef CAN_DO_DEBUG
 #define CAN_DO_DEBUG FALSE
#endif

#IFNDEF CAN_USE_EXTENDED_ID
  #define CAN_USE_EXTENDED_ID         TRUE
#ENDIF

#IFNDEF CAN_BRG_SYNCH_JUMP_WIDTH
  #define CAN_BRG_SYNCH_JUMP_WIDTH  0  //synchronized jump width (def: 1 x Tq)
#ENDIF

#IFNDEF CAN_BRG_PRESCALAR
  #define CAN_BRG_PRESCALAR  4  //baud rate generator prescalar (def: 4) ( Tq = (2 x (PRE + 1))/Fosc )
#ENDIF

#ifndef CAN_BRG_SEG_2_PHASE_TS
 #define CAN_BRG_SEG_2_PHASE_TS   TRUE //phase segment 2 time select bit (def: freely programmable)
#endif

#ifndef CAN_BRG_SAM
 #define CAN_BRG_SAM 0 //sample of the can bus line (def: bus line is sampled 1 times prior to sample point)
#endif

#ifndef CAN_BRG_PHASE_SEGMENT_1
 #define CAN_BRG_PHASE_SEGMENT_1  5 //phase segment 1 (def: 6 x Tq)
#endif

#ifndef CAN_BRG_PROPAGATION_TIME
 #define CAN_BRG_PROPAGATION_TIME 2 //propagation time select (def: 3 x Tq)
#endif

#ifndef CAN_BRG_WAKE_FILTER
 #define CAN_BRG_WAKE_FILTER FALSE   //selects can bus line filter for wake up bit
#endif

#ifndef CAN_BRG_PHASE_SEGMENT_2
 #define CAN_BRG_PHASE_SEGMENT_2 5 //phase segment 2 time select (def: 6 x Tq)
#endif

#ifndef CAN_USE_RX_DOUBLE_BUFFER
 #define CAN_USE_RX_DOUBLE_BUFFER TRUE   //if buffer 0 overflows, do NOT use buffer 1 to put buffer 0 data
#endif

#ifndef CAN_ENABLE_DRIVE_HIGH
 #define CAN_ENABLE_DRIVE_HIGH 0
#endif

#ifndef CAN_ENABLE_CAN_CAPTURE
 #define CAN_ENABLE_CAN_CAPTURE 0
#endif

#ifndef CAN_ENABLE_CANTX2           // added 03/30/09 for PIC18F6585/8585/6680/8680
   #define CAN_ENABLE_CANTX2 0      // 0 CANTX2 disabled, 1 CANTX2 enabled
#endif

#ifndef CAN_CANTX2_SOURCE           // added 03/30/09 for PIC18F6585/8585/6680/8680
   #define CAN_CANTX2_SOURCE 0      // 0 source is invert of CANTX1, 1 source is CAN Clock
#endif

enum CAN_OP_MODE {CAN_OP_CONFIG=4, CAN_OP_LISTEN=3, CAN_OP_LOOPBACK=2, CAN_OP_DISABLE=1, CAN_OP_NORMAL=0};
enum CAN_WIN_ADDRESS {CAN_WIN_RX0=0, CAN_WIN_RX1=5, CAN_WIN_TX0=4, CAN_WIN_TX1=3, CAN_WIN_TX2=2};

//can control
struct {
   int1 void0; //0
   CAN_WIN_ADDRESS win:3;   //1:3 //window address bits
   int1 abat;   //4 //abort all pending transmissions
   CAN_OP_MODE reqop:3;   //5:7   //request can operation mode bits
} CANCON;
#byte CANCON = getenv("SFR:CANCON")   //0xF6F


enum CAN_INT_CODE {CAN_INT_WAKEUP=7, CAN_INT_RX0=6, CAN_INT_RX1=5, CAN_INT_TX0=4, CAN_INT_TX1=3, CAN_INT_TX2=2, CAN_INT_ERROR=1, CAN_INT_NO=0};

//can status register READ-ONLY
struct {
   int1 void0;   //0
   CAN_INT_CODE icode:3;   //1:3   //interrupt code
   int1 void4;   //4
   CAN_OP_MODE opmode:3;   //5:7   //operation mode status
} CANSTAT;
#byte CANSTAT = getenv("SFR:CANSTAT")   //0xF6E

//communication status register READ-ONLY
struct {
   int1 ewarn;      //0 //error warning
   int1 rxwarn;      //1 //receiver warning
   int1 txwarn;      //2 //transmitter warning
   int1 rxbp;   //3 //receiver bus passive
   int1 txbp;   //4 //transmitter bus passive bit
   int1 txbo;   //5   //transmitter bus off
   int1 rx1ovfl;   //6   //receive buffer 1 overflow
   int1 rx0ovfl;   //7   //receive buffer 0 overflow
} COMSTAT;
#byte COMSTAT= getenv("SFR:COMSTAT") //0xF74

//baud rate control register 1
struct {
   int brp:6;   //0:5   //baud rate prescalar
   int sjw:2;   //6:7   //synchronized jump width
} BRGCON1;
#byte BRGCON1 = getenv("SFR:BRGCON1")   //0xF70

//baud rate control register 2
struct {
   int prseg:3; //0:2 //propagation time select
   int seg1ph:3; //3:5 //phase segment 1
   int1 sam; //6 //sample of the can bus line
   int1 seg2phts; //7 //phase segment 2 time select
} BRGCON2;
#byte BRGCON2 = getenv("SFR:BRGCON2")   //0xF71

//baud rate control register 3
struct {
   int seg2ph:3;   //0:2   //phase segment 2 time select
   int void543:3;   //3:5
   int1 wakfil;   //6 //selects can bus line filter for wake-up
   int1 void7;   //7
} BRGCON3;
#byte BRGCON3 = getenv("SFR:BRGCON3")   //0xF72

//can i/o control register
struct {
   int void3210:4;   //0:3
   int1 cancap;   //4 //can message receive caputre
   int1 endrhi;   //5 //enable drive high
   int1 tx2en;    //6   //CANTX2 Pin Enable bit       //added 3/30/09 for PIC18F6585/8585/6680/8680
   int1 tx2src;   //7   //CANTX2 Pin Data Source bit  //added 3/30/09 for PIC18F6585/8585/6680/8680
} CIOCON;
#byte CIOCON = getenv("SFR:CIOCON")    //0xF73

//transmit buffer n control register
struct txbNcon_struct {
   int  txpri:2;   //0:1   //transmit priority bits
   int1 void2; //2
   int1 txreq;   //3   //transmit request status (clear to request message abort)
   int1 txerr;   //4   //transmission error detected
   int1 txlarb;   //5   //transmission lost arbitration status
   int1 txabt;   //6   //transmission aborted status
   int1 void7;
};
struct txbNcon_struct TXB0CON;
struct txbNcon_struct TXB1CON;
struct txbNcon_struct TXB2CON;
struct txbNcon_struct TXBaCON;
#byte   TXB0CON = getenv("SFR:TXB0CON")      //0xF40
#byte   TXB1CON = getenv("SFR:TXB1CON")      //0xF30
#byte   TXB2CON = getenv("SFR:TXB2CON")      //0xF20
#byte TXBaCON =     0xF60             // txbXcon when in the access bank


//transmit buffer n standard identifier
#byte TXB0SIDH = getenv("SFR:TXB0SIDH")      //
#byte TXB0SIDL = getenv("SFR:TXB0SIDL")      //
#byte TXB1SIDH = getenv("SFR:TXB1SIDH")      //
#byte TXB1SIDL = getenv("SFR:TXB1SIDL")      //
#byte TXB2SIDH = getenv("SFR:TXB2SIDH")      //
#byte TXB2SIDL = getenv("SFR:TXB2SIDL")      //

//transmit buffer n extended identifier
#byte TXB0EIDH = getenv("SFR:TXB0EIDH")      //0xF43
#byte TXB0EIDL = getenv("SFR:TXB0EIDL")      //0xF44
#byte TXB1EIDH = getenv("SFR:TXB1EIDH")      //0xF33
#byte TXB1EIDL = getenv("SFR:TXB1EIDL")      //0xF34
#byte TXB2EIDH = getenv("SFR:TXB2EIDH")      //0xF23
#byte TXB2EIDL = getenv("SFR:TXB2EIDL")      //0xF24

#define RX0MASK      getenv("SFR:RXM0EIDL")     //0xF1B    //rxm0eidl
#define RX1MASK      getenv("SFR:RXM1EIDL")     //0xF1F    //rxm1eidl
#define RX0FILTER0   getenv("SFR:RXF0EIDL")     //0xF03    //rxf0eidl
#define RX0FILTER1   getenv("SFR:RXF1EIDL")     //0xF07    //rxf1eidl
#define RX1FILTER2   getenv("SFR:RXF2EIDL")     //0xF0B    //rxf2eidl
#define RX1FILTER3   getenv("SFR:RXF3EIDL")     //0xF0F    //rxf3eidl
#define RX1FILTER4   getenv("SFR:RXF4EIDL")     //0xF13    //rxf4eidl
#define RX1FILTER5   getenv("SFR:RXF5EIDL")     //0xF17    //rxf5eidl
#define RXB0ID       getenv("SFR:RXB0EIDL")     //0xF64    //rxb0eidl
#define RXB1ID       getenv("SFR:RXB1EIDL")     //0xF54    //rxb1eidl
#define TXB0ID       getenv("SFR:TXB0EIDL")     //0xF44    //txb0eidl
#define TXB1ID       getenv("SFR:TXB1EIDL")     //0xF34    //txb1eidl
#define TXB2ID       getenv("SFR:TXB2EIDL")     //0xF24    //tsb2eidl
#define TXRXBaID     0xF64

//transmit buffer n data byte m
#byte TXB0D0 = getenv("SFR:TXB0D0")       //0xF46
#byte TXB0D7 = getenv("SFR:TXB0D7")       //0xF4D
#byte TXB1D0 = getenv("SFR:TXB1D0")       //0xF36
#byte TXB1D7 = getenv("SFR:TXB1D7")       //0xF3D
#byte TXB2D0 = getenv("SFR:TXB2D0")       //0xF26
#byte TXB2D7 = getenv("SFR:TXB2D7")       //0xF2D

//transmit buffer n data length
struct txbNdlc_struct {
   int dlc:4;   //0:3
   int void54:2; //4:5
   int1 rtr; //6 //transmission frame remote tranmission
   int1 void7; //7
};
struct txbNdlc_struct TXB0DLC;
struct txbNdlc_struct TXB1DLC;
struct txbNdlc_struct TXB2DLC;
struct txbNdlc_struct TXBaDLC;
#byte TXB0DLC = getenv("SFR:TXB0DLC")     //0xF45
#byte TXB1DLC = getenv("SFR:TXB1DLC")     //0xF35
#byte TXB2DLC = getenv("SFR:TXB2DLC")     //0xF25
#byte TXBaDLC = 0xF65  //txbXdlc when in the access bank


//transmit error count register
#byte TXERRCNT=getenv("SFR:TXERRCNT")     //0xF76


enum CAN_RX_MODE {CAN_RX_ALL=3, CAN_RX_EXT=2, CAN_RX_STD=1, CAN_RX_VALID=0};

//receive buffer 0 control register
struct {
   int1 filthit0;   //0 //filter hit
   int1 jtoff;   //1 //jump table offset
   int1 rxb0dben;   //2 //receive buffer 0 double buffer enable
   int1 rxrtrro;   //3 //receive remote transfer request
   int1 void4;   //4
   CAN_RX_MODE rxm:2;   //5:6 //receiver buffer mode
   int1 rxful;   //7 //receive full status
} RXB0CON;
#byte RXB0CON = getenv("SFR:RXB0CON")     //0xF60

//receive buffer 1 control register
struct {
   int filthit:3;   //0:2
   int1 rxrtrro;   //3 //receive remote transfer request
   int1 void4;   //4
   CAN_RX_MODE rxm:2;   //5:6 //receive buffer mode
   int1 rxful;   //7   //receive full
} RXB1CON;
#byte   RXB1CON = getenv("SFR:RXB1CON")     //0xF50


//receive buffer n standard identifier
#byte   RXB0SIDH = getenv("SFR:RXB0SIDH")    //0xF61
#byte   RXB0SIDL = getenv("SFR:RXB0SIDL")    //0xF62
#byte   RXB1SIDH = getenv("SFR:RXB1SIDH")    //0xF51
#byte   RXB1SIDL = getenv("SFR:RXB1SIDL")    //0xF52

//receive buffer n extended identifier
#byte   RXB0EIDH = getenv("SFR:RXB0EIDH")    //0xF63
#byte   RXB0EIDL = getenv("SFR:RXB0EIDL")    //0xF64
#byte   RXB1EIDH = getenv("SFR:RXB1EIDH")    //0xF53
#byte   RXB1EIDL = getenv("SFR:RXB1EIDL")    //0xF54

#byte TXRXBaEIDL=0xF64

struct {
   int void012:3; //0:3
   int1 ext;   //extendid id
   int1 srr;   //substitute remove request bit
   int void567:3; //5:7
} TXRXBaSIDL;
#byte TXRXBaSIDL=0xF62

//receive buffer n data length code register
struct rxbNdlc_struct {
   int dlc:4;   //0:3 //data length code
   int1 rb0; //4 //reserved
   int1 rb1;   //5 //reserved
   int1 rtr;   //6 //receiver remote transmission request bit
   int1 void7;   //7
};
struct rxbNdlc_struct RXB0DLC;
struct rxbNdlc_struct RXB1DLC;
struct rxbNdlc_struct RXBaDLC;
#byte   RXB0DLC = getenv("SFR:RXB0DLC")      //0xF65
#byte   RXB1DLC = getenv("SFR:RXB1DLC")      //0xF55
#byte   RXBaDLC = getenv("SFR:RXB0DLC")      //0xF65
//receive buffer n data field byte m register
#byte RXB0D0 = getenv("SFR:RXB0D0")    //0xF66
#byte RXB0D7 = getenv("SFR:RXB0D7")    //0xF6D
#byte TXRXBaD0=0xF66
#byte TXRXBaD7=0xF6D

//receive error count
#byte RXERRCNT = getenv("SFR:RXERRCNT")      //0xF75

//receive acceptance filter n standard indifier
#byte RXF0SIDH = getenv("SFR:RXF0SIDH")      //0xF00
#byte RXF0SIDL = getenv("SFR:RXF0SIDL")      //0xF01
#byte RXF1SIDH = getenv("SFR:RXF1SIDH")      //0xF04
#byte RXF1SIDL = getenv("SFR:RXF1SIDL")      //0xF05
#byte RXF2SIDH = getenv("SFR:RXF2SIDH")      //0xF08
#byte RXF2SIDL = getenv("SFR:RXF2SIDL")      //0xF09
#byte RXF3SIDH = getenv("SFR:RXF3SIDH")      //0xF0C
#byte RXF3SIDL = getenv("SFR:RXF3SIDL")      //0xF0D
#byte RXF4SIDH = getenv("SFR:RXF4SIDH")      //0xF10
#byte RXF4SIDL = getenv("SFR:RXF4SIDL")      //0xF11
#byte RXF5SIDH = getenv("SFR:RXF5SIDH")      //0xF14
#byte RXF5SIDL = getenv("SFR:RXF5SIDL")      //0xF15

//receive acceptance filter n extended indifier
#byte RXF0EIDH = getenv("SFR:RXF0EIDH")      //0xF02
#byte RXF0EIDL = getenv("SFR:RXF0EIDL")      //0xF03
#byte RXF1EIDH = getenv("SFR:RXF1EIDH")      //0xF06
#byte RXF1EIDL = getenv("SFR:RXF1EIDL")      //0xF07
#byte RXF2EIDH = getenv("SFR:RXF2EIDH")      //0xF0A
#byte RXF2EIDL = getenv("SFR:RXF2EIDL")      //0xF0B
#byte RXF3EIDH = getenv("SFR:RXF3EIDH")      //0xF0E
#byte RXF3EIDL = getenv("SFR:RXF3EIDL")      //0xF0F
#byte RXF4EIDH = getenv("SFR:RXF4EIDH")      //0xF12
#byte RXF4EIDL = getenv("SFR:RXF4EIDL")      //0xF13
#byte RXF5EIDH = getenv("SFR:RXF5EIDH")      //0xF16
#byte RXF5EIDL = getenv("SFR:RXF5EIDL")      //0xF17

//receive acceptance mask n standard identifer mask
#byte RXM0SIDH = getenv("SFR:RXM0SIDH")      //0xF18
#byte RXM0SIDL = getenv("SFR:RXM0SIDL")      //0xF19
#byte RXM1SIDH = getenv("SFR:RXM1SIDH")      //0xF1C
#byte RXM1SIDL = getenv("SFR:RXM1SIDL")      //0xF1D

//receive acceptance mask n extended identifer mask
#byte RXM0EIDH = getenv("SFR:RXM0EIDH")      //0xF1A
#byte RXM0EIDL = getenv("SFR:RXM0EIDL")      //0xF1B
#byte RXM1EIDH = getenv("SFR:RXM1EIDH")      //0xF1E
#byte RXM1EIDL = getenv("SFR:RXM1EIDL")      //0xF1F

//value to put in mask field to accept all incoming id's
#define CAN_MASK_ACCEPT_ALL   0

//can interrupt flags
#bit CAN_INT_IRXIF = getenv("BIT:IRXIF")     //0xFA4.7
#bit CAN_INT_WAKIF = getenv("BIT:WAKIF")     //0xFA4.6
#bit CAN_INT_ERRIF = getenv("BIT:ERRIF")     //0xFA4.5
#bit CAN_INT_TXB2IF = getenv("BIT:TXB2IF")   // 0xFA4.4
#bit CAN_INT_TXB1IF = getenv("BIT:TXB1IF")   // 0xFA4.3
#bit CAN_INT_TXB0IF = getenv("BIT:TXB0IF")   // 0xFA4.2
#bit CAN_INT_RXB1IF = getenv("BIT:RXB1IF")   // 0xFA4.1
#bit CAN_INT_RXB0IF = getenv("BIT:RXB0IF")   // 0xFA4.0

//PROTOTYPES

struct rx_stat {
   int1 err_ovfl;
   int filthit:3;
   int1 buffer;
   int1 rtr;
   int1 ext;
   int1 inv;
};

void  can_init(void);
void  can_set_baud(void);
void  can_set_mode(CAN_OP_MODE mode);
void  can_set_id(unsigned int* addr, unsigned int32 id, int1 ext);
unsigned int32 can_get_id(unsigned int * addr, int1 ext);
int1  can_putd(unsigned int32 id, unsigned int * data, unsigned int len, unsigned int priority, int1 ext, int1 rtr);
int1  can_getd(unsigned int32 & id, unsigned int * data, unsigned int & len, struct rx_stat & stat);

#endif
