void setup() {

  Serial.begin(9600); // set data rate in bits per second for serial data transmission
  pinMode(8,OUTPUT);
}

void loop() {

  if(Serial.available()) // Get the number of bytes (characters) available for reading from the serial port.
  {
    int dato = Serial.read();
    if(dato == 'S') digitalWrite(8,LOW);
    if(dato == 'A') digitalWrite(8,HIGH);
  }

}
