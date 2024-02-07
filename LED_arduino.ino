#include <FastLED.h>
//pin pre pripojenie lediek
#define LED_PIN 4
//pocet lediek na pasiku
#define NUM_LEDS 60

CRGB leds[NUM_LEDS];

void setup()
{
  pinMode(3,INPUT);
  FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS);
  FastLED.setMaxPowerInVoltsAndMilliamps(5, 500);
  FastLED.clear();
  FastLED.show();
  
}

void loop(){
  //zapnutie lediek zo spodu schodov, pin 3
  if (digitalRead(3)== LOW)
  {
    for (int i = 0; i < NUM_LEDS; i++){
    //nastavenie farby
      leds[i] = CRGB(10, 90, 255);
      FastLED.show();
      delay(40);
    }
  //pauza medzi zasvietenim a vypnutim
  delay(120000);

    for (int i=NUM_LEDS; i>-1; i--){
    //vypnutie lediek
      leds[i] = CRGB(0, 0, 0);
      FastLED.setBrightness(100-i); //nastanevie jasu
      FastLED.show();
      delay(150);
    }
  }

  //zapnutie lediek z vrchu schodov, pin 2
  if (digitalRead(2)== LOW){
  for (int i=NUM_LEDS; i>-1; i--){
    leds[i] = CRGB(10, 90, 255);
    FastLED.show();
    delay(40);
  }
  //pauza medzi zasvietenim a vypnutim
  delay(120000);

  for (int i = 0; i < NUM_LEDS; i++){
    //vypnutie lediek
    leds[i] = CRGB(0, 0, 0);
    FastLED.setBrightness(100-i); //nastavenie jasu
    FastLED.show();
    delay(150);
  }

  }
}
