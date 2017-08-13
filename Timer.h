/*
 * Timer.h
 *
 *  Created on: Aug 13, 2017
 *      Author: Boston
 */

#ifndef TIMER_H_
#define TIMER_H_

#include <stdint.h>
#include <stdbool.h>

class Timer {
public:
	Timer() :
		started(false),
		usOld(0),
		elapsedUs(0) {}

	void start();
	void run();
	void stop();
	void reset();
	uint32_t getTimeUs();
	uint32_t getTimeMs();

private:
	bool started;

	uint32_t usOld;
	uint32_t elapsedUs;
};

#endif /* TIMER_H_ */
