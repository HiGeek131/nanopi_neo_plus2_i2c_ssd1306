#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <wiringPi.h>
#include <wiringPiI2C.h>
#include "ssd1306.h"

#define SSD1306 0x3c

char cpu_temp_str[6];
char dis_buf[21];

int main()
{
    wiringPiSetup();
    int fd = wiringPiI2CSetup(SSD1306);
    if(fd >= -1)
    {
        // printf("fd = %d\n", fd);
        ssd1306_fd = fd;
        ssd1306Init();
        ssd1306Flush(0x00);
        while(1)
        {
            FILE *fp = fopen("/sys/class/thermal/thermal_zone0/temp", "r");
            fgets(cpu_temp_str, 6, fp);
            sprintf(dis_buf, "CPU_TEMP = %.2f", (float)atoi(cpu_temp_str)/1000);
            ssd1306Display(0, (uint8_t *)dis_buf);
            fclose(fp);
            delay(1000);
        }
    }
    else
    {
        printf("The screen is not connected!\n");
        return -1;
    }
    return 0;
}