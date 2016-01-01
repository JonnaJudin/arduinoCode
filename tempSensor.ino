const int PIN_TMP_SENSOR = A0;
const int PIN_BLUE = 4;
const int PIN_GREEN  = 3;
const int PIN_RED    = 2;

// preferred temperature limits
const float COLD = 18.0;
const float HOT = 22.0;

void setup() {
  // open serial for debug
  Serial.begin(9600);
 // INIT PINS
  for(int pin = PIN_RED; pin <= PIN_YELLOW; pin++){
    pinMode(pin, OUTPUT);
    digitalWrite(pin,LOW);
  } 
}

void loop() {
  // read sensor data
  int sensorVal = analogRead(PIN_TMP_SENSOR);  
  Serial.print("Sensor Value: ");
  Serial.print(sensorVal);
  
  // convert reading to voltage 
  float voltage = (sensorVal/1024.0) * 5.0;
  Serial.print(" Volts: ");
  Serial.print(voltage);

  // convert voltage to degrees celcius
  float temperature = (voltage - 0.5) * 100;
  Serial.print(" Temperature in C: ");
  Serial.println(temperature);

  // if colder than COLD, light blue led, turn off rest
  if(temperature < COLD){
    Serial.println("It's Cold");
    digitalWrite(PIN_BLUE,HIGH);
    digitalWrite(PIN_RED,LOW);
    digitalWrite(PIN_GREEN, LOW);
  }
  else if(temperature > HOT){
    Serial.println("It's Hot");
    // when too hot, light red one, turn off rest
    digitalWrite(PIN_BLUE,LOW);
    digitalWrite(PIN_RED,HIGH);
    digitalWrite(PIN_GREEN, LOW);
  }
  else{
    // ok temp, light green one, turn off rest
    Serial.println("It's OK");
    digitalWrite(PIN_BLUE,LOW);
    digitalWrite(PIN_RED,LOW);
    digitalWrite(PIN_GREEN, HIGH);
  }
  delay(5000); // wait 5 secs between temp checks
}
