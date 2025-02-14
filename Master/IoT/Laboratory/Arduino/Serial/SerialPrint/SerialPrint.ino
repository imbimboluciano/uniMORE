void setup() {
  Serial.begin(9600);

}

void loop() {

  int dato;
  if(Serial.available()){
    dato = Serial.read();
    Serial.write(dato);
  }

}
