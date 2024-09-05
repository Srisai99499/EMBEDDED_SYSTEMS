#include <reg51.h>

void main() {

    TMOD = 0x02;   // Configure Timer 0 in Mode 2 (8-bit auto-reload mode), Timer 1 in Mode 0 (not used)
    
    TH0 = 0x10;    // Load the high byte of Timer 0 with 0x10. This is the value that will be auto-reloaded after each overflow.
    TL0 = 0x00;    // Set the initial low byte of Timer 0 to 0x00. Timer will start counting from 0x00.
    
    TR0 = 1;       // Start Timer 0 by setting the TR0 bit (Timer Run Control bit). Timer will begin counting from 0x00 to 0xFF.
    
    while (TF0 == 0);  // Wait for Timer 0 to overflow. When it counts up from 0x00 to 0xFF, TF0 (Timer 0 overflow flag) will be set.
    
    TR0 = 0;       // Stop Timer 0 after the overflow by clearing the TR0 bit. This halts the timer.
    
    TR1 = 0;       // Ensure Timer 1 is also stopped, though it is not in use here.
}
