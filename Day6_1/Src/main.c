
#include <stdint.h>
#include <stdio.h>
#include "stm32f4xx.h"
#include "system_stm32f4xx.h"

#include "led.h"
#include "switch.h"
#include "lcd.h"

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

int cnt = 0;
int main(void)
{
	char str[16];
	SystemInit();
	SwitchInit(SWITCH);
	while(1) {
		while(exti0_flag == 0)
			;
			
			sprintf(str, "CNT = %d", cnt);
			LcdPuts(LCD_LINE2, str);
			cnt ++ ;
		exti0_flag = 0;
	}
	return 0;
}
