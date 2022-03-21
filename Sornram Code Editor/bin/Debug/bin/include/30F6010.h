//////// Standard Header file for the DSPIC30F6010 device ////////////////
#device DSPIC30F6010
#nolist
//////// Program memory: 49152x24  Data RAM: 8192  Stack: 31
//////// I/O: 68   Analog Pins: 16
//////// Data EEPROM: 4096
//////// Fuses: XTL,HS,XT,XT_PLL4,XT_PLL8,XT_PLL16,ER_IO,ER,EC,EC_IO,EC_PLL4
//////// Fuses: EC_PLL8,EC_PLL16,LP,FRC,LPRC,PR,CKSFSM,CKSNOFSM,NOCKSFSM
//////// Fuses: WPSB1,WPSB2,WPSB3,WPSB4,WPSB5,WPSB6,WPSB7,WPSB8,WPSB9,WPSB10
//////// Fuses: WPSB11,WPSB12,WPSB13,WPSB14,WPSB15,WPSB16,WPSA1,WPSA8,WPSA64
//////// Fuses: WPSA512,NOWDT,WDT,NOPUT,PUT4,PUT16,PUT64,BORV45,BORV42
//////// Fuses: BORV27,BORRES,NOBROWNOUT,BROWNOUT,LPOL_LOW,LPOL_HIGH
//////// Fuses: HPOL_LOW,HPOL_HIGH,PWMPIN,NOPWMPIN,NOMCLR,MCLR,WRT,NOWRT
//////// Fuses: PROTECT,NOPROTECT,ICSP4,ICSP3,ICSP2,ICSP1,DEBUG,NODEBUG
//////// 
////////////////////////////////////////////////////////////////// I/O
// Discrete I/O Functions: SET_TRIS_x(), OUTPUT_x(), INPUT_x(),
//                         SET_PULLUP(), INPUT(),
//                         OUTPUT_LOW(), OUTPUT_HIGH(),
//                         OUTPUT_FLOAT(), OUTPUT_BIT()
// Constants used to identify pins in the above are:

#define PIN_A9  5657
#define PIN_A10  5658
#define PIN_A14  5662
#define PIN_A15  5663

#define PIN_B0  5696
#define PIN_B1  5697
#define PIN_B2  5698
#define PIN_B3  5699
#define PIN_B4  5700
#define PIN_B5  5701
#define PIN_B6  5702
#define PIN_B7  5703
#define PIN_B8  5704
#define PIN_B9  5705
#define PIN_B10  5706
#define PIN_B11  5707
#define PIN_B12  5708
#define PIN_B13  5709
#define PIN_B14  5710
#define PIN_B15  5711

#define PIN_C1  5745
#define PIN_C3  5747
#define PIN_C13  5757
#define PIN_C14  5758
#define PIN_C15  5759

#define PIN_D0  5792
#define PIN_D1  5793
#define PIN_D2  5794
#define PIN_D3  5795
#define PIN_D4  5796
#define PIN_D5  5797
#define PIN_D6  5798
#define PIN_D7  5799
#define PIN_D8  5800
#define PIN_D9  5801
#define PIN_D10  5802
#define PIN_D11  5803
#define PIN_D12  5804
#define PIN_D13  5805
#define PIN_D14  5806
#define PIN_D15  5807

#define PIN_E0  5840
#define PIN_E1  5841
#define PIN_E2  5842
#define PIN_E3  5843
#define PIN_E4  5844
#define PIN_E5  5845
#define PIN_E6  5846
#define PIN_E7  5847
#define PIN_E8  5848
#define PIN_E9  5849

#define PIN_F0  5888
#define PIN_F1  5889
#define PIN_F2  5890
#define PIN_F3  5891
#define PIN_F4  5892
#define PIN_F5  5893
#define PIN_F6  5894
#define PIN_F7  5895
#define PIN_F8  5896

#define PIN_G0  5936
#define PIN_G1  5937
#define PIN_G2  5938
#define PIN_G3  5939
#define PIN_G6  5942
#define PIN_G7  5943
#define PIN_G8  5944
#define PIN_G9  5945

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

////////////////////////////////////////////////////////////////// ADC
// ADC Functions: SETUP_ADC(), SETUP_ADC_PORTS()
//                SET_ADC_CHANNEL(), READ_ADC()
//
// Constants used for SETUP_ADC() are:
// Clock is at ADCS<5:0> of ADCON3 Reg. (0x02A4)
// Tad = (Tcy/2)*(ADCS<5:0>+1)
#define ADC_OFF           0x10000
#define ADC_CLOCK          0x0000     // External
#define ADC_CLOCK_DIV_2    0x0001
#define ADC_CLOCK_DIV_4    0x0003
#define ADC_CLOCK_DIV_8    0x0007
#define ADC_CLOCK_DIV_16   0x000F
#define ADC_CLOCK_DIV_32   0x001F
#define ADC_CLOCK_DIV_64   0x003F   
#define ADC_CLOCK_INTERNAL 0x0080     // Internal

// The following may be OR'ed in with the above using |
// Auto-Sample Time bits
#define ADC_TAD_MUL_0      0x0000
#define ADC_TAD_MUL_2      0x0200
#define ADC_TAD_MUL_4      0x0400
#define ADC_TAD_MUL_8      0x0800
#define ADC_TAD_MUL_16     0x1000
#define ADC_TAD_MUL_31     0x1F00

// Constants used in READ_ADC() are:
#define ADC_START_AND_READ 0x07
#define ADC_START_ONLY     0x01
#define ADC_READ_ONLY      0x06



// Constants used in SETUP_ADC_PORTS() are:
// First argument:
// OR together desired pins
#define NO_ANALOGS      0           // None
#define ALL_ANALOG      0xFFFFFFFF  // All
#define sAN0      0x00000001 //| B0
#define sAN1      0x00000002 //| B1
#define sAN2      0x00000004 //| B2
#define sAN3      0x00000008 //| B3
#define sAN4      0x00000010 //| B4
#define sAN5      0x00000020 //| B5
#define sAN6      0x00000040 //| B6
#define sAN7      0x00000080 //| B7
#define sAN8      0x00000100 //| B8
#define sAN9      0x00000200 //| B9
#define sAN10      0x00000400 //| B10
#define sAN11      0x00000800 //| B11
#define sAN12      0x00001000 //| B12
#define sAN13      0x00002000 //| B13
#define sAN14      0x00004000 //| B14
#define sAN15      0x00008000 //| B15
#define sAN16      0x00010000 //| C1
#define sAN17      0x00020000 //| C2
#define sAN18      0x00040000 //| C3
#define sAN19      0x00080000 //| C4
#define sAN20      0x00100000 //| A12
#define sAN21      0x00200000 //| A13
#define sAN22      0x00400000 //| A6
#define sAN23      0x00800000 //| A7
#define sAN24      0x01000000 //| E0
#define sAN25      0x02000000 //| E1
#define sAN26      0x04000000 //| E2
#define sAN27      0x08000000 //| E3
#define sAN28      0x10000000 //| E4
#define sAN29      0x20000000 //| E5
#define sAN30      0x40000000 //| E6
#define sAN31      0x80000000 //| E7

// Optional Second argument:
#define VSS_VDD            0x0000 // Range 0-Vdd
#define VREF_VREF          0x6000 // Range VrefL-VrefH
#define VREF_VDD           0x4000 // Range VrefL-Vdd
#define VSS_VREF           0x2000 // Range 0-VrefH

////////////////////////////////////////////////////////////////// LVD
// Low Voltage Detect Functions: SETUP_LOW_VOLT_DETECT()
// Constants used in SETUP_LOW_VOLT_DETECT() are:
#define LVD_LVDIN  0x1F00
#define LVD_46     0x1E00
#define LVD_43     0x1D00
#define LVD_41     0x1C00
#define LVD_39     0x1B00
#define LVD_37     0x1A00
#define LVD_36     0x1900
#define LVD_34     0x1800
#define LVD_31     0x1700
#define LVD_29     0x1600
#define LVD_28     0x1500
#define LVD_26     0x1400
#define LVD_25     0x1300
#define LVD_23     0x1200
#define LVD_21     0x1100
#define LVD_19     0x1000

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

////////////////////////////////////////////////////////////////// MOTOR PWM
// MPWM Functions: setup_motor_pwm(), set_motor_pwm_unit(),
//                 set_motor_pwm_duty(), set_motor_pwm_event(),
//                 get_motor_pwm_count()
// Constants used in setup_motor_pwm() second param are (first param is unit number 1,2...):
#define MPWM_DISABLED          0
#define MPWM_FREE_RUN          0x8000
#define MPWM_SINGLE_PULSE      0x8001
#define MPWM_UP_DOWN           0x8002
#define MPWM_UP_DOWN_WITH_INTS 0x8003
// OR in any of the following:
#define MPWM_HALT_WHEN_IDLE            0x2000
#define MPWM_DUTY_UPDATES_IMMEADIATE  0x40000
#define MPWM_SYNC_OVERRIDES           0x20000
#define MPWM_DISABLE_UPDATES          0x10000
#define MPWM_LATCH_FAULTS            0x100000

// Constants used in set_motor_unit() third param are:  (first param is unit number 1,2... and second param is pwm pin pair 1,2,3 or 4)
#define MPWM_INDEPENDENT     0x0001
#define MPWM_ENABLE          0x0006  // both H and L
#define MPWM_ENABLE_H        0x0004
#define MPWM_ENABLE_L        0x0002

#define MPWM_FORCE_L_0       0x0010
#define MPWM_FORCE_L_1       0x0050
#define MPWM_FORCE_H_0       0x0020
#define MPWM_FORCE_H_1       0x00A0

#define MPWM_FAULTA_LA_HA     0x0700
#define MPWM_FAULTA_LA_HI     0x0500
#define MPWM_FAULTA_LI_HA     0x0600
#define MPWM_FAULTA_LI_HI     0x0400
#define MPWM_FAULTB_LA_HA     0x7000
#define MPWM_FAULTB_LA_HI     0x5000
#define MPWM_FAULTB_LI_HA     0x6000
#define MPWM_FAULTB_LI_HI     0x4000
#define MPWM_FAULT_NO_CHANGE 0x0000

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
#define INT_DMAERR                5
#define INT_EXT0                  6
#define INT_IC1                   7
#define INT_OC1                   8
#define INT_TIMER1                9
#define INT_IC2                   10
#define INT_OC2                   11
#define INT_TIMER2                12
#define INT_TIMER3                13
#define INT_SPI1                  14
#define INT_RDA                   15
#define INT_TBE                   16
#define INT_ADC1                  17
#define INT_EEPROM                18
#define INT_SI2C                  19
#define INT_MI2C                  20
#define INT_CNI                   21
#define INT_EXT1                  22
#define INT_IC7                   24
#define INT_IC8                   25
#define INT_OC3                   27
#define INT_OC4                   29
#define INT_TIMER4                31
#define INT_TIMER5                33
#define INT_EXT2                  35
#define INT_RDA2                  36
#define INT_TBE2                  37
#define INT_SPI2                  38
#define INT_CAN1                  39
#define INT_IC3                   41
#define INT_IC4                   42
#define INT_IC5                   44
#define INT_IC6                   46
#define INT_OC5                   48
#define INT_OC6                   50
#define INT_OC7                   51
#define INT_OC8                   52
#define INT_EXT3                  53
#define INT_EX4                   54
#define INT_CAN2                  56
#define INT_PWM1                  58
#define INT_QEI                   60
#define INT_LOWVOLT               64
#define INT_unused                67
#define INT_FAULTB                68

#list
