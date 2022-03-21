//////// Standard Header file for the PIC16F913 device ////////////////
#device PIC16F913
#nolist
//////// Program memory: 4096x14  Data RAM: 260  Stack: 8
//////// I/O: 25   Analog Pins: 5
//////// Data EEPROM: 256
//////// C Scratch area: 77   ID Location: 2000
//////// Fuses: LP,XT,HS,EC_IO,INTRC_IO,INTRC,RC_IO,RC,NOWDT,WDT,PUT,NOPUT
//////// Fuses: NOMCLR,MCLR,PROTECT,NOPROTECT,CPD,NOCPD,NOBROWNOUT
//////// Fuses: BROWNOUT_SW,BROWNOUT_NOSL,BROWNOUT,NOIESO,IESO,NOFCMEN,FCMEN
//////// Fuses: DEBUG,NODEBUG
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

#define PIN_C0  56
#define PIN_C1  57
#define PIN_C2  58
#define PIN_C3  59
#define PIN_C4  60
#define PIN_C5  61
#define PIN_C6  62
#define PIN_C7  63

#define PIN_E3  75

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

// One of the following may be OR'ed in with the above:

#define WDT_ON             0x4000   
#define WDT_OFF            0       
#define WDT_DIV_16         0x100
#define WDT_DIV_8          0x300
#define WDT_DIV_4          0x500
#define WDT_DIV_2          0x700
#define WDT_TIMES_1        0x900  // Default
#define WDT_TIMES_2        0xB00
#define WDT_TIMES_4        0xD00
#define WDT_TIMES_8        0xF00
#define WDT_TIMES_16      0x1100
#define WDT_TIMES_32      0x1300
#define WDT_TIMES_64      0x1500
#define WDT_TIMES_128     0x1700

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
////////////////////////////////////////////////////////////////// COMP
// Comparator Variables: C1OUT, C2OUT
// Constants used in setup_comparator() are:
#define NC_NC_NC_NC  0x00FF07
#define NC_NC  0x00FF07
#define A0_A3_A1_A2  0x30FF04
#define A0_VR_A1_VR  0x30FF02
#define A3_VR_A2_VR  0x30FF0A
#define A0_A2_A1_A2  0x30FF03
#define A0_A2_A1_A2_OUT_ON_A4_A5  0x00CF06
#define NC_NC_C1_C0_OUT_ON_A5  0x00DF05
#define NC_NC_A1_06_OUT_ON_A5  0x00DF0D
#define A3_A2_A1_A2  0x30FF09

// The following may be OR'ed with the above
#define COMP_DISABLE_WAKEUP   1
#define COMP_INVERT           0x10
#define COMP_T1_SYNC          0x1000000
#define COMP_T1_GATE          0x2000000

#bit C1OUT = 0x9C.6
#bit C2OUT = 0x9C.7

////////////////////////////////////////////////////////////////// VREF
// Constants used in setup_vref() are:
//
#define VREF_LOW  0xa0
#define VREF_HIGH 0x80
// Or (with |) the above with a number 0-15
#define VREF_A2   0x40

////////////////////////////////////////////////////////////////// VREF
// Constants used in setup_low_volt_detect() are:
//
#define LVD_45 0x17
#define LVD_42 0x16
#define LVD_40 0x15
#define LVD_23 0x14
#define LVD_22 0x13
#define LVD_21 0x12
#define LVD_20 0x11
#define LVD_19 0x10


////////////////////////////////////////////////////////////////// LCD
// LCD Functions: SETUP_LCD, LCD_SYMBOL, LCD_LOAD
// Constants used in setup_lcd() are:
#define LCD_DISABLED  0
#define LCD_STATIC    0x80
#define LCD_MUX12     0x81
#define LCD_MUX13     0x82
#define LCD_MUX14     0x83
#define LCD_STOP_ON_SLEEP 0x40
#define LCD_USE_TIMER_1   0x04
#define LCD_INTRC         0x08
#define LCD_BIAS_PINS     0x10
#define LCD_HALF_BIAS   0x4000
#define LCD_TYPE_B_WAVE 0x8000

// Constants used in lcd_symbol() are:
#define COM0 0
#define COM1 24
#define COM2 48
#define COM3 72


////////////////////////////////////////////////////////////////// INTERNAL RC
// Constants used in setup_oscillator() are:
#define OSC_31KHZ   1
#define OSC_125KHZ  0x11
#define OSC_250KHZ  0x21
#define OSC_500KHZ  0x31
#define OSC_1MHZ    0x41
#define OSC_2MHZ    0x51
#define OSC_4MHZ    0x61
#define OSC_8MHZ    0x71
#define OSC_INTRC   1
#define OSC_NORMAL  0
// Result may be (ignore all other bits)
#define OSC_STATE_STABLE 4
#define OSC_31KHZ_STABLE 2



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
#define sAN0            1       //| A0
#define sAN1            2       //| A1
#define sAN2            4       //| A2
#define sAN3            8       //| A3
#define sAN4            16      //| A5
#define NO_ANALOGS      0       // None
#define ALL_ANALOG      31      // A0 A1 A2 A3 A5 

// Optional Second argument:
#define VSS_VDD               0x0000    //| Range 0-Vdd
#define VREF_VREF             0x6000    //| Range VrefL-VrefH
#define VSS_VREF              0x2000    //| Range 0-VrefH
#define VREF_VDD              0x4000    //| Range VrefL-Vdd

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
#define INT_RB                    0x01FF0B08
#define INT_EXT_L2H               0x50000B10
#define INT_EXT_H2L               0x60000B10
#define INT_EXT                   0x000B10
#define INT_AD                    0x008C40
#define INT_TBE                   0x008C10
#define INT_RDA                   0x008C20
#define INT_TIMER1                0x008C01
#define INT_TIMER2                0x008C02
#define INT_CCP1                  0x008C04
#define INT_SSP                   0x008C08
#define INT_TIMER0                0x000B20
#define INT_EEPROM                0x008C80
#define INT_OSC_FAIL              0x008D80
#define INT_LCD                   0x008D10
#define INT_LOWVOLT               0x008D04
#define INT_COMP                  0x008D20
#define INT_COMP2                 0x008D40
#define INT_RB0                   0x1010B08
#define INT_RB1                   0x1020B08
#define INT_RB2                   0x1040B08
#define INT_RB3                   0x1080B08
#define INT_RB4                   0x1100B08
#define INT_RB5                   0x1200B08
#define INT_RB6                   0x1400B08
#define INT_RB7                   0x1800B08

#list
