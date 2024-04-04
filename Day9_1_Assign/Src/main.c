
#include <stdint.h>
#include <stdio.h>
#include "stm32f4xx.h"
#include "system_stm32f4xx.h"

#include "spi.h"
#include "lis3dsh.h"
#include "i2c.h"
#include "i2c_lcd.h"

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

int main(void)
{
	char str1[32], str2[34];
	int ret;
	LIS_Data val;
	SystemInit();
    LcdInit();
	LIS_Init();
	DelayMs(1000);
	while(1) {
		ret = LIS_DRdy();
		if(ret) {
			val = LIS_GetData();
			//UartPuts(str);
			sprintf(str1, "X=%d,\r\n", val.x);
			sprintf( str2, "Y=%d, Z=%d\r\n", val.y, val.z);

			LcdPuts(LCD_LINE1, str1);
			LcdPuts(LCD_LINE2, str2);
		}
	}
	return 0;
}







