
// xc.h is the main include file - this contains all the "friendly names"
// for the PIC32 pins and peripherals
#include <xc.h>
#include <cstdlib>      // for C++

using namespace std;    // for C++





#pragma config   JTAGEN    = OFF    // JTAG Enable OFF (only use for '250)
#pragma config   FNOSC     = FRCPLL // Fast RC w PLL 8mHz internal rc Osc
#pragma config   FPLLIDIV  = DIV_10  // PLL in 8mHz/10 = 800 kHz
#pragma config   FPLLMUL   = MUL_15 // PLL mul 800 khz * 15 = 12 Mhz
#pragma config   FPLLODIV  = DIV_64  // PLL Out: 12MHz / 64 187.5 kHz
#pragma config   FPBDIV    = DIV_1  // Peripheral Bus Divisor
#pragma config   FCKSM     = CSECME // Clock Switch Enable, FSCM Enabled
#pragma config   POSCMOD   = OFF    // Primary osc disabled
#pragma config   IESO      = OFF    // Internal/external switch over
#pragma config   OSCIOFNC  = OFF    // CLKO Output Signal Active on the OSCO Pin
#pragma config   FWDTEN    = OFF    // Watchdog Timer Enable:

// ------------------------  Configuration (end) ----------------------------

int global_ctr = 0;                 // a global variable counter.
int global_delay_val = 1;        // vary this to change the pulse's delay.
int global_delay_val_long = 3;


// Function prototypes
void delay(int d); // This is the prototype declaration for the Delay function


// Main function
/*
 * 
 */
int main(int argc, char** argv) {


    
	// Set Port A to be output, in two steps.
	LATA = 0;				// Set value of PORT A output to 0. 
	TRISA = 0;				// Set all pins on PORT A to output
	
	// Infinite Loop.  Keeps repeating.
    while(1) 
    {
        
        for(int i=0; i<3; i++)
        {
            
            delay(global_delay_val);         // 1000: roughly Delay for roughly 1 second with 187.5 kHz system clock
            LATA = 0x0001;
            
            delay(global_delay_val);         // 1000: roughly Delay for roughly 1 second with 187.5 kHz system clock
            LATA = 0x0000;
            
        }
        
        for(int i=0; i<2; i++)
        {
            delay(global_delay_val);         // 1000: roughly Delay for roughly 1 second with 187.5 kHz system clock
            LATA = 0x0001;
            
            delay(global_delay_val_long);         // 1000: roughly Delay for roughly 1 second with 187.5 kHz system clock
            LATA = 0x0000;
        }
        global_ctr++;
    }

	return (EXIT_SUCCESS);
}

// 500/((100/119)/2) = 1190
void delay(int d)
{
    int i;  // Declare variable to be used in the loop

    while(d)    // While d > 0
    {
        i = 5;    // set i to 100 for inner loop
        while(i)    // while i > 0
        {
            i--;    // decrement i (e.g. i will equal 99, 98, 97,...)
        }

        d--;    // decrement d
    }
}
