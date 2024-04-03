

#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include "stm32f4xx.h"
#include "system_stm32f4xx.h"
#include "uart.h"
#include "switch.h"
#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

int count = 1;
int main(void)
{
	char str[16];
	SystemInit();
	UartInit(BAUD_9600);
	UartPuts("HELLO\r\n");
	SwitchInit(SWITCH);

	while(1){
		while(exti0_flag == 0)
			;
		sprintf(str,"%d\r\n", count);
		UartPuts(str);
		count ++;
		exti0_flag = 0;
	}
	return 0;
}
