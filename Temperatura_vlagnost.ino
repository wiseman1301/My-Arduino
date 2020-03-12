// Example testing sketch for various DHT humidity/temperature sensors
// Written by ladyada, public domain

// REQUIRES the following Arduino libraries:
// - DHT Sensor Library: https://github.com/adafruit/DHT-sensor-library
// - Adafruit Unified Sensor Lib: https://github.com/adafruit/Adafruit_Sensor

#include "DHT.h"
#define DHTPIN 2 // Digital pin connected to the DHT sensor
// Feather HUZZAH ESP8266 note: use pins 3, 4, 5, 12, 13 or 14 --
// Pin 15 can work but DHT must be disconnected during program upload.
#include <TM1637Display.h>
#define CLK 9   //can be any digital pin
#define DIO 8 //can be any digital pin
#define CHAR_DEG 0b01100011
#define CHAR_C 0b00111001

// Uncomment whatever type you're using!
#define DHTTYPE DHT11    // DHT 11
//#define DHTTYPE DHT22 // DHT 22 (AM2302), AM2321
//#define DHTTYPE DHT21 // DHT 21 (AM2301)

// Connect pin 1 (on the left) of the sensor to +5V
// NOTE: If using a board with 3.3V logic like an Arduino Due connect pin 1
// to 3.3V instead of 5V!
// Connect pin 2 of the sensor to whatever your DHTPIN is
// Connect pin 4 (on the right) of the sensor to GROUND
// Connect a 10K resistor from pin 2 (data) to pin 1 (power) of the sensor

// Initialize DHT sensor.
// Note that older versions of this library took an optional third parameter to
// tweak the timings for faster processors. This parameter is no longer needed
// as the current DHT reading algorithm adjusts itself to work on faster procs.
DHT dht(DHTPIN, DHTTYPE);
TM1637Display display(CLK, DIO);
const uint8_t Letter_deg[] = { SEG_A | SEG_B | SEG_F | SEG_G };
const uint8_t Letter_C[] = { SEG_A | SEG_D | SEG_E | SEG_F };
const uint8_t Letter_o[] = { SEG_C | SEG_D | SEG_E | SEG_G };

void setup() {
Serial.begin(9600);
Serial.println(F("DHTxx test!"));
display.setBrightness(4); // 0x01 << dark -- bright >> 0x0f
display.clear();

dht.begin();
}

void loop() {
// Wait a few seconds between measurements.
delay(3000);

// Reading temperature or humidity takes about 250 milliseconds!
// Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
float h = dht.readHumidity();
// Read temperature as Celsius (the default)
float t = dht.readTemperature();
// Read temperature as Fahrenheit (isFahrenheit = true)
float f = dht.readTemperature(true);

// Check if any reads failed and exit early (to try again).
if (isnan(h) || isnan(t) || isnan(f)) {
Serial.println(F("Failed to read from DHT sensor!"));
return;
}

// Compute heat index in Fahrenheit (the default)
float hif = dht.computeHeatIndex(f, h);
// Compute heat index in Celsius (isFahreheit = false)
float hic = dht.computeHeatIndex(t, h, false);

Serial.print(F("Humidity: "));
Serial.print(h);
Serial.print(F("% Temperature: "));
Serial.print(t);
Serial.print(F("°C "));
Serial.print(f);
Serial.print(F("°F Heat index: "));
Serial.print(hic);
Serial.print(F("°C "));
Serial.print(hif);
Serial.println(F("°F"));

display.clear();
display.showNumberDec(t,false, 2, 0); // distance to front obstacle
display.setSegments(Letter_deg,1,2);
display.setSegments(Letter_C,1,3);
delay(3000);

display.clear();
display.showNumberDec(h,false, 2, 0); // distance to front obstacle
display.setSegments(Letter_deg,1,2);
display.setSegments(Letter_o,1,3);
delay(100);
}
