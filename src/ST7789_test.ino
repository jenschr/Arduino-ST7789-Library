#include <SPI.h>
#include "Arduino_ST7789.h"

#define TFT_MOSI       A5
#define TFT_MISO       A4
#define TFT_CLK        A3
#define TFT_CS         A2
#define TFT_RST        A1                                            
#define TFT_DC         A0

// Uncomment according to your screen resolution
Arduino_ST7789 tft = Arduino_ST7789(TFT_DC, TFT_RST, TFT_CS); // Using Hardware SPI
//Arduino_ST7789 tft = Arduino_ST7789(TFT_DC, TFT_RST, TFT_MOSI, TFT_CLK, TFT_CS); // Using software SPI (bitbanging)

int counter = 0;
long now;
long then;
int delayTime = 500;

void setup() {
  Serial.begin(9600);
  delay(200);

  // Uncomment according to your screen resolution
  tft.init(135,240);
  //tft.init(240,240);
}

void loop()
{  
  tft.setRotation(3);
  sampleOutput();

  tft.setRotation(2);
  sampleOutput();

  tft.setRotation(1);
  sampleOutput();

  //sampleColors();

  tft.setRotation(0);
  sampleOutput();

  //sampleColors();

  // Uncomment the block below to test the timing for the first 
  // 5 loops (skip the first). Great for showing the difference
  // between HW pins and Bitbanging (see the two construtors)

  /*
  if( counter > 1 && counter < 6){
    now = millis();
    Serial.printlnf("tft.loopTime: %d", now-then );
    then = now;
    delayTime = 0;
  }
  counter++;
  */
}

void sampleOutput()
{
  tft.fillScreen(BLACK);
  tft.setFont(COMICS_8); // TIMESNR_8, CENTURY_8, ARIAL_8, COMICS_8, GLCDFONT

  tft.setCursor(0,0);
  tft.setTextColor(WHITE);
  tft.setTextSize(1);
  tft.print("Small");

  tft.setCursor(0,20);
  tft.setTextSize(2);
  tft.print("Medium");

  tft.setCursor(0,50);
  tft.setTextSize(3);
  tft.print("Large");
  delay( delayTime );
}

void sampleColors()
{
  tft.fillScreen(WHITE);
  tft.fillScreen(CYAN);
  tft.fillScreen(RED);
  tft.fillScreen(BLUE);
  tft.fillScreen(GREEN);
  tft.fillScreen(YELLOW);
  tft.fillScreen(MAGENTA);
  tft.fillScreen(BLACK);
}