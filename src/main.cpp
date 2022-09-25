#define BLYNK_TEMPLATE_ID "TMPLuYrm86fg"
#define BLYNK_DEVICE_NAME "Sequencial de LEDs"
#define BLYNK_AUTH_TOKEN "Dop8PvZ6xlHa23uf5OTp3GWxtNYuFBf3"

#define BLYNK_PRINT Serial

#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "Luciana";
char pass[] = "Lu_e_convidados";

int LEDVermelho = 32;
int LEDAmarelo = 26;
int LEDVerde = 13;

BLYNK_WRITE(V0) {
  int valor = param.asInt();
  digitalWrite(LEDVermelho, valor);
}

BLYNK_WRITE(V1) {
  int valor = param.asInt();
  digitalWrite(LEDAmarelo, valor);
}

BLYNK_WRITE(V2) {
  int valor = param.asInt();
  digitalWrite(LEDVerde, valor);
}

void setup()
{
  Serial.begin(115200);

  Blynk.begin(auth, ssid, pass);

  pinMode(LEDVermelho, OUTPUT);
  pinMode(LEDAmarelo, OUTPUT);
  pinMode(LEDVerde, OUTPUT);
}

void loop() {
  Blynk.run();
}