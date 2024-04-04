

#include <stdint.h>
#include <stdio.h>
#include "stm32f4xx.h"
#include "system_stm32f4xx.h"

#include "lis3dsh.h"
#include "i2c_lcd.h"
#include "led.h"
#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif


int main(void)
{
	int ret;
		LIS_Data val;
		SystemInit();
		LIS_Init();

		LedInit(LED_BLUE);
		LedInit(LED_GREEN);
		LedInit(LED_ORANGE);
		LedInit(LED_RED);

	DelayMs(1000);

	while(1) {
		ret = LIS_DRdy();
				if(ret) {
					val = LIS_GetData();

					LedOff(LED_BLUE);
					LedOff(LED_GREEN);
					LedOff(LED_ORANGE);
					LedOff(LED_RED);

					if(val.x > 600)
						LedOn(LED_RED);
					if(val.x <-600)
						LedOn(LED_GREEN);
					if(val.y > 600)
						LedOn(LED_ORANGE);
					if(val.y < -600)
						LedOn(LED_BLUE);


					DelayMs(1000);
				}
			}
			return 0;
		}





