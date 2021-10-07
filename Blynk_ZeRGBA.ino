#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>
#define BLYNK_PRINT Serial


#define LED_R    2
#define LED_G    26
#define LED_B    27

bool isFirstConnect = true;

int R,G,B;

const char* auth = "***Your token Blynk***";
const char* ssid = "***Your user Wifi***";
const char* pass = "***Your password Wifi***";
const char * blynkhost = "blynk.iot-cm.com";

BLYNK_CONNNECT()
{
  if(isFirstConnect)
  {
    Blynk.syncAll();
    isFirstConnect = false;
  }
}

BLYNK_WRITE(V1)
{
  int value = param[0].asInt();
  int value1 = param[1].asInt();
  int value2 = param[2].asInt();
  digitalWrite(LED_R,value);
  digitalWrite(LED_G,value);
  digitalWrite(LED_B,value);
}

void setup()
{
  Serial.begin(9600);
  pinMode(LED_R,OUTPUT);
  pinMode(LED_G,OUTPUT);
  pinMode(LED_B,OUTPUT);

  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, pass);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print(".");
  }
  Serial.println("Connect WiFi");

  Blynk.begin(auth, ssid, pass, blynkhost, 8080);
  Serial.println("Connect Blynk");
}

void loop()
{
  Blynk.run();
}
