#include <reg51.h>

void main() {

    TMOD = 0x03;   // Configure Timer 0 in Mode 3 (Split Timer Mode), Timer 1 in Mode 0 (not used)
    
    TH0 = 0x00;    // Load the high byte of Timer 0 with 0x00 (not used in Mode 3 as Timer 0 is split into two 8-bit timers)
    TL0 = 0x00;    // Load the low byte of Timer 0 with 0x00 (acts as an independent 8-bit timer in Mode 3)
    
    TR0 = 1;       // Start Timer 0 by setting the TR0 bit (Timer Run Control bit). In Mode 3, TL0 starts counting from 0x00.
    
    while (TF0 == 0);  // Wait for the overflow in TL0. TF0 will be set when TL0 counts from 0x00 to 0xFF and overflows.
    
    TR0 = 0;       // Stop Timer 0 after TL0 overflows by clearing the TR0 bit. This halts TL0 (lower 8-bit timer).
    
    TR1 = 0;       // Ensure Timer 1 is stopped as well (TR1 controls TH0 in Mode 3).
}
