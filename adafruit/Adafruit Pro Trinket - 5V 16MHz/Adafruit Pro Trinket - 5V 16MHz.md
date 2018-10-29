# Adafruit Pro Trinket - 5V 16MHz

## Product Page

https://www.adafruit.com/product/2000

## Setup Guide

https://learn.adafruit.com/adafruit-arduino-ide-setup?view=all

## Description

The Pro Trinket 5V uses the Atmega328P chip, which is the same core chip in the Arduino UNO/Duemilanove/Mini/etc. at the same speed and voltage.


Here's some things you may have to consider when adapting Arduino sketches:

    * Pins #2 and #7 are not available (they are exclusively for USB)
    * The onboard 5V regulator can provide 150mA output, not 800mA out
    * You cannot plug shields directly into the Pro Trinket
    * There is no Serial-to-USB chip onboard. This is to keep the Pro Trinket small and inexpensive, you can use any FTDI cable to connect to the FTDI port for a Serial connection. The USB connection is for uploading new code only.
    * The bootloader on the Pro Trinket use 4KB of FLASH so the maximum sketch size is 28,672 bytes. The bootloader does not affect RAM usage.

## Specifications:

    ATmega328P onboad chip in QFN package
    16MHz clock rate, 28K FLASH available
    USB bootloader with a nice LED indicator looks just like a USBtinyISP so you can program it with AVRdude and/or the Arduino IDE (with a few simple config modifications).
    Also has headers for an FTDI port for reprogramming
    Micro-USB jack for power and/or USB uploading, you can put it in a box or tape it up and use any USB cable for when you want to reprogram.
    On-board 5.0V power regulator with 150mA output capability and ultra-low dropout. Up to 16V input, reverse-polarity protection, thermal and current-limit protection.
    Power with either USB or external output (such as a battery) - it'll automatically switch over
    On-board green power LED and red pin #13 LED
    Reset button for entering the bootloader or restarting the program.

## Pinout

https://learn.adafruit.com/introducing-pro-trinket/pinouts

## First Program 

https://learn.adafruit.com/introducing-pro-trinket?view=all#blink-7-5

## Error: "id_type"

https://arduino.stackexchange.com/questions/30658/avrdude-conf-programmer-type-must-be-written-as-id-type