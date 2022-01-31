#include <WiFi.h>
#include <PubSubClient.h> //Biblioteca para as publicações via mqtt
#define wifi "CLARO_2G02C36B"
#define passwd "5A02C36B"

#define TOPIC "/v1.6/devices/esp32"
#define DEVICE_ID "61f6fd3c44371f113f58098c"
#define SERVER "things.ubidots.com"
#define PORT 1883
#define TOKEN "BBFF-ewhBSmqsadXqLTlpknFDfATV3ZhIl5"

void init();
void reconnect();
bool sendValues(float temperature, float humidity);