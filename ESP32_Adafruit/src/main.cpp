#include <Arduino.h>
#include "functions.hpp"
#include "task.hpp"

void setup() {
  // Inicializar el Serial
  Serial.begin(115200);
  Serial.print("\n");
  // DHT11
  dht11_init(); 
  // Crar un ID para MQTT
  get_MQTT_ID();
  // LED 1 a Salida
  set_LED();
  // Crear Tarea TaskMQTT enviar por MQTT
  xTaskCreatePinnedToCore(
    TaskMQTT
    , "TaskMQTT"
    , 2048
    , NULL
    , 2
    , NULL
    , 1
  );
  // Tarea sensor de Temp y Hum DHT11
  xTaskCreatePinnedToCore(
    TaskDHT11
    , "TaskDHT11"
    , 2048
    , NULL
    , 2
    , NULL
    , 1
  );
  // Inicio conexión a WiFi
  WiFi_begin();
  // Iniciar el servidor MQTT
  client.setServer(ADAFRUIT_SERVER, ADAFRUIT_PORT);
  client.setCallback(callback);
}

void loop() {
  loopMQTT();
}