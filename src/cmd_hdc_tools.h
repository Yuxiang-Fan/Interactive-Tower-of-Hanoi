#pragma once

#include <Windows.h>

#define INVALID_RGB		0x7FFFFFFF

void hdc_init(const int bgcolor = RGB(255,255,255), const int fgcolor = RGB(0,0,0), const int width = 8 * 120, const int high = 16 * 30);
void hdc_release(void);

void hdc_set_pencolor(const int rgb_value);
void hdc_set_pencolor(const unsigned char red, const unsigned char green, const unsigned char blue);

void hdc_cls(void);

void hdc_rectangle(const int x1, const int y1, const int width, const int high, const int RGB_value = INVALID_RGB);
