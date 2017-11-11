# Setup Instructions

**Hookup Guide**

	https://learn.sparkfun.com/tutorials/pro-micro--fio-v3-hookup-guide/installing-mac--linux

**Add Third Party Boards**

To begin, you’ll need to point the Arduino IDE board manager to a custom URL. Open up Arduino, then go to the Preferences (File > Preferences). Then, towards the bottom of the window, paste this URL into the “Additional Board Manager URLs” text box:

	https://raw.githubusercontent.com/sparkfun/Arduino_Boards/master/IDE_Board_Manager/package_sparkfun_index.json

Then open the Board Manager by clicking Tools, then hovering over the Board selection tab and clicking Board Manager.

Search for ‘sparkfun’ in the Board Manager. You should see the SparkFun AVR Boards package appear. Click install.

**Installing the Arduino Addon**

	`downloading the Pro Micro addon files`

Copy the ‘sparkfun’ folder that was unzipped in the first step into the ‘hardware’ folder.
Your directory structure should look something like “Arduino/hardware/sparkfun/avr

	mkdir -p ~/Arduino/hardware

move the extracted `sparkfun` folder to the `hardware` folder
