// Credenciales Red WiFi
#define WIFI_SSID "your_ssid"
#define WIFI_PASSWORD "your_ssid_passw"
// Credenciales Adafruit
#define ADAFRUIT_USER "your_user"
#define ADAFRUIT_KEY "your_key"
// Publicar
#define ADAFRUIT_FEED_LED ADAFRUIT_USER "/feeds/led"
#define ADAFRUIT_FEED_TEMP ADAFRUIT_USER "/feeds/temp"
#define ADAFRUIT_FEED_HUM ADAFRUIT_USER "/feeds/hum"
// Suscripción
#define ADAFRUIT_FEED_ON_OFF ADAFRUIT_USER "/feeds/led_on_off"
// Servidor
#define ADAFRUIT_SERVER "io.adafruit.com"
#define ADAFRUIT_PORT 1883

char ADAFRUIT_ID[30];

#define LED_1   27

#define DHTPIN  4
#define DHTTYPE DHT11  

float t = 0;
float h = 0;

