
#include <stdint.h>
#include <stdio.h>
#include "stm32f4xx.h"
#include "system_stm32f4xx.h"


#include "led.h"
#include "timer.h"

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

int main(void)
{

	SystemInit();
	LedInit(LED_BLUE);
		TimerInit();
		while(1) {
			LedBlink(LED_BLUE, 500);
			TimerDelayMs(10000);
		}
		return 0;
	}
