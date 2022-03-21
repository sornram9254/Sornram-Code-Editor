//////// Standard Header file for the DSPIC33FJ06GS202 device ////////////////
#device DSPIC33FJ06GS202
#nolist
//////// Program memory: 2048x24  Data RAM: 1024  Stack: 31
//////// I/O: 21   Analog Pins: 6
//////// Fuses: WRTB,NOWRTB,BSSHL,BSSHM,BSSHS,BSSSL,BSSSM,BSSSS,NOBSS,WRT
//////// Fuses: NOWRT,PROTECT_HIGH,PROTECT,NOPROTECT,FRC,FRC_PLL,PR,PR_PLL
//////// Fuses: SOSC,LPRC,FRC_DIV_BY_16,FRC_PS,NOIESO,IESO,EC,XT,HS,NOPR
//////// Fuses: OSCIO,NOOSCIO,NOIOL1WAY,IOL1WAY,CKSFSM,CKSNOFSM,NOCKSNOFSM
//////// Fuses: WPOSTS1,WPOSTS2,WPOSTS3,WPOSTS4,WPOSTS5,WPOSTS6,WPOSTS7
//////// Fuses: WPOSTS8,WPOSTS9,WPOSTS10,WPOSTS11,WPOSTS12,WPOSTS13,WPOSTS14
//////// Fuses: WPOSTS15,WPOSTS16,WPRES32,WPRES128,NOWINDIS,WINDIS,NOWDT,WDT
//////// Fuses: NOPUT,PUT2,PUT4,PUT8,PUT16,PUT32,PUT64,PUT128,ICSP3,ICSP2
//////// Fuses: ICSP1,NOJTAG,JTAG,DEBUG,NODEBUG
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

#define PIN_B0  5712
#define PIN_B1  5713
#define PIN_B2  5714
#define PIN_B3  5715
#define PIN_B4  5716
#define PIN_B5  5717
#define PIN_B6  5718
#define PIN_B7  5719
#define PIN_B8  5720
#define PIN_B9  5721
#define PIN_B10  5722
#define PIN_B11  5723
#define PIN_B12  5724
#define PIN_B13  5725
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

////////////////////////////////////////////////////////////////// Timer
// Timer Functions: SETUP_TIMERx, GET_TIMERx, GET_TIMERxy,
// SET_TIMERx, SET_TIMERxy
// Constants used for SETUP_TIMERx() are:
//      (or (via |) together constants from each group)
#define TMR_DISABLED 0x0000
#define TMR_INTERNAL 0x8000
#define TMR_EXTERNAL 0x8002
#define TMR_GATE     0x0040 

#define TMR_DIV_BY_1   0x0000
#define TMR_DIV_BY_8   0x0010
#define TMR_DIV_BY_64  0x0020
#define TMR_DIV_BY_256 0x0030
#define TMR_32_BIT     0x0008 // Only for even numbered timers

#define TMR_HALT_IDLE      0x2000
#define TMR_CONTINUE_IDLE  0x0000

#define T1_EXTERNAL_SYNC  0x8006 //This only applies to Timer1
#define T1_EXTERNAL_RTC   0xC002 //This only applies to Timer1
/////////////////////////////////////////////////////////// INPUT CAPTURE
// Functions: SETUP_CAPTURE, GET_CAPTURE,
//
// Constants used for SETUP_CAPTURE() are:
#define CAPTURE_OFF               0x0000  // Capture OFF
#define CAPTURE_EE                0x0001  // Capture Every Edge
#define CAPTURE_FE                0x0002  // Capture Falling Edge
#define CAPTURE_RE                0x0003  // Capture Rising Edge
#define CAPTURE_DIV_4             0x0004  // Capture Every 4th Rising Edge
#define CAPTURE_DIV_16            0x0005  // Capture Every 16th Rising Edge
#define CAPTURE_INTERRUPT_ONLY    0x0007  // Interrupt on Rising Edge when in Sleep or Idle

// The following defines can be ORed | with above to configure interrupts
#define INTERRUPT_EVERY_CAPTURE   0x0000  // Interrupt on every capture event
#define INTERRUPT_SECOND_CAPTURE  0x0020  // Interrupt on every second capture event
#define INTERRUPT_THIRD_CAPTURE   0x0040  // Interrupt on every third capture event
#define INTERRUPT_FOURTH_CAPTURE  0x0060  // Interrupt on every fourth capture event

// The following defines can be ORed | with above to select timer
#define CAPTURE_TIMER2            0x0080  // On capture event Timer 2 is captured
#define CAPTURE_TIMER3            0x0000  // On capture event Timer 3 is captured

// The following defines can be ORed | with above to select idle operation mode
#define CAPTURE_HALT_IDLE         0x2000  // Capture module halts during idle mode
#define CAPTURE_CONTINUE_IDLE     0x0000  // Capture module continues during idle mode

/////////////////////////////////////////////////////////// OUTPUT COMPARE
// Functions: SETUP_COMPARE, SET_PWM_DUTY, SET_COMPARE_TIME
//
// Constants used for SETUP_COMPARE() are:
#define COMPARE_OFF               0x0000  // Compare OFF
#define COMPARE_SET_ON_MATCH      0x0001  // Pin from low to high on match
#define COMPARE_CLR_ON_MATCH      0x0002  // Pin from high to low on match
#define COMPARE_TOGGEL            0x0003  // Pin will toggle on every match occurrence
#define COMPARE_SINGLE_PULSE      0x0004  // Pin will generate single pulse on first match
#define COMPARE_CONT_PULSE        0x0005  // Pin will pulse for every match
#define COMPARE_PWM               0x0006  // Compare operates as PWM with fault pin disabled
#define COMPARE_PWM_FAULT         0x0007  // Compare operates as PWM with fault pin enabled

// The following defines can be ORed | with above to select timer
#define COMPARE_TIMER2            0x0000  // Timer 2 is the base timer
#define COMPARE_TIMER3            0x0008  // Timer 3 is the base timer

// The following defines can be ORed | with above to select idle operation mode
#define COMPARE_HALT_IDLE         0x2000  // Compare module halts during idle mode
#define COMPARE_CONTINUE_IDLE     0x0000  // Compare module continues during idle mode

////////////////////////////////////////////////////////////////// SPI
// SPI Functions: SETUP_SPI, SPI_WRITE, SPI_READ, SPI_DATA_IN
//
// Constants used in SETUP_SPI() are:
//      (or (via |) together constants from each group)
#define SPI_MASTER                 0x0020
#define SPI_SLAVE                  0x0000

#define SPI_SCK_IDLE_HIGH          0x0040
#define SPI_SCK_IDLE_LOW           0x0000

#define SPI_XMIT_L_TO_H            0x0100
#define SPI_XMIT_H_TO_L            0x0000

#define SPI_MODE_16B               0x0400
#define SPI_MODE_8B                0x0000

#define SPI_SAMPLE_AT_END          0x0200
#define SPI_SAMPLE_AT_MIDDLE       0x0000

#define SPI_SS_ENABLED             0x0000
#define SPI_SS_DISABLED            0x0080

//or (via |) one of the following when operating as MASTER 
#define SPI_CLK_DIV_1              0x001F
#define SPI_CLK_DIV_2              0x001B
#define SPI_CLK_DIV_3              0x0017
#define SPI_CLK_DIV_4              0x001E
#define SPI_CLK_DIV_5              0x000F
#define SPI_CLK_DIV_6              0x000B
#define SPI_CLK_DIV_7              0x0007
#define SPI_CLK_DIV_8              0x0003
#define SPI_CLK_DIV_12             0x0016
#define SPI_CLK_DIV_16             0x001D
#define SPI_CLK_DIV_20             0x000E
#define SPI_CLK_DIV_24             0x000A
#define SPI_CLK_DIV_28             0x0006
#define SPI_CLK_DIV_32             0x0002
#define SPI_CLK_DIV_48             0x0015
#define SPI_CLK_DIV_64             0x001C
#define SPI_CLK_DIV_80             0x000D
#define SPI_CLK_DIV_96             0x0009
#define SPI_CLK_DIV_112            0x0005
#define SPI_CLK_DIV_128            0x0001
#define SPI_CLK_DIV_192            0x0014
#define SPI_CLK_DIV_256            0x0010
#define SPI_CLK_DIV_320            0x000C
#define SPI_CLK_DIV_384            0x0008
#define SPI_CLK_DIV_448            0x0004
#define SPI_CLK_DIV_512            0x0000

//The following defines are provided for compatibility
#define SPI_L_TO_H         SPI_SCK_IDLE_LOW
#define SPI_H_TO_L         SPI_SCK_IDLE_HIGH

////////////////////////////////////////////////////////////////// HIGH-SPEED ADC
// HIGH-SPEED ADC Functions: SETUP_HIGH_SPEED_ADC(), SETUP_HIGH_SPEED_ADC_PAIR()
//                           READ_HIGH_SPEED_ADC(), HIGH_SPEED_ADC_DONE()
//                           SETUP_ADC_PORTS()
//
//Constants used for SETUP_HIGH_SPEED_ADC() are:
#define ADC_OFF                         0x10000
#define ADC_CLOCK_DIV_1                  0x0000
#define ADC_CLOCK_DIV_2                  0x0001
#define ADC_CLOCK_DIV_3                  0x0002
#define ADC_CLOCK_DIV_4                  0x0003
#define ADC_CLOCK_DIV_5                  0x0004
#define ADC_CLOCK_DIV_6                  0x0005
#define ADC_CLOCK_DIV_7                  0x0006
#define ADC_CLOCK_DIV_8                  0x0007

//OR in one of the following
#define ADC_CLOCKED_BY_PRI_PLL           0x0000
#define ADC_CLOCKED_BY_AUX_PLL           0x1000

//OR in any of the following
#define ADC_HALT_IDLE                    0x2000
#define ADC_OUTPUT_FRACTIONAL            0x0100
#define ADC_INTERRUPT_EARLY              0x0080
#define ADC_CONVERT_ODD_THEN_EVEN        0x0040
#define ADC_SAMPLE_SEQUENTIAL            0x0020
#define ADC_DEDICATED_SAMPLE_CONSTANTLY  0x0010

//Constants used for second parameter of SETUP_HIGH_SPEED_ADC_PAIR() are: (first parameter is Pair Number to setup)
// -The following selects the Trigger Source for the ADC Pair
#define NO_TRIGGER                       0x00
#define INDIVIDUAL_SOFTWARE_TRIGGER      0x01
#define GLOBAL_SOFTWARE_TRIGGER          0x02
#define PWM_PRIMARY_SE_TRIGGER           0x03
#define PWM_GEN1_PRIMARY_TRIGGER         0x04
#define PWM_GEN2_PRIMARY_TRIGGER         0x05
#define PWM_GEN3_PRIMARY_TRIGGER         0x06
#define PWM_GEN4_PRIMARY_TRIGGER         0x07
#define TIMER1_PERIOD_MATCH              0x0C
#define PWM_GEN1_SECONDARY_TRIGGER       0x0E
#define PWM_GEN2_SECONDARY_TRIGGER       0x0F
#define PWM_GEN3_SECONDARY_TRIGGER       0x10
#define PWM_GEN4_SECONDARY_TRIGGER       0x11
#define PWM_GEN1_CURRENT_LIMIT_TRIGGER   0x17
#define PWM_GEN2_CURRENT_LIMIT_TRIGGER   0x18
#define PWM_GEN3_CURRENT_LIMIT_TRIGGER   0x19
#define PWM_GEN4_CURRENT_LIMIT_TRIGGER   0x1A
#define TIMER2_PERIOD_MATCH              0x1F

//the follwoing may be OR in with the above
#define ADC_PAIR_USES_COMMON_INTERRUPT   0x80

//Constants used in READ_HIGH_SPEED_ADC() are:
#define ADC_START_AND_READ               0xF7
#define ADC_START_ONLY                   0xF1
#define ADC_READ_ONLY                    0xF6

//Constants used in SETUP_ADC_PORTS() are:
// - Function provided to allow setting up individual analog pins.
//   If setting up pins for HIGH-SPEED ADC use the SETUP_HIGH_SPEED_ADC_PAIR()
//   function instead, which setups up the analog pins for each pair.
//
// OR together desired pins
#define sAN0                0x0001 //| A0 
#define sAN1                0x0002 //| A1 
#define sAN2                0x0004 //| A2 
#define sAN3                0x0008 //| B0 
#define sAN4                0x0010 //| B9 
#define sAN5                0x0020 //| B10 
#define NO_ANALOGS               0 //| None
#define ALL_ANALOG        0xFFFFFF 


////////////////////////////////////////////////////////////////// COMP
// Comparator Variables: C1OUT, C2OUT
// Constants used in setup_comparator() are:
#define NC_NC_NC_NC      0x00
#define A4_A5_NC_NC      0x201
#define A4_VR_NC_NC      0x200
#define A5_VR_NC_NC      0x202
#define NC_NC_A2_A3      0x804
#define NC_NC_A2_VR      0x800
#define NC_NC_A3_VR      0x808
#define A4_A5_A2_A3      A4_A5_NC_NC | NC_NC_A2_A3
#define A4_VR_A2_VR      A4_VR_NC_NC | NC_NC_A2_VR
#define A5_VR_A3_VR      A5_VR_NC_NC |  NC_NC_A3_VR

#define C1_INVERT     0x10
#define C2_INVERT     0x20
#define C1_OUTPUT     0x40
#define C2_OUTPUT     0x80

//#bit COMPARATOR1_RESULT = getenv("SFR:CMCON").6
//#bit COMPARATOR2_RESULT = getenv("SFR:CMCON").7

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
#define INT_IC1                   7
#define INT_OC1                   8
#define INT_TIMER1                9
#define INT_TIMER2                72
#define INT_SPI1E                 74
#define INT_SPI1                  75
#define INT_RDA                   76
#define INT_TBE                   77
#define INT_ADC1                  78
#define INT_SI2C                  81
#define INT_MI2C                  82
#define INT_CNI                   84
#define INT_EXT1                  85
#define INT_EXT2                  94
#define INT_UART1E                130
#define INT_CMP1                  153
#define INT_PWMSEN                154
#define INT_PWM1                  155
#define INT_PWM2                  156
#define INT_CMP2                  159
#define INT_ADCP0                 165
#define INT_ADCP1                 166
#define INT_ADCP2                 167
#define INT_ADCP6                 171

#list
