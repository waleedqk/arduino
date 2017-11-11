/* keyPadHiduino Example Code
   by: Jim Lindblom
   date: January 5, 2012
   license: MIT license - feel free to use this code in any way
   you see fit. If you go on to use it in another project, please
   keep this 

   This code turns your ProMicro, with an ATmega32U4, into an
   HID USB Keypad. Buttons 0-9 enter their respective number,
   The * button enters a '+' and the # button enters a 'Enter'.
   
   Keypad Pinout:
   Rows and columns are connected as such on the keypad:
   -------------
   | 1 | 2 | 3 | - 3
   | 4 | 5 | 6 | - 7
   | 7 | 8 | 9 | - 6
   | * | 0 | # | - 1
   -------------
     |   |   |
     2   4   5
     
   This is how they're connected to the ProMicro:
   Keypad Pin ------ Pro Micro Pin
      1 ------------------ 2
      2 ------------------ 3
      3 ------------------ 4
      4 ------------------ 5
      5 ------------------ 10
      6 ------------------ 16
      7 ------------------ 14
*/
#include <Keyboard.h>

#define KEY_LEFT_CTRL  0x80
#define KEY_LEFT_SHIFT 0x81
#define KEY_LEFT_ALT   0x82
#define KEY_LEFT_GUI   0x83
#define KEY_RIGHT_CTRL 0x84
#define KEY_RIGHT_SHIFT    0x85
#define KEY_RIGHT_ALT  0x86
#define KEY_RIGHT_GUI  0x87

#define KEY_UP_ARROW   0xDA
#define KEY_DOWN_ARROW 0xD9
#define KEY_LEFT_ARROW 0xD8
#define KEY_RIGHT_ARROW    0xD7
#define KEY_BACKSPACE  0xB2
#define KEY_TAB        0xB3
#define KEY_RETURN 0xB0
#define KEY_ESC        0xB1
#define KEY_INSERT 0xD1
#define KEY_DELETE 0xD4
#define KEY_PAGE_UP    0xD3
#define KEY_PAGE_DOWN  0xD6
#define KEY_HOME   0xD2
#define KEY_END        0xD5
#define KEY_CAPS_LOCK  0xC1
#define KEY_F1     0xC2
#define KEY_F2     0xC3
#define KEY_F3     0xC4
#define KEY_F4     0xC5
#define KEY_F5     0xC6
#define KEY_F6     0xC7
#define KEY_F7     0xC8
#define KEY_F8     0xC9
#define KEY_F9     0xCA
#define KEY_F10        0xCB
#define KEY_F11        0xCC
#define KEY_F12        0xCD

// Pins 1-7 of the keypad connected to the Arduino respectively:
int keypadPins[7] = {2, 3, 4, 5, 10, 16, 14};
int keypadStatus;  // Used to monitor which buttons are pressed.
int timeout;  // timeout variable used in loop

void setup()
{
  for (int i=0; i<7; i++)
  {
    pinMode(keypadPins[i], INPUT);  // Set all keypad pins as inputs
    digitalWrite(keypadPins[i], HIGH);  // pull all keypad pins high
  }
}

void loop()
{
  keypadStatus = getKeypadStatus();  // read which buttons are pressed
  if (keypadStatus != 0)  // If a button is pressed go into here
  {
    sendKeyPress(keypadStatus);  // send the button over USB
    timeout = 2000;  // top of the repeat delay
    while ((getKeypadStatus() == keypadStatus) && (--timeout))  // Decrement timeout and check if key is being held down
      delayMicroseconds(1);
    while (getKeypadStatus() == keypadStatus)  // while the same button is held down
    {
      sendKeyPress(keypadStatus);  // continue to send the button over USB
      delay(50);  // 50ms repeat rate
    }
  }
}

/* sendKeyPress(int key): This function sends a single key over USB
   It requires an int, of which the 12 LSbs are used. Each bit in
   key represents a single button on the keypad.
   This function will only send a key press if a single button
   is being pressed */
void sendKeyPress(int key)
{
   //Keyboard.println(key);
}

/* getKeypadStatus(): This function returns an int that represents
the status of the 12-button keypad. Only the 12 LSb's of the return
value hold any significange. Each bit represents the status of a single
key on the button pad. '1' is bit 0, '2' is bit 1, '3' is bit 2, ..., 
'#' is bit 11.

This function doesn't work for multitouch.
*/
int getKeypadStatus()
{
  int rowPins[4] = {keypadPins[2], keypadPins[6], keypadPins[5], keypadPins[0]};  // row pins are 2, 7, 6, and 1 of the keypad
  int columnPins[3] = {keypadPins[1], keypadPins[3], keypadPins[4]};  // column pins are pins 2, 4, and 5 of the keypad
  int keypadStatus = 0;  // this will be what's returned
  
  /* initialize all pins, inputs w/ pull-ups */
  for (int i=0; i<7; i++)
  {
    pinMode(keypadPins[i], INPUT);
    digitalWrite(keypadPins[i], HIGH);
  }
  
  for (int row=0; row<4; row++)
  {  // initial for loop to check all 4 rows
    pinMode(rowPins[row], OUTPUT);  // set the row pin as an output
    digitalWrite(rowPins[row], LOW);  // pull the row pins low
    for (int col=0; col<3; col++)
    {  // embedded for loop to check all 3 columns of each row
      if (!digitalRead(columnPins[col]))
      {
        Keyboard.println(row);
        Keyboard.println(col);
        
        keypadStatus |= 1 << ((row+1)*3 + (col+1) - 4);  // set the status bit of the keypad return value
      }
    }
    pinMode(rowPins[row], INPUT);  // reset the row pin as an input
    digitalWrite(rowPins[row], HIGH);  // pull the row pin high
  }
  
  return keypadStatus;
}


