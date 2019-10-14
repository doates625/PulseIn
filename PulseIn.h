/**
 * @file PulseIn.h
 * @brief Class for Arduino and Mbed pulse-length reading inputs
 * @author Dan Oates (WPI Class of 2020)
 * 
 * This class adds pulse-length reading functionality to the DigitalIn class.
 * It is capable of reading the lengths of both low and high pulses with a 
 * configurable timeout, after which the method will return 0.
 * 
 * Dependencies:
 * - DigitalIn: https://github.com/doates625/DigitalIn.git
 * - Platform: https://github.com/doates625/Platform.git
 * 
 * References:
 * - Arduino pulseIn: https://www.arduino.cc/reference/en/language/functions/advanced-io/pulsein/
 */
#pragma once
#include <DigitalIn.h>

/**
 * Class Declaration
 */
class PulseIn : public DigitalIn
{
public:
	PulseIn(Platform::pin_t pin, PinMode mode = PullNone);
	float read_pulse(int value, float timeout);
};