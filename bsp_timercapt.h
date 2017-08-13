/*
 * bsp_timercapt.h
 *
 *  Created on: Aug 13, 2017
 *      Author: Boston
 */

#ifndef BSP_TIMERCAPT_H_
#define BSP_TIMERCAPT_H_

#include <stdint.h>

//#ifdef __cplusplus
//extern "C" {
//#endif

void bsp_timercapt_init(uint8_t clockMHz, uint8_t prescaler);

uint32_t bsp_timercapt_elapsedTicks();
uint32_t bsp_timercapt_elapsedUs();

uint32_t bsp_timercapt_ticksBetweenCaptures(void);
uint32_t bsp_timercapt_usBetweenCaptures(void);
uint32_t bsp_timercapt_ticksSinceCapture(void);
uint32_t bsp_timercapt_usSinceCapture(void);

//#ifdef __cplusplus
//} //extern "C"
//#endif


#endif /* BSP_TIMERCAPT_H_ */
