//////// Standard Header file for the PIC18LF44J11 device ////////////////
#device PIC18LF44J11
#nolist
//////// Program memory: 8188x16  Data RAM: 3776  Stack: 31
//////// I/O: 34   Analog Pins: 13
//////// C Scratch area: 00   ID Location: 0000
//////// Fuses: NOWDT,WDT,NOSTVREN,STVREN,NOXINST,XINST,DEBUG,NODEBUG
//////// Fuses: PROTECT,NOPROTECT,INTRC_IO,INTRC,INTRC_PLL_IO,INTRC_PLL,HS
//////// Fuses: HSPLL,EC,ECPLL,NOT1DIG,T1DIG,LPT1OSC,NOLPT1OSC,NOFCMEN,FCMEN
//////// Fuses: NOIESO,IESO,WDT1,WDT2,WDT4,WDT8,WDT16,WDT32,WDT64,WDT128
//////// Fuses: WDT256,WDT512,WDT1024,WDT2048,WDT4096,WDT8192,WDT16384
//////// Fuses: WDT32768,DSWDTOSC_T1,DSWDTOSC_INT,RTCOSC_INT,RTCOSC_T1
//////// Fuses: NODSBOR,DSBOR,NODSWDT,DSWDT,DSWDT2,DSWDT8,DSWDT32,DSWDT128
//////// Fuses: DSWDT512,DSWDT2048,DSWDT8192,DSWDT32768,DSWDT131072
//////// Fuses: DSWDT524288,DSWDT2097152,DSWDT8388608,DSWDT33554432
//////// Fuses: DSWDT134217728,DSWDT536870912,DSWDT2147483648,NOIOL1WAY
//////// Fuses: IOL1WAY,MSSPMSK5,MSSPMSK7,NOWPFP,WPFP,WPBEG,WPEND,WPCFG
//////// Fuses: NOWPCFG,NOWPDIS,WPDIS
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

#define PIN_C0  31760
#define PIN_C1  31761
#define PIN_C2  31762
#define PIN_C3  31763
#define PIN_C4  31764
#define PIN_C5  31765
#define PIN_C6  31766
#define PIN_C7  31767

#define PIN_D0  31768
#define PIN_D1  31769
#define PIN_D2  31770
#define PIN_D3  31771
#define PIN_D4  31772
#define PIN_D5  31773
#define PIN_D6  31774
#define PIN_D7  31775

#define PIN_E0  31776
#define PIN_E1  31777
#define PIN_E2  31778

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

#define POR_FROM_DS      0x0100
#define MCLR_FROM_DS     0x0400
#define RTC_FROM_DS      0x0800
#define DSWDT_FROM_DS    0x1000
#define ULPWU_FROM_DS    0x2000
#define FAULT_FROM_DS    0x8000
#define EXT_FROM_DS      0x0200

//Constants for calls to sleep() to enable deep sleep mode are:
#define DEEP_SLEEP       3
// Any of the following may be OR'ed in with the above using |
#define WAKE_FROM_RTCC   4  // Wake-up from RTCC is enabled
#define WAKE_FROM_ULP    8  // ULPWU module is enabled in Deep Sleep

#byte DSGPR0 = getenv("SFR:DSGPR0")
#byte DSGPR1 = getenv("SFR:DSGPR1")

// Constants for calls to sleep() are:
#define REG_LOW_POWER    2
#define REG_NORMAL       0  // default

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
#define T1_INTERNAL         0x07
#define T1_EXTERNAL         0x87
#define T1_EXTERNAL_SYNC    0x83
#define T1_FOSC             0x47

#define T1_ENABLE_T1OSC	    0x08

#define T1_DIV_BY_1         0
#define T1_DIV_BY_2         0x10
#define T1_DIV_BY_4         0x20
#define T1_DIV_BY_8         0x30

#define T1_GATE           0x8000
#define T1_GATE_INVERTED  0xC000
#define T1_GATE_TOGGLE    0xA000
#define T1_GATE_SINGLE    0x9000
#define T1_GATE_TIMER0    0x8100
#define T1_GATE_TIMER2    0x8200

////////////////////////////////////////////////////////////////// Timer 2
// Timer 2 Functions: SETUP_TIMER_2, GET_TIMER2, SET_TIMER2
// Constants used for SETUP_TIMER_2() are:
#define T2_DISABLED         0
#define T2_DIV_BY_1         4
#define T2_DIV_BY_4         5
#define T2_DIV_BY_16        6

////////////////////////////////////////////////////////////////// Timer 3
// Timer 3 Functions: SETUP_TIMER_3, GET_TIMER3, SET_TIMER3
// Constants used for SETUP_TIMER_3() are:
//      (or (via |) together constants from each group)
#define T3_DISABLED         0
#define T3_INTERNAL         0x07
#define T3_INTERNAL_TIMES_4 0x47
#define T3_EXTERNAL         0x87
#define T3_EXTERNAL_SYNC    0x83

#define T3_ENABLE_T1OSC	    0x08  

#define T3_DIV_BY_1         0
#define T3_DIV_BY_2         0x10
#define T3_DIV_BY_4         0x20
#define T3_DIV_BY_8         0x30

#define T3_GATE           0x8000
#define T3_GATE_INVERTED  0xC000
#define T3_GATE_TOGGLE    0xA000
#define T3_GATE_SINGLE    0x9000
#define T3_GATE_TIMER0    0x8100
#define T3_GATE_TIMER2    0x8200


////////////////////////////////////////////////////////////////// Timer 4
// Timer 4 Functions: SETUP_TIMER_4, GET_TIMER4, SET_TIMER4
// Constants used for SETUP_TIMER_4() are:
#define T4_DISABLED         0
#define T4_DIV_BY_1         4
#define T4_DIV_BY_4         5
#define T4_DIV_BY_16        6

////////////////////////////////////////////////////////////////// RTC
// RTC Functions: setup_rtc(), setup_rtc_alarm(), rtc_read(),
//                rtc_write(), rtc_alarm_read(), rtc_alarm_write()
// Structure used in read and write functions (pass pointer):
typedef struct {
   int8 tm_year;
   int8 tm_yday;  // Not used by built in functions
   int8 tm_mday;
   int8 tm_mon;
   int8 tm_hour;
   int8 tm_wday;
   int8 tm_sec;
   int8 tm_min;
   int8 tm_isdst; // Not used by built in functions
} rtc_time_t;
//
// Constants used in setup_rtc() are:  // Second param is calibration
#define RTC_ENABLE           0x8000
#define RTC_DISABLE          0
#define RTC_OUTPUT_SOURCE    0x20400
#define RTC_OUTPUT_SECONDS   0x10400
#define RTC_OUTPUT_ALARM     0x00400
//
// Constants used in setup_rtc_alarm() first param are:
#define RTC_ALARM_ENABLE     0x80
#define RTC_ALARM_DISABLE    0
#define RTC_CHIME_ENABLE     0x40
#define RTC_CHIME_DISABLE    0
// Constants used in setup_rtc_alarm() second param are:  // Third param is repeat#
#define RTC_ALARM_HALFSECOND 0x00
#define RTC_ALARM_SECOND     0x04
#define RTC_ALARM_10_SECONDS 0x08
#define RTC_ALARM_MINUTE     0x0C
#define RTC_ALARM_10_MINUTES 0x10
#define RTC_ALARM_HOUR       0x14
#define RTC_ALARM_DAY        0x18
#define RTC_ALARM_WEEK       0x1C
#define RTC_ALARM_MONTH      0x20
#define RTC_ALARM_YEAR       0x24

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
#define CCP_COMPARE_INT_AND_TOGGLE      0x2       
#define CCP_COMPARE_RESET_TIMER         0xB
#define CCP_PWM                         0xC
#define CCP_PWM_PLUS_1                  0x1c  
#define CCP_PWM_PLUS_2                  0x2c
#define CCP_PWM_PLUS_3                  0x3c
//#define CCP_USE_TIMER3                0x100  OBSOLETE, SEE TIMER-3     
#word   CCP_1       =                   getenv("SFR:CCPR1L")
#byte   CCP_1_LOW   =                   getenv("SFR:CCPR1L")
#byte   CCP_1_HIGH  =                   getenv("SFR:CCPR1H")
// OR in one of the following to use timer 3 with a CCP unit
#define  T3_CCP1_TO_2  0x0200
#define  T3_CCP1       0x0100

// The following should be used with the ECCP unit only (or these in)
#define CCP_PWM_H_H                     0x0c
#define CCP_PWM_H_L                     0x0d
#define CCP_PWM_L_H                     0x0e
#define CCP_PWM_L_L                     0x0f

#define CCP_PWM_FULL_BRIDGE             0x40
#define CCP_PWM_FULL_BRIDGE_REV         0xC0
#define CCP_PWM_HALF_BRIDGE             0x80

#define CCP_SHUTDOWN_ON_COMP1           0x100000
#define CCP_SHUTDOWN_ON_COMP2           0x200000
#define CCP_SHUTDOWN_ON_COMP            0x300000
#define CCP_SHUTDOWN_ON_INT0            0x400000
#define CCP_SHUTDOWN_ON_COMP1_INT0      0x500000
#define CCP_SHUTDOWN_ON_COMP2_INT0      0x600000
#define CCP_SHUTDOWN_ON_COMP_INT0       0x700000

#define CCP_SHUTDOWN_AC_L               0x000000
#define CCP_SHUTDOWN_AC_H               0x040000
#define CCP_SHUTDOWN_AC_F               0x080000

#define CCP_SHUTDOWN_BD_L               0x000000
#define CCP_SHUTDOWN_BD_H               0x010000
#define CCP_SHUTDOWN_BD_F               0x020000

#define CCP_SHUTDOWN_RESTART            0x80000000  

#define CCP_PULSE_STEERING_A            0x01000000
#define CCP_PULSE_STEERING_B            0x02000000
#define CCP_PULSE_STEERING_C            0x04000000
#define CCP_PULSE_STEERING_D            0x08000000
#define CCP_PULSE_STEERING_SYNC         0x10000000

#word   CCP_2       =                   getenv("SFR:CCPR2L")
#byte   CCP_2_LOW   =                   getenv("SFR:CCPR2L")
#byte   CCP_2_HIGH  =                   getenv("SFR:CCPR2H")
////////////////////////////////////////////////////////////////// PMP
// PP Functions: SETUP_PP,
// PSP_INPUT_FULL(), PSP_OUTPUT_FULL(),
//                PSP_OVERFLOW(), INPUT_D(), OUTPUT_D()
// PMP Variables: PSP_DATA
// Constants used in SETUP_PP() are:
#define PMP_DISABLED     0
#define PMP_ENABLED      0x02008000
#define PMP_COMBINE_RW   0x01000000
#define PSP_ADDRESS_MODE 0x01000000
#define PSP_NORMAL_MODE  0x18000000
#define PMP_16_BIT       0x04000000
#define PMP_INC_ADDR     0x08000000
#define PMP_DEC_ADDR     0x10000000
#define PMP_INT          0x20000000
#define PMP_STALL        0x40000000
#define PMP_INT_3        0x60000000

#define PMP_RD_ACT_HIGH  0x00000101
#define PMP_WR_ACT_HIGH  0x00000202
#define PMP_RD_ACT_LOW   0x00000100
#define PMP_WR_ACT_LOW   0x00000200
#define PMP_BE_ACT_HIGH  0x00000404
#define PMP_BE_ACT_LOW   0x00000400
#define PMP_CS1_ACT_HIGH 0x00000008
#define PMP_CS2_ACT_HIGH 0x00000010
#define PMP_AL_ACT_HIGH  0x00000020
#define PMP_ADDR_MUX_A_D 0x00000800
#define PMP_ADDR_MUX_D   0x00001000
#define PMP_IDLE_OFF     0x00002000

#define PMP_WAITE        0x00010000  // Data hold after strobe, add *2 for 3Tcy or *3 for 4Tcy
#define PMP_WAITM        0x00040000  // Data hold read to strobe, add *n for n*Tcy (n=1..15)
#define PMP_WAITB        0x00400000  // Data hold before R/W, add *2 for 3Tcy or *3 for 4Tcy

#define PP_ACTIVE_IDLE   0x00002000

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
#define NC_NC_NC_NC   0x00
#define NC_NC         0x00

//Pick one constant for COMP1
#define CP1_VREF_F6     0x83
#define CP1_F5_F6       0x80
#define CP1_VREF_VREF   0x87
#define CP1_F5_VREF     0x84
//Optionally OR with one or both of the following
#define CP1_OUT_ON_F2 0x40
#define CP1_INVERT    0x20
#define CP1_INT_H_TO_L 0x10
#define CP1_INT_L_TO_H 0x08

//Pick one constant for COMP2
#define CP2_VREF_F4     0x8300
#define CP2_F3_F4       0x8000
#define CP2_VREF_VREF   0x8700
#define CP2_F3_VREF     0x8400
//Optionally OR with one or both of the following
#define CP2_OUT_ON_F1   0x4000
#define CP2_INVERT      0x2000
#define CP2_INT_H_TO_L  0x1000
#define CP2_INT_L_TO_H  0x0800

#bit C1OUT = 0xfa6.0
#bit C2OUT = 0xfa6.1

////////////////////////////////////////////////////////////////// VREF
// Constants used in setup_vref() are:
//
#define VREF_LOW  0xa0
#define VREF_HIGH 0x80
// Or (with |) the above with a number 0-15
#define VREF_F5   0x40
#define VREF_COMP 0x10


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
#define ADC_CLOCK_INTERNAL 0x03           // Internal 2-6us
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
// OR together desired pins
#define sAN12            0x10     //| B0
#define sAN11            0x8      //| C2
#define sAN10            0x4      //| B1
#define sAN9             0x2      //| B3
#define sAN8             0x1      //| B2
#define sAN7            0x800000  //| E2 
#define sAN6            0x400000  //| E1 
#define sAN5            0x200000  //| E0 
#define sAN4            0x100000  //| A5
#define sAN3             0x80000  //| A3
#define sAN2             0x40000  //| A2
#define sAN1             0x20000  //| A1
#define sAN0             0x10000  //| A0
#define NO_ANALOGS           0x0  // None
#define ALL_ANALOG      0xff00ff  // A0 A1 A2 A3 A5 E0 E1 E2 B2 B3 B1 C2 B0

// Optional Second argument:
#define VSS_VDD              0x0000        //| Range 0-Vdd
#define VSS_VREF             0x4000        //| Range 0-Vref
#define VREF_VREF            0xc000        //| Range Vref-Vref
#define VREF_VDD             0x8000        //| Range Vref-Vdd


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
#define INT_TIMER2                0x009D02
#define INT_TIMER3                0x00A002
#define INT_EXT_L2H               0x5000F210
#define INT_EXT_H2L               0x6000F210
#define INT_EXT                   0x00F210
#define INT_EXT1_L2H              0x5001F008
#define INT_EXT1_H2L              0x6001F008
#define INT_EXT1                  0x00F008
#define INT_EXT2_L2H              0x5002F010
#define INT_EXT2_H2L              0x6002F010
#define INT_EXT2                  0x00F010
#define INT_RB                    0x00FFF208
#define INT_AD                    0x009D40
#define INT_RDA                   0x009D20
#define INT_TBE                   0x009D10
#define INT_SSP                   0x009D08
#define INT_CCP1                  0x009D04
#define INT_CCP2                  0x00A001
#define INT_BUSCOL                0x00A008
#define INT_COMP                  0x00A040
#define INT_RDA2                  0x00A320
#define INT_TBE2                  0x00A310
#define INT_TIMER4                0x00A308
#define INT_OSCF                  0x00A080
#define INT_HLVD                  0x00A004
#define INT_BUSCOL2               0x00A340
#define INT_EXT3_L2H              0x5003F020
#define INT_EXT3_H2L              0x6003F020
#define INT_EXT3                  0x00F020
#define INT_PMP                   0x009D80
#define INT_SSP2                  0x00A380
#define INT_RTC                   0x00A301

#list
