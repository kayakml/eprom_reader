/*CONFIGURATION DEFINITIONS*/
/*PMCON REGISTER*/
    #define PMP_MODULE_ENABLE   0b1000000000000000 
    #define STOP_IN_IDLE        0b0010000000000000 
    #define ADDR_MUXED_ON_DATA  0b0001000000000000
    #define PMBE_ENABLE         0b0000010000000000 //16bit master mode
    #define PMWR_ENABLE         0b0000001000000000
    #define PMRD_ENABLE         0b0000000100000000
    #define CS1_CS2_CHIPSEL     0b0000000010000000
    #define ADR_LATC_HIGH       0b0000000000100000 // PMALL, PMALH
    #define CS2_HIGH            0b0000000000010000
    #define CS1_HIGH            0b0000000000001000
    #define PMBE_HIGH           0b0000000000000100
    #define WR_STROBE_HIGH      0b0000000000000010
    #define RD_STROBE_HIGH      0b0000000000000001

    
/*PMMODE REGISTER*/
    #define INTRPT_AT_RW        0b0010000000000000 // Interrupt is generated at the end of the read/write cycle
    #define INTRPT_AT_PSP       0b0110000000000000 // Interrupt is generated at PSP modes
    #define DECR_ADDR           0b0001000000000000 // Decrements ADDR by 1 every read/write cycle
    #define INCR_ADDR           0b0000100000000000 // Increments ADDR by 1 every read/write cycle
    #define NO_INC_NO_DEC       0b0000000000000000 // 
    #define MODE_16             0b0000010000000000 // 16 bit data register mode
    #define MASTER_1_MODE       0b0000001100000000 // combined R/W extra strobe PMENB
    #define MASTER_2_MODE       0b0000001000000000 // seperate R seperate W
    #define ENHANCED_SLAVE_MODE 0b0000000100000000
    #define LEGACY_SLAVE_MODE   0b0000000000000000
    #define WAITB_4TCY          0b0000000011000000
    #define WAITM_15TCY         0b0000000000111100
    #define WAITE_4TCY          0b0000000000000011



/*PMAEN REGISTER*/
    #define CS2_PMA15_AT_PMP    0b1000000000000000 // only CS2/PMA15 is dedicated to PMP Port, not I/O  
    #define CS1_PMA14_AT_PMP    0b0100000000000000 // only CS1/PMA14 is dedicated to PMP Port, not I/O  
    #define PMA_13_2_AT_PMP     0b0011111111111100 // PMA<13:2> are dedicated to PMP port, not I/O  
    #define PMA_1_0_AT_PMP      0b0000000000000011 // PMA<1:0> are dedicated to PMP port, not I/O  

void configure_pmp(void);
void test_pmp(void);
