#include "QTT_manager.h"

WiFiClient ubidots;
    //Objeto PubSubClient usado para publish–subscribe
PubSubClient client(ubidots);

void init(){
    Serial.println("Connection with wifi...");
    WiFi.begin(wifi,passwd);

    while(WiFi.status() !=  WL_CONNECTED){
        Serial.println("Connection unstable, reconect...");
        delay(100);
    }
    Serial.println("Conectando com domain");
    client.setServer(SERVER, PORT);

    while(!client.connect(DEVICE_ID, TOKEN, "")){
        Serial.println("Try reconect...");
    }
    Serial.println("MQTT - Connect ok");
    
}

void reconnect() 
{  
  //Loop até que o MQTT esteja conectado
  while (!client.connected()) 
  {
    //sinaliza desconexão do mqtt no display
    Serial.println("Attempting MQTT connection...");
    
    //Tenta conectar
    if (client.connect(DEVICE_ID, TOKEN,"")) 
      Serial.println("connected");
    else 
    {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 2 seconds");
      //Aguarda 2 segundos antes de retomar
      delay(2000);
    }
  }
}

//Exemplo: {"temperature":{"value":24.50, "context":{"temperature":24.50, "humidity":57.20}}}
bool sendValues(float temperature, float amb)
{
  char json[250];
 
  //Atribui para a cadeia de caracteres "json" os valores referentes a temperatura e os envia para a variável do ubidots correspondente
  sprintf(json,  "{\"%s\":{\"value\":%02.02f, \"context\":{\"temperature\":%02.02f, \"humidity\":%02.02f}}}", "TEMP", temperature, temperature, amb);  

  if(!client.publish(TOPIC, json))
    return false;
  
  sprintf(json,  "{\"%s\":{\"value\":%02.02f, \"context\":{\"temperature\":%02.02f, \"humidity\":%02.02f}}}", "AMB", amb, amb, amb);  

  if(!client.publish(TOPIC, json))
    return false;
 
  return true;
}