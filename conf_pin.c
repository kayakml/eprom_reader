void configure_digital_IO_ports(){
    #ifdef PIM_dsPIC33EP512MU810
            #ifdef eprom_rw
            ANSELDbits.ANSD6 = 0;
            TRISDbits.TRISD6 = 1; //RD6 as SWITCH_S3
            TRISAbits.TRISA0 = 0; //RA0 as LED_D3
        #endif
    #endif
