//////// Standard Header file for the PIC24FJ128GA308 device ////////////////
#device PIC24FJ128GA308
#nolist
//////// Program memory: 44028x24  Data RAM: 8192  Stack: 31
//////// I/O: 69   Analog Pins: 16
//////// Fuses: WPOSTS1,WPOSTS2,WPOSTS3,WPOSTS4,WPOSTS5,WPOSTS6,WPOSTS7
//////// Fuses: WPOSTS8,WPOSTS9,WPOSTS10,WPOSTS11,WPOSTS12,WPOSTS13,WPOSTS14
//////// Fuses: WPOSTS15,WPOSTS16,WDT32,WDT128,NOWDT,WDT_NOSL,WDT_SW,WDT
//////// Fuses: NOWINDIS,WINDIS,ICSP3,ICSP2,ICSP1,LVR,NOLVR,DEBUG,NODEBUG
//////// Fuses: WRT,NOWRT,PROTECT,NOPROTECT,NOJTAG,JTAG,EC,XT,HS,NOPR
//////// Fuses: NOIOL1WAY,IOL1WAY,OSCIO,NOOSCIO,CKSFSM,CKSNOFSM,NOCKSNOFSM
//////// Fuses: FRC,FRC_PLL,PR,PR_PLL,SOSC,LPRC,FRC_PS,VREFALT_CVREFALT
//////// Fuses: VREFALT_CVREFNORM,VREFNORM_CVREFALT,VREFNORM_CVREFNORM
//////// Fuses: NOIESO,IESO,NOWPFP,WPFP,NOVBATBOR,VBATBOR,SOSC_DIG,SOSC_SEL
//////// Fuses: WDTWIN_75%,WDTWIN_50%,WDTWIN_37%,WDTWIN_25%,NOBROWNOUT
//////// Fuses: BROWNOUT,NOWPDIS,WPDIS,WPCFG,NOWPCFG,WPBEG,WPEND,DSWDT_1MS
//////// Fuses: DSWDT_2MS,DSWDT_4MS,DSWDT_8MS,DSWDT_16MS,DSWDT_33MS
//////// Fuses: DSWDT_66MS,DSWDT_132MS,DSWDT_264MS,DSWDT_528MS,DSWDT_1SEC
//////// Fuses: DSWDT_2SEC,DSWDT_4SEC,DSWDT_8SEC,DSWDT_16SEC,DSWDT_33SEC
//////// Fuses: DSWDT_67SEC,DSWDT_135SEC,DSWDT_4MINS,DSWDT_9MINS
//////// Fuses: DSWDT_18MINS,DSWDT_36MINS,DSWDT_72MINS,DSWDT_2HRS,DSWDT_4HRS
//////// Fuses: DSWDT_9HRS,DSWDT_19HRS,DSWDT_38HRS,DSWDT_77HRS,DSWDT_6DAYS
//////// Fuses: DSWDT_12DAYS,DSWDT_25DAYS,DSWDTCK_SOSC,DSWDTCK_LPRC,NODSBOR
//////// Fuses: DSBOR,NODSWDT,DSWDT,NODS,DS_SW
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
#define PIN_C3  5779
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

#define PIN_G0  6032
#define PIN_G1  6033
#define PIN_G2  6034
#define PIN_G3  6035
#define PIN_G6  6038
#define PIN_G7  6039
#define PIN_G8  6040
#define PIN_G9  6041

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
// Functions: SETUP_CAPTURE, GET_CAPTURE, GET_CAPTURE32
//
// Constants used for SETUP_CAPTURE() are:
#define CAPTURE_OFF                 0x0000  // Capture OFF
#define CAPTURE_EE                  0x0001  // Capture Every Edge
#define CAPTURE_FE                  0x0002  // Capture Falling Edge
#define CAPTURE_RE                  0x0003  // Capture Rising Edge
#define CAPTURE_DIV_4               0x0004  // Capture Every 4th Rising Edge
#define CAPTURE_DIV_16              0x0005  // Capture Every 16th Rising Edge
#define CAPTURE_INTERRUPT_ONLY      0x0007  // Interrupt on Rising Edge when in Sleep or Idle

// The following defines can be ORed | with above to configure interrupts
#define INTERRUPT_EVERY_CAPTURE     0x0000  // Interrupt on every capture event
#define INTERRUPT_SECOND_CAPTURE    0x0020  // Interrupt on every second capture event
#define INTERRUPT_THIRD_CAPTURE     0x0040  // Interrupt on every third capture event
#define INTERRUPT_FOURTH_CAPTURE    0x0060  // Interrupt on every fourth capture event

// The following defines can be ORed | with above to select timer
#define CAPTURE_TIMER1              0x1000
#define CAPTURE_TIMER2              0x0400
#define CAPTURE_TIMER3              0x0000
#define CAPTURE_TIMER4              0x0800
#define CAPTURE_TIMER5              0x0C00
#define CAPTURE_SYSTEM_CLOCK        0x1C00

// The following defines can be ORed | with above to select idle operation mode
#define CAPTURE_HALT_IDLE           0x2000  // Capture module halts during idle mode
#define CAPTURE_CONTINUE_IDLE       0x0000  // Capture module continues during idle mode

// The following defines can be ORed | with above to select # of bits
#define CAPTURE_32_BIT              0x01000000  //Only used with odd number capture units
#define CAPTURE_16_BIT                       0

// The following defines can be ORed | with above and determines whether the next block
// of defines are the capture unit's trigger or syncronize source
#define CAPTURE_TRIGGER             0x00800000
#define CAPTURE_SYNCHRONIZE                  0

// The following defines can be ORed | with above and selects the capture unit's
// trigger or synchronization source
#define CAPTURE_TRIG_SYNC_OC1       0x00010000
#define CAPTURE_TRIG_SYNC_OC2       0x00020000
#define CAPTURE_TRIG_SYNC_OC3       0x00030000
#define CAPTURE_TRIG_SYNC_OC4       0x00040000
#define CAPTURE_TRIG_SYNC_OC5       0x00050000
#define CAPTURE_TRIG_SYNC_OC6       0x00060000
#define CAPTURE_TRIG_SYNC_OC7       0x00070000
#define CAPTURE_TRIG_SYNC_OC8       0x00080000
#define CAPTURE_TRIG_SYNC_OC9       0x00090000
#define CAPTURE_TRIG_SYNC_IC5       0x000A0000
#define CAPTURE_TRIG_SYNC_TIMER1    0x000B0000
#define CAPTURE_TRIG_SYNC_TIMER2    0x000C0000
#define CAPTURE_TRIG_SYNC_TIMER3    0x000D0000
#define CAPTURE_TRIG_SYNC_TIMER4    0x000E0000
#define CAPTURE_TRIG_SYNC_TIMER5    0x000F0000
#define CAPTURE_TRIG_SYNC_IC7       0x00120000
#define CAPTURE_TRIG_SYNC_IC8       0x00130000
#define CAPTURE_TRIG_SYNC_IC1       0x00140000
#define CAPTURE_TRIG_SYNC_IC2       0x00150000
#define CAPTURE_TRIG_SYNC_IC3       0x00160000
#define CAPTURE_TRIG_SYNC_IC4       0x00170000
#define CAPTURE_TRIG_SYNC_COMP1     0x00180000  //Trigger Source only
#define CAPTURE_TRIG_SYNC_COMP2     0x00190000  //Trigger Source only
#define CAPTURE_TRIG_SYNC_COMP3     0x001A0000  //Trigger Source only
#define CAPTURE_TRIG_SYNC_ADC       0x001B0000  //Trigger Source only
#define CAPTURE_TRIG_SYNC_CTMU      0x001C0000  //Trigger Source only
#define CAPTURE_TRIG_SYNC_IC6       0x001D0000
#define CAPTURE_TRIG_SYNC_IC9       0x001E0000
#define CAPTURE_TRIG_SYNC_NONE               0

/////////////////////////////////////////////////////////// OUTPUT COMPARE
// Functions: SETUP_COMPARE, SET_PWM_DUTY, SET_COMPARE_TIME
//            SETUP_PWM_PERIOD
//
// Constants used for SETUP_COMPARE() are:
#define COMPARE_OFF               0x0000  // Compare OFF
#define COMPARE_SET_ON_MATCH      0x0001  // Pin from low to high on match
#define COMPARE_CLR_ON_MATCH      0x0002  // Pin from high to low on match
#define COMPARE_TOGGEL            0x0003  // Pin will toggle on every match occurrence
#define COMPARE_SINGLE_PULSE      0x0004  // Pin will generate single pulse on first match
#define COMPARE_CONT_PULSE        0x0005  // Pin will pulse for every match
#define COMPARE_PWM_EDGE          0x0006
#define COMPARE_PWM_CENTER        0x0007

// The following defines can be ORed | with above
#define COMPARE_TIMER2     	      0x0000
#define COMPARE_TIMER3     	      0x0400
#define COMPARE_TIMER4     	      0x0800
#define COMPARE_TIMER5     	      0x0C00
#define COMPARE_TIMER1     	      0x1000
#define COMPARE_SYSTEM_CLOCK      0x1C00

#define COMPARE_FAULT0            0x0080
#define COMPARE_NO_FAULT0         0x0000

#define COMPARE_FAULT_CLEAR       0x80000000
#define COMPARE_FAULT_NEW         0x00000000
#define COMPARE_PWM_HIGH_ON_FAULT 0x40000000
#define COMPART_PWM_LOW_ON_FAULT  0x00000000
#define COMPARE_FAULT_OUTPUT      0x20000000
#define COMPARE_INVERT_OC_PIN     0x10000000
#define COMPARE_32_BIT            0x01000000
#define COMPARE_TRIGGER           0x00800000
#define COMPARE_SYNCHRONIZE       0x00000000
#define COMPARE_OC_PIN_TRISTATED  0x00200000
#define COMPARE_TRIG_SYNC_SELF    0x001F0000
#define COMPARE_TRIG_SYNC_CAP9    0x001E0000
#define COMPARE_TRIG_SYNC_CAP6    0x001D0000
#define COMPARE_TRIG_SYNC_CTMU    0x001C0000
#define COMPARE_TRIG_SYNC_ADC     0x001B0000
#define COMPARE_TRIG_SYNC_COMP3   0x001A0000
#define COMPARE_TRIG_SYNC_COMP2   0x00190000
#define COMPARE_TRIG_SYNC_COMP1	  0x00180000
#define COMPARE_TRIG_SYNC_CAP4    0x00170000
#define COMPARE_TRIG_SYNC_CAP3    0x00160000
#define COMPARE_TRIG_SYNC_CAP2    0x00150000
#define COMPARE_TRIG_SYNC_CAP1    0x00140000
#define COMPARE_TRIG_SYNC_CAP8    0x00130000
#define COMPARE_TRIG_SYNC_CAP7    0x00120000
#define COMPARE_TRIG_SYNC_TIMER5  0x000F0000
#define COMPARE_TRIG_SYNC_TIMER4  0x000E0000
#define COMPARE_TRIG_SYNC_TIMER3  0x000D0000
#define COMPARE_TRIG_SYNC_TIMER2  0x000C0000
#define COMPARE_TRIG_SYNC_TIMER1  0x000B0000
#define COMPARE_TRIG_SYNC_CAP5    0x000A0000
#define COMPARE_TRIG_SYNC_OC9     0x00090000
#define COMPARE_TRIG_SYNC_OC8     0x00080000
#define COMPARE_TRIG_SYNC_OC7     0x00070000
#define COMPARE_TRIG_SYNC_OC6     0x00060000
#define COMPARE_TRIG_SYNC_OC5     0x00050000
#define COMPARE_TRIG_SYNC_OC4     0x00040000
#define COMPARE_TRIG_SYNC_OC3     0x00030000
#define COMPARE_TRIG_SYNC_OC2     0x00020000
#define COMPARE_TRIG_SYNC_OC1     0x00010000
#define COMPARE_TRIG_SYNC_NONE    0x00000000

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
#define ADC_CLOCK_DIV_64   0x007F   
#define ADC_CLOCK_DIV_128  0x00FF   
#define ADC_CLOCK_INTERNAL 0x8000     // Internal

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
#define sAN16      0x00010000 //| C4
#define sAN17      0x00020000 //| G6
#define sAN18      0x00040000 //| G7
#define sAN19      0x00080000 //| G8
#define sAN20      0x00100000 //| G9
#define sAN21      0x00200000 //| E9
#define sAN22      0x00400000 //| A7
#define sAN23      0x00800000 //| A6

// Optional Second argument:
#define VSS_VDD            0x0000 // Range 0-Vdd
#define VREF_VREF          0x6000 // Range VrefL-VrefH
#define VREF_VDD           0x4000 // Range VrefL-Vdd
#define VSS_VREF           0x2000 // Range 0-VrefH

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
#bit C2OUT = 0x636.8
#bit C2ENV = 0x636.9  // User must clear
#bit C3OUT = 0x638.8
#bit C3ENV = 0x638.9  // User must clear

////////////////////////////////////////////////////////////////// VREF
// Constants used in setup_vref() are:
//
#define VREF_DISABLED  0x0000
#define VREF_ANALOG    0x0010
#define VREF_HIGH      0x1000
#define VREF_LOW       0x1020
// Or (with |) the above with a number 0-15

////////////////////////////////////////////////////////////////// EPMP
// EPMP Functions: SETUP_PMP(), SETUP_PMP_CSx(), SETUP_PSP(), SETUP_PSP_CS(),
// PMP_WRITE16(), PMP_WRITE8(), PSP_WRITE(), PMP_READ16(), PMP_READ8(),
// PSP_READ(), PSP_OUTPUT_FULL(), PSP_INPUT_FULL(), PSP_OVERFLOW(),
// PMP_ERROR(), PSP_ERROR(), PMP_TIMEOUT(), PSP_TIMEOUT()
//
// Constants used in SETUP_PMP() and SETUP_PSP() first parm are:
#define PAR_ENABLE                    0x00008000
#define PAR_DISABLE                   0x00000000 // Module enable/disable options
#define PAR_STOP_IN_IDLE              0x00002000
#define PAR_CONTINUE_IN_IDLE          0x00000000
#define PAR_ADDR_MULTIPLEXED_3_PHASES 0x00001800 // Address multiplexing options
#define PAR_ADDR_MULTIPLEXED_2_PHASES 0x00001000 // Address multiplexing options
#define PAR_ADDR_MULTIPLEXED_1_PHASE  0x00000800 // Address multiplexing options
#define PAR_ADDR_NOT_MULTIPLEXED      0x00000000 // Address multiplexing options
#define PAR_MASTER_MODE               0x00000300 // Master mode
#define PAR_ENHANCED_PSP              0x00000200 // Enhanced PSP
#define PAR_BUFFERED_PSP              0x00000100 // Buffered PSP
#define PAR_LEGACY_PSP                0x00000000 // Legacy Parallel Slave Port
#define PAR_CS_00                     0x00000080 // PMA15 used for Chip Select 2, PMA14 used for Chip Select 1
#define PAR_CS_01                     0x00000040 // PMA15 used for Chip Select 2, PMCS1 used for Chip Select 1
#define PAR_CS_11                     0x00000000 // PMCS2 used for Chip Select 2, PMCS1 used for Chip Select 1
#define PAR_ALP_ACTIVE_HIGH           0x00000020 // Address latch polarity high
#define PAR_ALS_SMART                 0x00000010 // Enable "smart" address strobes
#define PAR_DATA_BUS_KEEPS            0x00000004 // Data bus keeps its last value when not actively being driven
#define PAR_INTR_ON_3_RW_BUF          0x00000003 // Interrupt on write to Buffer 3 or read from Buffer 3
#define PAR_INTR_ON_RW                0x00000001 // Interrupt on read write
#define PAR_NO_INTR                   0x00000000 // No interrupt
#define PAR_PTWREN_ENABLE             0x80000000 // Write/Enable Strobe Port Enable bit
#define PAR_PTRDEN_ENABLE             0x40000000 // Read/Write Strobe Port Enable bit
#define PAR_PTBE1EN_ENABLE            0x20000000 // High Nibble/Byte Enable Port Enable bit
#define PAR_PTBE0EN_ENABLE            0x10000000 // Low Nibble/Byte Enable Port Enable bit
#define PAR_AWAITM3                   0x06000000 // Wait of 3 1/2 Tcy
#define PAR_AWAITM2                   0x04000000 // Wait of 2 1/2 Tcy
#define PAR_AWAITM1                   0x02000000 // Wait of 1 1/2 Tcy
#define PAR_AWAITM0                   0x00000000 // Wait of 1/2 Tcy
#define PAR_AWAITE1                   0x01000000 // Wait of 1 1/4 Tcy
#define PAR_AWAITE0                   0x00000000 // Wait of 1/4 Tcy
#define PAR_USE_TTL_INPUT_BUFFERS     0x00010000 // EPMP module inputs use TTL input buffers
#define PAR_USE_SC_INPUT_BUFFERS      0x00000000 // EPMP module inputs use Schmitt Trigger input buffers

// Constants used in SETUP_PMP_CSx() and SETUP_PSP_CS() first parm are:
#define PAR_ENABLE_CS                 0x00000000 // Enable the Chip Select x functionality
#define PAR_DISABLE_CS                0x00008000 // Disable the Chip Select x functionality
#define PAR_CSP_ACTIVE_HIGH           0x00004000 // Chip Select x polarity high
#define PAR_CSPTEN_ENABLE             0x00002000 // PMCSx Port Enable bit
#define PAR_BEP_ACTIVE_HIGH           0x00001000 // PMBEx polarity high
#define PAR_WRSP_ACTIVE_HIGH          0x00000400 // PMWR or PMENB polarity high
#define PAR_RDSP_ACTIVE_HIGH          0x00000200 // PMRD polarity high
#define PAR_SM_READ_WRITE_AND_ENABLE  0x00000100 // Read/Write and Enable strobes (PMRD/PMWR and PMENB)
#define PAR_SM_READ_AND_WRITE         0x00000000 // Read and Write strobes (PMRD and PMWR)
#define PAR_ACKP_ACTIVE_HIGH          0x00000080 // PMACKx polarity high
#define PAR_PTSZ_16_BIT               0x00000040 // 16-bit port size
#define PAR_PTSZ_4_BIT                0x00000020 // 4-bit port size
#define PAR_PTSZ_8_BIT                0x00000000 // 8-bit port size
#define PAR_USE_ACK                   0x80000000 // PMACKx is used to determine when a read/write operation is complete
#define PAR_USE_ACK_WITH_TIMEOUT      0x40000000 // PMACKx is used to determine when a read/write operation is complete with timeout
#define PAR_ACK_NOT_USED              0x00000000 // PMACKx is not used
#define PAR_AMWAIT10                  0x38000000 // Wait 10 Alternate Master Cycles
#define PAR_AMWAIT9                   0x30000000 // Wait 9 Alternate Master Cycles
#define PAR_AMWAIT8                   0x28000000 // Wait 8 Alternate Master Cycles
#define PAR_AMWAIT7                   0x20000000 // Wait 7 Alternate Master Cycles
#define PAR_AMWAIT6                   0x18000000 // Wait 6 Alternate Master Cycles
#define PAR_AMWAIT5                   0x10000000 // Wait 5 Alternate Master Cycles
#define PAR_AMWAIT4                   0x08000000 // Wait 4 Alternate Master Cycles
#define PAR_AMWAIT3                   0x00000000 // Wait 3 Alternate Master Cycles
#define PAR_DWAITB3                   0x00C00000 // 3 1/4 Tcy Wait state for data setup R/W
#define PAR_DWAITB2                   0x00800000 // 2 1/4 Tcy Wait state for data setup R/W
#define PAR_DWAITB1                   0x00400000 // 1 1/4 Tcy Wait state for data setup R/W
#define PAR_DWAITB0                   0x00000000 // 1/4 Tcy Wait state for data setup R/W
#define PAR_DWAITM15                  0x003C0000 // 15 1/2 Tcy Wait state for write to byte, 15 3/4 Tcy Wait state for read
#define PAR_DWAITM14                  0x00380000 // 14 1/2 Tcy Wait state for write to byte, 14 3/4 Tcy Wait state for read
#define PAR_DWAITM13                  0x00340000 // 13 1/2 Tcy Wait state for write to byte, 13 3/4 Tcy Wait state for read
#define PAR_DWAITM12                  0x00300000 // 12 1/2 Tcy Wait state for write to byte, 12 3/4 Tcy Wait state for read
#define PAR_DWAITM11                  0x002C0000 // 11 1/2 Tcy Wait state for write to byte, 11 3/4 Tcy Wait state for read
#define PAR_DWAITM10                  0x00280000 // 10 1/2 Tcy Wait state for write to byte, 10 3/4 Tcy Wait state for read
#define PAR_DWAITM9                   0x00240000 // 9 1/2 Tcy Wait state for write to byte, 9 3/4 Tcy Wait state for read
#define PAR_DWAITM8                   0x00200000 // 8 1/2 Tcy Wait state for write to byte, 8 3/4 Tcy Wait state for read
#define PAR_DWAITM7                   0x001C0000 // 7 1/2 Tcy Wait state for write to byte, 7 3/4 Tcy Wait state for read
#define PAR_DWAITM6                   0x00180000 // 6 1/2 Tcy Wait state for write to byte, 6 3/4 Tcy Wait state for read
#define PAR_DWAITM5                   0x00140000 // 5 1/2 Tcy Wait state for write to byte, 5 3/4 Tcy Wait state for read
#define PAR_DWAITM4                   0x00100000 // 4 1/2 Tcy Wait state for write to byte, 4 3/4 Tcy Wait state for read
#define PAR_DWAITM3                   0x000C0000 // 3 1/2 Tcy Wait state for write to byte, 3 3/4 Tcy Wait state for read
#define PAR_DWAITM2                   0x00080000 // 2 1/2 Tcy Wait state for write to byte, 2 3/4 Tcy Wait state for read
#define PAR_DWAITM1                   0x00040000 // 1 1/2 Tcy Wait state for write to byte, 1 3/4 Tcy Wait state for read
#define PAR_DWAITM0                   0x00000000 // 1/2 Tcy Wait state for write to byte, 3/4 Tcy Wait state for read
#define PAR_DWAITE3                   0x00030000 // 3 1/4 Tcy Wait state for data hold after write strobe, 3 Tcy Wait state after read strobe
#define PAR_DWAITE2                   0x00020000 // 2 1/4 Tcy Wait state for data hold after write strobe, 2 Tcy Wait state after read strobe
#define PAR_DWAITE1                   0x00010000 // 1 1/4 Tcy Wait state for data hold after write strobe, 1 Tcy Wait state after read strobe
#define PAR_DWAITE0                   0x00000000 // 1/4 Tcy Wait state for data hold after write strobe, 0 Tcy Wait state after read strobe

////////////////////////////////////////////////////////////////// LCD
// LCD Functions: SETUP_LCD, LCD_SYMBOL, LCD_LOAD, LCD_CONTRAST
// Constants used in setup_lcd() are:

// LCD Multiplex Mode (first param)
#define LCD_STATIC         0x0000000000008000
#define LCD_MUX12          0x0000000000008001
#define LCD_MUX13          0x0000000000008002
#define LCD_MUX14          0x0000000000008003
#define LCD_MUX15          0x0000000000008004
#define LCD_MUX16          0x0000000000008005
#define LCD_MUX17          0x0000000000008006
#define LCD_MUX18          0x0000000000008007
#define LCD_DISABLED       0x0000000000000000

//      Any of the following may be or'ed in with the first parametter
// LCD Sleep Mode
#define LCD_HALT_IDLE      0x0000000000002000
#define LCD_CONTINUE_IDLE  0x0000000000000000   //default

// LCD Clock Source
#define LCD_FRC            0x0000000000000000   //default
#define LCD_LPRC           0x0000000000000008
#define LCD_SOSC           0x0000000000000010

// LCD Waveform Type
#define LCD_TYPE_B         0x0000000000800000
#define LCD_TYPE_A         0x0000000000000000  //default

// LCD Bias Mode (MUX12 & MUX13 Only)
#define LCD_BIAS12         0x0000000000400000
#define LCD_BIAS13         0x0000000000000000  //default

// LCD Internal Reference Enable
#define LCD_REF_ENABLED    0x0000800000000000
#define LCD_REF_DISABLED   0x0000000000000000  //default

// LCD Voltage Pin Enable
#define LCD_VOLTAGE3       0x0000040000000000
#define LCD_VOLTAGE2       0x0000020000000000
#define LCD_VOLTAGE1       0x0000010000000000
#define LCD_NO_VOLTAGE     0x0000000000000000 //default

// LCD Ladder A Controls
#define LCD_A_NO_POWER     0x0000000000000000 //default
#define LCD_A_LOW_POWER    0x0000004000000000
#define LCD_A_MED_POWER    0x0000008000000000
#define LCD_A_HIGH_POWER   0x000000C000000000

// LCD Ladder B Controls
#define LCD_B_NO_POWER     0x0000000000000000 //default
#define LCD_B_LOW_POWER    0x0000001000000000
#define LCD_B_MED_POWER    0x0000002000000000
#define LCD_B_HIGH_POWER   0x0000003000000000

// LCD Ladder A Time Interval
#define LCD_B_ONLY         0x0000000000000000  //default
#define LCD_A_CLOCK1       0x0000010000000000
#define LCD_A_CLOCK2       0x0000020000000000
#define LCD_A_CLOCK3       0x0000030000000000
#define LCD_A_CLOCK4       0x0000040000000000
#define LCD_A_CLOCK5       0x0000050000000000
#define LCD_A_CLOCK6       0x0000060000000000
#define LCD_A_CLOCK7       0x0000070000000000

// LCD Charge Pump Control
#define LCD_CP_ENABLED     0x8000000000000000
#define LCD_CP_DISABLED    0x0000000000000000  //default

// LCD Charge Pump Clock
#define LCD_CP_NO_CLOCK    0x0000000000000000  //default
#define LCD_CP_SOSC        0x0001000000000000
#define LCD_CP_FRC         0x0002000000000000
#define LCD_CP_LPRC        0x0003000000000000

// LCD Charge Pump Bias Support
#define LCD_CP_STATIC      0x0000000000000000  //default
#define LCD_CP_BIAS13      0x0004000000000000

// LCD Charge Pump Regulator Output
#define LCD_CP_2V69        0x0000000000000000  //2.69V peak //default
#define LCD_CP_2V82        0x0008000000000000  //2.82V peak
#define LCD_CP_2V95        0x0010000000000000  //2.95V peak
#define LCD_CP_3V08        0x0018000000000000  //3.08V peak
#define LCD_CP_3V21        0x0020000000000000  //3.21V peak
#define LCD_CP_3V34        0x0028000000000000  //3.34V peak
#define LCD_CP_3V47        0x0030000000000000  //3.47V peak
#define LCD_CP_3V60        0x0038000000000000  //3.60V peak

// Constants used in lcd_symbol() are:
#define COM0 0
#define COM1 64
#define COM2 128
#define COM3 192
#define COM4 256
#define COM5 320
#define COM6 384
#define COM7 448
////////////////////////////////////////////////////////////////// DSM
// Data Signal Modulator Functions: SETUP_DSM()
// Constants used in SETUP_DSM() first param are:
#define DSM_ENABLED                     0x8000
#define DSM_DISABLED                    0x0000
#define DSM_HALT_IDLE                   0x2000
#define DSM_OUTPUT_ENABLED              0x0040
#define DSM_SLEW_RATE_LIMITING_ENABLED  0x0020
#define DSM_OUTPUT_INVERTED             0x0010
//Constants used as the second param are:
#define DSM_SOURCE_MANUAL               0x0000
#define DSM_SOURCE_MDMIN                0x0001
#define DSM_SOURCE_SPI1                 0x0002
#define DSM_SOURCE_SPI2                 0x0003
#define DSM_SOURCE_UART1                0x0004
#define DSM_SOURCE_UART2                0x0005
#define DSM_SOURCE_UART3                0x0006
#define DSM_SOURCE_UART4                0x0007
#define DSM_SOURCE_OC1                  0x0008
#define DSM_SOURCE_OC2                  0x0009
#define DSM_SOURCE_OC3                  0x000A
#define DSM_SOURCE_OC4                  0x000B
#define DSM_SOURCE_OC5                  0x000C
#define DSM_SOURCE_OC6                  0x000D
#define DSM_SOURCE_OC7                  0x000E
#define DSM_DISABLE_SOURCE              0x0080
//Constants used as the third param are:
#define DSM_CARRIER_LOW_VSS             0x0000
#define DSM_CARRIER_LOW_MDCIN1          0x0001
#define DSM_CARRIER_LOW_MDCIN2          0x0002
#define DSM_CARRIER_LOW_REFO            0x0003
#define DSM_CARRIER_LOW_OC1             0x0004
#define DSM_CARRIER_LOW_OC2             0x0005
#define DSM_CARRIER_LOW_OC3             0x0006
#define DSM_CARRIER_LOW_OC4             0x0007
#define DSM_CARRIER_LOW_OC5             0x0008
#define DSM_CARRIER_LOW_OC6             0x0009
#define DSM_CARRIER_LOW_OC7             0x000A
#define DSM_SYNC_CARRIER_LOW            0x0020
#define DSM_INVERT_CARRIER_LOW          0x0040
#define DSM_DISABLE_CARRIER_LOW         0x0080
#define DSM_CARRIER_HIGH_VSS            0x0000
#define DSM_CARRIER_HIGH_MDCIN1         0x0100
#define DSM_CARRIER_HIGH_MDCIN2         0x0200
#define DSM_CARRIER_HIGH_REFO           0x0300
#define DSM_CARRIER_HIGH_OC1            0x0400
#define DSM_CARRIER_HIGH_OC2            0x0500
#define DSM_CARRIER_HIGH_OC3            0x0600
#define DSM_CARRIER_HIGH_OC4            0x0700
#define DSM_CARRIER_HIGH_OC5            0x0800
#define DSM_CARRIER_HIGH_OC6            0x0900
#define DSM_CARRIER_HIGH_OC7            0x0A00
#define DSM_SYNC_CARRIER_HIGH           0x2000
#define DSM_INVERT_CARRIER_HIGH         0x4000
#define DSM_DISABLE_CARRIER_HIGH        0x8000

#bit MDBIT = getenv("SFR:MDCON").0

////////////////////////////////////////////////////////////////// CRC
// CRC Functions: setup_crc(), crc_init(), crc_calc32(),
//                crc_calc16(), crc_calc8()
// Constants used in setup_crc() are:
#define CRC_LITTLE_ENDIAN    128

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

// Constants used in setup_rtc() are:  // Second param is calibration
#define RTC_ENABLE               0x00008000
#define RTC_DISABLE              0
#define RTC_CLOCK_EXT_60HZ       0x0C000000
#define RTC_CLOCK_EXT_50HZ       0x08000000
#define RTC_CLOCK_INT            0x04000000
#define RTC_CLOCK_SOSC           0
#define RTC_OUTPUT_PWC           0x03000400
#define RTC_OUTPUT_CLOCK         0x02000400
#define RTC_OUTPUT_SECONDS       0x01000400
#define RTC_OUTPUT_ALARM         0x0000400
// OR in any of the following:
#define RTC_PWC_ENABLE           0x80000000
#define RTC_PWC_HIGH             0x40000000
#define RTC_PWC_LOW              0
#define RTC_PWC_STAB_CLOCK_DIV2  0x20000000
#define RTC_PWC_STAB_CLOCK_DIV1  0
#define RTC_PWC_SAMP_CLOCK_DIV2  0x10000000
#define RTC_PWC_SAMP_CLOCK_DIV1  0

// Constants used in setup_rtc_alarm() first param are:  
#define RTC_ALARM_ENABLE         0x8000
#define RTC_ALARM_DISABLE        0
#define RTC_CHIME_ENABLE         0x4000
#define RTC_CHIME_DISABLE        0
// Constants used in setup_rtc_alarm() second param are:  // Third param is repeat#
#define RTC_ALARM_HALFSECOND     0x0000
#define RTC_ALARM_SECOND         0x0400
#define RTC_ALARM_10_SECONDS     0x0800
#define RTC_ALARM_MINUTE         0x0C00
#define RTC_ALARM_10_MINUTES     0x1000
#define RTC_ALARM_HOUR           0x1400
#define RTC_ALARM_DAY            0x1800
#define RTC_ALARM_WEEK           0x1C00
#define RTC_ALARM_MONTH          0x2000
#define RTC_ALARM_YEAR           0x2400

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

//////////////////////////////////////////////////////////////////  DMA
// DMA Functions: setup_dma(), dma_start(), dma_status()
//
// Constants used in setup_dma() second param are:
#define DMA_TRIGGER_JTAG           0x00000100
#define DMA_TRIGGER_LCD            0x00000200
#define DMA_TRIGGER_TBE4           0x00000300
#define DMA_TRIGGER_RDA4           0x00000400
#define DMA_TRIGGER_UART4E         0x00000500
#define DMA_TRIGGER_TBE3           0x00000600
#define DMA_TRIGGER_RDA3           0x00000700
#define DMA_TRIGGER_UART3E         0x00000800
#define DMA_TRIGGER_CTMU           0x00000900
#define DMA_TRIGGER_HLVD           0x00000A00
#define DMA_TRIGGER_CRC            0x00000B00
#define DMA_TRIGGER_UART2E         0x00000C00
#define DMA_TRIGGER_UART1E         0x00000D00
#define DMA_TRIGGER_RTC            0x00000E00
#define DMA_TRIGGER_DMA5           0x00000F00
#define DMA_TRIGGER_EXT4           0x00001000
#define DMA_TRIGGER_EXT3           0x00001100
#define DMA_TRIGGER_MI2C2          0x00001200
#define DMA_TRIGGER_SI2C2          0x00001300
#define DMA_TRIGGER_DMA4           0x00001400
#define DMA_TRIGGER_PMP            0x00001500
#define DMA_TRIGGER_OC7            0x00001600
#define DMA_TRIGGER_OC6            0x00001700
#define DMA_TRIGGER_OC5            0x00001800
#define DMA_TRIGGER_IC6            0x00001900
#define DMA_TRIGGER_IC5            0x00001A00
#define DMA_TRIGGER_IC4            0x00001B00
#define DMA_TRIGGER_IC3            0x00001C00
#define DMA_TRIGGER_DMA3           0x00001D00
#define DMA_TRIGGER_SPI2           0x00001E00
#define DMA_TRIGGER_SPI2E          0x00001F00
#define DMA_TRIGGER_TBE2           0x00002000
#define DMA_TRIGGER_RDA2           0x00002100
#define DMA_TRIGGER_EXT2           0x00002200
#define DMA_TRIGGER_TIMER5         0x00002300
#define DMA_TRIGGER_TIMER4         0x00002400
#define DMA_TRIGGER_OC4            0x00002500
#define DMA_TRIGGER_OC3            0x00002600
#define DMA_TRIGGER_DMA2           0x00002700
#define DMA_TRIGGER_IC7            0x00002800
#define DMA_TRIGGER_EXT1           0x00002900
#define DMA_TRIGGER_CNI            0x00002A00
#define DMA_TRIGGER_COMP           0x00002B00
#define DMA_TRIGGER_MI2C           0x00002C00
#define DMA_TRIGGER_SI2C           0x00002D00
#define DMA_TRIGGER_DMA1           0x00002E00
#define DMA_TRIGGER_ADC1           0x00002F00
#define DMA_TRIGGER_TBE            0x00003000
#define DMA_TRIGGER_RDA            0x00003100
#define DMA_TRIGGER_SPI1           0x00003200
#define DMA_TRIGGER_SPI1E          0x00003300
#define DMA_TRIGGER_TIMER3         0x00003400
#define DMA_TRIGGER_TIMER2         0x00003500
#define DMA_TRIGGER_OC2            0x00003600
#define DMA_TRIGGER_IC2            0x00003700
#define DMA_TRIGGER_DMA0           0x00003800
#define DMA_TRIGGER_TIMER1         0x00003900
#define DMA_TRIGGER_OC1            0x00003A00
#define DMA_TRIGGER_IC1            0x00003B00
#define DMA_TRIGGER_EXT0           0x00003C00
// Constants used in setup_dma() third param are:
#define DMA_ROUND_ROBIN            0x00000002
#define DMA_HALF_INT               0x00000001
#define DMA_WRITE_NULL             0x04000000
#define DMA_RELOAD_ADDRESS         0x02000000
#define DMA_BYTE                   0x00020000
#define DMA_WORD                   0x00000000  //default

// Constants used in dma_start() second param are:
#define DMA_SOURCE_PIA_MODE        0x00C0
#define DMA_DEC_SOURCE_ADDR        0x0080
#define DMA_INC_SOURCE_ADDR        0x0040
#define DMA_SOURCE_ADDR_UNCHANGED  0x0000
// or (via |) one of the following with the above
#define DMA_DEST_PIA_MODE          0x0030
#define DMA_DEC_DEST_ADDR          0x0020
#define DMA_INC_DEST_ADDR          0x0010
#define DMA_DEST_ADDR_UNCHANGED    0x0000
// or (via |) one of the following with the above
#define DMA_CONTINUOUS             0x0008
#define DMA_ONE_SHOT               0x0000
// or (via |) the following with the above
#define DMA_REPEATED               0x0004
#define DMA_FORCE_NOW              0x0100

// Constants returned from dma_status() are:
#define DMA_ERROR_OVERRUN          0x0008
#define DMA_HALF_DONE              0x0010
#define DMA_DONE                   0x0020
#define DMA_ERROR_ADDR_BELOW_DMAL  0x0040
#define DMA_ERROR_ADDR_ABOVE_DMAH  0x0080
#define DMA_REQUEST_INITIATED      0x0100
#define DMA_BUFFER_NOT_WRITTEN     0x8000

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
#define INT_DMA0                  69
#define INT_IC2                   70
#define INT_OC2                   71
#define INT_TIMER2                72
#define INT_TIMER3                73
#define INT_SPI1E                 74
#define INT_SPI1                  75
#define INT_RDA                   76
#define INT_TBE                   77
#define INT_ADC1                  78
#define INT_DMA1                  79
#define INT_SI2C                  81
#define INT_MI2C                  82
#define INT_CNI                   84
#define INT_EXT1                  85
#define INT_IC7                   87
#define INT_DMA2                  89
#define INT_OC3                   90
#define INT_OC4                   91
#define INT_TIMER4                92
#define INT_TIMER5                93
#define INT_EXT2                  94
#define INT_RDA2                  95
#define INT_TBE2                  96
#define INT_SPI2E                 97
#define INT_SPI2                  98
#define INT_DMA3                  101
#define INT_IC3                   102
#define INT_IC4                   103
#define INT_IC5                   104
#define INT_IC6                   105
#define INT_OC5                   106
#define INT_OC6                   107
#define INT_OC7                   108
#define INT_DMA4                  111
#define INT_SI2C2                 114
#define INT_MI2C2                 115
#define INT_EXT3                  118
#define INT_EXT4                  119
#define INT_DMA5                  126
#define INT_UART1E                130
#define INT_UART2E                131
#define INT_UART3E                141
#define INT_RDA3                  142
#define INT_TBE3                  143
#define INT_UART4E                144
#define INT_RDA4                  145
#define INT_TBE4                  146
#define INT_COMP                  152
#define INT_PMP                   164
#define INT_RTC                   173
#define INT_CRC                   174
#define INT_CTMU                  176
#define INT_LVD                   179

#list
