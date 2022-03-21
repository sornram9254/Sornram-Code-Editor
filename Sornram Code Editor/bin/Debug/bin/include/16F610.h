//////// Standard Header file for the PIC16F610 device ////////////////
#device PIC16F610
#nolist
//////// Program memory: 1024x14  Data RAM: 64  Stack: 8
//////// I/O: 12   Analog Pins: 0
//////// C Scratch area: 40   ID Location: 2000
//////// Fuses: LP,XT,HS,EC_IO,INTRC_IO,INTRC,RC_IO,RC,NOWDT,WDT,PUT,NOPUT
//////// Fuses: NOMCLR,MCLR,PROTECT,NOPROTECT,IOSC4,IOSC8,NOBROWNOUT
//////// Fuses: BROWNOUT_NOSL,BROWNOUT
//////// 
////////////////////////////////////////////////////////////////// I/O
// Discrete I/O Functions: SET_TRIS_x(), OUTPUT_x(), INPUT_x(),
//                         PORT_x_PULLUPS(), INPUT(),
//                         OUTPUT_LOW(), OUTPUT_HIGH(),
//                         OUTPUT_FLOAT(), OUTPUT_BIT()
// Constants used to identify pins in the above are:

#define PIN_A0  40
#define PIN_A1  41
#define PIN_A2  42
#define PIN_A3  43
#define PIN_A4  44
#define PIN_A5  45

#define PIN_C0  56
#define PIN_C1  57
#define PIN_C2  58
#define PIN_C3  59
#define PIN_C4  60
#define PIN_C5  61

////////////////////////////////////////////////////////////////// Useful defines
#define FALSE 0
#define TRUE 1

#define BYTE int8
#define BOOLEAN int1

#define getc getch
#define fgetc getch
#define getchar getch
#define putc putchar
#define fputc putchar
#define fgets gets
#define fputs puts

////////////////////////////////////////////////////////////////// Control
// Control Functions:  RESET_CPU(), SLEEP(), RESTART_CAUSE()
// Constants returned from RESTART_CAUSE() are:
#define WDT_FROM_SLEEP    3   
#define WDT_TIMEOUT      11   
#define MCLR_FROM_SLEEP  19   
#define MCLR_FROM_RUN    27   
#define NORMAL_POWER_UP  25   
#define BROWNOUT_RESTART 26   

////////////////////////////////////////////////////////////////// Timer 0
// Timer 0 (AKA RTCC)Functions: SETUP_COUNTERS() or SETUP_TIMER_0(),
//                              SET_TIMER0() or SET_RTCC(),
//                              GET_TIMER0() or GET_RTCC()
// Constants used for SETUP_TIMER_0() are:
#define T0_INTERNAL   0
#define T0_EXT_L_TO_H 32
#define T0_EXT_H_TO_L 48

#define T0_DIV_1      8
#define T0_DIV_2      0
#define T0_DIV_4      1
#define T0_DIV_8      2
#define T0_DIV_16     3
#define T0_DIV_32     4
#define T0_DIV_64     5
#define T0_DIV_128    6
#define T0_DIV_256    7


#define T0_8_BIT      0     

#define RTCC_INTERNAL   0      // The following are provided for compatibility
#define RTCC_EXT_L_TO_H 32     // with older compiler versions
#define RTCC_EXT_H_TO_L 48
#define RTCC_DIV_1      8
#define RTCC_DIV_2      0
#define RTCC_DIV_4      1
#define RTCC_DIV_8      2
#define RTCC_DIV_16     3
#define RTCC_DIV_32     4
#define RTCC_DIV_64     5
#define RTCC_DIV_128    6
#define RTCC_DIV_256    7
#define RTCC_8_BIT      0     

// Constants used for SETUP_COUNTERS() are the above
// constants for the 1st param and the following for
// the 2nd param:

////////////////////////////////////////////////////////////////// WDT
// Watch Dog Timer Functions: SETUP_WDT() or SETUP_COUNTERS() (see above)
//                            RESTART_WDT()
// WDT base is 18ms
//

#define WDT_18MS        8   
#define WDT_36MS        9   
#define WDT_72MS       10   
#define WDT_144MS      11   
#define WDT_288MS      12   
#define WDT_576MS      13   
#define WDT_1152MS     14   
#define WDT_2304MS     15   

////////////////////////////////////////////////////////////////// Timer 1
// Timer 1 Functions: SETUP_TIMER_1, GET_TIMER1, SET_TIMER1
// Constants used for SETUP_TIMER_1() are:
//      (or (via |) together constants from each group)
#define T1_DISABLED         0
#define T1_INTERNAL         5
#define T1_EXTERNAL         7
#define T1_EXTERNAL_SYNC    3

#define T1_CLK_OUT          8

#define T1_DIV_BY_1         0
#define T1_DIV_BY_2         0x10
#define T1_DIV_BY_4         0x20
#define T1_DIV_BY_8         0x30

#define T1_GATE           0x40
#define T1_GATE_INVERTED  0xC0

// Comparator Variables: C1OUT, C2OUT
// Constants used in setup_comparator() are:
//
#define NC_NC_NC_NC  0x00

// OR together one from the first group with one from the second
#define CP1_A1_A0  0x80
#define CP1_C1_A0  0x81
#define CP1_C2_A0  0x82
#define CP1_C3_A0  0x83
#define CP1_A1_VREF  0x84
#define CP1_C1_VREF  0x85
#define CP1_C2_VREF  0x86
#define CP1_C3_VREF  0x87
//
#define CP2_A1_A0  0x8000
#define CP2_C1_A0  0x8100
#define CP2_C2_A0  0x8200
#define CP2_C3_A0  0x8300
#define CP2_A1_VREF  0x8400
#define CP2_C1_VREF  0x8500
#define CP2_C2_VREF  0x8600
#define CP2_C3_VREF  0x8700
// and any of the following
#define CP1_OUT_ON_A2  0x20
#define CP2_OUT_ON_C4  0x2000
#define CP1_INVERT 0x010
#define CP2_INVERT 0x01000
#define COMP_T1_SYNC          0x100000
#define COMP_T1_GATE          0x200000
#define CP1_HYST  0x800000
#define CP2_HYST  0x400000
#define T1_TIMES_4  0x1000000
#define CP1_LATCH_SET    0x60000000
#define CP2_LATCH_CLEAR  0x90000000
#define CP_LATCH_SET    0x8000000
#define CP_LATCH_CLEAR  0x4000000
#define CP_SR_CLK_DIV_4  0x1000000
#define CP_SR_CLK_DIV_8  0x1400000
#define CP_SR_CLK_DIV_16 0x1800000
#define CP_SR_CLK_DIV_32 0x1C00000

#bit C1OUT = 0x1A.6
#bit C2OUT = 0x1B.6

////////////////////////////////////////////////////////////////// VREF
// Constants used in setup_vref() are:
//
#define VREF_LOW  0x20
#define VREF_HIGH 0x00
// Or (with |) the above with a number 0-15
#define VREF_6th   0x10  // Turn on .6V ref
#define VREF_COMP1 0x80
#define VREF_COMP2 0x40

////////////////////////////////////////////////////////////////// INT
// Interrupt Functions: ENABLE_INTERRUPTS(), DISABLE_INTERRUPTS(),
//                      CLEAR_INTERRUPT(), INTERRUPT_ACTIVE(),
//                      EXT_INT_EDGE()
//
// Constants used in EXT_INT_EDGE() are:
#define L_TO_H              0x40
#define H_TO_L                 0
// Constants used in ENABLE/DISABLE_INTERRUPTS() are:
#define GLOBAL                    0x0BC0
#define PERIPH                    0x0B40
#define INT_RTCC                  0x000B20
#define INT_EXT_L2H               0x50000B10
#define INT_EXT_H2L               0x60000B10
#define INT_EXT                   0x000B10
#define INT_TIMER1                0x008C01
#define INT_TIMER0                0x000B20
#define INT_COMP                  0x008C08
#define INT_RA                    0x00FF0B08
#define INT_COMP2                 0x008C10
#define INT_RA0                   0x0010B08
#define INT_RA1                   0x0020B08
#define INT_RA2                   0x0040B08
#define INT_RA3                   0x0080B08
#define INT_RA4                   0x0100B08
#define INT_RA5                   0x0200B08

#list
