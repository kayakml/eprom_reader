
// DSPIC33EP512MU810 Configuration Bit Settings

// 'C' source line config statements

// FGS
#pragma config GWRP = OFF               // General Segment Write-Protect bit (General Segment may be written)
#pragma config GSS = OFF                // General Segment Code-Protect bit (General Segment Code protect is disabled)
#pragma config GSSK = OFF               // General Segment Key bits (General Segment Write Protection and Code Protection is Disabled)

// FOSCSEL
#pragma config FNOSC = FRC              // Initial Oscillator Source Selection Bits (Internal Fast RC (FRC))
#pragma config IESO = OFF               // Two-speed Oscillator Start-up Enable bit (Start up with user-selected oscillator source)

// FOSC
#pragma config POSCMD = NONE            // Primary Oscillator Mode Select bits (Primary Oscillator disabled)
#pragma config OSCIOFNC = OFF           // OSC2 Pin Function bit (OSC2 is clock output)
#pragma config IOL1WAY = OFF            // Peripheral pin select configuration (Allow multiple reconfigurations)
#pragma config FCKSM = CSDCMD           // Clock Switching Mode bits (Both Clock switching and Fail-safe Clock Monitor are disabled)

// FWDT
#pragma config WDTPOST = PS32768        // Watchdog Timer Postscaler Bits (1:32,768)
#pragma config WDTPRE = PR128           // Watchdog Timer Prescaler bit (1:128)
#pragma config PLLKEN = ON              // PLL Lock Wait Enable bit (Clock switch to PLL source will wait until the PLL lock signal is valid.)
#pragma config WINDIS = OFF             // Watchdog Timer Window Enable bit (Watchdog Timer in Non-Window mode)
#pragma config FWDTEN = OFF             // Watchdog Timer Enable bit (Watchdog timer enabled/disabled by user software)

// FPOR
#pragma config FPWRT = PWR128           // Power-on Reset Timer Value Select bits (128ms)
#pragma config BOREN = ON               // Brown-out Reset (BOR) Detection Enable bit (BOR is enabled)
#pragma config ALTI2C1 = OFF            // Alternate I2C pins for I2C1 (SDA1/SCK1 pins are selected as the I/O pins for I2C1)
#pragma config ALTI2C2 = OFF            // Alternate I2C pins for I2C2 (SDA2/SCK2 pins are selected as the I/O pins for I2C2)

// FICD
#pragma config ICS = PGD1               // ICD Communication Channel Select bits (Communicate on PGEC1 and PGED1)
#pragma config RSTPRI = PF              // Reset Target Vector Select bit (Device will obtain reset instruction from Primary flash)
#pragma config JTAGEN = OFF             // JTAG Enable bit (JTAG is disabled)

// FAS
#pragma config AWRP = OFF               // Auxiliary Segment Write-protect bit (Auxiliary program memory is not write-protected)
#pragma config APL = OFF                // Auxiliary Segment Code-protect bit (Aux Flash Code protect is disabled)
#pragma config APLK = OFF               // Auxiliary Segment Key bits (Aux Flash Write Protection and Code Protection is Disabled)


#include "xc.h"
#include "string.h"
#include "../my_libraries/my_headers/header_definition.h"
#include "../my_libraries/my_headers/conf_clock.h"
#include "../my_libraries/my_headers/conf_pmp.h"
#include "../my_libraries/my_headers/conf_uart.h"
#include "../my_libraries/my_headers/conf_pin.h"
#include "project_specific.h"
#include "libpic30.h"

fill_eprom_buffer(){
    char eprom_data[650];
    char * ptr;
    int count;
    ptr = read_pmp_in2_buffer(eprom_data);
    count=0;
    while (count<650){
        send_uart2_8(*ptr);
        ptr+=1;
        count+=1;
    }
}

just_one(int addr){
    send_uart2_8(one_from_eprom(addr));
}
pirpir(void){
    int i;
    for(i=0;i<5;i++){
        LED_D3=1;
        __delay_ms(50)
        LED_D3=0;
        __delay_ms(50)
    }
}


int main(void) {

int data;
char receive_buffer[3];
char send_buffer[10];
char * uart_received_data;
char komut1[3];
komut1[0] = 'A';
komut1[1] = 'D';
komut1[2] = 'A';
//komut1[3] = '\n';

configure_clock();
configure_uart();
configure_pmp();
configure_digital_IO_ports();
data = 0;

while(1){
    inString_uart(receive_buffer,3);
    data = strcmp(*komut1,*receive_buffer);
    if(data==0)
        {
        LED_D3=1;
        eprom_2_uart(0L,1000L);
        }
    pirpir();
    
    
}
    return 0;
}
