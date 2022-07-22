#define LINE_FEED 0x0A
#define UART1_MODULE_ENABLE (U1MODEbits.UARTEN = 1)
#define UART1_TRANSMIT_ENABLE (U1STAbits.UTXEN = 1)
#define UART2_MODULE_ENABLE (U2MODEbits.UARTEN = 1)
#define UART2_TRANSMIT_ENABLE (U2STAbits.UTXEN = 1)
#define TRANSMIT_NOT_READY() (!U1STAbits.TRMT)
#define TRANSMIT_NOT_READY_uart2() (!U2STAbits.TRMT)
//#define TRANSMIT_NOT_READY() (!U1STAbits.TRMT ||U1STAbits.UTXBF)
//U1STAbits.TRMT = 0 --> TransmitShiftRegister is not empty a transmission is in progress or queued in transmitbuffer
//U1STAbits.UTXBF = 1 --> Transmitbuffer is full
#define IS_CHAR_READY_UART1() U1STAbits.URXDA
#define IS_CHAR_READY_UART2() U2STAbits.URXDA

void configure_uart(void);
void send_uart_8(uint8_t send_data);
void send_data_MPLABVis(uint8_t data);
void outString_to_MPLABVis (const char* message);
void outString (const char* message);
char inChar(void);
void send_float_MPLABVis(float data);
void print_8x8_table_MPLABVis(uint8_t *ptr);
void print_space(void);
void new_line(void);
uint8_t test_uart(void);

#define BRGVAL1 ((FCY/BAUDRATE1)/4)-1 //BRGH = 1
#define BRGVAL2 ((FCY/BAUDRATE2)/4)-1 //BRGH = 1
