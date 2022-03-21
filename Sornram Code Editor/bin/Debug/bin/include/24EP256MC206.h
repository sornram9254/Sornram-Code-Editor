//////// Standard Header file for the PIC24EP256MC206 device ////////////////
#device PIC24EP256MC206
#nolist
//////// Program memory: 88054x24  Data RAM: 32768  Stack: 31
//////// I/O: 53   Analog Pins: 16
//////// Fuses: ICSP3,ICSP2,ICSP1,NOJTAG,JTAG,DEBUG,NODEBUG,ALTI2C1
//////// Fuses: NOALTI2C1,ALTI2C2,NOALTI2C2,WDTWIN_75%,WDTWIN_50%,WDTWIN_37%
//////// Fuses: WDTWIN_25%,WPOSTS1,WPOSTS2,WPOSTS3,WPOSTS4,WPOSTS5,WPOSTS6
//////// Fuses: WPOSTS7,WPOSTS8,WPOSTS9,WPOSTS10,WPOSTS11,WPOSTS12,WPOSTS13
//////// Fuses: WPOSTS14,WPOSTS15,WPOSTS16,WPRES32,WPRES128,NOPLLWAIT
//////// Fuses: PLLWAIT,NOWINDIS,WINDIS,NOWDT,WDT,EC,XT,HS,NOPR,OSCIO
//////// Fuses: NOOSCIO,NOIOL1WAY,IOL1WAY,CKSFSM,CKSNOFSM,NOCKSNOFSM,FRC
//////// Fuses: FRC_PLL,PR,PR_PLL,LPRC,FRC_PS,NOPWMLOCK,PWMLOCK,NOIESO,IESO
//////// Fuses: WRT,NOWRT,PROTECT,NOPROTECT
//////// 
////////////////////////////////////////////////////////////////// I/O
// Discrete I/O Functions: SET_TRIS_x(), OUTPUT_x(), INPUT_x(),
//                         SET_PULLUP(), INPUT(),
//                         OUTPUT_LOW(), OUTPUT_HIGH(),
//                         OUTPUT_FLOAT(), OUTPUT_BIT()
// Constants used to identify pins in the above are:

#define PIN_A0  28688
#define PIN_A1  28689
#define PIN_A4  28692
#define PIN_A7  28695
#define PIN_A8  28696
#define PIN_A9  28697
#define PIN_A10  28698
#define PIN_A11  28699
#define PIN_A12  28700

#define PIN_B0  28816
#define PIN_B1  28817
#define PIN_B2  28818
#define PIN_B3  28819
#define PIN_B4  28820
#define PIN_B5  28821
#define PIN_B6  28822
#define PIN_B7  28823
#define PIN_B8  28824
#define PIN_B9  28825
#define PIN_B10  28826
#define PIN_B11  28827
#define PIN_B12  28828
#define PIN_B13  28829
#define PIN_B14  28830
#define PIN_B15  28831

#define PIN_C0  28944
#define PIN_C1  28945
#define PIN_C2  28946
#define PIN_C3  28947
#define PIN_C4  28948
#define PIN_C5  28949
#define PIN_C6  28950
#define PIN_C7  28951
#define PIN_C8  28952
#define PIN_C9  28953
#define PIN_C10  28954
#define PIN_C11  28955
#define PIN_C12  28956
#define PIN_C13  28957
#define PIN_C15  28959

#define PIN_D5  29077
#define PIN_D6  29078
#define PIN_D8  29080

#define PIN_E12  29212
#define PIN_E13  29213
#define PIN_E14  29214
#define PIN_E15  29215

#define PIN_F0  29328
#define PIN_F1  29329

#define PIN_G6  29462
#define PIN_G7  29463
#define PIN_G8  29464
#define PIN_G9  29465

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
#define CAPTURE_TRIG_SYNC_PTGOx     0x000A0000 
#define CAPTURE_TRIG_SYNC_TIMER1    0x000B0000
#define CAPTURE_TRIG_SYNC_TIMER2    0x000C0000
#define CAPTURE_TRIG_SYNC_TIMER3    0x000D0000
#define CAPTURE_TRIG_SYNC_TIMER4    0x000E0000
#define CAPTURE_TRIG_SYNC_TIMER5    0x000F0000
#define CAPTURE_TRIG_SYNC_IC1       0x00100000
#define CAPTURE_TRIG_SYNC_IC2       0x00110000
#define CAPTURE_TRIG_SYNC_IC3       0x00120000
#define CAPTURE_TRIG_SYNC_IC4       0x00130000
#define CAPTURE_TRIG_SYNC_COMP1     0x00180000  //Trigger Source only
#define CAPTURE_TRIG_SYNC_COMP2     0x00190000  //Trigger Source only
#define CAPTURE_TRIG_SYNC_COMP3     0x001A0000  //Trigger Source only
#define CAPTURE_TRIG_SYNC_ADC       0x001B0000  //Trigger Source only
#define CAPTURE_TRIG_SYNC_CTMU      0x001C0000  //Trigger Source only 
#define CAPTURE_TRIG_SYNC_NONE               0

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
#define COMPARE_PWM_EDGE          0x0006
#define COMPARE_PWM_CENTER        0x0007

// One of the following defines maybe ORed | with above
#define COMPARE_TIMER2     	      0x0000
#define COMPARE_TIMER3     	      0x0400
#define COMPARE_TIMER4     	      0x0800
#define COMPARE_TIMER5     	      0x0C00
#define COMPARE_TIMER1     	      0x1000
#define COMPARE_SYSTEM_CLOCK      0x1C00

// The following defines maybe ORed | with above
#define COMPARE_FAULTA            0x0080
#define COMPARE_FAULTB            0x0100

// The following defines maybe ORed | with above
#define COMPARE_FAULT_CLEARED_SW  0x80000000
#define COMPARE_HIGH_ON_FAULT     0x40000000
#define COMPARE_LOW_ON_FAULT      0x00000000
#define COMPARE_TRISTATE_ON_FAULT 0x20000000
#define COMPARE_INVERT_OUTPUT     0x10000000
#define COMPARE_32_BIT            0x01000000
#define COMPARE_TRIGGER           0x00800000
#define COMPARE_SYNCHRONIZE       0x00000000
#define COMPARE_OUTPUT_TRISTATED  0x00200000

// One of the following maybe ORed | with above
#define COMPARE_TRIG_SYNC_INT2    0x001E0000
#define COMPARE_TRIG_SYNC_INT1    0x001D0000
#define COMPARE_TRIG_SYNC_CTMU    0x001C0000 
#define COMPARE_TRIG_SYNC_ADC1    0x001B0000
#define COMPARE_TRIG_SYNC_COMP3   0x001A0000
#define COMPARE_TRIG_SYNC_COMP2   0x00190000
#define COMPARE_TRIG_SYNC_COMP1   0x00180000
#define COMPARE_TRIG_SYNC_IC4     0x00130000
#define COMPARE_TRIG_SYNC_IC3     0x00120000
#define COMPARE_TRIG_SYNC_IC2     0x00110000
#define COMPARE_TRIG_SYNC_IC1     0x00100000
#define COMPARE_TRIG_SYNC_TIMER5  0x000F0000
#define COMPARE_TRIG_SYNC_TIMER4  0x000E0000
#define COMPARE_TRIG_SYNC_TIMER3  0x000D0000
#define COMPARE_TRIG_SYNC_TIMER2  0x000C0000
#define COMPARE_TRIG_SYNC_TIMER1  0x000B0000
#define COMPARE_TRIG_SYNC_PTGOx   0x000A0000 
#define COMPARE_TRIG_SYNC_OC4     0x00040000
#define COMPARE_TRIG_SYNC_OC3     0x00030000
#define COMPARE_TRIG_SYNC_OC2     0x00020000
#define COMPARE_TRIG_SYNC_OC1     0x00010000
#define COMPARE_TRIG_SYNC_NONE    0x00000000

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
#define sAN0      0x00000001 //| A0
#define sAN1      0x00000002 //| A1
#define sAN2      0x00000004 //| B0
#define sAN3      0x00000008 //| B1
#define sAN4      0x00000010 //| B2
#define sAN5      0x00000020 //| B3

// Optional Second argument:
#define VSS_VDD            0x0000 // Range 0-Vdd
#define VREF_VREF          0x6000 // Range VrefL-VrefH
#define VREF_VDD           0x4000 // Range VrefL-Vdd
#define VSS_VREF           0x2000 // Range 0-VrefH

////////////////////////////////////////////////////////////////// COMP
// Comparator Functions: SETUP_COMPARATOR(), SETUP_COMPARATOR_FILTER(),
//                       SETUP_COMPARATOR_MASK()
//
// Constants used in SETUP_COMPARATOR() second param are: - first param is the comparator number.
#define NC_NC                 0x0000
#define CXIN1_CXIN1           0x8000
#define CXIN2_CXIN1           0x8001  // Comparator 1,2,3 only
#define CXIN1_VREF            0x8010
#define CXIN2_VREF            0x8011  // Comparator 1,2,3 only
#define COMP1_C4IN1           0x8001  // Comparator 4 only
#define COMP2_C4IN1           0x8002  // Comparator 4 only
#define COMP3_C4IN1           0x8003  // Comparator 4 only
#define COMP1_VREF            0x8011  // Comparator 4 only
#define COMP2_VREF            0x8012  // Comparator 4 only
#define COMP3_VREF            0x8013  // Comparator 4 only
      // OR in any of the following
#define COMP_OPAMP            0x0400  // Circuit operates as an Op Amp, Comparator 1,2,3 only   
#define COMP_INVERT           0x2000  // Invert output
#define COMP_OUTPUT           0x4000  // Output on pin
#define COMP_INTR             0x0040  // Generate interrupt on high
#define COMP_INTR_INV         0x0080  // Generate interrupt on low
#define COMP_INTR_CHANGE      0x00C0  // Generate interrupt on change

// Constants used in SETUP_COMPARATOR_FILTER() second param are: - first param is the comparator number.
#define COMP_FILTER_DISABLE         0x0000
#define COMP_FILTER_ENABLE          0x0008
      // OR in one of the following
#define COMP_FILTER_CLK_T5          0x0070
#define COMP_FILTER_CLK_T4          0x0060
#define COMP_FILTER_CLK_T3          0x0050
#define COMP_FILTER_CLK_T2          0x0040
#define COMP_FILTER_CLK_SYNCO2      0x0030
#define COMP_FILTER_CLK_SYNCO1      0x0020
#define COMP_FILTER_CLK_FOSC        0x0010
#define COMP_FILTER_CLK_INTERNAL    0x0000
      // OR in one of the following
#define COMP_FILTER_CLK_DIV_BY_128  0x0007
#define COMP_FILTER_CLK_DIV_BY_64   0x0006
#define COMP_FILTER_CLK_DIV_BY_32   0x0005
#define COMP_FILTER_CLK_DIV_BY_16   0x0004
#define COMP_FILTER_CLK_DIV_BY_8    0x0003
#define COMP_FILTER_CLK_DIV_BY_4    0x0002
#define COMP_FILTER_CLK_DIV_BY_2    0x0001
#define COMP_FILTER_CLK_DIV_BY_1    0x0000

// Constants used in SETUP_COMPARATOR_MASK() second param are: - first param is the comparator number.
#define COMP_MASK_COMP_HIGH                      0x0000
#define COMP_MASK_COMP_LOW                       0x8000
      // OR in any of the following
#define COMP_MASK_MCI_CONNECTED_TO_OR            0x2000
#define COMP_MASK_INVERTED_MCI_CONNECTED_TO_OR   0x1000
#define COMP_MASK_MBI_CONNECTED_TO_OR            0x0800
#define COMP_MASK_INVERTED_MBI_CONNECTED_TO_OR   0x0400
#define COMP_MASK_MAI_CONNETED_TO_OR             0x0200
#define COMP_MASK_INVERTED_MAI_CONNECTED_TO_OR   0x0100
#define COMP_MASK_INVERTED_ANDI_CONNECTED_TO_OR  0x0080
#define COMP_MASK_ANDI_CONNECTED_TO_OR           0x0040
#define COMP_MASK_MCI_CONNECTED_TO_AND           0x0020
#define COMP_MASK_INVERTED_MCI_CONNECTED_TO_AND  0x0010
#define COMP_MASK_MBI_CONNECTED_TO_AND           0x0008
#define COMP_MASK_INVERTED_MBI_CONNECTED_TO_AND  0x0004
#define COMP_MASK_MAI_CONNECTED_TO_AND           0x0002
#define COMP_MASK_INVERTED_MAI_CONNECTED_TO_AND  0x0001
// Constants used in SETUP_COMPARATOR_MASK() third, forth and fifth param are:
#define COMP_MASK_INPUT_FLT4                     0x000F
#define COMP_MASK_INPUT_FLT2                     0x000E
#define COMP_MASK_INPUT_PTGO19                   0x000D
#define COMP_MASK_INPUT_PTGO18                   0x000C
#define COMP_MASK_INPUT_PWM3H                    0x0005
#define COMP_MASK_INPUT_PWM3L                    0x0004
#define COMP_MASK_INPUT_PWM2H                    0x0003
#define COMP_MASK_INPUT_PWM2L                    0x0002
#define COMP_MASK_INPUT_PWM1H                    0x0001
#define COMP_MASK_INPUT_PWM1L                    0x0000

#bit C1OUT = 0xA84.8
#bit C1ENV = 0xA84.9  // User must clear
#bit C2OUT = 0xA8C.8
#bit C2ENV = 0xA8C.9  // User must clear
#bit C3OUT = 0xA94.8
#bit C3ENV = 0xA94.9  // User must clear
#bit C4OUT = 0xA9C.8
#bit C4ENV = 0xA9C.9  // User must clear

////////////////////////////////////////////////////////////////// VREF
// Constants used in setup_vref() are:
//
#define VREF_DISABLED              0x0000
#define VREF_CVREF_IS_VREF         0x0400  //CVrefin = VREF+
#define VREF_CVREF_FROM_VREF_VREF  0x0090  //CVrefin is generated from resistor network, voltage reference sources are VREF- and VREF+
#define VREF_CVREF_FROM_VSS_VDD    0x0080  //CVrefin is generated from resistor network, voltage reference sources are VSS and VDD
      //One of the following maybe OR'ed in with the above using |
#define VREF_HIGH                  0x0000
#define VREF_LOW                   0x0020
      //One of the following maybe OR'ed in with the above using |
#define VREF_INTREF_VREF           0x0300  //INTREF = VREF+, invalid if used with VREF_CVREF_FROM_VREF_VREF
#define VREF_INTREF_0v197          0x0200  //INTREF = 0.197V
#define VREF_INTREF_0v59           0x0100  //INTREF = 0.59V
#define VREF_INTREF_1v18           0x0000  //INTREF = 1.18V
      //The following maybe OR'ed in with the above using |
#define VREF_OUTPUT                0x0040
// OR a number 0-15 with the above using |

////////////////////////////////////////////////////////////////// CRC
// CRC Functions: setup_crc(), crc_init(), crc_calc32(),
//                crc_calc16(), crc_calc8()
// Constants used in setup_crc() are:
#define CRC_LITTLE_ENDIAN    128

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

////////////////////////////////////////////////////////////////// DMA
// DMA Functions: setup_dma(), dma_start(), dma_status()
//
// Constants used in setup_dma() second param are:

#define DMA_IN_SPI1      (0x0A0000|getenv("sfr:SPI1BUF"))
#define DMA_OUT_SPI1     (0x8A0000|getenv("sfr:SPI1BUF"))
#define DMA_IN_SPI2      (0x210000|getenv("sfr:SPI2BUF"))
#define DMA_OUT_SPI2     (0xA10000|getenv("sfr:SPI2BUF"))
#define DMA_IN_UART1     (0x0B0000|getenv("sfr:U1RXREG"))
#define DMA_OUT_UART1    (0x8C0000|getenv("sfr:U1TXREG"))
#define DMA_IN_UART2     (0x1E0000|getenv("sfr:U2RXREG"))
#define DMA_OUT_UART2    (0x9F0000|getenv("sfr:U2TXREG"))
#define DMA_IN_ADC1      (0x0D0000|getenv("sfr:ADC1BUF0"))
#define DMA_IN_ECAN1     (0x220000|getenv("sfr:C1RXD"))
#define DMA_OUT_ECAN1    (0xC60000|getenv("sfr:C1TXD"))
#define DMA_INT0         0x000000 // or in direction and perif address
#define DMA_IC1          0x010000 // or in direction and perif address
#define DMA_IC2          0x050000 // or in direction and perif address
#define DMA_OC1          0x020000 // or in direction and perif address
#define DMA_OC2          0x060000 // or in direction and perif address
#define DMA_TIMER2       0x070000 // or in direction and perif address
#define DMA_TIMER3       0x080000 // or in direction and perif address
#define DMA_IN          0x00
#define DMA_OUT         0x800000
// Constants used in setup_dma() third param are:
#define DMA_BYTE        0x40
#define DMA_WORD        0x00  // default
#define DMA_HALF_INT    0x10  // interrupt when half full
#define DMA_WRITE_NULL  0x08
// Constants used in dma_start() second param are:
#define DMA_CONTINOUS   0x00
#define DMA_ONE_SHOT    0x01
#define DMA_PING_PONG   0x02
#define DMA_NO_INC      0x10
#define DMA_PERIF_ADDR  0x20 // Device supplies address
#define DMA_FORCE_NOW  0x100
// Constants returned from dma_status() are:
#define DMA_IN_ERROR    0x01
#define DMA_OUT_ERROR   0x02
#define DMA_B_SELECT    0x04

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

#define INT_STACKERR              3
#define INT_MATHERR               4
#define INT_DMAERR                5
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
#define INT_SI2C2                 114
#define INT_MI2C2                 115
#define INT_QEI                   123
#define INT_UART1E                130
#define INT_UART2E                131
#define INT_COMP                  152
#define INT_PWMSEN                154
#define INT_PWM1                  155
#define INT_PWM2                  156
#define INT_PWM3                  157
#define INT_CRC                   174
#define INT_CTMU                  176
#define INT_SOFTWARE              193
#define INT_GENERIC               217
#define INT_OSCFAIL               218
#define INT_ADDRERR               219
#define INT_PTGWDT                221
#define INT_PTG0                  222
#define INT_PTG1                  223
#define INT_PTG2                  224
#define INT_PTG3                  225

#list
