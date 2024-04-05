
#include <stdint.h>
#include <stdio.h>
#include "stm32f4xx.h"
#include "system_stm32f4xx.h"

#include "i2c_lcd.h"
#include "rtc.h"
#include "uart.h"

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

int main(void)
{
	char str1[24], str2[20];
	RTC_Date d, dt = { .Date = 28, .Month = 02, .Year = 24, .WeekDay = 3 };
	RTC_Time t, tm = { .Hours = 23, .Minutes = 59, .Seconds = 50 };

	SystemInit();
	//LcdInit();
	UartInit(BAUD_9600);
	//UartPuts("Real time clock...\r\n");
	//UartPuts("time clock...\r\n");
//	LcdPuts(LCD_LINE1, "DESD @ Sunbeam\n");
	//LcdPuts(LCD_LINE2, "STM32 RTC Demo!\n");
	//DelayMs(1000);
	//LcdWrite(LCD_CMD, LCD_CLEAR);
	RTC_Init(&dt, &tm);
	while(1) {
		RTC_GetTime(&t);
		RTC_GetDate(&d);
		sprintf(str1, "DT=%02d-%02d-%02d W=%d\t", d.Date, d.Month, d.Year, d.WeekDay);
		UartPuts(str1);
		sprintf(str2, "TM=%02d:%02d:%02d\r", t.Hours, t.Minutes, t.Seconds);
		UartPuts(str2);
		//LcdPuts(LCD_LINE1, str1);
		//LcdPuts(LCD_LINE2, str2);

		DelayMs(1000);
	}
	return 0;
}

