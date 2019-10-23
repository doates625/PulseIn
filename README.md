# PulseIn
Class for Arduino and Mbed pulse-length reading inputs  
Written by Dan Oates (WPI Class of 2020)

### Description
This class adds pulse-length reading functionality to the DigitalIn class. It is capable of reading the lengths of both low and high pulses with a configurable timeout, after which the method will return 0.

### Testing
On an Arduino Uno, this library has a minimum pulse read of 2us and a noise of +/-2%. On an STM32 Nucleo L433RC-P, this library has a minimum pulse read of 50us and a noise of +/-5us.

### Dependencies
- [Platform](https://github.com/doates625/Platform.git)
- [DigitalIn](https://github.com/doates625/DigitalIn.git)