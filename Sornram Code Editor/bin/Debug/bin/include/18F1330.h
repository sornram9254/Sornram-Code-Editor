//////// Standard Header file for the PIC18F1330 device ////////////////
#device PIC18F1330
#nolist
//////// Program memory: 4096x16  Data RAM: 256  Stack: 31
//////// I/O: 16   Analog Pins: 4
//////// Data EEPROM: 128
//////// C Scratch area: 00   ID Location: 200000
//////// Fuses: LP,XT,HS,RC,EC,EC_IO,H4,RC_IO,INTRC_IO,INTRC,NOFCMEN,FCMEN
//////// Fuses: NOIESO,IESO,PUT,NOPUT,NOBROWNOUT,BROWNOUT_SW,BROWNOUT_NOSL
//////// Fuses: BROWNOUT,BORV45,BORV43,BORV27,BORV21,NOWDT,WDT,WDT1,WDT2
//////// Fuses: WDT4,WDT8,WDT16,WDT32,WDT64,WDT128,WDT256,WDT512,WDT1024
//////// Fuses: WDT2048,WDT4096,WDT8192,WDT16384,WDT32768,PWMPIN,NOPWMPIN
//////// Fuses: LPOL_LOW,LPOL_HIGH,HPOL_LOW,HPOL_HIGH,FLTAA7,FLTAA5,T1OSCB2
//////// Fuses: T1OSCA6,NOMCLR,MCLR,NOSTVREN,STVREN,BBSIZ256,BBSIZ512
//////// Fuses: BBSIZ1K,NOXINST,XINST,DEBUG,NODEBUG,PROTECT,NOPROTECT,CPB
//////// Fuses: NOCPB,CPD,NOCPD,WRT1_50%,WRT,NOWRT,WRTC,NOWRTC,WRTB,NOWRTB
//////// Fuses: WRTD,NOWRTD,EBTR,NOEBTR,EBTRB,NOEBTRB
//////// 
////////////////////////////////////////////////////////////////// I/O
// Discrete I/O Functions: SET_TRIS_x(), OUTPUT_x(), INPUT_x(),
//                         PORT_x_PULLUPS(), INPUT(),
//                         OUTPUT_LOW(), OUTPUT_HIGH(),
//                         OUTPUT_FLOAT(), OUTPUT_BIT()
// Constants used to identify pins in the above are:

#define PIN_A0  31744
#define PIN_A1  31745
#define PIN_A2  31746
#define PIN_A3  31747
#define PIN_A4  31748
#define PIN_A5  31749
#define PIN_A6  31750
#define PIN_A7  31751

#define PIN_B0  31752
#define PIN_B1  31753
#define PIN_B2  31754
#define PIN_B3  31755
#define PIN_B4  31756
#define PIN_B5  31757
#define PIN_B6  31758
#define PIN_B7  31759

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
#define WDT_TIMEOUT       7    
#define MCLR_FROM_SLEEP  11    
#define MCLR_FROM_RUN    15    
#define NORMAL_POWER_UP  12    
#define BROWNOUT_RESTART 14    
#define WDT_FROM_SLEEP    3    
#define RESET_INSTRUCTION 0    

// Constants for calls to sleep() are:
#define SLEEP_FULL       0  // Default
#define SLEEP_IDLE       1  // Clock and peripherals don't stop

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

#define T0_OFF        0x80  

#define T0_8_BIT      0x40  

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
#define RTCC_OFF        0x80  
#define RTCC_8_BIT      0x40  

// Constants used for SETUP_COUNTERS() are the above
// constants for the 1st param and the following for
// the 2nd param:

////////////////////////////////////////////////////////////////// WDT
// Watch Dog Timer Functions: SETUP_WDT() or SETUP_COUNTERS() (see above)
//                            RESTART_WDT()
// WDT base is 4ms
//
#define WDT_ON        0x100
#define WDT_OFF       0

////////////////////////////////////////////////////////////////// Timer 1
// Timer 1 Functions: SETUP_TIMER_1, GET_TIMER1, SET_TIMER1
// Constants used for SETUP_TIMER_1() are:
//      (or (via |) together constants from each group)
#define T1_DISABLED         0
#define T1_INTERNAL         0x85
#define T1_EXTERNAL         0x87
#define T1_EXTERNAL_SYNC    0x83

#define T1_CLK_OUT          8

#define T1_DIV_BY_1         0
#define T1_DIV_BY_2         0x10
#define T1_DIV_BY_4         0x20
#define T1_DIV_BY_8         0x30

////////////////////////////////////////////////////////////////// UART
// Constants used in setup_uart() are:
// FALSE - Turn UART off
// TRUE  - Turn UART on
#define UART_ADDRESS           2
#define UART_DATA              4
#define UART_AUTODETECT        8
#define UART_AUTODETECT_NOWAIT 9
#define UART_WAKEUP_ON_RDA     10
#define UART_SEND_BREAK        13
////////////////////////////////////////////////////////////////// COMP
// Comparator Variables: C1OUT, C2OUT, C3OUT
// Constants used in setup_comparator() are:
//
#define NC_NC_NC   0x00
//or any of the following
#define CP1_A0_VREF 0x21
#define CP2_B3_VREF 0x42
#define CP1_B2_VREF 0x84
#define CP1_INVERT 0x01
#define CP2_INVERT 0x02
#define CP3_INVERT 0x04

#bit C1OUT = 0xFB4.5
#bit C2OUT = 0xFB4.6
#bit C3OUT = 0xFB4.7

////////////////////////////////////////////////////////////////// VREF
// Constants used in setup_vref() are:
//
#define VREF_LOW  0xa0
#define VREF_HIGH 0x80
// Or (with |) the above with a number 0-15
#define VREF_F5   0x40
#define VREF_COMP 0x10

////////////////////////////////////////////////////////////////// VREF
// Constants used in setup_low_volt_detect() are:
//
#define LVD_LVDIN   0x1F
#define LVD_45 0x1E
#define LVD_42 0x1D
#define LVD_40 0x1C
#define LVD_38 0x1B
#define LVD_36 0x1A
#define LVD_35 0x19
#define LVD_33 0x18
#define LVD_30 0x17
#define LVD_28 0x16
#define LVD_27 0x15
#define LVD_25 0x14
#define LVD_24 0x13
#define LVD_23 0x12
#define LVD_22 0x11
#define LVD_21 0x10


////////////////////////////////////////////////////////////////// INTERNAL RC
// Constants used in setup_oscillator() are:
// First param:
#define OSC_31KHZ   0
#define OSC_125KHZ  0x10
#define OSC_250KHZ  0x20
#define OSC_500KHZ  0x30
#define OSC_1MHZ    0x40
#define OSC_2MHZ    0x50
#define OSC_4MHZ    0x60
#define OSC_8MHZ    0x70
#define OSC_16MHZ   0x4060
#define OSC_32MHZ   0x4070
// The following may be OR'ed in with the above using |
#define OSC_TIMER1  1
#define OSC_INTRC   2
#define OSC_NORMAL  0
// The following may be OR'ed in with the above using |
#define OSC_IDLE_MODE  0x80
#define OSC_31250   0x8000
#define OSC_PLL_ON  0x4000
#define OSC_PLL_OFF 0
// A second optional parameter may be used with this part to fine
// tune the speed (signed int,0-31)
// Result may be (ignore all other bits)
#define OSC_STATE_STABLE 4
#define OSC_STATE_EXT_RUNNING 8

////////////////////////////////////////////////////////////////// POWER PWM
// CCP Functions: SETUP_POWER_PWM(), SET_POWER_PWMx_DUTY(), 
//                SETUP_POWER_PWM_PINS(), SETUP_POWER_PWM_FAULTS()
// Constants used for SETUP_POWER_PWM() are:
#define PWM_CLOCK_DIV_4   0x00
#define PWM_CLOCK_DIV_16  0x04
#define PWM_CLOCK_DIV_64  0x08
#define PWM_CLOCK_DIV_128 0x0C

#define PWM_OFF           0x0000
#define PWM_FREE_RUN      0x8000
#define PWM_SINGLE_SHOT   0x8001
#define PWM_UP_DOWN       0x8002
#define PWM_UP_DOWN_INT   0x8003

#define PWM_OVERRIDE_SYNC  0x10000

#define PWM_UP_TRIGGER     0x00000
#define PWM_DOWN_TRIGGER   0x80000

#define PWM_DEAD_CLOCK_DIV_2  0x000000
#define PWM_DEAD_CLOCK_DIV_4  0x100000
#define PWM_DEAD_CLOCK_DIV_8  0x200000
#define PWM_DEAD_CLOCK_DIV_16 0x300000

// Constants used for SET_POWER_PWMx_DUTY() are:
#define PWM_UPDATE_DISABLE 0x20000
#define PWM_UPDATE_ENABLE  0x00000

// Constants used for SETUP_POWER_PWM_PINS() are:
//#define PWM_OFF         0
#define PWM_ODD_ON        1
#define PWM_BOTH_ON       2
#define PWM_COMPLEMENTARY 3

// Constants used for SETUP_POWER_PWM_FAULTS() are:
#define PWM_ENABLE_FLTA          0x01
#define PWM_AUTO_CLEAR_FLTA      0x02
#define PWM_FAULT_ON_BREAKPOINT  0x80

#bit FLTA=getenv("BIT:FLTAS")


////////////////////////////////////////////////////////////////// ADC
// ADC Functions: SETUP_ADC(), SETUP_ADC_PORTS() (aka SETUP_PORT_A),
//                SET_ADC_CHANNEL(), READ_ADC()
// Constants used for SETUP_ADC() are:
#define ADC_OFF               0           // ADC Off
#define ADC_CLOCK_DIV_2   0x100
#define ADC_CLOCK_DIV_4    0x04
#define ADC_CLOCK_DIV_8    0x01
#define ADC_CLOCK_DIV_16   0x05
#define ADC_CLOCK_DIV_32   0x02
#define ADC_CLOCK_DIV_64   0x06
#define ADC_CLOCK_INTERNAL 0x07           // Internal 2-6us
// The following may be OR'ed in with the above using |
#define ADC_TAD_MUL_0      0x00
#define ADC_TAD_MUL_2      0x08
#define ADC_TAD_MUL_4      0x10
#define ADC_TAD_MUL_6      0x18
#define ADC_TAD_MUL_8      0x20
#define ADC_TAD_MUL_12     0x28
#define ADC_TAD_MUL_16     0x30
#define ADC_TAD_MUL_20     0x38

// Constants used in SETUP_ADC_PORTS() are:
// First argument:
#define ALL_ANALOG   0x0        // A0 A1 A4 A6
#define AN1_AN2_AN3     1       // A1 A4 A6
#define AN0_AN2_AN3     2       // A0 A4 A6
#define AN2_AN3         3       // A4 A6
#define AN0_AN1_AN3     4       // A0 A1 A6 
#define AN1_AN3         5       // A1 A6 
#define AN0_AN3         6       // A0 A6
#define AN3             7       // A6
#define AN0_AN1_AN2     8       // A0 A1 A4 
#define AN1_AN2         9       // A1 A4
#define AN0_AN2         0xa     // A0 A4 
#define AN2             0xb     // A4 
#define AN0_AN1         0xc     // A0 A1
#define AN1             0xd     // A1
#define AN0             0xe     // A0
#define NO_ANALOGS      0xf     // None

// Optional Second argument:
#define VSS_VDD              0x00        //| Range 0-Vdd
#define VSS_VREF             0x10        //| Range 0-Vref

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
#define GLOBAL                    0xF2C0
#define PERIPH                    0xF240
#define INT_RTCC                  0x00F220
#define INT_TIMER0                0x00F220
#define INT_TIMER1                0x009D01
#define INT_EXT_L2H               0x5000F210
#define INT_EXT_H2L               0x6000F210
#define INT_EXT                   0x00F210
#define INT_EXT1_L2H              0x5001F008
#define INT_EXT1_H2L              0x6001F008
#define INT_EXT1                  0x00F008
#define INT_EXT2_L2H              0x5002F010
#define INT_EXT2_H2L              0x6002F010
#define INT_EXT2                  0x00F010
#define INT_EXT3_L2H              0x5003F020
#define INT_EXT3_H2L              0x6003F020
#define INT_EXT3                  0x00F020
#define INT_RB                    0x00FFF208
#define INT_AD                    0x009D40
#define INT_RDA                   0x009D20
#define INT_TBE                   0x009D10
#define INT_LOWVOLT               0x00A004
#define INT_EEPROM                0x00A010
#define INT_OSCF                  0x00A080
#define INT_PWMTB                 0x00A310
#define INT_COMP0                 0x009D02
#define INT_COMP1                 0x009D04
#define INT_COMP2                 0x009D08

#list
