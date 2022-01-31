#include <Arduino.h>
#include "QTT_manager.h"
#include "displayOLED.h"
#include "TempSensor.h"

float tempAmbiente;
float tempObjeto;
void setup() {
  // put your setup code here, to run once:
  //Wire.begin(I2C_SDA, I2C_SCL);
  Serial.begin(9600);
  init();
  initDisplay();
  delay(1000);
  helloMsg();
  initTemp();
}

void loop() {
  tempAmbiente = temperaturaAmbiente();
  tempObjeto = temperaturaObjeto();
  reconnect();
  Serial.println(sendValues(tempObjeto, tempAmbiente));
  Serial.println();
  printDisplay(tempObjeto, tempAmbiente);
  delay(1000);
  
}