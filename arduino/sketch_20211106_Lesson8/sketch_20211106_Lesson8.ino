//Temperature and Humidity Sensor
//updated by @hohno_at_kuimc to fit for the monogramming approach (2023-04-07)
//updated by @hohno_at_kuimc to work with new GBKA (2023-04-14)

#include "DHT.h"
#include <Arduino.h>
#include <U8x8lib.h>
#define DHTPIN 3 // what pin we're connected to
// #define DHTTYPE DHT11
#define DHTTYPE DHT20
#define OUTPUT_INTERVAL (500) // in msec

DHT dht(DHTPIN, DHTTYPE);
U8X8_SSD1306_128X64_ALT0_HW_I2C u8x8(/* reset=*/ U8X8_PIN_NONE);

void setup(void) {
  /**modified**/ Serial.begin(57600);
  //removed// Serial.println("DHTxx test!");
  u8x8.begin();
  u8x8.setPowerSave(0);
  u8x8.setFlipMode(1);
  /**moved**/. dht.begin();
}

void loop(void) {
  float temp, humi;
  temp = dht.readTemperature();
  humi = dht.readHumidity();
  u8x8.setFont(u8x8_font_chroma48medium8_r);
  u8x8.setCursor(0, 33);
  u8x8.print("Temp:");
  u8x8.print(temp);
  u8x8.print("C");
  u8x8.setCursor(0,50);
  u8x8.print("Humidity:");
  u8x8.print(humi);
  u8x8.print("%");
  u8x8.refreshDisplay();
  /**added**/ Serial.print(millis()), Serial.print("\t");
  /**added**/ Serial.print(temp), Serial.print("\t");
  /**added**/ Serial.print(humi), Serial.println();
  delay(OUTPUT_INTERVAL);
}
