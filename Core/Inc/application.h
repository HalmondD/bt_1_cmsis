/*
 * application.h
 *
 *  Created on: Jan 30, 2024
 *      Author: duong
 */

#ifndef INC_APPLICATION_H_
#define INC_APPLICATION_H_

#include <stdint.h>

#include "stm32f1xx.h"

void app_main(void);
void delay_ms(uint32_t delay_time_ms);

#endif /* INC_APPLICATION_H_ */
