//////// Standard Header file for the PIC12F510 device ////////////////
#device PIC12F510
#nolist
//////// Program memory: 1024x12  Data RAM: 38  Stack: 2
//////// I/O: 6   Analog Pins: 3
//////// C Scratch area: 0A   ID Location: 0400
//////// Oscilator Calibration Address: 05
//////// Fuses: LP,XT,INTRC,RC,NOWDT,WDT,PROTECT,NOPROTECT,NOMCLR,MCLR,IOSC4
//////// Fuses: IOSC8
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
// Comparator Variables: C1OUT
// Constants used in setup_comparator() are:
#define NC_NC_NC_NC  0x00FF07
#define NC_NC  0x00FF07
#define A1_A0  0x04FF5E
#define VR_A0  0x04ff5A
#define VR_A1  0x04ff58
#define A1_A0_OUT_ON_A2  0x00FB1E
#define VR_A0_OUT_ON_A2  0x00FB1A
#define VR_A1_OUT_ON_A2  0x00FB18

// The following may be OR'ed with the above
#define COMP_DISABLE_WAKEUP   1
#define COMP_INVERT           0x20

#bit C1OUT = 7.7


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
