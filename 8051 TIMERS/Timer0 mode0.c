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


/* 1. TMOD Register Configuration:

TMOD = 0x00: This sets both Timer 0 and Timer 1 to Mode 0.
Mode 0 is a 13-bit Timer/Counter mode, where the lower 8 bits are stored in TLx (Timer Low byte) and the upper 5 bits are stored in the lower 5 bits of THx (Timer High byte). It counts from 00000 to 1FFFH (i.e., 8191 counts).
Timer 0 is used here, but Timer 1 is not activated in this code.

2.TH0 and TL0:

Both TH0 and TL0 are set to 0x00 to initialize Timer 0 from zero. The timer will start counting from 0 up to 8191 (or 0x1FFF).

3.TR0:

TR0 = 1: This bit in the TCON register starts Timer 0. The timer begins incrementing from the value in TH0 and TL0.

4.TF0 (Timer Overflow Flag):

while (TF0 == 0);: The program enters a loop and waits for the overflow flag (TF0) to become 1. This flag is set when the timer overflows (i.e., it reaches the maximum value and rolls over to 0).
Stopping the Timer:

5.TR0 = 0;: After the overflow occurs, the timer is stopped by clearing the TR0 bit.
6.TR1 = 0;: Even though Timer 1 is not used in this program, this line stops it as a precaution */
