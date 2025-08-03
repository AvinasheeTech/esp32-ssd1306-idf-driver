#include <stdio.h>
#include "ssd1306.h"

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

void app_main(void)
{
    //initialize display driver
    if(!oled_begin(SCREEN_WIDTH,SCREEN_HEIGHT,SSD1306_SWITCHCAPVCC,true)) { // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally

        printf("SSD1306 allocation failed");
    }


    // Clear the buffer
    oled_clearDisplay();

    // Draw a single pixel in white
    oled_drawPixel(10,10,SSD1306_WHITE);

    // Draw character H in white
    oled_drawPixel(100,30,SSD1306_WHITE);
    oled_drawPixel(100,31,SSD1306_WHITE);
    oled_drawPixel(100,32,SSD1306_WHITE);
    oled_drawPixel(100,33,SSD1306_WHITE);
    oled_drawPixel(100,34,SSD1306_WHITE);
    oled_drawPixel(100,35,SSD1306_WHITE);
    oled_drawPixel(100,36,SSD1306_WHITE);
    oled_drawPixel(100,37,SSD1306_WHITE);
    oled_drawPixel(100,38,SSD1306_WHITE);
    oled_drawPixel(100,39,SSD1306_WHITE);
    oled_drawPixel(100,40,SSD1306_WHITE);
    oled_drawPixel(101,35,SSD1306_WHITE);
    oled_drawPixel(102,35,SSD1306_WHITE);
    oled_drawPixel(103,35,SSD1306_WHITE);
    oled_drawPixel(104,35,SSD1306_WHITE);
    oled_drawPixel(105,35,SSD1306_WHITE);
    oled_drawPixel(106,35,SSD1306_WHITE);
    oled_drawPixel(107,30,SSD1306_WHITE);
    oled_drawPixel(107,31,SSD1306_WHITE);
    oled_drawPixel(107,32,SSD1306_WHITE);
    oled_drawPixel(107,33,SSD1306_WHITE);
    oled_drawPixel(107,34,SSD1306_WHITE);
    oled_drawPixel(107,35,SSD1306_WHITE);
    oled_drawPixel(107,36,SSD1306_WHITE);
    oled_drawPixel(107,37,SSD1306_WHITE);
    oled_drawPixel(107,38,SSD1306_WHITE);
    oled_drawPixel(107,39,SSD1306_WHITE);
    oled_drawPixel(107,40,SSD1306_WHITE);

    // Display on screen
    oled_display();

}
