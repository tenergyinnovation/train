#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>
#define BLYNK_SERIAL SERIAL

bool isFirstConnnect = true;
#define LED       2

int Brightness = 0;
int fadeAmount = 5;

const int freq = 5000;
const int ledChannel = 0;
const int resolu = 10;

const char * auth = "VadHUUPeTotJ1wFGEVbuvK2dZ4o6ii6U";
const char * ssid = "TENERGYINNOVATION";
const char * pass = "L0vemel0vemydog";
const char * blynkhost = "blynk.iot-cm.com";

BLYNK_CONNECTED()
{
  if(isFirstConnect)
  {
    Blynk.syncAll();
    isFirstConnect = false;
  }
}

BLYNK_WRITE(V4)
{
  Brightness = param.asInt();
  ledcWrite(ledChannel,Brightness);
}
void setup() {
  Serial.begin(9600);
  pinMode(LED,OUTPUT);

  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, pass);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print(".");
  }
  Serial.println("Connect WiFi");

  Blynk.begin(auth, ssid, pass, blynkhost, 8080);
  Serial.println("Connect Blynk");

  ledcSetup(ledChannel, freq, resolu);
  ledcAttachPin(LED,ledChannel);

}

void loop() {
  Blynk.run();

}
