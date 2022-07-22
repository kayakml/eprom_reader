    #ifdef PIM_dsPIC33EP512MU810
        void configure_uart(void){
                    #ifdef _dsPIC33EP512MU810_uart2
                    #ifdef Control_Register_Bit_Poll
                    //unlock registers
                    __builtin_write_OSCCONL(OSCCON & ~(1<<6));
                    //RPINR19bits.U2RXR = 109;     // U2RX fonksiyonu chipin 39ncu pinindeki RP109 pinine tanimlandi/RF13
                    RPINR19bits.U2RXR = 78;     // U2RX fonksiyonu chipin 47ncu pinindeki RPI78 pinine tanimlandi/
                    //RPOR11bits.RP108R = 0b000011;// chipin 40nci pinindeki RP108 pinine U2TX fonksiyonu tanimlandi/RF12
                    RPOR4bits.RP79R = 0b000011;// chipin 48nci pinindeki RP79 pinine U2TX fonksiyonu tanimlandi/
                    //lock registers
                    __builtin_write_OSCCONL(OSCCON | ~(1<<6));
                    U2MODEbits.BRGH = 1;
                    U2BRG = BRGVAL2;
                    U2MODEbits.UARTEN = 1;
                    U2MODEbits.STSEL = 0; //1 stop bit
                    U2STAbits.UTXISEL1 = 0;
                    U2STAbits.UTXISEL0 = 1;
                    U2STAbits.UTXEN = 1;
                    IFS1bits.U2TXIF = 0;
                #endif

            //.....

            #endif
        }

        void send_uart2_8(uint8_t send_data){
            #ifdef _dsPIC33EP512MU810_uart2
                #ifdef Control_Register_Bit_Poll
                    while(TRANSMIT_NOT_READY_uart2()){};
                    U2TXREG = send_data;
                #endif
            #endif       
        }
        char inChar(void) {
            #ifdef _dsPIC33EP512MU810_uart1
                #ifdef Control_Register_Bit_Poll
                    while (!IS_CHAR_READY_UART1())
                    return U1RXREG; //read the receive register
                #endif
            #endif
            #ifdef _dsPIC33EP512MU810_uart2
                #ifdef Control_Register_Bit_Poll
                    while (!IS_CHAR_READY_UART2());
                        if(U2STAbits.FERR==1){;}
                        if(U2STAbits.PERR==1){;}
                        if(U2STAbits.OERR==1){U2STAbits.OERR=0;}
                    return U2RXREG; //read the receive register
                #endif
            #endif
        return U2RXREG;
        }
        void inString_uart( char * receive_buffer, int rec_buf_len) {
            #ifdef _dsPIC33EP512MU810_uart1
                #ifdef Control_Register_Bit_Poll
                    char *strptr ;
                    while (!IS_CHAR_READY_UART1());
                    *strptr = U1RXREG;
                    strptr++;
                #endif
            #endif
            #ifdef _dsPIC33EP512MU810_uart2
                #ifdef Control_Register_Bit_Poll
                    char * strptr;
                    strptr=receive_buffer;
                    int i;
                    for (i=0;i<rec_buf_len;i++){
                        *strptr = inChar();
                        strptr++;
                        }
                #endif
            #endif
        }
    #endif
/*---------
