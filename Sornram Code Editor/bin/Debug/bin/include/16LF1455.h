//////// Standard Header file for the PIC16LF1455 device ////////////////
#device PIC16LF1455
#nolist
//////// Program memory: 8192x14  Data RAM: 1008  Stack: 16
//////// I/O: 11   Analog Pins: 5
//////// C Scratch area: 77   ID Location: 8000
//////// Fuses: LP,XT,HS,RC,INTRC_IO,ECL,ECM,ECH,NOWDT,WDT_SW,WDT_NOSL,WDT
//////// Fuses: PUT,NOPUT,NOMCLR,MCLR,PROTECT,NOPROTECT,NOBROWNOUT
//////// Fuses: BROWNOUT_SW,BROWNOUT_NOSL,BROWNOUT,CLKOUT,NOCLKOUT,NOIESO
//////// Fuses: IESO,NOFCMEN,FCMEN,WRT,WRT_1000,WRT_200,NOWRT,NOCPUDIV
//////// Fuses: CPUDIV2,CPUDIV3,CPUDIV6,LS24MHZ,LS48MHZ,PLL4X,PLL3X,NOPLLEN
//////// Fuses: PLLEN,NOSTVREN,STVREN,BORV25,BORV19,LPBOR,NOLPBOR,DEBUG
//////// Fuses: NODEBUG,NOLVP,LVP
//////// 
////////////////////////////////////////////////////////////////// I/O
// Discrete I/O Functions: SET_TRIS_x(), OUTPUT_x(), INPUT_x(),
//                         PORT_x_PULLUPS(), INPUT(),
//                         OUTPUT_LOW(), OUTPUT_HIGH(),
//                         OUTPUT_FLOAT(), OUTPUT_BIT()
// Constants used to identify pins in the above are:

#define PIN_A0  96
#define PIN_A1  97
#define PIN_A3  99
#define PIN_A4  100
#define PIN_A5  101

#define PIN_C0  112
#define PIN_C1  113
#define PIN_C2  114
#define PIN_C3  115
#define PIN_C4  116
#define PIN_C5  117

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
#define NORMAL_POWER_UP      0x3C
#define BROWNOUT_RESTART     0x3E
#define MCLR_FROM_SLEEP      0x27
#define WDT_TIMEOUT          0x1F
#define WDT_FROM_SLEEP       0x0F
#define INTERRUPT_FROM_SLEEP 0x2F
#define MCLR_FROM_RUN        0x37
#define RESET_INSTRUCTION    0x3B
#define STACK_OVERFLOW       0xBF
#define STACK_UNDERFLOW      0x7F

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
// Watch Dog Timer Functions: SETUP_WDT(), RESTART_WDT()
// WDT base is 1ms
//
#define WDT_ON      0x1000
#define WDT_OFF     0x2000

#define WDT_1MS     0x100
#define WDT_2MS     0x101
#define WDT_4MS     0x102
#define WDT_8MS     0x103
#define WDT_16MS    0x104
#define WDT_32MS    0x105
#define WDT_64MS    0x106
#define WDT_128MS   0x107
#define WDT_256MS   0x108
#define WDT_512MS   0x109
#define WDT_1S      0x10A
#define WDT_2S      0x10B
#define WDT_4S      0x10C
#define WDT_8S      0x10D
#define WDT_16S     0x10E
#define WDT_32S     0x10F
#define WDT_64S     0x110
#define WDT_128S    0x111
#define WDT_256S    0x112

////////////////////////////////////////////////////////////////// Timer 1
// Timer 1 Functions: SETUP_TIMER_1, GET_TIMER1, SET_TIMER1
// Constants used for SETUP_TIMER_1() are:
//      (or (via |) together constants from each group)
#define T1_DISABLED         0
#define T1_CAPSENSE         0xC5
#define T1_EXTERNAL         0x85
#define T1_EXTERNAL_SYNC    0x81
#define T1_FOSC             0x45
#define T1_INTERNAL         0x05

#define T1_ENABLE_T1OSC	    0x08

#define T1_DIV_BY_1         0x00
#define T1_DIV_BY_2         0x10
#define T1_DIV_BY_4         0x20
#define T1_DIV_BY_8         0x30

#define T1_GATE           0x8000
#define T1_GATE_INVERTED  0xC000
#define T1_GATE_TOGGLE    0xA000
#define T1_GATE_SINGLE    0x9000
#define T1_GATE_TIMER0    0x8100
#define T1_GATE_COMP1     0x8200 
#define T1_GATE_COMP2     0x8300  

#define T1_GATE_A4          0
#define T1_GATE_A3          0x10000

////////////////////////////////////////////////////////////////// Timer 2
// Timer 2 Functions: SETUP_TIMER_2, GET_TIMER2, SET_TIMER2
// Constants used for SETUP_TIMER_2() are:
#define T2_DISABLED         0
#define T2_DIV_BY_1         4
#define T2_DIV_BY_4         5
#define T2_DIV_BY_16        6
#define T2_DIV_BY_64        7 

////////////////////////////////////////////////////////////////// SPI
// SPI Functions: SETUP_SPI, SPI_WRITE, SPI_READ, SPI_DATA_IN
// Constants used in SETUP_SPI() are:
#define SPI_DISABLED             0x00
#define SPI_MASTER               0x20
#define SPI_SLAVE                0x24
#define SPI_SCK_IDLE_HIGH        0x10
#define SPI_SCK_IDLE_LOW         0x00
#define SPI_CLK_DIV_4            0x00
#define SPI_CLK_DIV_16           0x01
#define SPI_CLK_DIV_64           0x02
#define SPI_CLK_T2               0x03
#define SPI_SS_DISABLED          0x01

#define SPI_SS_C3             0x00000  
#define SPI_SS_A3             0x10000
#define SPI_DO_C2             0x00000  
#define SPI_D0_A4             0x20000  

#define SPI_XMIT_L_TO_H          0x4000
#define SPI_XMIT_H_TO_L          0x0000

#define SPI_SAMPLE_AT_MIDDLE     0x0000
#define SPI_SAMPLE_AT_END        0x8000

//The following are provided for compatibility
#define SPI_L_TO_H       SPI_SCK_IDLE_LOW
#define SPI_H_TO_L       SPI_SCK_IDLE_HIGH

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
// Comparator Variables: C1OUT, C2OUT
// Constants used in setup_comparator() are:
//
#define NC_NC_NC_NC     0x00300030

//Pick one constant for COMP1
#define CP1_C1_C0       0x8001
#define CP1_C2_C0       0x8002
#define CP1_C3_C0       0x8003
#define CP1_FVR_C0      0x8004
#define CP1_C1_DAC      0x8011
#define CP1_C2_DAC      0x8012
#define CP1_C3_DAC      0x8013
#define CP1_FVR_DAC     0x8014
#define CP1_C1_FVR      0x8021
#define CP1_C2_FVR      0x8022
#define CP1_C3_FVR      0x8023
#define CP1_FVR_FVR     0x8024
#define CP1_C1_VSS      0x8031
#define CP1_C2_VSS      0x8032
#define CP1_C3_VSS      0x8033
#define CP1_FVR_VSS     0x8034
//Optionaly OR any of the following with the above
#define CP1_INT_L2H     0x0080
#define CP1_INT_H2L     0x0040
#define CP1_OUT_ON_C4   0x2000
#define CP1_INVERT      0x1000
#define CP1_FAST        0x0400
#define CP1_HYST        0x0200
#define CP1_SYNC        0x0100

//Pick one constant for COMP2
#define CP2_C1_C0       0x80010000
#define CP2_C2_C0       0x80020000
#define CP2_C3_C0       0x80030000
#define CP2_FVR_C0      0x80040000
#define CP2_C1_DAC      0x80110000
#define CP2_C2_DAC      0x80120000
#define CP2_C3_DAC      0x80130000
#define CP2_FVR_DAC     0x80140000
#define CP2_C1_FVR      0x80210000
#define CP2_C2_FVR      0x80220000
#define CP2_C3_FVR      0x80230000
#define CP2_FVR_FVR     0x80240000
#define CP2_C1_VSS      0x80310000
#define CP2_C2_VSS      0x80320000
#define CP2_C3_VSS      0x80330000
#define CP2_FVR_VSS     0x80340000
//Optionaly OR any of the following with the above
#define CP2_INT_L2H     0x00800000
#define CP2_INT_H2L     0x00400000
#define CP2_OUT_ON_C4   0x20000000
#define CP2_INVERT      0x10000000
#define CP2_FAST        0x04000000
#define CP2_HYST        0x02000000
#define CP2_SYNC        0x01000000

#bit C1OUT = getenv("SFR:CM1CON0").6
#bit C2OUT = getenv("SFR:CM2CON0").6

////////////////////////////////////////////////////////////////// VREF
// Constants used in setup_vref() are:
//
#define VREF_OFF                        0
#define VREF_ON                         0x80
// The following may be OR'ed in with the above using |
#define VREF_ADC_OFF                    0
#define VREF_ADC_1v024                  0x01
#define VREF_ADC_2v048                  0x02
#define VREF_ADC_4v096                  0x03
// The following may be OR'ed in with the above using |
#define VREF_COMP_DAC_OFF               0
#define VREF_COMP_DAC_1v024             0x04
#define VREF_COMP_DAC_2v048             0x08
#define VREF_COMP_DAC_4v096             0x0C
// The following may be OR'ed in with the above using |
#define TEMPERATURE_INDICATOR_DISABLED  0
#define TEMPERATURE_INDICATOR_ENABLED   0x20
#define TEMPERATURE_RANGE_LOW           0
#define TEMPERATURE_RANGE_HIGH          0x10

////////////////////////////////////////////////////////////////// DAC
// Digital to Analog Functions: SETUP_DAC(), DAC_WRITE()
// Constants used in SETUP_DAC() are:
#define DAC_OFF         0
#define DAC_VDD         0x80
#define DAC_VREF        0x84
#define DAC_FVR         0x88
// The following may be OR'ed in with the above using |
#define DAC_OUTPUT1     0x20
#define DAC_OUTPUT2     0x10

////////////////////////////////////////////////////////////////// CWG
// CWG Functions: SETUP_CWG(), CWG_STATUS(), CWG_RESTART()
// Constants used in SETUP_CWG() first param are:
#define CWG_ENABLED                    0x0080
#define CWG_DISABLED                   0
#define CWG_OUTPUT_A                   0x0020
#define CWG_OUTPUT_B                   0x0040
#define CWG_A_INVERTED                 0x0008
#define CWG_B_INVERTED                 0x0010
#define CWG_CLOCK_HFINTOSC             0x0001
#define CWG_CLOCK_FOSC                 0x0000  
#define CWG_INPUT_C2OUT                0x0000  
#define CWG_INPUT_C1OUT                0x0100  
#define CWG_INPUT_PWM1                 0x0200  
#define CWG_INPUT_PWM2                 0x0300  


// Constants used in SETUP_CWG() second param are:
#define CWG_NO_AUTO_SHUTDOWN           0
#define CWG_SHUTDOWN_ON_FLT            0x0002  
#define CWG_SHUTDOWN_ON_COMP1          0x0004  
#define CWG_SHUTDONW_ON_COMP2          0x0008  
#define CWG_AUTO_RESTART               0x0040
// One of the following may be OR'ed in with the above using |
#define CWG_SHUTDOWN_A_INACTIVE_STATE  0
#define CWG_SHUTDOWN_A_TRISTATE        0x1000
#define CWG_SHUTDOWN_A_LOW             0x2000
#define CWG_SHUTDOWN_A_HIGH            0x3000
// One of the following may be OR'ed in with the above using |
#define CWG_SHUTDOWN_B_INACTIVE_STATE  0
#define CWG_SHUTDOWN_B_TRISTATE        0x4000
#define CWG_SHUTDOWN_B_LOW             0x8000
#define CWG_SHUTDOWN_B_HIGH            0xC000

// Constants returned from CWG_STATUS() are:
#define CWG_AUTO_SHUTDOWN              0x80


////////////////////////////////////////////////////////////////// INTERNAL RC
// Constants used in setup_oscillator() are:
// First param:
#define OSC_31KHZ                 0
#define OSC_31250                 0x08
#define OSC_62500                 0x10
#define OSC_125KHZ                0x20
#define OSC_250KHZ                0x24
#define OSC_500KHZ                0x28
#define OSC_1MHZ                  0x2C
#define OSC_2MHZ                  0x30
#define OSC_4MHZ                  0x34
#define OSC_8MHZ                  0x38
#define OSC_16MHZ                 0x3C
// One of the following may be OR'ed in with the above using |
#define OSC_SOSC                  1
#define OSC_INTRC                 2
#define OSC_NORMAL                0
// The following may be OR'ed in with the above using |
#define OSC_PLL_3X                0x40
#define OSC_PLL_4X                0x00
#define OSC_PLL_ON                0x80
#define OSC_PLL_OFF               0x00
// A second optional parameter may be used with this part to fine
// tune the speed (signed int,-64 to 63)
// Result may be (ignore all other bits)
#define OSC_HFINTRC_STABLE        0x01
#define OSC_LFINTRC_READY         0x02
#define OSC_HFINTRC_READY         0x10
#define OSC_RUNNING_FROM_FUSES    0x20 //Device is running from the clock defined by FOSC<2:0> of the CONFIG1 register
#define OSC_PLL_READY             0x40
#define OSC_SOSC_READY            0x80

////////////////////////////////////////////////////////////////// PWM
// PWM Functions: SETUP_PWMx, SET_PWMx_DUTY
// Constants used for SETUP_PWMx() are:
#define PWM_ENABLED      0x80
#define PWM_DISABLED     0
#define PWM_OUTPUT       0x40
#define PWM_ACTIVE_LOW   0x10
#define PWM_ACTIVE_HIGH  0

#define PWM2_C3          0  
#define PWM2_A5          0x100 

#bit PWM1OUT=getenv("BIT:PWM1OUT")
#bit PWM2OUT=getenv("BIT:PWM2OUT")


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
#define sAN3            0x00100000  //| A4
#define sAN4            0x00000100  //| C0
#define sAN5            0x00000200  //| C1
#define sAN6            0x00000400  //| C2
#define sAN7            0x00000800  //| C3
#define NO_ANALOGS               0  // None
#define ALL_ANALOG      0x00100F00  // A4 C0 C1 C2 C3 

//Optional Second argument:
#define VSS_VDD         0x00000000  //| Range 0 to Vdd
#define VSS_VREF        0x02000000  //| Range 0 to Vref+
#define VSS_FVR         0x03000000  //| Range 0 to Fvr

// Constants used for first parameter of SET_ADC_CHANNEL() are:
// either use the channel number or one of the following
#define TEMPERATURE_INDICATOR     0x1D
#define DAC_CHANNEL               0x1E
#define FVR_CHANNEL               0x1F

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
#define INT_EXT_L2H               0x50000B10
#define INT_EXT_H2L               0x60000B10
#define INT_EXT                   0x300B10
#define INT_TIMER0                0x300B20
#define INT_TIMER1                0x309101
#define INT_TIMER2                0x309102
#define INT_SSP                   0x309108
#define INT_TBE                   0x309110
#define INT_RDA                   0x309120
#define INT_AD                    0x309140
#define INT_TIMER1_GATE            0x309180
#define INT_BUSCOL                0x309208
#define INT_COMP                  0x309220
#define INT_COMP2                 0x309240
#define INT_OSC_FAIL              0x309280
#define INT_RA                    0x30FF0B08
#define INT_ACT                   0x309202
#define INT_USB                   0x309204
#define INT_RA0                   0x30010B08
#define INT_RA0_L2H               0x10010B08
#define INT_RA0_H2L               0x20010B08
#define INT_RA1                   0x30020B08
#define INT_RA1_L2H               0x10020B08
#define INT_RA1_H2L               0x20020B08
#define INT_RA3                   0x30080B08
#define INT_RA3_L2H               0x10080B08
#define INT_RA3_H2L               0x20080B08
#define INT_RA4                   0x30100B08
#define INT_RA4_L2H               0x10100B08
#define INT_RA4_H2L               0x20100B08
#define INT_RA5                   0x30200B08
#define INT_RA5_L2H               0x10200B08
#define INT_RA5_H2L               0x20200B08

#list
