#ifndef __SSD1306_H
#define __SSD1306_H

#include <stdint.h>
#include <wiringPi.h>
#include <wiringPiI2C.h>

#define SSD1306COM 0x00
#define SSD1306DAT 0x40

// extern const uint8_t zi[][6];
extern int32_t ssd1306_fd;

void fill_picture(uint8_t fill_Data);
uint8_t* convertAsciiToDat(uint8_t *p);
void ssd1306Display(uint8_t b,uint8_t *p);
void ssd1306Init(void);
void ssd1306Flush(uint8_t fill_Data);

#endif
