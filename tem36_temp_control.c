// C++ code
//

int data_value;
int x = 24;
  
void setup()
{
  pinMode(LED_BUILTIN, OUTPUT);
  
  // config I/O
  pinMode(7, OUTPUT);
  pinMode(3, INPUT);
  pinMode(2, INPUT);
  
  // config serial monitor
  Serial.begin(115200);
  while(!Serial);
}

void loop()
{  
  // switch(3) press
  if (digitalRead(3) == LOW)
  {
    delay(80);
    while (digitalRead(3) != HIGH);
    delay(80);
    x = x-1;
  }
  
  // switch(2) press
  if (digitalRead(2) == LOW)
  {
    delay(80);
    while (digitalRead(2) != HIGH);
    delay(80);
    x = x+1;
  }
  
  // read temp sensor (TMP36)
  data_value = analogRead(A0);
  Serial.print("ADC value : ");
  Serial.println(data_value);
  
  // calculate ADC input voltag
  Serial.print("ADC input voltag : ");
  Serial.print(data_value * 0.0048828125);
  Serial.println(" V.");
  
  // calculate temperature (°C) value
  Serial.print("Temperature : ");
  // temp = (vout - 0.5) * 100
  Serial.print( ((data_value * 0.0048828125)-0.5) * 100 );
  Serial.println(" Celcius degrees");
  
  // print setpoint
  Serial.print("X : ");
  Serial.println(x);
  
  Serial.println("");
  
  // LED On
  if ( (((data_value * 0.0048828125)-0.5) * 100 ) > x+2 )
  {
    digitalWrite(7, HIGH);
  }
  
  // LED Off
  if ( (((data_value * 0.0048828125)-0.5) * 100 ) < x-2 )
  {
    digitalWrite(7, LOW);
  }
  
  
  delay(500);
}