//////// Standard Header file for the PIC16LF1782 device ////////////////
#device PIC16LF1782
#nolist
//////// Program memory: 2048x14  Data RAM: 240  Stack: 16
//////// I/O: 25   Analog Pins: 11
//////// Data EEPROM: 256
//////// C Scratch area: 77   ID Location: 8000
//////// Fuses: LP,XT,HS,RC,INTRC_IO,ECL,ECM,ECH,NOWDT,WDT_SW,WDT_NOSL,WDT
//////// Fuses: PUT,NOPUT,NOMCLR,MCLR,PROTECT,NOPROTECT,CPD,NOCPD,NOBROWNOUT
//////// Fuses: BROWNOUT_SW,BROWNOUT_NOSL,BROWNOUT,CLKOUT,NOCLKOUT,NOIESO
//////// Fuses: IESO,NOFCMEN,FCMEN,WRT,WRT_400,WRT_200,NOWRT,VCAP,NOVCAP
//////// Fuses: PLL_SW,PLL,NOSTVREN,STVREN,BORV25,BORV19,LPBOR,NOLPBOR,DEBUG
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
#define PIN_A2  98
#define PIN_A3  99
#define PIN_A4  100
#define PIN_A5  101
#define PIN_A6  102
#define PIN_A7  103

#define PIN_B0  104
#define PIN_B1  105
#define PIN_B2  106
#define PIN_B3  107
#define PIN_B4  108
#define PIN_B5  109
#define PIN_B6  110
#define PIN_B7  111

#define PIN_C0  112
#define PIN_C1  113
#define PIN_C2  114
#define PIN_C3  115
#define PIN_C4  116
#define PIN_C5  117
#define PIN_C6  118
#define PIN_C7  119

#define PIN_E3  131

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
#define T1_INTERNAL         0x07
#define T1_EXTERNAL         0x87
#define T1_EXTERNAL_SYNC    0x83
#define T1_FOSC             0x47

#define T1_ENABLE_SOSC		0x08

#define T1_DIV_BY_1         0
#define T1_DIV_BY_2         0x10
#define T1_DIV_BY_4         0x20
#define T1_DIV_BY_8         0x30

#define T1_GATE           0x8000
#define T1_GATE_INVERTED  0xC000
#define T1_GATE_TOGGLE    0xA000
#define T1_GATE_SINGLE    0x9000
#define T1_GATE_TIMER2    0x8100
#define T1_GATE_COMP1     0x8200
#define T1_GATE_COMP2     0x8300

////////////////////////////////////////////////////////////////// Timer 2
// Timer 2 Functions: SETUP_TIMER_2, GET_TIMER2, SET_TIMER2
// Constants used for SETUP_TIMER_2() are:
#define T2_DISABLED         0
#define T2_DIV_BY_1         4
#define T2_DIV_BY_4         5
#define T2_DIV_BY_16        6
#define T2_DIV_BY_64        7 

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
#define CCP1_C2             0x000
#define CCP1_B0             0x100
#define CCP2_C1             0x000
#define CCP2_B3             0x100

#word   CCP_2       =                   getenv("SFR:CCPR2L")
#byte   CCP_2_LOW   =                   getenv("SFR:CCPR2L")
#byte   CCP_2_HIGH  =                   getenv("SFR:CCPR2H")
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

#define SPI_DI_C4             0x00000
#define SPI_DI_B6             0x10000
#define SPI_SCK_C3            0x00000
#define SPI_SCK_B7            0x20000
#define SPI_DO_C5             0x00000
#define SPI_DO_B5             0x40000

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
// Comparator Variables: C1OUT, C2OUT, C3OUT
// Constants used in setup_comparator_x() are:
//
#define NC_NC           0x003F

// Constants used in setup_comparator_1() are:
// Pick one of the following
#define CP1_A0_A2       0x8000
#define CP1_A1_A2       0x8001
#define CP1_B3_A2       0x8002
#define CP1_B1_A2       0x8003
#define CP1_VSS_A2      0x8007
#define CP1_A0_A3       0x8008
#define CP1_A1_A3       0x8009
#define CP1_B3_A3       0x800A
#define CP1_B1_A3       0x800B
#define CP1_VSS_A3      0x800F
#define CP1_A0_DAC      0x8028
#define CP1_A1_DAC      0x8029
#define CP1_B3_DAC      0x802A
#define CP1_B1_DAC      0x802B
#define CP1_VSS_DAC     0x802F
#define CP1_A0_FVR      0x8030
#define CP1_A1_FVR      0x8031
#define CP1_B3_FVR      0x8032
#define CP1_B1_FVR      0x8033
#define CP1_VSS_FVR     0x8037
#define CP1_A0_VSS      0x8038
#define CP1_A1_VSS      0x8039
#define CP1_B3_VSS      0x803A
#define CP1_B1_VSS      0x803B
#define CP1_VSS_VSS     0x803F
//Optionally OR any of the following with the above
#define CP1_INT_L2H     0x0080
#define CP1_INT_H2L     0x0040
#define CP1_OUT_ON_A4   0x2000
#define CP1_INVERT      0x1000
#define CP1_FAST        0x0400
#define CP1_HYST        0x0200
#define CP1_SYNC        0x0100

// Constants used in setup_comparator_2() are:
// Pick one of the following
#define CP2_A0_A2       0x8000
#define CP2_A1_A2       0x8001
#define CP2_B3_A2       0x8002
#define CP2_B1_A2       0x8003
#define CP2_VSS_A2      0x8007
#define CP2_A0_B0       0x8008
#define CP2_A1_B0       0x8009
#define CP2_B3_B0       0x800A
#define CP2_B1_B0       0x800B
#define CP2_VSS_B0      0x800F
#define CP2_A0_DAC      0x8028
#define CP2_A1_DAC      0x8029
#define CP2_B3_DAC      0x802A
#define CP2_B1_DAC      0x802B
#define CP2_VSS_DAC     0x802F
#define CP2_A0_FVR      0x8030
#define CP2_A1_FVR      0x8031
#define CP2_B3_FVR      0x8032
#define CP2_B1_FVR      0x8033
#define CP2_VSS_FVR     0x8037
#define CP2_A0_VSS      0x8038
#define CP2_A1_VSS      0x8039
#define CP2_B3_VSS      0x803A
#define CP2_B1_VSS      0x803B
#define CP2_VSS_VSS     0x803F
//Optionally OR any of the following with the above
#define CP2_INT_L2H     0x00080
#define CP2_INT_H2L     0x00040
#define CP2_OUT_ON_A5   0x02000
#define CP2_OUT_ON_A6   0x12000
#define CP2_INVERT      0x01000
#define CP2_FAST        0x00400
#define CP2_HYST        0x00200
#define CP2_SYNC        0x00100

// Constants used in setup_comparator_3() are:
// Pick one of the following
#define CP3_A0_A2       0x8000
#define CP3_A1_A2       0x8001
#define CP3_B3_A2       0x8002
#define CP3_B1_A2       0x8003
#define CP3_VSS_A2      0x8007
#define CP3_A0_B4       0x8008
#define CP3_A1_B4       0x8009
#define CP3_B3_B4       0x800A
#define CP3_B1_B4       0x800B
#define CP3_VSS_B4      0x800F
#define CP3_A0_DAC      0x8028
#define CP3_A1_DAC      0x8029
#define CP3_B3_DAC      0x802A
#define CP3_B1_DAC      0x802B
#define CP3_VSS_DAC     0x802F
#define CP3_A0_FVR      0x8030
#define CP3_A1_FVR      0x8031
#define CP3_B3_FVR      0x8032
#define CP3_B1_FVR      0x8033
#define CP3_VSS_FVR     0x8037
#define CP3_A0_VSS      0x8038
#define CP3_A1_VSS      0x8039
#define CP3_B3_VSS      0x803A
#define CP3_B1_VSS      0x803B
#define CP3_VSS_VSS     0x803F
//Optionally OR any of the following with the above
#define CP3_INT_L2H     0x0080
#define CP3_INT_H2L     0x0040
#define CP3_OUT_ON_B5   0x2000
#define CP3_INVERT      0x1000
#define CP3_FAST        0x0400
#define CP3_HYST        0x0200
#define CP3_SYNC        0x0100

#bit C1OUT = getenv("SFR:CM1CON0").6
#bit C2OUT = getenv("SFR:CM2CON0").6
#bit C3OUT = getenv("SFR:CM3CON0").6

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
#define DAC_OFF       0
#define DAC_VSS_VDD   0x80
#define DAC_VREF_VDD  0x81  
#define DAC_VSS_VREF  0x84
#define DAC_VREF_VREF 0x85  
#define DAC_VSS_FVR   0x88  
#define DAC_FVR_VREF  0x89  
// The Following may be OR'ed in with the above using |
#define DAC_OUTPUT1   0x20	// DAC voltage level outputted on DACOUT1 pin
#define DAC_OUTPUT2   0x10  // DAC Voltage lever outputted on DACOUT2 pin

////////////////////////////////////////////////////////////////// OPAMP
// OPAMP Functions: SETUP_OPAMPx()
// Constants used in SETUP_OPAMPx() are:
#define OPAMP_ENABLED                0x80
#define OPAMP_DISABLED               0x00
#define OPAMP_HIGH_GBWP_MODE         0x40
#define OPAMP_LOW_GBWP_MODE          0x00
#define OPAMP_NI_TO_OPAIN            0x00  // Non-inverting input connects to OPAxIN+ pin
#define OPAMP_NI_TO_DAC              0x02  // Non-inverting input connects to DAC output
#define OPAMP_NI_TO_FVR              0x03  // Non-inverting input connects to FVR Buffer 2 output


////////////////////////////////////////////////////////////////// INTERNAL RC
// Constants used in setup_oscillator() are:
// First param:
#define OSC_31KHZ   0
#define OSC_31250   (2*8)
#define OSC_62KHZ   (4*8)
#define OSC_125KHZ  (5*8)
#define OSC_250KHZ  (6*8)
#define OSC_500KHZ  (7*8)
#define OSC_1MHZ    (11*8)
#define OSC_2MHZ    (12*8)
#define OSC_4MHZ    (13*8)
#define OSC_8MHZ    (14*8)
#define OSC_16MHZ   (15*8)
// The following may be OR'ed in with the above using |
#define OSC_TIMER1  1
#define OSC_INTRC   2
#define OSC_NORMAL  0
// The following may be OR'ed in with the above using |
#define OSC_PLL_ON  0x80
#define OSC_PLL_OFF 0


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
#define sAN0            0x000100  //| A0
#define sAN1            0x000200  //| A1
#define sAN2            0x000400  //| A2
#define sAN3            0x000800  //| A3
#define sAN4            0x002000  //| A5
#define sAN8            0x000004  //| B2
#define sAN9            0x000008  //| B3
#define sAN10           0x000002  //| B1
#define sAN11           0x000010  //| B4
#define sAN12           0x000001  //| B0
#define sAN13           0x000020  //| B5
#define NO_ANALOGS             0  // None
#define ALL_ANALOG      0x002F3F  // A0 A1 A2 A3 A5 B2 B3 B1 B4 B0 B5

// Optional Second argument:
#define VSS_VDD         0x000000  //| Range 0 to Vdd
#define VSS_VREF1       0x010000  //| Range 0 to Vref1+
#define VSS_VREF2       0x020000  //| Range 0 to Vref2+
#define VSS_FVR         0x030000  //| Range 0 to Fvr
#define VREF_VDD        0x040000  //| Range Vref- to Vdd
#define VREF_VREF1      0x050000  //| Range Vref- to Vref1+
#define VREF_VREF2      0x060000  //| Range Vref- to Vref2+
#define VREF_FVR        0x070000  //| Range Vref- to Fvr

// Constants used for first parameter of SET_ADC_CHANNEL() are:
// either use the channel number or one of the following
#define TEMPERATURE_INDICATOR     0x1D
#define DAC_CHANNEL               0x1E
#define FVR_CHANNEL               0x1F
// Constants used for second parameter of SET_ADC_CHANNEL() are:
// either use the channel number or the following
#define ADC_NEG_REFERENCE         0xFF  // Analog Negative Channel connected to ADC Negative Reference

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
#define INT_CCP1                  0x309104
#define INT_SSP                   0x309108
#define INT_TBE                   0x309110
#define INT_RDA                   0x309120
#define INT_AD                    0x309140
#define INT_TIMER1_GATE            0x309180
#define INT_BUSCOL                0x309208
#define INT_EEPROM                0x309210
#define INT_COMP                  0x309220
#define INT_COMP2                 0x309240
#define INT_OSC_FAIL              0x309280
#define INT_CCP2                  0x309201
#define INT_IOC                   0x3FFF0B08
#define INT_COMP3                 0x309202
#define INT_PSMC1S                0x309401
#define INT_PSMC2S                0x309402
#define INT_PSMC1T                0x309410
#define INT_PSMC2T                0x309420
#define INT_IOC_A0                   0x30010B08
#define INT_IOC_A0_L2H               0x10010B08
#define INT_IOC_A0_H2L               0x20010B08
#define INT_IOC_A1                   0x30020B08
#define INT_IOC_A1_L2H               0x10020B08
#define INT_IOC_A1_H2L               0x20020B08
#define INT_IOC_A2                   0x30040B08
#define INT_IOC_A2_L2H               0x10040B08
#define INT_IOC_A2_H2L               0x20040B08
#define INT_IOC_A3                   0x30080B08
#define INT_IOC_A3_L2H               0x10080B08
#define INT_IOC_A3_H2L               0x20080B08
#define INT_IOC_A4                   0x30100B08
#define INT_IOC_A4_L2H               0x10100B08
#define INT_IOC_A4_H2L               0x20100B08
#define INT_IOC_A5                   0x30200B08
#define INT_IOC_A5_L2H               0x10200B08
#define INT_IOC_A5_H2L               0x20200B08
#define INT_IOC_A6                   0x30400B08
#define INT_IOC_A6_L2H               0x10400B08
#define INT_IOC_A6_H2L               0x20400B08
#define INT_IOC_A7                   0x30800B08
#define INT_IOC_A7_L2H               0x10800B08
#define INT_IOC_A7_H2L               0x20800B08
#define INT_IOC_B0                   0x31010B08
#define INT_IOC_B0_L2H               0x11010B08
#define INT_IOC_B0_H2L               0x21010B08
#define INT_IOC_B1                   0x31020B08
#define INT_IOC_B1_L2H               0x11020B08
#define INT_IOC_B1_H2L               0x21020B08
#define INT_IOC_B2                   0x31040B08
#define INT_IOC_B2_L2H               0x11040B08
#define INT_IOC_B2_H2L               0x21040B08
#define INT_IOC_B3                   0x31080B08
#define INT_IOC_B3_L2H               0x11080B08
#define INT_IOC_B3_H2L               0x21080B08
#define INT_IOC_B4                   0x31100B08
#define INT_IOC_B4_L2H               0x11100B08
#define INT_IOC_B4_H2L               0x21100B08
#define INT_IOC_B5                   0x31200B08
#define INT_IOC_B5_L2H               0x11200B08
#define INT_IOC_B5_H2L               0x21200B08
#define INT_IOC_B6                   0x31400B08
#define INT_IOC_B6_L2H               0x11400B08
#define INT_IOC_B6_H2L               0x21400B08
#define INT_IOC_B7                   0x31800B08
#define INT_IOC_B7_L2H               0x11800B08
#define INT_IOC_B7_H2L               0x21800B08
#define INT_IOC_C0                   0x32010B08
#define INT_IOC_C0_L2H               0x12010B08
#define INT_IOC_C0_H2L               0x22010B08
#define INT_IOC_C1                   0x32020B08
#define INT_IOC_C1_L2H               0x12020B08
#define INT_IOC_C1_H2L               0x22020B08
#define INT_IOC_C2                   0x32040B08
#define INT_IOC_C2_L2H               0x12040B08
#define INT_IOC_C2_H2L               0x22040B08
#define INT_IOC_C3                   0x32080B08
#define INT_IOC_C3_L2H               0x12080B08
#define INT_IOC_C3_H2L               0x22080B08
#define INT_IOC_C4                   0x32100B08
#define INT_IOC_C4_L2H               0x12100B08
#define INT_IOC_C4_H2L               0x22100B08
#define INT_IOC_C5                   0x32200B08
#define INT_IOC_C5_L2H               0x12200B08
#define INT_IOC_C5_H2L               0x22200B08
#define INT_IOC_C6                   0x32400B08
#define INT_IOC_C6_L2H               0x12400B08
#define INT_IOC_C6_H2L               0x22400B08
#define INT_IOC_C7                   0x32800B08
#define INT_IOC_C7_L2H               0x12800B08
#define INT_IOC_C7_H2L               0x22800B08
#define INT_IOC_E3                   0x34080B08
#define INT_IOC_E3_L2H               0x14080B08
#define INT_IOC_E3_H2L               0x24080B08

#list
