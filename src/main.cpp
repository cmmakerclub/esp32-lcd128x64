#include <Arduino.h>
#include <U8g2lib.h>
// #include "utils.h"
#include "logo.h"
#include <CMMC_Interval.h>
#define MAX_PAGE 2

U8G2_ST7920_128X64_F_SW_SPI *u8g2;
void setup() {
    Serial.begin(115200);
    Serial2.begin(9600, SERIAL_8N1,  16 /* rx */,  17 /* tx */);
    Serial2.setTimeout(10);
    u8g2 = new U8G2_ST7920_128X64_F_SW_SPI(U8G2_R0, /* clock=*/ 18, /* MOSI=*/ 23, /* MISO=*/ 19);
    u8g2->begin();
    // displayLogo(); }
    Serial.println("HELLO WORLD.");
    Serial2.flush();
    u8g2->setFont(u8g2_font_micro_tr);
    u8g2->print("HELLO..");
}

void loop() {
      while(Serial2.available()) {
        Serial2.readStringUntil('+');
        delay(10);
        String o = Serial2.readStringUntil('\n');
        Serial.print(o);
        u8g2->clear();
        u8g2->firstPage();
        do {
          u8g2->setFont(u8g2_font_micro_tr);
          u8g2->print(o.c_str());
        } while (u8g2->nextPage());
      }
}
