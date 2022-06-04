

void TaskMQTT(void *pvParameters){

    (void) pvParameters;

    while(1){
        vTaskDelay(30000); // 30 seg
        mqtt_publish(ADAFRUIT_FEED_LED, digitalRead(LED_1));
        vTaskDelay(10);
        mqtt_publish(ADAFRUIT_FEED_TEMP, t);
        vTaskDelay(10);
        mqtt_publish(ADAFRUIT_FEED_HUM, h);
    }

}

void TaskDHT11(void *pvParameters){
    (void) pvParameters;
    while(1){
        vTaskDelay(5000);
        sensors_event_t event;
        // Temperatura °C
        dht.temperature().getEvent(&event);
        if (isnan(event.temperature)) {
            Serial.println(F("Error leyendo la temperatura!"));
        }
        else {
            Serial.print(F("Temperatura: "));
            Serial.print(event.temperature);
            Serial.println(F("°C"));
            t = event.temperature;
        }
        // Humedad %
        dht.humidity().getEvent(&event);
        if (isnan(event.relative_humidity)) {
            Serial.println(F("Error leyendo la humedad!"));
        }
        else {
            Serial.print(F("Humedad: "));
            Serial.print(event.relative_humidity);
            Serial.println(F("%"));
            h = event.relative_humidity;
        }
    }
}
