#include <Arduino.h>
#include <TM1637Display.h>

// Module connection pins (Digital Pins)
#define CLK 2 //D2 for WeMOS
#define DIO 3 //D3 for WeMOS

// The amount of time (in milliseconds) between tests
#define TEST_DELAY 1000

const uint8_t SEG_FOOL[] = {
	SEG_A | SEG_E | SEG_F | SEG_G,                   // F
	SEG_A | SEG_B | SEG_C | SEG_D | SEG_E | SEG_F,   // O
	SEG_A | SEG_B | SEG_C | SEG_D | SEG_E | SEG_F,   // O
	SEG_D | SEG_E | SEG_F                            // L
	};

TM1637Display display(CLK, DIO);

void setup()
{
  display.setBrightness(0x0f);
  
}

void loop()
{
  int test = 0;
  while (test <= 10000) {
    display.showNumberDec(test, true, 4, 0);
    if (test == 9999) {
      delay(2000);
    };
    delay(TEST_DELAY);
    display.setSegments(SEG_FOOL);
    delay(TEST_DELAY);
    test++;
  }
}