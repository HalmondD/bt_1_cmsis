#include "application.h"
#define UINT32_T_MAX 4294967295

volatile uint32_t ms_ticks = 0;

/*
*The SysTick_Handler is written to stm32f1xx_it.c
*with the extern to ms_ticks
*/

void delay_ms(uint32_t delay_time_ms)
{
	uint32_t expected_ticks = ms_ticks + delay_time_ms;
    
    if (expected_ticks >= UINT32_T_MAX)
    {
        ms_ticks = 0;
        expected_ticks = delay_time_ms;
    }

	while (ms_ticks < expected_ticks)
	{
		__asm("nop");
	}
}

void app_main(void)
{
    /**
     * - Enable clock for GPIOC
     * - set pin13 as push pull output
    */
    RCC->APB2ENR |= 0xFC;
	GPIOC->CRH = 0x44344444;

    // 8000000 / 8 = 10000000, 1ms can 1000 dem
	SysTick->LOAD = 1000 - 1;
    // Clock = AHB / 8, INT = enable, Enable = 1
    SysTick->CTRL = 0x03;

	while (1)
	{
        delay_ms(1000);
        GPIOC->ODR ^= (1 << 13);
	}
}
