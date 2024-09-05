#include <reg51.h>
void main() {

    TMOD = 0x01;  // Set Timer 0 to Mode 1 (16-bit timer) and Timer 1 to Mode 0 (not used)
    TH0 = 0x00;   // Load the high byte of Timer 0 (Initial value)
    TL0 = 0x00;   // Load the low byte of Timer 0 (Initial value)
    TR0 = 1;      // Start Timer 0 (Set the TR0 bit)

    while (TF0 == 0);  // Wait for the Timer 0 overflow flag to be set (indicating the timer has overflowed)

    TR0 = 0;      // Stop Timer 0
    TR1 = 0;      // Stop Timer 1 (not in use here)
}
