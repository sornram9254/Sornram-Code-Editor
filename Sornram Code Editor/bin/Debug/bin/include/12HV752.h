//////// Standard Header file for the PIC12HV752 device ////////////////
#device PIC12HV752
#nolist
//////// Program memory: 1024x14  Data RAM: 64  Stack: 8
//////// I/O: 6   Analog Pins: 4
//////// C Scratch area: 40   ID Location: 2000
//////// Fuses: INTRC_IO,EC,NOWDT,WDT,PUT,NOPUT,NOMCLR,MCLR,PROTECT
//////// Fuses: NOPROTECT,NOBROWNOUT,BROWNOUT_NOSL,BROWNOUT,WRT,WRT_200
//////// Fuses: WRT_100,NOWRT,CLKOUT,NOCLKOUT,DEBUG,NODEBUG
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

#define T1_GATE_A4          0
#define T1_GATE_A3          0x10000

////////////////////////////////////////////////////////////////// Timer 2
// Timer 2 Functions: SETUP_TIMER_2, GET_TIMER2, SET_TIMER2
// Constants used for SETUP_TIMER_2() are:
#define T2_DISABLED         0
#define T2_DIV_BY_1         4
#define T2_DIV_BY_4         5
#define T2_DIV_BY_16        6

////////////////////////////////////////////////////////////////// Timer 4
// Timer 4 Functions: SETUP_TIMER_4, GET_TIMER4, SET_TIMER4
// Constants used for SETUP_TIMER_4() are:
#define T4_DISABLED         0
#define T4_DIV_BY_1         4
#define T4_DIV_BY_4         5
#define T4_DIV_BY_16        6

//The following may be OR'ed with the above for setting up the Hardware Limit Timer
#define T4_RESET_FROM_CCP1      0x0000
#define T4_RESET_FROM_C1OUT     0x0400
#define T4_RESET_FROM_C2OUT     0x0800
#define T4_RESET_FROM_COG1FLT   0x0C00
#define T4_RESET_FROM_COG1OUT0  0x1000
#define T4_RESET_FROM_COG1OUT1  0x1400
#define T4_RESET_ON_H2L         0x0200
#define T4_RESET_ON_L2H         0x0100

////////////////////////////////////////////////////////////////// CCP
// CCP Functions: SETUP_CCPx, SET_PWMx_DUTY
// CCP Variables: CCP_x, CCP_x_LOW, CCP_x_HIGH
// Constants used for SETUP_CCPx() are:
#define CCP_OFF                         0
#define CCP_CAPTURE_FE                  4
#define CCP_CAPTURE_RE                  5
#define CCP_CAPTURE_DIV_4               6
#define CCP_CAPTURE_DIV_16              7
#define CCP_COMPARE_SET_ON_MATCH        8
#define CCP_COMPARE_CLR_ON_MATCH        9
#define CCP_COMPARE_INT                 0xA
#define CCP_COMPARE_RESET_TIMER         0xB
#define CCP_PWM                         0xC
#define CCP_PWM_PLUS_1                  0x1c  
#define CCP_PWM_PLUS_2                  0x2c
#define CCP_PWM_PLUS_3                  0x3c
#word   CCP_1       =                   getenv("SFR:CCPR1L")
#byte   CCP_1_LOW   =                   getenv("SFR:CCPR1L")
#byte   CCP_1_HIGH  =                   getenv("SFR:CCPR1H")
////////////////////////////////////////////////////////////////// COMP
// Comparator Variables: C1OUT, C2OUT
// Constants used in setup_comparator() are:
//
#define NC_NC_NC_NC     0x00

//Pick one constant for COMP1
#define CP1_A1_A0       0x8000
#define CP1_A4_A0       0x8001
#define CP1_A1_DAC      0x8010
#define CP1_A4_DAC      0x8011
#define CP1_A1_FVR      0x8020
#define CP1_A4_FVR      0x8021
#define CP1_A1_VSS      0x8030
#define CP1_A4_VSS      0x8031
//Optionaly OR any of the following with the above
#define CP1_INT_L2H     0x0080
#define CP1_INT_H2L     0x0040
#define CP1_OUT_ON_A2   0x2000
#define CP1_INVERT      0x1000
#define CP1_FILTER      0x0800
#define CP1_FAST        0x0400
#define CP1_HYST        0x0200
#define CP1_SYNC        0x0100

//Pick one constant for COMP2
#define CP2_A1_A0       0x80000000
#define CP2_A5_A0       0x80010000
#define CP2_A1_DAC      0x80100000
#define CP2_A5_DAC      0x80110000
#define CP2_A1_FVR      0x80200000
#define CP2_A5_FVR      0x80210000
#define CP2_A1_VSS      0x80300000
#define CP2_A5_VSS      0x80310000
//Optionaly OR any of the following with the above
#define CP2_INT_L2H     0x00800000
#define CP2_INT_H2L     0x00400000
#define CP2_OUT_ON_A2   0x20000000
#define CP2_INVERT      0x10000000
#define CP2_FILTER      0x08000000
#define CP2_FAST        0x04000000
#define CP2_HYST        0x02000000
#define CP2_SYNC        0x01000000

#bit C1OUT = getenv("SFR:CM1CON0").6
#bit C2OUT = getenv("SFR:CM2CON0").6

////////////////////////////////////////////////////////////////// VREF
// Constants used in setup_vref() are:
//
#define VREF_OFF     0
#define VREF_ON      0x80
#define VREF_OUT_A0  0x20

////////////////////////////////////////////////////////////////// DAC
// Digital to Analog Functions: SETUP_DAC(), DAC_WRITE()
// Constants used in SETUP_DAC() are:
#define DAC_OFF         0
#define DAC_VDD         0x80
#define DAC_VREF        0x84
// The following may be OR'ed in with the above using |
#define DAC_OUTPUT      0x20
#define DAC_FULL_RANGE  0x40

////////////////////////////////////////////////////////////////// COG
// CLC Functions: SETUP_COG(), SET_COG_DEAD_BAND(), SET_COG_PHASE(),
//                SET_COG_BLANKING(), COG_STATUS(), COG_RESTART()
// Constants used in SETUP_COG() first param are:
#define COG_ENABLED                  0x80
#define COG_DISABLED                 0
#define COG_ENABLE_OUT1              0x40
#define COG_ENABLE_OUT0              0x20
#define COG_OUT1_INVERTED            0x10
#define COG_OUT0_INVERTED            0x08
// One of the following may be OR'ed in with the above using |
#define COG_CLOCK_HFINTOSC           0x02
#define COG_CLOCK_FOSC_DIV_4         0x01
#define COG_CLOCK_FOSC               0
// One of the following may be OR'ed in with the above using |
#define COG_FALLING_EDGE_SENSITIVE   0x8000
#define COG_FALLING_LEVEL_SENSITIVE  0
// One of the following may be OR'ed in with the above using |
#define COG_RISING_EDGE_SENSITIVE    0x4000
#define COG_RISING_LEVEL_SENSITIVE   0
// One of the following may be OR'ed in with the above using |
#define COG_FALLING_SOURCE_FLT_HLT   0x3800
#define COG_FALLING_SOURCE_CCP1_HLT  0x3000
#define COG_FALLING_SOURCE_C2OUT_HLT 0x2800
#define COG_FALLING_SOURCE_C1OUT_HLT 0x2000
#define COG_FALLING_SOURCE_FLT       0x1800
#define COG_FALLING_SOURCE_CCP1      0x1000
#define COG_FALLING_SOURCE_C2OUT     0x0800
#define COG_FALLING_SOURCE_C1OUT     0
// One of the following may be OR'ed in with the above using |
#define COG_RISING_SOURCE_FLT_HLT    0x0700
#define COG_RISING_SOURCE_CCP1_HLT   0x0600
#define COG_RISING_SOURCE_C2OUT_HLT  0x0500
#define COG_RISING_SOURCE_C1OUT_HLT  0x0400
#define COG_RISING_SOURCE_FLT        0x0300
#define COG_RISING_SOURCE_CCP1       0x0200
#define COG_RISING_SOURCE_C2OUT      0x0100
#define COG_RISING_SOURCE_C1OUT      0

#define COG_COG1OUT0_A5              0x10000
#define COG_COG1OUT0_A2              0
#define COG_COG1OUT1_A4              0x20000
#define COG_COG1OUT1_A0              0
#define COG_COG1FLT_A3               0x40000
#define COG_COG1FLT_A4               0

// Constants used in SETUP_COG() second param are:
#define COG_NO_AUTO_SHUTDOWN         0
#define COG_SHUTDOWN_ON_FLT          0x01
#define COG_SHUTDOWN_ON_C1OUT        0x02
#define COG_SHUTDOWN_ON_C2OUT        0x04
#define COG_SHUTDOWN_ON_HLT          0x08
#define COG_AUTO_RESTART             0x40
// One of the following may be OR'ed in with the above using |
#define COG_SHUTDOWN_OUT0_HIGH       0x10
#define COG_SHUTDOWN_OUT0_LOW        0
// One of the following may be OR'ed in with the above using |
#define COG_SHUTDOWN_OUT1_HIGH       0x20
#define COG_SHUTDOWN_OUT1_LOW        0

// Constants returned from COG_STATUS() are:
#define COG_AUTO_SHUTDOWN              0x80 

////////////////////////////////////////////////////////////////// INTERNAL RC
// Constants used in setup_oscillator() are:
// First param:
#define OSC_31KHZ                 0
#define OSC_1MHZ                  0x10
#define OSC_4MHZ                  0x20
#define OSC_8MHZ                  0x30
// A second optional parameter may be used with this part to fine
// tune the speed (signed int,0-15)
// Result may be (ignore all other bits)
#define OSC_LFINTRC_STABLE       2
#define OSC_HFINTRC_STABLE       4


////////////////////////////////////////////////////////////////// ADC
// ADC Functions: SETUP_ADC(), SETUP_ADC_PORTS() (aka SETUP_PORT_A),
//                SET_ADC_CHANNEL(), READ_ADC()
// Constants used for SETUP_ADC() are:
#define ADC_OFF                0              // ADC Off
#define ADC_CLOCK_DIV_2    0x100
#define ADC_CLOCK_DIV_4     0x40
#define ADC_CLOCK_DIV_8     0x10
#define ADC_CLOCK_DIV_32    0x20
#define ADC_CLOCK_DIV_16    0x50
#define ADC_CLOCK_DIV_64    0x60
#define ADC_CLOCK_INTERNAL  0x30              // Internal 2-6us

// Constants used is SETUP_ADC_PORTS() are:
// First argument:
// OR together desired pins
#define sAN0            0x01  //| A0
#define sAN1            0x02  //| A1
#define sAN2            0x04  //| A2
#define sAN3            0x10  //| A4
#define NO_ANALOGS         0  // None
#define ALL_ANALOG      0x17  // A0 A1 A2 A4

//Optional Second argument:
#define VSS_VDD         0x0000  //| Range 0 to Vdd
#define VSS_VREF        0x4000  //| Range 0 to Vref+

// Constants used in SET_ADC_CHANNEL() are:
// either use the channel number or one of the following
#define DAC_CHANNEL               0x0E
#define FVR_CHANNEL               0x0F

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
#define GLOBAL                    0x0BC0
#define PERIPH                    0x0B40
#define INT_RTCC                  0x000B20
#define INT_EXT_L2H               0x50000B10
#define INT_EXT_H2L               0x60000B10
#define INT_EXT                   0x000B10
#define INT_AD                    0x008C40
#define INT_TIMER1                0x008C01
#define INT_TIMER2                0x008C02
#define INT_TIMER0                0x000B20
#define INT_RA                    0x00FF0B08
#define INT_TMR1G                 0x008C80
#define INT_TIMER4                0x008C04
#define INT_CCP1                  0x008D01
#define INT_COG1                  0x008D04
#define INT_COMP                  0x008D10
#define INT_COMP2                 0x008D20
#define INT_RA0                   0x0010B08
#define INT_RA1                   0x0020B08
#define INT_RA2                   0x0040B08
#define INT_RA3                   0x0080B08
#define INT_RA4                   0x0100B08
#define INT_RA5                   0x0200B08

#list
