#include <Arduino.h>

//////Relevantant Values///////////
double a[3] = {1, -1.1430, 0.4128};
double b[3] = {0.0675, 0.1349, 0.0675};
float fc = 10;
double y[3] = {0, 0, 0};
int x[3] = {0, 0, 0}; // entrada
int i = 0;
int adc_pin = 34;
unsigned long prev_millis;

///////////PWM Properties/////////////////
float freq = 5;
const int resolution = 8;
const int channel = 0;
const int ledPin = 25;

int dutyCycle = 128;

void setup()
{
  Serial.begin(115200);
  pinMode(ledPin, OUTPUT);
  ledcSetup(channel, freq, resolution);

  ledcAttachPin(ledPin, channel);
  ledcWrite(channel, dutyCycle);
  prev_millis = millis();
  // put your setup code here, to run once:
}

void loop()
{

  if ((millis() - prev_millis >= 5))
  {
    prev_millis = millis();

    x[2] = x[1];
    x[1] = x[0];
    x[0] = analogRead(adc_pin);

    y[2] = y[1];
    y[1] = y[0];

    y[0] = b[0] * x[0] + b[1] * x[1] + b[2] * x[2] - a[1] * y[1] - a[2] * y[2];

    Serial.printf("%d,%.2f\n",x[0],y[0]);
  }

  // put your main code here, to run repeatedly:
}
