#define PIC_TYPE_DEFINITIONS
#define CLOCK_DEFINITIONS
#define UART_DEFINITIONS

#ifdef PIC_TYPE_DEFINITIONS
    #define PIM_dsPIC33EP512MU810
#endif
#ifdef CLOCK_DEFINITIONS
//    #define CLK_XT_8MHZ
    #define CLK_FRC_7_37_MHZ
#endif

#ifdef UART_DEFINITIONS
/* UART DEFINITIONS*/
//    #define _dsPIC33EP512MU810_uart1
    #define _dsPIC33EP512MU810_uart2
    #define Control_Register_Bit_Poll
    #define BRGH_VALUE_HIGH
    //#define BRGH_VALUE_LOW
    #define BAUDRATE2 9600
//    #define BAUDRATE2 9600
    #define BAUDRATE1 9600
    #define ONE_STOP_BIT
    //#define TWO_STOP_BIT
    //#define uart_for_debug
#endif
