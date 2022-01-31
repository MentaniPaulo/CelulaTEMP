#include "displayOLED.h"

Adafruit_SH1106G display = Adafruit_SH1106G(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
//Objeto do Sensor de temperatura
void initDisplay(){
  display.begin(i2c_Address, true); // Address 0x3C default
  display.setContrast (10); // dim display
  display.clearDisplay();
  display.setTextSize(2);
  display.display();  
}

void helloMsg(){
    display.clearDisplay();
    display.display(); 
    
    display.setTextColor(SH110X_WHITE);
    display.setCursor(0, 0);
    display.println("MQTT TEMP. SENSOR ");
    display.display();  
}
void printDisplay(float temp, float amb){
    display.clearDisplay();
    display.setTextColor(SH110X_WHITE);
   
    display.setCursor(0, 0);
    display.print("TEMP. OBJ: ");
    display.print(temp);
    display.println("C");
    display.print("TEMP. AMB: ");
    display.print(amb);
    display.println("C");
    display.display();  
}