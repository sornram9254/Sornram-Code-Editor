//////// Standard Header file for the PIC16C781 device ////////////////
#device PIC16C781
#nolist
//////// Program memory: 1024x14  Data RAM: 256  Stack: 8
//////// I/O: 16   Analog Pins: 8
//////// C Scratch area: 20   ID Location: 2000
//////// Fuses: LP,XT,HS,EC_IO,INTRC_IO,INTRC,ER_IO,ER,NOWDT,WDT,PUT,NOPUT
//////// Fuses: NOMCLR,MCLR,NOBROWNOUT,BROWNOUT,BORV45,BORV42,BORV27,BORV25
//////// Fuses: PROTECT,NOPROTECT
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
#define PIN_A6  46
#define PIN_A7  47

#define PIN_B0  48
#define PIN_B1  49
#define PIN_B2  50
#define PIN_B3  51
#define PIN_B4  52
#define PIN_B5  53
#define PIN_B6  54
#define PIN_B7  55

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

////////////////////////////////////////////////////////////////// Timer 2
// Timer 2 Functions: SETUP_TIMER_2, GET_TIMER2, SET_TIMER2
// Constants used for SETUP_TIMER_2() are:
#define T2_DISABLED         0
#define T2_DIV_BY_1         4
#define T2_DIV_BY_4         5
#define T2_DIV_BY_16        6

////////////////////////////////////////////////////////////////// COMP
// Comparator Variables: C1OUT, C2OUT
// Constants used in setup_comparator() are:
//
#define NC_NC_NC_NC   0x00
#define NC_NC         0x00

//Pick one constant for COMP1
#define CP1_A1_A0     0x4000088
#define CP1_C1_A0     0x0100089
#define CP1_C2_A0     0x020008A
#define CP1_C3_A0     0x040008B
#define CP1_A1_VREF   0x400008C
#define CP1_C1_VREF   0x010008D
#define CP1_C2_VREF   0x020008E
#define CP1_C3_VREF   0x040008F
//Optionally OR with one or both of the following
#define CP1_OUT_ON_A2 0x2000020
#define CP1_INVERT    0x0000010

//OR with one constant for COMP2
#define CP2_A1_C0     0x4008800
#define CP2_C1_C0     0x0108900
#define CP2_C2_C0     0x0208A00
#define CP2_C3_C0     0x0408B00
#define CP2_A1_VREF   0x4008C00
#define CP2_C1_VREF   0x0108D00
#define CP2_C2_VREF   0x0208E00
#define CP2_C3_VREF   0x0408F00
//Optionally OR with one or both of the following
#define CP2_OUT_ON_C4 0x0082000
#define CP2_INVERT    0x0001000

//Optionally OR with one or both of the following
#define CP2_T1_SYNC   0x10000000
#define CP2_T1_GATE   0x20000000

#bit C1OUT = 0x119.6
#bit C2OUT = 0x11A.6

////////////////////////////////////////////////////////////////// VREF
// Constants used in setup_vref() are:
//
#define VREF_ON  8
#define VREF_B0  4

////////////////////////////////////////////////////////////////// DAC
// Digital to Analog Functions: SETUP_DAC(), DAC_WRITE()
// Constants used in SETUP_DAC() are:
#define DAC_OFF  0
#define DAC_VDD  0x80
#define DAC_VREF 0x81
#define DAC_VR   0x82
#define DAC_OUTPUT 0x40


////////////////////////////////////////////////////////////////// ADC
// ADC Functions: SETUP_ADC(), SETUP_ADC_PORTS() (aka SETUP_PORT_A),
//                SET_ADC_CHANNEL(), READ_ADC()
// Constants used for SETUP_ADC() are:
#define ADC_OFF                0          // ADC Off
#define ADC_CLOCK_DIV_2    0x100
#define ADC_CLOCK_DIV_8     0x40
#define ADC_CLOCK_DIV_32    0x80
#define ADC_CLOCK_INTERNAL  0xc0          // Internal 2-6us


// Constants used in SETUP_ADC_PORTS() are:
// First argument:
// OR together desired pins
#define sAN0                   1         //| A0
#define sAN1                   2         //| A1
#define sAN2                   4         //| A2
#define sAN3                   8         //| A3
#define sAN4                  16         //| B0
#define sAN5                  32         //| B1
#define sAN6                  64         //| B2
#define sAN7                  128        //| B3
#define NO_ANALOGS             0         // None
#define ALL_ANALOG            255        // A0 A1 A2 A3 B0 B1 B2 B3

// Optional Second argument:
#define VSS_VDD              0x0000  //| Range 0-Vdd
#define VSS_VREF             0x1000  //| Range 0-Vref1
#define VSS_VR               0x2000  //| Range 0-Vr
#define VSS_VDAC             0x3000  //| Range 0-Vdac


// Constants used in READ_ADC() are:
#define ADC_START_AND_READ     7   // This is the default if nothing is specified
#define ADC_START_ONLY         1
#define ADC_READ_ONLY          6

////////////////////////////////////////////////////////////////// INT
// Interrupt Functions: ENABLE_INTERRUPTS(), DISABLE_INTERRUPTS(),
//                      CLEAR_INTERRUPT(), INTERRUPT_ACTIVE(),
//                      EXT_INT_EDGE()
//
// Constants used in EXT_INT_EDGE() are:
#define L_TO_H              0x40
#define H_TO_L                 0
// Constants used in ENABLE/DISABLE_INTERRUPTS() are:
#define GLOBAL                    0x0B80
#define INT_RTCC                  0x000B20
#define INT_RB                    0x00FF0B08
#define INT_EXT_L2H               0x50000B10
#define INT_EXT_H2L               0x60000B10
#define INT_EXT                   0x000B10
#define INT_AD                    0x000B40
#define INT_TIMER1                0x008C01
#define INT_LOWVOLT               0x008D80
#define INT_TIMER0                0x000B20
#define INT_COMP1                 0x008C10
#define INT_COMP2                 0x008C20

#list
