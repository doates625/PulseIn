/**
 * @file PulseIn.h
 * @brief Class for Arduino and Mbed pulse-length reading inputs
 * @author Dan Oates (WPI Class of 2020)
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