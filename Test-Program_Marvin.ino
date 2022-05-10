
// NeoPixel Ring simple sketch (c) 2013 Shae Erisson
// Released under the GPLv3 license to match the rest of the
// Adafruit NeoPixel library

#include <Adafruit_NeoPixel.h>

// Which pin on the Arduino is connected to the NeoPixels?
#define PIN        6 // On Trinket or Gemma, suggest changing this to 1

int schalter_1 = 0;
int schalter_2 = 0;

int led_1 = 0;
int led_2 = 2;

// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS 9 // Popular NeoPixel ring size

Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

#define DELAYVAL 500 // Time (in milliseconds) to pause between pixels

void setup() {
  // These lines are specifically to support the Adafruit Trinket 5V 16 MHz.
  // Any other board, you can remove this part (but no harm leaving it):
#if defined(__AVR_ATtiny85__) && (F_CPU == 16000000)
  clock_prescale_set(clock_div_1);
#endif
  // END of Trinket-specific code.

  pixels.begin(); // INITIALIZE NeoPixel strip object (REQUIRED)
}

void loop() {

  schalter_1 = digitalRead(2); //Schalter 1 auf Eingang 2 gelegt
  schalter_2 = digitalRead(3);//Schalter 2 auf Eingang 3 gelegt
  
  pixels.clear(); // Set all pixel colors to 'off

  if (schalter_1 == LOW){ //Falls Schalter 1 nicht gedrückt ist, Led 1 zeigt keine Farbe
    pixels.setPixelColor(led_1, pixels.Color(0, 0, 0));
  }
  else { //Ansonsten schalte Led 1 auf Grün
    pixels.setPixelColor(led_1, pixels.Color(0, 255, 0));
  }

    if (schalter_2 == LOW){ //Falls Schalter 2 nicht gedrückt ist, Led 1 zeigt keine Farbe
    pixels.setPixelColor(led_2, pixels.Color(0, 0, 0));
  }
  else { //Ansonsten schalte Led 2 auf Grün
    pixels.setPixelColor(led_2, pixels.Color(255, 0, 255));

  
  }

  
 
  


    pixels.show();   // Send the updated pixel colors to the hardware.
}
