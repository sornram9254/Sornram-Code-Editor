//////// Standard Header file for the PIC24F04KL100 device ////////////////
#device PIC24F04KL100
#nolist
//////// Program memory: 1408x24  Data RAM: 512  Stack: 31
//////// I/O: 12   Analog Pins: 0
//////// Fuses: WRTB,NOWRTB,BSSH1152,BSSS1152,NOBSS,WRT,NOWRT,PROTECT
//////// Fuses: NOPROTECT,FRC,FRC_PLL,PR,PR_PLL,SOSC,LPRC,LPFRC_DIV,FRC_DIV
//////// Fuses: SOSC_DIGITAL,SOSC_ANALOG,LPRC_LOW,LPRC_HIGH,NOIESO,IESO,EC
//////// Fuses: XT,HS,NOPR,NOCLKOUT,CLKOUT,POSCFREQ_L,POSCFREQ_M,POSCFREQ_H
//////// Fuses: SOSC_LOW,SOSC_HIGH,CKSFSM,CKSNOFSM,NOCKSFSM,WPOSTS1,WPOSTS2
//////// Fuses: WPOSTS3,WPOSTS4,WPOSTS5,WPOSTS6,WPOSTS7,WPOSTS8,WPOSTS9
//////// Fuses: WPOSTS10,WPOSTS11,WPOSTS12,WPOSTS13,WPOSTS14,WPOSTS15
//////// Fuses: WPOSTS16,WDT32,WDT128,NOWINDIS,WINDIS,NOWDT,WDT_NOSL,WDT_SW
//////// Fuses: WDT,NOBROWNOUT,BROWNOUT_SW,BROWNOUT_NOSL,BROWNOUT,NOPUT,PUT
//////// Fuses: I2C1SELA,I2C1SELD,LPBORV,BORV_HIGH,BORV_MID,BORV_LOW,NOMCLR
//////// Fuses: MCLR,ICSP3,ICSP2,ICSP1,DEBUG,NODEBUG
//////// 
////////////////////////////////////////////////////////////////// I/O
// Discrete I/O Functions: SET_TRIS_x(), OUTPUT_x(), INPUT_x(),
//                         SET_PULLUP(), INPUT(),
//                         OUTPUT_LOW(), OUTPUT_HIGH(),
//                         OUTPUT_FLOAT(), OUTPUT_BIT()
// Constants used to identify pins in the above are:

#define PIN_A0  5648
#define PIN_A1  5649
#define PIN_A2  5650
#define PIN_A3  5651
#define PIN_A4  5652
#define PIN_A5  5653
#define PIN_A6  5654

#define PIN_B4  5716
#define PIN_B8  5720
#define PIN_B9  5721
#define PIN_B14  5726
#define PIN_B15  5727

////////////////////////////////////////////////////////////////// Useful defines
#define FALSE 0
#define TRUE 1

#define BYTE unsigned int8
#define BOOLEAN int1

#define getc getch
#define fgetc getch
#define getchar getch
#define putc putchar
#define fputc putchar
#define fgets gets
#define fputs puts

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


////////////////////////////////////////////////////////////////// WDT
// Watch Dog Timer Functions: SETUP_WDT() and RESTART_WDT()
//
// Constants used for SETUP_WDT() are:
#define WDT_ON      1
#define WDT_OFF     0

////////////////////////////////////////////////////////////////// Control
// Control Functions:  RESET_CPU(), SLEEP(), RESTART_CAUSE()
// Constants passed into RESTART_CAUSE() are:
#define RESTART_POWER_UP      0
#define RESTART_BROWNOUT      1
#define RESTART_WATCHDOG      4
#define RESTART_SOFTWARE      6
#define RESTART_MCLR          7
#define RESTART_ILLEGAL_OP    14
#define RESTART_TRAP_CONFLICT 15
//
// Constants passed into SLEEP() are:
#define SLEEP_FULL      0  // Default
#define SLEEP_IDLE      1  // Clock and peripherals don't stop

////////////////////////////////////////////////////////////////// INTERNAL RC
// Constants used in setup_oscillator() are:
#define OSC_INTERNAL     32
#define OSC_CRYSTAL       1
#define OSC_CLOCK         2
#define OSC_RC            3
#define OSC_SECONDARY    16

////////////////////////////////////////////////////////////////// Timer 1
// Timer Functions: SETUP_TIMER1, GET_TIMER1, SET_TIMER1
// Constants used for SETUP_TIMER1() are:
//      (or (via |) together constants from each group)
#define T1_INTERNAL       0x8000
#define T1_INTERNAL_LPRC  0x8202
#define T1_EXTERNAL_T1CK  0x8102
#define T1_EXTERNAL_SOSC  0x8002
#define T1_SYNC           0x0004
#define T1_GATE           0x0040

#define T1_HALT_IDLE      0x2000
#define T1_CONTINUE_IDLE  0x0000

#define T1_DIV_BY_1       0x0000
#define T1_DIV_BY_8       0x0010
#define T1_DIV_BY_64      0x0020
#define T1_DIV_BY_256     0x0030



////////////////////////////////////////////////////////////////// Timer 2
// Timer Functions: SETUP_TIMER2, GET_TIMER2, SET_TIMER2
// Constants used for SETUP_TIMER2() are:
#define T2_DISABLED         0x00
#define T2_DIV_BY_1         0x04
#define T2_DIV_BY_4         0x05
#define T2_DIV_BY_16        0x06

////////////////////////////////////////////////////////////////// Timer 3
// Timer Functions: SETUP_TIMER3, GET_TIMER3, SET_TIMER3
// Constants used for SETUP_TIMER3() are:
//      (or (via |) together constants from each group)
#define T3_INTERNAL_FOSC        0x01
#define T3_INTERNAL_FOSC_DIV_2  0x41
#define T3_EXTERNAL_T3CK        0x81
#define T3_EXTERNAL_SOSC        0x89
#define T3_INTERNAL_LPRC        0xC1

#define T3_SYNC                 0x00
#define T2_NOSYNC               0x04

#define T3_DIV_BY_1             0x00
#define T3_DIV_BY_2             0x10
#define T3_DIV_BY_4             0x20
#define T3_DIV_BY_8             0x30

#define T3_GATE                 0x8000
#define T3_GATE_INVERTED        0xC000
#define T3_GATE_TOGGLE          0xA000
#define T3_GATE_SINGLE          0x9000
#define T3_GATE_TIMER2          0x8100
#define T3_GATE_COMP1           0x8200
#define T3_GATE_COMP2           0x8300

////////////////////////////////////////////////////////////////// CCP
// CCP Functions: SETUP_CCPx, SET_PWMx_DUTY
// CCP Variables: CCP_x, CCP_x_LOW, CCP_x_HIGH
// Constants used for SETUP_CCPx() are:
#define CCP_OFF                         0
#define CCP_COMPARE_INT_AND_TOGGLE      0x2
#define CCP_CAPTURE_FE                  0x4
#define CCP_CAPTURE_RE                  0x5
#define CCP_CAPTURE_DIV_4               0x6
#define CCP_CAPTURE_DIV_16              0x7
#define CCP_COMPARE_SET_ON_MATCH        0x8
#define CCP_COMPARE_CLR_ON_MATCH        0x9
#define CCP_COMPARE_INT                 0xA
#define CCP_COMPARE_RESET_TIMER         0xB
#define CCP_PWM                         0xC









#word   CCP_1       =                   getenv("SFR:CCPR1L")
#byte   CCP_1_LOW   =                   getenv("SFR:CCPR1L")
#byte   CCP_1_HIGH  =                   getenv("SFR:CCPR1H")
#word   CCP_2       =                   getenv("SFR:CCPR2L")
#byte   CCP_2_LOW   =                   getenv("SFR:CCPR2L")
#byte   CCP_2_HIGH  =                   getenv("SFR:CCPR2H")
////////////////////////////////////////////////////////////////// SPI
// SPI Functions: SETUP_SPI, SPI_WRITE, SPI_READ, SPI_DATA_IN
//
// Constants used in SETUP_SPI() are:
//      (or (via |) together constants from each group)
#define SPI_DISABLED               0x0000
#define SPI_MASTER                 0x0020
#define SPI_SLAVE                  0x0024

#define SPI_SCK_IDLE_HIGH          0x0010
#define SPI_SCK_IDLE_LOW           0x0000

#define SPI_XMIT_L_TO_H            0x4000
#define SPI_XMIT_H_TO_L            0x0000

#define SPI_SAMPLE_AT_END          0x8000
#define SPI_SAMPLE_AT_MIDDLE       0x0000

//or (via |) on of the following when operating as SLAVE
#define SPI_SS_ENABLED             0x0000
#define SPI_SS_DISABLED            0x0001

//or (via |) one of the following when operating as MASTER
#define SPI_CLK_TMR2_DIV_2         0x0003
#define SPI_CLK_DIV_16             0x0002
#define SPI_CLK_DIV_4              0x0001
#define SPI_CLK_DIV_1              0x0000

//The following defines are provided for compatibility
#define SPI_L_TO_H         SPI_SCK_IDLE_LOW
#define SPI_H_TO_L         SPI_SCK_IDLE_HIGH

////////////////////////////////////////////////////////////////// COMP
// setup_comparator() first param is the comparator number.
// Constants used in setup_comparator() second param are:
#define NC_NC            0x00
#define CXINB_CXINA      0x8000
#define CXINC_CXINA      0x8001
#define CXIND_CXINA      0x8002
#define VBG2_CXINA       0x8003
#define CXINB_VREF       0x8010
#define CXINC_VREF       0x8011
#define CXIND_VREF       0x8012
#define VBG2_VREF        0x8013
      // OR in any of the following
#define COMP_INVERT      0x2000   // Invert output
#define COMP_OUTPUT      0x4000   // Output on pin
#define COMP_INTR        0x0040   // Generate interrupt on high
#define COMP_INTR_INV    0x0080   // Generate interrupt on low
#define COMP_INTR_CHANGE 0x00c0   // Generate interrupt on change

#bit C1OUT = 0x634.8
#bit C1ENV = 0x634.9  // User must clear

////////////////////////////////////////////////////////////////// VREF
// Constants used in setup_vref() are:
//
#define VREF_DISABLED  0x0000
#define VREF_ANALOG    0x0010
#define VREF_HIGH      0x1000
#define VREF_LOW       0x1020
// Or (with |) the above with a number 0-15

////////////////////////////////////////////////////////////////// LVD
// Low Voltage Detect Functions: SETUP_LOW_VOLT_DETECT()
// Constants used in SETUP_LOW_VOLT_DETECT() are:
#define LVD_ENABLE          0x8000
#define LVD_DISABLE         0x0000
#define LVD_HALT_IDLE       0x2000
#define LVD_TRIGGER_ABOVE   0x0080
#define LVD_TRIGGER_BELOW   0x0000
// OR a number 0-15 with the above using | or the following
//    refer to device's datasheet for trip point when using a number
#define LVD_LVDIN           0x000F

////////////////////////////////////////////////////////////////// INT
// Interrupt Functions: ENABLE_INTERRUPTS(), DISABLE_INTERRUPTS(),
//                      CLEAR_INTERRUPT(), INTERRUPT_ACTIVE(),
//                      EXT_INT_EDGE()
//
// Constants used in EXT_INT_EDGE() are:
#define L_TO_H              0x40
#define H_TO_L                 0
//
// Constants used in other interrupt functions are:
#define INTR_GLOBAL               0x400
#define INTR_NORMAL               0x100
#define INTR_ALTERNATE            0x200
#define INTR_LEVEL0               0x500
#define INTR_LEVEL1               0x501
#define INTR_LEVEL2               0x502
#define INTR_LEVEL3               0x503
#define INTR_LEVEL4               0x504
#define INTR_LEVEL5               0x505
#define INTR_LEVEL6               0x506
#define INTR_LEVEL7               0x507

#define INTR_CN_PIN              0x8000  // or in a PIN_xx constant

#define INT_OSCFAIL               1
#define INT_ADDRERR               2
#define INT_STACKERR              3
#define INT_MATHERR               4
#define INT_EXT0                  6
#define INT_TIMER1                9
#define INT_TIMER2                72
#define INT_TIMER3                73
#define INT_RDA                   76
#define INT_TBE                   77
#define INT_NVM                   80
#define INT_CNI                   84
#define INT_EXT1                  85
#define INT_EXT2                  94
#define INT_UART1E                130
#define INT_COMP                  152
#define INT_LVD                   179
#define INT_ULPWU                 192
#define INT_CCP1                  226
#define INT_CCP2                  227
#define INT_BOSCOL                229
#define INT_SSP                   230

#list
