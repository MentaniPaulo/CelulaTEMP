#include "TempSensor.h"
Adafruit_MLX90614 mlx = Adafruit_MLX90614();

void initTemp(){
    mlx.begin();
    
    mlx.readObjectTempC();
}
float temperaturaObjeto(){
     return mlx.readObjectTempC(); 
}

float temperaturaAmbiente(){   
    return mlx.readAmbientTempC();
}