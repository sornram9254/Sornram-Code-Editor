//////// Standard Header file for the PIC16F526 device ////////////////
#device PIC16F526
#nolist
//////// Program memory: 1024x12  Data RAM: 67  Stack: 2
//////// I/O: 12   Analog Pins: 3
//////// Data EEPROM: 64
//////// C Scratch area: 0D   ID Location: 0440
//////// Oscilator Calibration Address: 05
//////// Fuses: LP,XT,HS,EC_IO,INTRC_IO,INTRC,RC_IO,RC,NOWDT,WDT,PROTECT
//////// Fuses: NOPROTECT,NOMCLR,MCLR,IOSC4,IOSC8,PROTECTDF,NOPROTECTDF
//////// 
////////////////////////////////////////////////////////////////// I/O
// Discrete I/O Functions: SET_TRIS_x(), OUTPUT_x(), INPUT_x(),
//                         PORT_x_PULLUPS(), INPUT(),
//                         OUTPUT_LOW(), OUTPUT_HIGH(),
//                         OUTPUT_FLOAT(), OUTPUT_BIT()
// Constants used to identify pins in the above are:

#define PIN_B0  48
#define PIN_B1  49
#define PIN_B2  50
#define PIN_B3  51
#define PIN_B4  52
#define PIN_B5  53

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

#define DISABLE_PULLUPS            0x40  // for 508 and 509 only
#define DISABLE_WAKEUP_ON_CHANGE   0x80  // for 508 and 509 only
#define PIN_CHANGE_FROM_SLEEP      0     // DEFAULT, for 508 and 509 only

////////////////////////////////////////////////////////////////// COMP
// Comparator Variables: C1OUT, C2OUT
// Constants used in setup_comparator() are:
//
#define NC_NC_NC_NC   0x00
#define NC_NC         0x00

//Pick one constant for COMP1
#define CP1_B0_B1     0x3000000E
#define CP1_B0_VREF   0x1000000A
#define CP1_B1_VREF   0x20000008
//Optionally OR with one or both of the following
#define CP1_OUT_ON_B2 0x04000040
#define CP1_INVERT    0x00000020
#define CP1_WAKEUP    0x00000001
#define CP1_TIMER0    0x00000010

//OR with one constant for COMP2
#define CP2_B0_C1     0x30001C00
#define CP2_C0_C1     0x20100E00
#define CP2_B0_VREF   0x10001800
#define CP2_C0_VREF   0x00100A00
#define CP2_C1_VREF   0x30200800
//Optionally OR with one or both of the following
#define CP2_OUT_ON_C4 0x00084000
#define CP2_INVERT    0x00002000
#define CP2_WAKEUP    0x00000100

#bit C1OUT = 0x8.7
#bit C2OUT = 0xB.7


////////////////////////////////////////////////////////////////// ADC
// ADC Functions: SETUP_ADC(), SETUP_ADC_PORTS() (aka SETUP_PORT_A),
//                SET_ADC_CHANNEL(), READ_ADC()
// Constants used for SETUP_ADC() are:
#define ADC_OFF                0          // ADC Off
#define ADC_CLOCK_DIV_32    0x00
#define ADC_CLOCK_DIV_16    0x10
#define ADC_CLOCK_DIV_8     0x20
#define ADC_CLOCK_INTERNAL  0x30          // Internal 2-6us

// Constants used in SETUP_ADC_PORTS() are:
#define AN0_AN1_AN2                    0xc0   // A0 A1 A2
#define AN0_AN2                        0x80   // A0 A2
#define AN2                            0x40   // A2
#define NO_ANALOGS                        0   // None

// Constants used in READ_ADC() are:
#define ADC_START_AND_READ     7   // This is the default if nothing is specified
#define ADC_START_ONLY         1
#define ADC_READ_ONLY          6


#list
