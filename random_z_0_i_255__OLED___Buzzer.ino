#include <Adafruit_NeoPixel.h>
#include <Wire.h> // standardowa biblioteka Arduino
//#include <LiquidCrystal_I2C.h>
#define PIN 3 // On Trinket or Gemma, suggest changing this to 1

// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS 8 // Popular NeoPixel ring size

//LiquidCrystal_I2C lcd(0x27, 20, 4);
Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

#define DELAYVAL 200 // Time (in milliseconds) to pause between pixels

const int buzzer = 9;
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 32 // OLED display height, in pixels

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);





void setup()
{

    pinMode(buzzer, OUTPUT);
    Serial.begin(9600);
    pixels.begin(); // INITIALIZE NeoPixel strip object (REQUIRED)
    pixels.show();
    pixels.setBrightness(25);
    randomSeed(analogRead(3));
    //lcd.init();
    //lcd.backlight();
    //lcd.begin(16, 2);    //Deklaracja typu
    //lcd.setCursor(0, 0); //Ustawienie kursora
 Serial.begin(115200);
    randomSeed(analogRead(3));
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Address 0x3D for 128x64
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  }
}

void loop()
{

    pixels.clear();
    for (int i = 0; i < NUMPIXELS; i++)
    { // For each pixel...
        {

            tone(buzzer, 1100); // Send 1KHz sound signal...
            delay(100);         // ...for 1 sec
            noTone(buzzer);     // Stop sound...
            delay(1);
            //lcd.clear();
            //lcd.setCursor(random(0, 10), random(2));
             display.clearDisplay();

            display.setTextSize(2);
            display.setTextColor(WHITE);
            display.setCursor(random(0,55) ,random(0,18));
            switch (random(0, 7))

           
  
            {
            case 0:
                pixels.setPixelColor(i, pixels.Color(255, 0, 0));
                display.print("RED");
                display.display();
                break;
            case 1:
                pixels.setPixelColor(i, pixels.Color(0, 255, 0));
                display.print("GREEN");
                display.display();
                break;
            case 2:
                pixels.setPixelColor(i, pixels.Color(0, 0, 255));
                display.print("BLUE");
                display.display();
                break;
            case 3:
                pixels.setPixelColor(i, pixels.Color(255, 255, 255));
                display.print("WHITE");
                display.display();
                break;
            case 4:
                pixels.setPixelColor(i, pixels.Color(255, 255, 0)); //Yellow
                display.print("Yellow");
                display.display();
                break;
            case 5:
                pixels.setPixelColor(i, pixels.Color(0, 255, 255)); //Cyan
                display.print("Cyan");
                display.display();
                break;
            case 6:
                pixels.setPixelColor(i, pixels.Color(255, 0, 255)); //Magenta
                display.print("Magenta");
                display.display();
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
