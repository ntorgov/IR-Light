#include <Arduino.h>
// #include <IRremote.h>

// int RECV_PIN = 11;

//IRrecv irrecv(RECV_PIN);

// decode_results results;

const int buttonPin = 11;
const int ledPin = 3; // shim
int buttonState = 0;
double lightValue = 0;

void setup()
{
  Serial.begin(9600);
  // Serial.println("Enabling IRin");
  // irrecv.enableIRIn(); // Start the receiver
  Serial.println("Enabled IRin");
  // put your setup code here, to run once:
  pinMode(buttonPin, INPUT);
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);
}

void loop()
{
  // buttonState = digitalRead(buttonPin);
  // put your main code here, to run repeatedly:
  Serial.print(buttonState);
  Serial.print(" - ");
  Serial.println(lightValue);
  if (buttonState == 1)
  {
    // turn LED on:
    // digitalWrite(ledPin, HIGH);
    //Serial.println("HIGH");
    analogWrite(ledPin, lightValue);
  }
  else
  {
    // turn LED off:
    //Serial.println("LOW");
    //digitalWrite(ledPin, LOW);
  }

  buttonState = !buttonState;

  // if (irrecv.decode(&results))
  // {
  //   Serial.println(results.value, HEX);
  //   irrecv.resume(); // Receive the next value
  // }
  delay(100);

  lightValue = lightValue + 10;
  if (lightValue > 255)
  {
    lightValue = 0;
  }
}