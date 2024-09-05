#include <reg51.h>
void main() {

    TMOD = 0x00; // 0000 0000: Timer 0 in Mode 0, Timer 1 in Mode 0
    TH0 = 0x00;  // Set Timer 0 High byte to 0x00 (Initial Value)
    TL0 = 0x00;  // Set Timer 0 Low byte to 0x00 (Initial Value)
    TR0 = 1;     // Start Timer 0 by setting the TR0 bit (Timer Run Control Bit)

    while (TF0 == 0); // Wait for Timer 0 Overflow Flag (TF0) to be set (Overflow occurs when timer rolls over)

    TR0 = 0;     // Stop Timer 0
    TR1 = 0;     // Stop Timer 1 (if it's running, though it's not used here)
}

