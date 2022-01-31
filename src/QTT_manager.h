#include <WiFi.h>
#include <PubSubClient.h> //Biblioteca para as publicações via mqtt
#define wifi "YourWifi"
#define passwd "passaword"

#define TOPIC "/xxx/xxxxxxx/xxx"
#define DEVICE_ID "xxxxxxxxxxxxxx"
#define SERVER "things.ubidots.com"
#define PORT 1883
#define TOKEN "xxxxxxxxxxxxxxxxxxxxxxxx"

void init();
void reconnect();
bool sendValues(float temperature, float humidity);
