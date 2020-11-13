#include <Adafruit_NeoPixel.h>
#include <Wire.h> // standardowa biblioteka Arduino
#include <LiquidCrystal_I2C.h>
#define PIN 3 // On Trinket or Gemma, suggest changing this to 1

// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS 24 // Popular NeoPixel ring size

LiquidCrystal_I2C lcd(0x27, 20, 4);
Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

#define DELAYVAL 200 // Time (in milliseconds) to pause between pixels

const int buzzer = 9;

void setup()
{

    pinMode(buzzer, OUTPUT);
    Serial.begin(9600);
    pixels.begin(); // INITIALIZE NeoPixel strip object (REQUIRED)
    pixels.show();
    pixels.setBrightness(40);
    randomSeed(analogRead(3));
    lcd.init();
    lcd.backlight();
    lcd.begin(16, 2);    //Deklaracja typu
    lcd.setCursor(0, 0); //Ustawienie kursora
}

void loop()
{

    pixels.clear();
    for (int i = 0; i < NUMPIXELS; i++)
    { // For each pixel...
        {

            tone(buzzer, 2000); // Send 1KHz sound signal...
            delay(300);         // ...for 1 sec
            noTone(buzzer);     // Stop sound...
            delay(1);
            lcd.clear();
            lcd.setCursor(random(0, 10), random(2));
            switch (random(0, 7))
            {
            case 0:
                pixels.setPixelColor(i, pixels.Color(255, 0, 0));
                lcd.print("RED");
                break;
            case 1:
                pixels.setPixelColor(i, pixels.Color(0, 255, 0));
                lcd.print("GREEN");
                break;
            case 2:
                pixels.setPixelColor(i, pixels.Color(0, 0, 255));
                lcd.print("BLUE");
                break;
            case 3:
                pixels.setPixelColor(i, pixels.Color(255, 255, 255));
                lcd.print("WHITE");
                break;
            case 4:
                pixels.setPixelColor(i, pixels.Color(255, 255, 0)); //Yellow
                lcd.print("Yellow");
                break;
            case 5:
                pixels.setPixelColor(i, pixels.Color(0, 255, 255)); //Cyan
                lcd.print("Cyan");
                break;
            case 6:
                pixels.setPixelColor(i, pixels.Color(255, 0, 255)); //Magenta
                lcd.print("Magenta");
                break;
                noTone(buzzer); // Stop sound...
                delay(1);
            }
        }
        //pixels.setPixelColor(i, pixels.Color(random(y),random(y),random(y)));
        pixels.show();   // Send the updated pixel colors to the hardware.
        delay(DELAYVAL); // Pause before next pass through loop
        Serial.println(i);
    }
}
