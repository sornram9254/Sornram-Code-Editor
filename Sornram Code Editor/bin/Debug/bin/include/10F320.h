//////// Standard Header file for the PIC10F320 device ////////////////
#device PIC10F320
#nolist
//////// Program memory: 256x14  Data RAM: 64  Stack: 8
//////// I/O: 4   Analog Pins: 3
//////// C Scratch area: 60   ID Location: 2000
//////// Fuses: INTRC,EC,NOBROWNOUT,BROWNOUT_SW,BROWNOUT_NOSL,BROWNOUT,NOWDT
//////// Fuses: WDT_SW,WDT_NOSL,WDT,PUT,NOPUT,NOMCLR,MCLR,PROTECT,NOPROTECT
//////// Fuses: NOLVP,LVP,NOLPBOR,LPBOR,BORV25,BORV19,WRT,WRT_50%,WRT_25%
//////// Fuses: NOWRT,DEBUG,NODEBUG
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
// Watch Dog Timer Functions: SETUP_WDT(), RESTART_WDT()
// WDT base is 1ms
//
#define WDT_ON      0x01
#define WDT_OFF     0x00

#define WDT_1MS     0x00
#define WDT_2MS     0x02
#define WDT_4MS     0x04
#define WDT_8MS     0x06
#define WDT_16MS    0x08
#define WDT_32MS    0x0A
#define WDT_64MS    0x0C
#define WDT_128MS   0x0E
#define WDT_256MS   0x10
#define WDT_512MS   0x12
#define WDT_1S      0x14
#define WDT_2S      0x16
#define WDT_4S      0x18
#define WDT_8S      0x1A
#define WDT_16S     0x1C
#define WDT_32S     0x1E
#define WDT_64S     0x20
#define WDT_128S    0x22
#define WDT_256S    0x24

////////////////////////////////////////////////////////////////// Timer 2
// Timer 2 Functions: SETUP_TIMER_2, GET_TIMER2, SET_TIMER2
// Constants used for SETUP_TIMER_2() are:
#define T2_DISABLED         0
#define T2_DIV_BY_1         4
#define T2_DIV_BY_4         5
#define T2_DIV_BY_16        6

////////////////////////////////////////////////////////////////// VREF
// Constants used in setup_vref() are:
//
#define VREF_OFF     0
#define VREF_1v024   0x81
#define VREF_2v048   0x82
#define VREF_4v096   0x83
// The following may be OR'ed in with the above using |
#define TEMPERATURE_INDICATOR_DISABLED  0
#define TEMPERATURE_INDICATOR_ENABLED   0x20
#define TEMPERATURE_RANGE_LOW           0
#define TEMPERATURE_RANGE_HIGH          0x10

////////////////////////////////////////////////////////////////// CWG
// CWG Functions: SETUP_CWG(), CWG_STATUS(), CWG_RESTART()
// Constants used in SETUP_CWG() first param are:
#define CWG_ENABLED                    0x0080
#define CWG_DISABLED                   0
#define CWG_OUTPUT_A                   0x0020
#define CWG_OUTPUT_B                   0x0040
#define CWG_A_INVERTED                 0x0008
#define CWG_B_INVERTED                 0x0010
#define CWG_CLOCK_HFINTOSC             0x0001
#define CWG_INPUT_PWM1                 0x0000  
#define CWG_INPUT_PWM2                 0x0100  
#define CWG_INPUT_NCO1OUT              0x0200  
#define CWG_INPUT_LC1OUT               0x0300  


// Constants used in SETUP_CWG() second param are:
#define CWG_NO_AUTO_SHUTDOWN           0
#define CWG_SHUTDOWN_ON_FLT            0x0001  
#define CWG_SHUTDOWN_ON_LC1OUT         0x0002  
#define CWG_AUTO_RESTART               0x0040
// One of the following may be OR'ed in with the above using |
#define CWG_SHUTDOWN_A_INACTIVE_STATE  0
#define CWG_SHUTDOWN_A_TRISTATE        0x1000
#define CWG_SHUTDOWN_A_LOW             0x2000
#define CWG_SHUTDOWN_A_HIGH            0x3000
// One of the following may be OR'ed in with the above using |
#define CWG_SHUTDOWN_B_INACTIVE_STATE  0
#define CWG_SHUTDOWN_B_TRISTATE        0x4000
#define CWG_SHUTDOWN_B_LOW             0x8000
#define CWG_SHUTDOWN_B_HIGH            0xC000

// Constants returned from CWG_STATUS() are:
#define CWG_AUTO_SHUTDOWN              0x80

////////////////////////////////////////////////////////////////// NCO
// NCO Functions: SETUP_NCO(), SET_NCO_ACCUMULATOR(), 
//                GET_NCO_ACCUMULATOR(), SET_NCO_INC_VALUE(),
//                GET_NCO_INC_VALUE()
// Constants used in SETUP_NCO() first param are:
#define NCO_ENABLED          0x0080
#define NCO_DISABLED         0
#define NCO_OUTPUT           0x0040
#define NCO_ACTIVE_HIGH      0x0010
#define NCO_ADCIVE_LOW       0
#define NCO_PULSE_FREQ_MODE  0x0001
#define NCO_FIXED_DUTY_MODE  0
// One of the following may be OR'ed in with the above using |
#define NCO_CLOCK_NCO1CLK    0x0300
#define NCO_CLOCK_LC1OUT     0x0200
#define NCO_CLOCK_FOSC       0x0100
#define NCO_CLOCK_HFINOSC    0
// One of the following may be OR'ed in with the above using |
#define NCO_PULSE_WIDTH_1    0
#define NCO_PULSE_WIDTH_2    0x2000
#define NCO_PULSE_WIDTH_4    0x4000
#define NCO_PULSE_WIDTH_8    0x6000
#define NCO_PULSE_WIDTH_16   0x8000
#define NCO_PULSE_WIDTH_32   0xA000
#define NCO_PULSE_WIDTH_64   0xC000
#define NCO_PULSE_WIDTH_128  0xE000


#bit N1OUT = getenv("BIT:N1OUT")

////////////////////////////////////////////////////////////////// CLC
// CLC Functions: SETUP_CLCx(), CLCx_SETUP_INPUT(), 
//                CLCx_SETUP_GATE()
// Constants used in SETUP_CLCx() are:
#define CLC_ENABLED                         0x080
#define CLC_DISABLED                        0
#define CLC_OUTPUT                          0x040
#define CLC_INT_L_TO_H                      0x010
#define CLC_INT_H_TO_L                      0x008
#define CLC_OUTPUT_INVERTED                 0x100
// One of the following may be OR'ed in with the above using |
#define CLC_MODE_AND_OR                     0x000
#define CLC_MODE_OR_XOR                     0x001
#define CLC_MODE_AND                        0x002
#define CLC_MODE_SR_LATCH                   0x003
#define CLC_MODE_1_INPUT_D_FLIP_FLOP        0x004
#define CLC_MODE_2_INPUT_D_FLIP_FLOP        0x005
#define CLC_MODE_JK_FLIP_FLOP               0x006
#define CLC_MODE_1_INPUT_TRANSPARENT_LATCH  0x007


// Constants used in CLCx_SETUP_INPUT() second param are: (first param is input 1-4)
#define CLC_INPUT_0                         0
#define CLC_INPUT_1                         0x01
#define CLC_INPUT_2                         0x02
#define CLC_INPUT_3                         0x03
#define CLC_INPUT_4                         0x04
#define CLC_INPUT_5                         0x05
#define CLC_INPUT_6                         0x06
#define CLC_INPUT_7                         0x07

// Constants used in CLCx_SETUP_GATE() second param are: (first param is gate 1-4)
#define CLC_GATE_AND                        0x155
#define CLC_GATE_NAND                       0x055
#define CLC_GATE_NOR                        0x1AA
#define CLC_GATE_OR                         0x0AA
#define CLC_GATE_CLEAR                      0
#define CLC_GATE_SET                        0x100

#bit LC1OUT = getenv("BIT:LC1OUT")


////////////////////////////////////////////////////////////////// INTERNAL RC
// Constants used in setup_oscillator() are:
// First param:
#define OSC_31KHZ   0
#define OSC_250KHZ  0x10
#define OSC_500KHZ  0x20
#define OSC_1MHZ    0x30
#define OSC_2MHZ    0x40
#define OSC_4MHZ    0x50
#define OSC_8MHZ    0x60
#define OSC_16MHZ   0x70
// The following may be OR'ed in with the above using |
#define OSC_CLKOUT  0x4000
// Result may be (ignore all other bits)
#define OSC_HFINTRC_STABLE    1
#define OSC_HFINTRC_READY     8
#define OSC_LFINTRC_READY     2

////////////////////////////////////////////////////////////////// PWM
// PWM Functions: SETUP_PWMx, SET_PWMx_DUTY
// Constants used for SETUP_PWMx() are:
#define PWM_ENABLED      0x80
#define PWM_DISABLED     0
#define PWM_OUTPUT       0x40
#define PWM_ACTIVE_LOW   0x10
#define PWM_ACTIVE_HIGH  0


#bit PWM1OUT=getenv("BIT:PWM1OUT")
#bit PWM2OUT=getenv("BIT:PWM2OUT")


////////////////////////////////////////////////////////////////// ADC
// ADC Functions: SETUP_ADC(), SETUP_ADC_PORTS() (aka SETUP_PORT_A),
//                SET_ADC_CHANNEL(), READ_ADC()
//Constants used for SETUP_ADC() are:
#define ADC_OFF               0
#define ADC_CLOCK_DIV_2   0x100
#define ADC_CLOCK_DIV_4    0x80
#define ADC_CLOCK_DIV_8    0x20
#define ADC_CLOCK_DIV_16   0xA0
#define ADC_CLOCK_DIV_32   0x40
#define ADC_CLOCK_DIV_64   0xC0
#define ADC_CLOCK_INTERNAL 0x60

// Constants used in SETUP_ADC_PORTS() are:
// OR together desired pins
#define sAN0         0x01  //| A0
#define sAN1         0x02  //| A1
#define sAN2         0x04  //| A2
#define NO_ANALOGS      0  // None
#define ALL_ANALOG   0x07  // A0 A1 A2

// Constants used in SET_ADC_CHANNEL() are:
// either use the channel number or one of the following
#define TEMPERATURE_INDICATOR     0x06
#define FVR_CHANNEL               0x07

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
#define INT_EXT_L2H               0x50000B10
#define INT_EXT_H2L               0x60000B10
#define INT_EXT                   0x000B10
#define INT_TIMER0                0x000B20
#define INT_RA                    0x00FF0B08
#define INT_TIMER2                0x000D02
#define INT_CLC1                  0x000D08
#define INT_NCO1                  0x000D10
#define INT_AD                    0x000D40

#list
