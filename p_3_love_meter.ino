const int sensorPin = A0;
const float baselineTemp = 25;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  for(int pinNumber = 2; pinNumber < 5; pinNumber++ )
  {
    pinMode(pinNumber, OUTPUT);
    digitalWrite(pinNumber, LOW);
  }
}

void loop() {
  int sensorVal = analogRead(sensorPin);
  //Serial.print(" Valeur capteur : ");
  //Serial.print(sensorVal);

  float voltage = (sensorVal / 1024.0) * 5;
  //Serial.print(" Voltage : ");
  //Serial.print(voltage);

  Serial.print(" degres C° : ");
  float temperature = (voltage -0.5) * 100;
  Serial.println(temperature);
  
  if(temperature < baselineTemp)
  {
     for(int pinNumber = 2; pinNumber < 5; pinNumber++ )
     {
        digitalWrite(pinNumber, LOW);
     }
  }
  else if(temperature >= baselineTemp + 2 && temperature <= baselineTemp +4)
  {
    digitalWrite(2, HIGH);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
  }else if(temperature >= baselineTemp +4 && temperature <= baselineTemp +6)
  {
    for(int pinNumber = 2; pinNumber < 5; pinNumber++ )
     {
        digitalWrite(pinNumber, HIGH);
     }
  }

  delay(1);
}
