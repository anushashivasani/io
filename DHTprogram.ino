#include <DHT.h>

#define outPin 7
#define ledPin 13
DHT DHT_U(7, DHT11);

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
}
void loop() {
  delay(2000);

  DHT_U.read();

  float t = DHT_U.readTemperature();
  float h = DHT_U.readHumidity();

  Serial.print("Temparature = ");
  Serial.print(t);
  Serial.print(" |");
  Serial.print((t * 9.0) / 5.0 + 32.0);
  Serial.println(" ");
  Serial.print("Humidity = ");
  Serial.print(h);
  Serial.println("% ");
  Serial.println(" ");

  if(t > 25.0) {
    digitalWrite(ledPin, HIGH);
    delay(500);
    digitalWrite(ledPin, LOW);
    delay(500);
  }
  else {
    digitalWrite(ledPin, LOW);
    delay(1000);
  }

  


}
