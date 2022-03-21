//////// Standard Header file for the PIC16C773 device ////////////////
#device PIC16C773
#nolist
//////// Program memory: 4096x14  Data RAM: 255  Stack: 8
//////// I/O: 32   Analog Pins: 10
//////// C Scratch area: 77   ID Location: 2000
//////// Fuses: LP,XT,HS,RC,NOWDT,WDT,PUT,NOPUT,NOBROWNOUT,BROWNOUT,BORV45
//////// Fuses: BORV42,BORV27,BORV25,PROTECT,PROTECT_75%,PROTECT_50%
//////// Fuses: NOPROTECT
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

#define PIN_B0  48
#define PIN_B1  49
#define PIN_B2  50
#define PIN_B3  51
#define PIN_B4  52
#define PIN_B5  53
#define PIN_B6  54
#define PIN_B7  55

#define PIN_C0  56
#define PIN_C1  57
#define PIN_C2  58
#define PIN_C3  59
#define PIN_C4  60
#define PIN_C5  61
#define PIN_C6  62
#define PIN_C7  63

#define PIN_D0  64
#define PIN_D1  65
#define PIN_D2  66
#define PIN_D3  67
#define PIN_D4  68
#define PIN_D5  69
#define PIN_D6  70
#define PIN_D7  71

#define PIN_E0  72
#define PIN_E1  73
#define PIN_E2  74

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
#define T1_INTERNAL         0x85
#define T1_EXTERNAL         0x87
#define T1_EXTERNAL_SYNC    0x83

#define T1_CLK_OUT          8

#define T1_DIV_BY_1         0
#define T1_DIV_BY_2         0x10
#define T1_DIV_BY_4         0x20
#define T1_DIV_BY_8         0x30

////////////////////////////////////////////////////////////////// Timer 2
// Timer 2 Functions: SETUP_TIMER_2, GET_TIMER2, SET_TIMER2
// Constants used for SETUP_TIMER_2() are:
#define T2_DISABLED         0
#define T2_DIV_BY_1         4
#define T2_DIV_BY_4         5
#define T2_DIV_BY_16        6

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
#word   CCP_2       =                   getenv("SFR:CCPR2L")
#byte   CCP_2_LOW   =                   getenv("SFR:CCPR2L")
#byte   CCP_2_HIGH  =                   getenv("SFR:CCPR2H")
////////////////////////////////////////////////////////////////// PSP
// PSP Functions: SETUP_PSP, PSP_INPUT_FULL(), PSP_OUTPUT_FULL(),
//                PSP_OVERFLOW(), INPUT_D(), OUTPUT_D()
// PSP Variables: PSP_DATA
// Constants used in SETUP_PSP() are:
#define PSP_ENABLED                     0x10
#define PSP_DISABLED                    0

#byte   PSP_DATA=                       8   

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
#define NO_ANALOGS             0x0F         // None
#define ALL_ANALOG             0x00         // A0 A1 A2 A3 A5 E0 E1 E2 B2 B3   
#define AN0_TO_AN8             0x06         // A0 A1 A2 A3 A5 E0 E1 E2 B2      
#define AN0_TO_AN7             0x07         // A0 A1 A2 A3 A5 E0 E1 E2         
#define AN0_TO_AN6             0x08         // A0 A1 A2 A3 A5 E0 E1            
#define AN0_TO_AN5             0x09         // A0 A1 A2 A3 A5 E0               
#define AN0_TO_AN4             0x0A         // A0 A1 A2 A3 A5                  
#define AN0_TO_AN3             0x0B         // A0 A1 A2 A3
#define AN0_TO_AN2             0x0C         // A0 A1 A2
#define AN0_TO_AN1             0x0D         // A0 A1
#define AN0                    0x0E         // A0
#define AN0_TO_AN8_ANALOG      0x06         //!old only provided for compatibility
#define AN0_TO_AN7_ANALOG      0x07         //!old only provided for compatibility   
#define AN0_TO_AN6_ANALOG      0x08         //!old only provided for compatibility   
#define AN0_TO_AN5_ANALOG      0x09         //!old only provided for compatibility   
#define AN0_TO_AN4_ANALOG      0x0A         //!old only provided for compatibility   
#define AN0_TO_AN3_ANALOG      0x0B         //!old only provided for compatibility
#define AN0_TO_AN2_ANALOG      0x0C         //!old only provided for compatibility
#define AN0_TO_AN1_ANALOG      0x0D         //!old only provided for compatibility
#define AN0_ANALOG             0x0E         //!old only provided for compatibility

// Optional Second argument:
#define VSS_VDD               0x00          // Range 0-Vdd
#define VREF_VREF             0x10          // Range VrefL-VrefH
#define VRL_VRH               0x20          // Range Vrl-Vrh
#define VSS_VREF              0x30          // Range 0-VrefH
#define VSS_VRH               0x40          // Range 0-Vrh
#define VREF_VDD              0x50          // Range VrefL-Vdd
#define VRL_VDD               0x60          // Range Vrl-Vdd
#define VSS_VRL               0x70          // Range 0-Vrl

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
#define INT_RB                    0x00FF0B08
#define INT_EXT_L2H               0x50000B10
#define INT_EXT_H2L               0x60000B10
#define INT_EXT                   0x000B10
#define INT_AD                    0x008C40
#define INT_TBE                   0x008C10
#define INT_RDA                   0x008C20
#define INT_TIMER1                0x008C01
#define INT_TIMER2                0x008C02
#define INT_CCP1                  0x008C04
#define INT_CCP2                  0x008D01
#define INT_SSP                   0x008C08
#define INT_BUSCOL                0x008D08
#define INT_TIMER0                0x000B20

#list
