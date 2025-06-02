#include <Arduino.h>
#include <Adafruit_NeoPixel.h>


static uint8_t s_led_state = 0;
Adafruit_NeoPixel strip = Adafruit_NeoPixel(1, 8, NEO_GRB + NEO_KHZ800);

static void configure_led(void)
{
  pinMode(0,OUTPUT);  //regular led
  strip.begin();
  strip.setBrightness(50);
  strip.show();
}
void setup() {
  Serial.begin(115200);
  configure_led();
}
int counter=0;
void loop() {
  Serial.printf("loop %d %d\n",++counter,s_led_state);
  digitalWrite(0,s_led_state);  //regular led
  if(s_led_state ==0) {strip.setPixelColor(0,16,0,0);} 
  else if(s_led_state ==1) {strip.setPixelColor(0,0,16,0);}
  else {strip.setPixelColor(0,0,0,16);}
  strip.show();
  if(s_led_state <2) s_led_state ++;
  else s_led_state =0;
  delay(1000);
}