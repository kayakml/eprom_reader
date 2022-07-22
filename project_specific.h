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

/*PIN DEFINITIONS FOR dsPIC33EP512MU810*/
/*PMP PINS*/
//pin3 --> VAN29/PWM3H/PMD5/RP85/RE5<------------------ AS FOR PMD5
//pin4 --> VANxx/PWMxx/PMD6/RPxx/RE6<------------------ AS FOR PMD6
//pin5 --> VANxx/PWMxx/PMD7/RPxx/RE7<------------------ AS FOR PMD7
//pin10--> C1IN3-/SCK2/PMA5/RP118/RG6<----------------- AS FOR PMA5
//pin11--> XXXXXXXXXXX/PMA4/XXXXX/RG7<----------------- AS FOR PMA4
//pin12--> XXXXXXXXXXX/PMA3/XXXXX/RG8<----------------- AS FOR PMA3
//pin14--> XXXXXXXXXXX/PMA2/XXXXX/RG9<----------------- AS FOR PMA2
//pin17--> XXXXXXXXXXX/XXXX/XXXXX/RA0<----------------- LED_D3 (OUTPUT)
//pin32--> AN8/XXXXXXXX/PMA6/XXXXX/RB8<---------------- AS FOR PMA6
//pin33--> AN9XXXXXXXX/PMA7/XXXXX/RB9<----------------- AS FOR PMA7
//pin34--> AN10/XXXXXX/PMA13/XXXX/RB10<---------------- AS FOR PMA13
//pin35--> AN11/XXXXXX/PMA12/XXXX/RB11<---------------- AS FOR PMA12
//pin39--> XXXX/XXXXXX/XXXX/XXXX/XXXXX<---------------- AS FOR Receive of UART2
//pin40--> XXXX/XXXXXX/XXXX/XXXX/XXXXX<---------------- AS FOR Transmit of UART2
//pin41--> AN12/XXXXXX/PMA11/XXXX/RB12<---------------- AS FOR PMA11
//pin42--> AN13/XXXXXX/PMA10/XXXX/RB13<---------------- AS FOR PMA10
//pin43--> AN14/XXXXXX/PMA1/XXXXX/RB14<---------------- AS FOR PMA1
//pin44--> AN15/XXXXXX/PMA0/XXXXX/RB15<---------------- AS FOR PMA0
//pin49--> XXXX/XXXXXX/PMA9/XXXXX/RF4<----------------- AS FOR PMA9
//pin50--> XXXX/XXXXXX/PMA8/XXXXX/RF5<----------------- AS FOR PMA8
//pin70--> XXXX/XXXXXX/PMCS2/XXXXX/RD10<--------------- AS FOR PMA15(=PMCS2)
//pin71--> XXXX/XXXXXX/PMCS1/XXXXX/RD11<--------------- AS FOR PMA14(=PMCS1)
//pin78--> XXXX/XXXXXX/PMBE/XXXXX/RD3<----------------- USED AS RD3 (OUTPUT); E of 27MC1001
//pin81--> XXXX/XXXXXX/PMWR/XXXXX/RD4<----------------- AS FOR PMWR
//pin82--> XXXX/XXXXXX/PMRD/XXXXX/RD5<----------------- AS FOR PMRD
//pin83--> XXXX/XXXXXX/XXXX/XXXXX/RD6<----------------- SWITCH_S3(INPUT)
//pin93--> AN24/XXXXXX/PMD0/XXXXX/RE0<----------------- AS FOR PMD0
//pin94--> AN25/XXXXXX/PMD1/XXXXX/RE1<----------------- AS FOR PMD1
//pin98--> AN26/XXXXXX/PMD2/XXXXX/RE2<----------------- AS FOR PMD2
//pin99--> AN27/XXXXXX/PMD3/XXXXX/RE3<----------------- AS FOR PMD3
//pin100-> AN28/XXXXXX/PMD4/XXXXX/RE4<----------------- AS FOR PMD4
