#include <SomeSerial.h>

SoftwareSerial BTserial(13, 12); // RX | TX


int sensor_pin = A0; 
int output_value;
int s_state = 1;
const int fiveVolt =  2;


void setup() {
  Serial.begin(9600);
  BTserial.begin(9600);
  Serial.println("Reading From the Sensor ...");
  delay(2000);
  }

void loop(){
  output_value= analogRead(sensor_pin);
  output_value = map(output_value,550,0,0,100); //550 = wet; 0 = dry
  Serial.print("Mositure : ");
  Serial.print(output_value);
  Serial.println("%");
  BTserial.print(output_value);
  BTserial.print(";");
  if (output_value < 25)
    {
      s_state = 0;
      digitalWrite(fiveVolt, HIGH);
      Serial.println("Motor Activated!");
    } 
    else if(output_value<70 && output_value>60)
    {
      s_state=1;
      digitalWrite(fiveVolt, LOW);
      Serial.println("Motor Deactivated!");
    }
    else
    {
      digitalWrite(fiveVolt, LOW);
    }
  delay(1000);
  }
