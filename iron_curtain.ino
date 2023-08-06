#define BLYNK_PRINT Serial

#include <Blynk.h>
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

const int buzzer=4;
const int biled=2;
const int relay=5;

#define BLYNK_TEMPLATE_ID "TMPL3wQ4Kr9dO"
#define BLYNK_TEMPLATE_NAME "Iron Curtain"
#define BLYNK_AUTH_TOKEN "CucDewb8UBdz73v5UrKNaUH8NlKzO7rE"

char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "D4RK wifi";
char pass[] = "#23702370";

BlynkTimer timer;

void sendSensor(){
  
  int sensorValue = analogRead(A0);
  
  Serial.println(sensorValue);
  Blynk.virtualWrite(V1,0);
  //Blynk.virtualWrite(V0, "MACHINE WORKING NORMALLY");
  Blynk.virtualWrite(V2,0);
  
  if (sensorValue<1000){
    
    digitalWrite(buzzer,LOW);
    digitalWrite(biled,LOW);
    digitalWrite(relay,HIGH);
    
    //Blynk.virtualWrite(V0, "EMERGENCY STOP ACTIVATED");
    Blynk.virtualWrite(V2,1);
    Blynk.virtualWrite(V1,1);
    delay(25000);
    
    digitalWrite(buzzer,HIGH);
    digitalWrite(biled,HIGH);
    digitalWrite(relay,LOW);
    }
    
}
  void setup() {

  Serial.begin(9600);
  
  Blynk.begin(auth, ssid, pass);

  pinMode(buzzer,OUTPUT);
  pinMode(biled,OUTPUT);
  pinMode(relay,OUTPUT);
  
  digitalWrite(buzzer,HIGH);
  digitalWrite(biled,HIGH);
  digitalWrite(relay,LOW);
  
  timer.setInterval(100L,sendSensor);
 
}

void loop() {
  
  Blynk.run();
  timer.run();
  
  }
