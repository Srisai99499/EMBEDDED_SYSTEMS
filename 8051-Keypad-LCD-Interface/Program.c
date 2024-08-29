#include<reg51.h>


// Function declarations
void init(void);  // Initializes the LCD
void delay(unsigned int i);  // Generates a delay
void cmd_lcd(unsigned char a);  // Sends a command to the LCD
void data_lcd(unsigned char b);  // Sends data to the LCD
void lcd_str(unsigned char *str);  // Displays a string on the LCD

// Pin definitions for RS and EN
sbit rs = P2^0;  // RS pin connected to P2.0
sbit en = P2^1;  // EN pin connected to P2.1

// Define the data port for the LCD
sfr lcddata = 0xB0;  // LCD data connected to Port 3 (P3)

// Main function
void main() {
    init();  // Initialize the LCD with basic settings

    // Display "THIS IS LCD" on the first line
    lcd_str(" THIS IS LCD   ");

    // Move the cursor to the second line
    cmd_lcd(0xC0);

    // Display "EMBEDDED PROGRAM" on the second line
    lcd_str("EMBEDDED PROGRAM");

    // Delay to allow the text to remain visible for some time
    delay(65000);

    // Clear the display
    cmd_lcd(0x01);

    while(1);  // Infinite loop to keep the program running
}

// Function to initialize the LCD
void init(void) {
    cmd_lcd(0x38);  // Configure the LCD in 8-bit mode, 2-line display, 5x8 font
    cmd_lcd(0x0C);  // Turn on the display, cursor off, no blinking
    cmd_lcd(0x80);  // Set the cursor to the beginning of the first line
    cmd_lcd(0x01);  // Clear the display and move cursor to the home position

}

// Function to send a command to the LCD
void cmd_lcd(unsigned char a) {
    rs = 0;  // Set RS to 0 for command mode
    lcddata = a;  // Place command on data port
    en = 0;  // Pulse the enable pin to latch the command
    delay(5);  // Short delay for the command to execute
    en = 1;  // Finish the enable pulse
    delay(5);  // Short delay to ensure proper command execution
}

// Function to send data (a character) to the LCD
void data_lcd(unsigned char b) {
    rs = 1;  // Set RS to 1 for data mode
    lcddata = b;  // Place data (character) on data port
    en = 0;  // Pulse the enable pin to latch the data
    delay(5);  // Short delay for the data to be written
    en = 1;  // Finish the enable pulse
    delay(5);  // Short delay to ensure proper data writing
}

// Function to display a string on the LCD
void lcd_str(unsigned char *str) {
    while (*str) {  // Loop through each character in the string
        //delay(30000);  // Delay between displaying each character
        data_lcd(*str++);  // Send each character to the LCD
    }
}

// Function to generate a delay
void delay(unsigned int i) {
    unsigned int j;
    for (j = 0; j < i; j++);  // Simple loop to create the delay
}
