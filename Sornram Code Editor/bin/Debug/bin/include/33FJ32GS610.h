//////// Standard Header file for the DSPIC33FJ32GS610 device ////////////////
#device DSPIC33FJ32GS610
#nolist
//////// Program memory: 11008x24  Data RAM: 4096  Stack: 31
//////// I/O: 85   Analog Pins: 24
//////// Fuses: WRTB,NOWRTB,BSSHL,BSSHM,BSSHS,BSSSL,BSSSM,BSSSS,NOBSS,WRT
//////// Fuses: NOWRT,PROTECT_HIGH,PROTECT,NOPROTECT,FRC,FRC_PLL,PR,PR_PLL
//////// Fuses: SOSC,LPRC,FRC_DIV_BY_16,FRC_PS,NOIESO,IESO,EC,XT,HS,NOPR
//////// Fuses: OSCIO,NOOSCIO,CKSFSM,CKSNOFSM,NOCKSNOFSM,WPOSTS1,WPOSTS2
//////// Fuses: WPOSTS3,WPOSTS4,WPOSTS5,WPOSTS6,WPOSTS7,WPOSTS8,WPOSTS9
//////// Fuses: WPOSTS10,WPOSTS11,WPOSTS12,WPOSTS13,WPOSTS14,WPOSTS15
//////// Fuses: WPOSTS16,WPRES32,WPRES128,NOWINDIS,WINDIS,NOWDT,WDT,NOPUT
//////// Fuses: PUT2,PUT4,PUT8,PUT16,PUT32,PUT64,PUT128,SS1NORM,SS1ALT
//////// Fuses: QEIALT,QEINORM,ICSP3,ICSP2,ICSP1,NOJTAG,JTAG,DEBUG,NODEBUG
//////// Fuses: COMP_E_0MV,COMP_E_15MV,COMP_E_30MV,COMP_E_45MV,COMP_E_L2H
//////// Fuses: COMP_E_H2L,COMP_O_0MV,COMP_O_15MV,COMP_O_30MV,COMP_O_45MV
//////// Fuses: COMP_O_L2H,COMP_O_H2L
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
#define PIN_A7  5655
#define PIN_A9  5657
#define PIN_A10  5658
#define PIN_A14  5662
#define PIN_A15  5663

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

#define PIN_C1  5777
#define PIN_C2  5778
#define PIN_C3  5779
#define PIN_C4  5780
#define PIN_C12  5788
#define PIN_C13  5789
#define PIN_C14  5790
#define PIN_C15  5791

#define PIN_D0  5840
#define PIN_D1  5841
#define PIN_D2  5842
#define PIN_D3  5843
#define PIN_D4  5844
#define PIN_D5  5845
#define PIN_D6  5846
#define PIN_D7  5847
#define PIN_D8  5848
#define PIN_D9  5849
#define PIN_D10  5850
#define PIN_D11  5851
#define PIN_D12  5852
#define PIN_D13  5853
#define PIN_D14  5854
#define PIN_D15  5855

#define PIN_E0  5904
#define PIN_E1  5905
#define PIN_E2  5906
#define PIN_E3  5907
#define PIN_E4  5908
#define PIN_E5  5909
#define PIN_E6  5910
#define PIN_E7  5911
#define PIN_E8  5912
#define PIN_E9  5913

#define PIN_F0  5968
#define PIN_F1  5969
#define PIN_F2  5970
#define PIN_F3  5971
#define PIN_F4  5972
#define PIN_F5  5973
#define PIN_F6  5974
#define PIN_F7  5975
#define PIN_F8  5976
#define PIN_F12  5980
#define PIN_F13  5981

#define PIN_G0  6032
#define PIN_G1  6033
#define PIN_G2  6034
#define PIN_G3  6035
#define PIN_G6  6038
#define PIN_G7  6039
#define PIN_G8  6040
#define PIN_G9  6041
#define PIN_G12  6044
#define PIN_G13  6045
#define PIN_G14  6046
#define PIN_G15  6047

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
#define PWM_GEN5_PRIMARY_TRIGGER         0x08  
#define PWM_GEN6_PRIMARY_TRIGGER         0x09  
#define PWM_GEN7_PRIMARY_TRIGGER         0x0A  
#define PWM_GEN8_PRIMARY_TRIGGER         0x0B  
#define TIMER1_PERIOD_MATCH              0x0C
#define PWM_SECONDARY_SE_TRIGGER         0x0D  
#define PWM_GEN1_SECONDARY_TRIGGER       0x0E
#define PWM_GEN2_SECONDARY_TRIGGER       0x0F
#define PWM_GEN3_SECONDARY_TRIGGER       0x10
#define PWM_GEN4_SECONDARY_TRIGGER       0x11
#define PWM_GEN5_SECONDARY_TRIGGER       0x12  
#define PWM_GEN6_SECONDARY_TRIGGER       0x13  
#define PWM_GEN7_SECONDARY_TRIGGER       0x14  
#define PWM_GEN8_SECONDARY_TRIGGER       0x15  
#define PWM_GEN9_SECONDARY_TRIGGER       0x16  
#define PWM_GEN1_CURRENT_LIMIT_TRIGGER   0x17
#define PWM_GEN2_CURRENT_LIMIT_TRIGGER   0x18
#define PWM_GEN3_CURRENT_LIMIT_TRIGGER   0x19
#define PWM_GEN4_CURRENT_LIMIT_TRIGGER   0x1A
#define PWM_GEN5_CURRENT_LIMIT_TRIGGER   0x1B  
#define PWM_GEN6_CURRENT_LIMIT_TRIGGER   0x1C  
#define PWM_GEN7_CURRENT_LIMIT_TRIGGER   0x1D  
#define PWM_GEN8_CURRENT_LIMIT_TRIGGER   0x1E  
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
#define sAN0                0x0001 //| B0 
#define sAN1                0x0002 //| B1 
#define sAN2                0x0004 //| B2 
#define sAN3                0x0008 //| B3 
#define sAN4                0x0010 //| B4 
#define sAN5                0x0020 //| B5 
#define sAN6                0x0040 //| B6 
#define sAN7                0x0080 //| B7 
#define sAN8                0x0100 //| B8 
#define sAN9                0x0200 //| B9 
#define sAN10               0x0400 //| B10 
#define sAN11               0x0800 //| B11 
#define sAN12               0x1000 //| B12 
#define sAN13               0x2000 //| B13 
#define sAN14               0x4000 //| B14 
#define sAN15               0x8000 //| B15 
#define sAN16              0x10000 //| C1 
#define sAN17              0x20000 //| C2 
#define sAN18              0x40000 //| C3 
#define sAN19              0x80000 //| C4 
#define sAN20             0x100000 //| E8 
#define sAN21             0x200000 //| E9 
#define sAN22             0x400000 //| A6 
#define sAN23             0x800000 //| A7 
#define NO_ANALOGS               0 //| None
#define ALL_ANALOG        0xFFFFFF 


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

#bit C1OUT = 0x540.8
#bit C1ENV = 0x540.9  // User must clear
#bit C2OUT = 0x544.8
#bit C2ENV = 0x544.9  // User must clear
#bit C3OUT = 0x548.8
#bit C3ENV = 0x548.9  // User must clear
#bit C4OUT = 0x54C.8
#bit C4ENV = 0x54C.9  // User must clear

////////////////////////////////////////////////////////////////// QEI
// QEI Functions: setup_qei(), qei_set_count(), qei_get_count(),
//                qei_status()
//
// Constants used in setup_qei() first param are:
#define QEI_DISABLED        0
#define QEI_MODE_X2         0x0400
#define QEI_MODE_X4         0x0600
#define QEI_MODE_TIMER      0x0100
#define QEI_STOP_WHEN_IDLE  0x2000
#define QEI_SWAP_AB         0x0080
#define QEI_OUTPUT_ENABLE   0x0040
#define QEI_RESET_WHEN_MAXCOUNT  0x0100
#define QEI_RESET_WHEN_IDX_PULSE 0x0004
#define QEI_TIMER_GATED      0x0020
#define QEI_TIMER_INTERNAL   0x0000
#define QEI_TIMER_EXTERNAL   0x0002
#define QEI_TIMER_DIV_BY_1   0x0000
#define QEI_TIMER_DIV_BY_8   0x0008
#define QEI_TIMER_DIV_BY_64  0x0010
#define QEI_TIMER_DIV_BY_256 0x0018
// Constants used in setup_qei() second param are:   // Third param is MAXCOUNT
#define QEI_FILTER_DIV_1     0x0000
#define QEI_FILTER_DIV_2     0x0010
#define QEI_FILTER_DIV_4     0x0020
#define QEI_FILTER_DIV_16    0x0030
#define QEI_FILTER_DIV_32    0x0040
#define QEI_FILTER_DIV_64    0x0050
#define QEI_FILTER_DIV_128   0x0060
#define QEI_FILTER_DIV_256   0x0070
#define QEI_FILTER_OUTPUT    0x0080
#define QEI_NO_ERROR_INTS    0x0100
#define QEI_IDX_WHEN_A0      0x0000  // for 2X mode
#define QEI_IDX_WHEN_A1      0x0200  // for 2X mode
#define QEI_IDX_WHEN_B0      0x0400  // for 2X mode
#define QEI_IDX_WHEN_B1      0x0600  // for 2X mode
#define QEI_IDX_WHEN_A0_B0   0x0000  // for 4X mode
#define QEI_IDX_WHEN_A1_B0   0x0200  // for 4X mode
#define QEI_IDX_WHEN_A0_B1   0x0400  // for 4X mode
#define QEI_IDX_WHEN_A1_B1   0x0600  // for 4X mode
// Constants returned from qei_status() are:
#define QEI_POS_ERROR        0x8000
#define QEI_FORWARD          0x0800
#define QEI_INDEX_PIN        0x1000

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
#define INT_IC2                   70
#define INT_OC2                   71
#define INT_TIMER2                72
#define INT_TIMER3                73
#define INT_SPI1E                 74
#define INT_SPI1                  75
#define INT_RDA                   76
#define INT_TBE                   77
#define INT_ADC1                  78
#define INT_SI2C                  81
#define INT_MI2C                  82
#define INT_CNI                   84
#define INT_EXT1                  85
#define INT_OC3                   90
#define INT_OC4                   91
#define INT_TIMER4                92
#define INT_TIMER5                93
#define INT_EXT2                  94
#define INT_RDA2                  95
#define INT_TBE2                  96
#define INT_SPI2E                 97
#define INT_SPI2                  98
#define INT_IC3                   102
#define INT_IC4                   103
#define INT_SI2C2                 114
#define INT_MI2C2                 115
#define INT_EXT3                  118
#define INT_EXT4                  119
#define INT_QEI                   123
#define INT_UART1E                130
#define INT_UART2E                131
#define INT_QEI2                  132
#define INT_CMP1                  153
#define INT_PWMSEN                154
#define INT_PWM1                  155
#define INT_PWM2                  156
#define INT_PWM3                  157
#define INT_PWM4                  158
#define INT_CMP2                  159
#define INT_CMP3                  160
#define INT_CMP4                  161
#define INT_ADCP0                 165
#define INT_ADCP1                 166
#define INT_ADCP2                 167
#define INT_ADCP3                 168
#define INT_ADCP4                 169
#define INT_ADCP5                 170
#define INT_ADCP6                 171
#define INT_PWM5                  180
#define INT_PWM6                  181
#define INT_PWM7                  182
#define INT_PWM8                  183
#define INT_PWM9                  184
#define INT_ADCP7                 185
#define INT_ADCP8                 186
#define INT_ADCP9                 187
#define INT_ADCP10                188
#define INT_ADCP11                189
#define INT_ADCP12                190

#list
