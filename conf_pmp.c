configure_pmp(){
     #ifdef eprom_rw

        #define E LATDbits.LATD3
        TRISDbits.TRISD3 = 0; //RD3 as E

        ANSELBbits.ANSB8 = 0;  //PMA6
        ANSELBbits.ANSB9 = 0;  //PMA7
        ANSELBbits.ANSB10 = 0; //PMA13
        ANSELBbits.ANSB11 = 0; //PMA12
        ANSELBbits.ANSB12 = 0; //PMA11
        ANSELBbits.ANSB13 = 0; //PMA10
        ANSELBbits.ANSB14 = 0; //PMA1
        ANSELBbits.ANSB15 = 0; //PMA0
        ANSELEbits.ANSE0 = 0;  //PMD0
        ANSELEbits.ANSE1 = 0;  //PMD1
        ANSELEbits.ANSE2 = 0;  //PMD2
        ANSELEbits.ANSE3 = 0;  //PMD3
        ANSELEbits.ANSE4 = 0;  //PMD4
        ANSELEbits.ANSE5 = 0;  //PMD5
        ANSELEbits.ANSE6 = 0;  //PMD6
        ANSELEbits.ANSE7 = 0;  //PMD7
        
        PMMODE = (INTRPT_AT_RW|INCR_ADDR|MASTER_2_MODE|WAITB_4TCY|WAITM_15TCY|WAITE_4TCY);
        PMCON = (PMP_MODULE_ENABLE|PMWR_ENABLE|PMRD_ENABLE);      
        PMAEN = (CS2_PMA15_AT_PMP|CS1_PMA14_AT_PMP|PMA_13_2_AT_PMP|PMA_1_0_AT_PMP);
    
        E = 1;
    #endif
}
test_pmp(){
    PMADDR = 0;
    int data ;
    long count;
    count = 0;
    while(PMMODEbits.BUSY);
    data = PMDIN1;
    while (count<650){
        while(PMMODEbits.BUSY);
        data = PMDIN1;
        count++;
    }
    return 0;
}


char * read_pmp_in2_buffer(char *data){
    /*this function reads the first 650 bytes of 27MC1001 and store it into
     a char array named as 'buffer'. Then returns address of the first element
     * of 'buffer' */ 
    char buffer[650];
    int count;
    int dummy;
    data = buffer;
    E = 0;
    while(PMMODEbits.BUSY);
    dummy = PMDIN1;
    E = 1;
    
    count=0;
    E = 0;
    while (count<650){
        E = 0;
        while(PMMODEbits.BUSY);
        buffer[count] = ((PMDIN1 & 0x00FF));
        count+=1;
        E = 1;
    }
    return &buffer[0];
}
char one_from_eprom(int addr){
    /*this function reads the addr location of 27MC1001 and returns it as 
     * output */ 
    char output;
    E = 0;
    PMADDR = 0;
    while(PMMODEbits.BUSY);
    output = PMDIN1;
    E = 1;

    E = 0;
    PMADDR = addr;
    while(PMMODEbits.BUSY);
    output = (PMDIN1 & 0x00FF);
    E = 1;
    return output;
    

}
eprom_2_uart(unsigned long start_addr, unsigned long stop_addr){
    unsigned long count;
    int dummy;
    
    E = 0;
    while(PMMODEbits.BUSY);
    dummy = PMDIN1;
    E = 1;
    
    count = 0;
    E = 0;
    while (count<(stop_addr-start_addr))
    {
        E = 0;
        while(PMMODEbits.BUSY);
        send_uart2_8((PMDIN1 & 0x00FF));
        count+=1;
        E = 1;
    }
    PMADDR = 0;
    
    
    return 0;
}
