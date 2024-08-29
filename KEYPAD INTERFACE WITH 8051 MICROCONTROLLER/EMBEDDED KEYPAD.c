#include<reg51.h>


// Function declarations
void init(void);  // Initializes the LCD
void delay(unsigned int i);  // Generates a delay
void cmd_lcd(unsigned char a);  // Sends a command to the LCD
void data_lcd(unsigned char b);  // Sends data to the LCD
void lcd_str(unsigned char *str);  // Displays a string on the LCD
// Pin definitions for RS and EN
sbit rs = P2^0;  // RS pin connected to P2.0
sbit en = P2^1;// EN pin connected to P2.1
sbit r1 = P1^0;// row1 pin connected to P1.0
sbit r2 = P1^1;// row2 pin connected to P1.1
sbit r3 = P1^2;// row3 pin connected to P1.2
sbit r4 = P1^3;// row4 pin connected to P1.3
sbit c1 = P1^4;// column 1 pin connected to P1.4
sbit c2 = P1^5;// column 2 pin connected to P1.5
sbit c3 = P1^6;// column 3 pin connected to P1.6

// Define the data port for the LCD
sfr lcddata = 0xB0;  // LCD data connected to Port 3 (P3)

// Main function
void main() {
    init();  // Initialize the LCD with basic settings

    // Display "THIS IS LCD" on the first line
    lcd_str(" PRESS ANY KEY  ");
	
    cmd_lcd(0xC0);//cursor start from second line
    while(1){
			 // Initialize the rows (r1, r2, r3, r4) to 0, meaning all rows are active low.
       // Initialize the columns (c1, c2, c3) to 1, meaning all columns are inactive high.
       r1 = r2 = r3 = r4 = 0;
       c1 = c2 = c3 = 1;

    // Check if any key in the first column is pressed.
    if (c1 == 0) {
    // Deactivate all rows by setting them to 1.
    r1 = r2 = r3 = r4 = 1;
    // Activate the first column by setting it to 0.
    c1 = c2 = c3 = 0;

    // Check which row is pressed in the first column.
    if (r1 == 0) {
        data_lcd('1');  // If the first row is pressed, display '1'.
    } else if (r2 == 0) {
        data_lcd('4');  // If the second row is pressed, display '4'.
    } else if (r3 == 0) {
        data_lcd('7');  // If the third row is pressed, display '7'.
    } else if (r4 == 0) {
        data_lcd('*');  // If the fourth row is pressed, display '*'.
    }
}// Check if any key in the second  column is pressed.
    else if(c2==0){
	r1=r2=r3=r4=1;
        c1=c2=c3=0;
    if(r1==0){
      data_lcd('2');
    } else if(r2==0){
      data_lcd('5');
    }else if(r3==0){
      data_lcd('8');
    }else if(r4==0){
       data_lcd('0');
    }				
}// Check if any key in the third  column is pressed.
   else if(c3==0){
      r1=r2=r3=r4=1;
      c1=c2=c3=0;
   if(r1==0){
	data_lcd('3');
   }else if(r2==0){
	data_lcd('6');
   }else if(r3==0){
	data_lcd('9');
   }else if(r4==0){
	data_lcd('#');
   }
				
   }	
}
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
        data_lcd(*str++);  // Send each character to the LCD
		
    }
}

// Function to generate a delay
void delay(unsigned int i) {
    unsigned int j;
    for (j = 0; j < i; j++);  // Simple loop to create the delay
}
