/**
 * @file PulseIn.cpp
 * @author Dan Oates (WPI Class of 2020)
 */
#include "PulseIn.h"

/**
 * @brief Constructs pulse-reading digital input
 * @param pin Platform-specific pin ID
 * @param pull Pin mode (PullUp, PullNone)
 */
PulseIn::PulseIn(Platform::pin_t pin, PinMode mode) :
	DigitalIn(pin, mode)
{
	return;
}

/**
 * @brief Reads pulse length from digital input
 * @param value Value of pulse to read (1 = high, 0 = low)
 * @param timeout Pulse start wait timeout (seconds)
 * 
 * If the input already reads the value at the start of the method call, this
 * method will wait at most timeout until a new pulse begins. If no pulse
 * begins within the timeout, this method returns 0.
 */
float PulseIn::read_pulse(int value, float timeout)
{
#if defined(PLATFORM_ARDUINO)

	// Use Arduino PulseIn function
	uint32_t timeout_us = timeout * 1.0e+6;
	return pulseIn(pin, value, timeout_us) * 1.0e-6;

#elif defined(PLATFORM_MBED)

	// Create timer
	Timer timer;
	
	// Wait for end of last pulse
	timer.start();
	while (read() == value)
	{
		if (timer.read() > timeout)
		{
			return 0.0f;
		}
	}
	while (read() != value)
	{
		if (timer.read() > timeout)
		{
			return 0.0f;
		}
	}
	
	// Measure time of pulse
	timer.reset();
	while (read() == value);
	return timer.read();

#endif
}