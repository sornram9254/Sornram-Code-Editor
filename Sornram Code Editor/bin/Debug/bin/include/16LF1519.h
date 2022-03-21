//////// Standard Header file for the PIC16LF1519 device ////////////////
#device PIC16LF1519
#nolist
//////// Program memory: 16384x14  Data RAM: 1008  Stack: 16
//////// I/O: 54   Analog Pins: 28
//////// C Scratch area: 77   ID Location: 8000
//////// Fuses: LP,XT,HS,RC,INTRC_IO,ECL,ECM,ECH,NOWDT,WDT_SW,WDT_NOSL,WDT
//////// Fuses: PUT,NOPUT,NOMCLR,MCLR,PROTECT,NOPROTECT,NOBROWNOUT
//////// Fuses: BROWNOUT_SW,BROWNOUT_NOSL,BROWNOUT,CLKOUT,NOCLKOUT,NOIESO
//////// Fuses: IESO,NOFCMEN,FCMEN,WRT,WRT_2000,WRT_200,NOWRT,VCAP,NOVCAP
//////// Fuses: NOSTVREN,STVREN,BORV25,BORV19,LPBOR,NOLPBOR,DEBUG,NODEBUG
//////// Fuses: NOLVP,LVP
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

#define PIN_D0  120
#define PIN_D1  121
#define PIN_D2  122
#define PIN_D3  123
#define PIN_D4  124
#define PIN_D5  125
#define PIN_D6  126
#define PIN_D7  127

#define PIN_E0  128
#define PIN_E1  129
#define PIN_E2  130
#define PIN_E3  131
#define PIN_E4  132
#define PIN_E5  133
#define PIN_E6  134
#define PIN_E7  135

#define PIN_F0  5216
#define PIN_F1  5217
#define PIN_F2  5218
#define PIN_F3  5219
#define PIN_F4  5220
#define PIN_F5  5221
#define PIN_F6  5222
#define PIN_F7  5223

#define PIN_G0  5224
#define PIN_G1  5225
#define PIN_G2  5226
#define PIN_G3  5227
#define PIN_G4  5228
#define PIN_G5  5229

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

#define SPI_SS_A5             0x000
#define SPI_SS_A0             0x10000

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
////////////////////////////////////////////////////////////////// VREF
// Constants used in setup_vref() are:
//
#define VREF_OFF                        0
#define VREF_1v024                      0x81
#define VREF_2v048                      0x82
#define VREF_4v096                      0x83
// The following may be OR'ed in with the above using |
#define TEMPERATURE_INDICATOR_DISABLED  0
#define TEMPERATURE_INDICATOR_ENABLED   0x20
#define TEMPERATURE_RANGE_LOW           0
#define TEMPERATURE_RANGE_HIGH          0x10


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
#define OSC_SOSC    1
#define OSC_INTRC   2
#define OSC_NORMAL  0


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

// Constants used in SETUP_ADC_PORTS() are:
// First argument:
// OR together desired pins
#define sAN0         0x00800000       //| A0
#define sAN1         0x01000000       //| A1
#define sAN2         0x02000000       //| A2
#define sAN3         0x04000000       //| A3
#define sAN4         0x08000000       //| A5
#define sAN5         0x00100000       //| E0  
#define sAN6         0x00200000       //| E1  
#define sAN7         0x00400000       //| E2  
#define sAN8         0x00010000       //| B2
#define sAN9         0x00020000       //| B3
#define sAN10        0x00008000       //| B1
#define sAN11        0x00040000       //| B4
#define sAN12        0x00004000       //| B0
#define sAN13        0x00080000       //| B5
#define sAN14        0x00000100       //| C2
#define sAN15        0x00000200       //| C3
#define sAN16        0x00000400       //| C4
#define sAN17        0x00000800       //| C5
#define sAN18        0x00001000       //| C6
#define sAN19        0x00002000       //| C7
#define sAN20        0x00000001       //| D0  
#define sAN21        0x00000002       //| D1  
#define sAN22        0x00000004       //| D2  
#define sAN23        0x00000008       //| D3  
#define sAN24        0x00000010       //| D4  
#define sAN25        0x00000020       //| D5  
#define sAN26        0x00000040       //| D6  
#define sAN27        0x00000080       //| D7  
#define NO_ANALOGS            0       // None
#define ALL_ANALOG   0x0FFFFFFF       // A0 A1 A2 A3 A5 E0 E1 E2 B2 B3 B1 B4 B0 B5 C2 C3 C4 C5 C6 C6 D0 D1 D2 D3 D4 D5 D6 D7  

// Optional Second argument:
#define VSS_VDD      0x00000000       //| Range 0-Vdd
#define VSS_VREF     0x20000000       //| Range 0-VrefH
#define VSS_FVR      0x30000000       //| Range 0-Fvr

// Constants used in SET_ADC_CHANNEL() are:
// either use the channel number or one of the following
#define TEMPERATURE_INDICATOR     0x1E
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
#define INT_RB                    0x31FF0B08
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
#define INT_OSC_FAIL              0x309280
#define INT_TIMER4                0x309302
#define INT_TIMER6                0x309308
#define INT_CCP3                  0x309310
#define INT_CCP4                  0x309320
#define INT_CCP5                  0x309340
#define INT_CCP2                  0x309201
#define INT_SSP2                  0x309401
#define INT_BCL2                  0x309402
#define INT_RDA2                  0x309420
#define INT_TBE2                  0x309410
#define INT_RB0                   0x31010B08
#define INT_RB0_L2H               0x11010B08
#define INT_RB0_H2L               0x21010B08
#define INT_RB1                   0x31020B08
#define INT_RB1_L2H               0x11020B08
#define INT_RB1_H2L               0x21020B08
#define INT_RB2                   0x31040B08
#define INT_RB2_L2H               0x11040B08
#define INT_RB2_H2L               0x21040B08
#define INT_RB3                   0x31080B08
#define INT_RB3_L2H               0x11080B08
#define INT_RB3_H2L               0x21080B08
#define INT_RB4                   0x31100B08
#define INT_RB4_L2H               0x11100B08
#define INT_RB4_H2L               0x21100B08
#define INT_RB5                   0x31200B08
#define INT_RB5_L2H               0x11200B08
#define INT_RB5_H2L               0x21200B08
#define INT_RB6                   0x31400B08
#define INT_RB6_L2H               0x11400B08
#define INT_RB6_H2L               0x21400B08
#define INT_RB7                   0x31800B08
#define INT_RB7_L2H               0x11800B08
#define INT_RB7_H2L               0x21800B08

#list
