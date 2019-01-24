#include <Arduino.h>
#include <U8g2lib.h>
// #include "utils.h"
#include "logo.h"
#include <CMMC_Interval.h>
#define MAX_PAGE 2

U8G2_ST7920_128X64_F_SW_SPI *u8g2;
void setup() {
    Serial2.begin(9600);
    Serial2.setTimeout(10);
    u8g2 = new U8G2_ST7920_128X64_F_SW_SPI(U8G2_R0, /* clock=*/ 18, /* MOSI=*/ 23, /* MISO=*/ 19);
    u8g2->begin();
}

void loop() {
        u8g2->firstPage();
        do {
          u8g2->setFont(u8g2_font_micro_tr);
          // // u8g2->setCursor(logoMargin+10, 16);
          u8g2->setCursor(0, 10);
          u8g2->print("HELLO WORLD ");
          u8g2->print(millis());
        } while (u8g2->nextPage());
      }
