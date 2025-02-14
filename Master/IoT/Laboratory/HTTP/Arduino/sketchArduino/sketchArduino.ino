int iCurrentState;
unsigned long timestamp;

void setup(){
  Serial.begin(9600);
  iCurrentState = 0;
  timestamp = millis();
  pinMode(7,OUTPUT);
}

void loop() {

  if(Serial.available()) // Get the number of bytes (characters) available for reading from the serial port.
  {
    int dato = Serial.read();
    int futureState;
    if(dato == 'O' && iCurrentState == 0) futureState = 1;
    if(dato == 'N' && iCurrentState == 1) futureState = 2;
    if(dato == 'F' && iCurrentState == 1) futureState = 3;
    if(dato != 'F' && dato != 'N' && iCurrentState == 1) futureState = 0;
    if(dato == 'O' && iCurrentState == 2) futureState = 1;
    if(dato != 'F' && iCurrentState == 3) futureState = 0;
    if(dato == 'F' && iCurrentState == 3) futureState = 4;
    if(dato == 'O' && iCurrentState == 4) futureState = 1;


    if(dato == 10 || dato == 13) futureState = iCurrentState;

    iCurrentState = futureState;

    if(iCurrentState == 2) digitalWrite(7,HIGH);
    if(iCurrentState == 4) digitalWrite(7,LOW);
  }

  int dato1;
  if (millis() - timestamp > 5000){
    dato1 = analogRead(A2);
    // pacchetto dati
    // FF  2  dato1 FE
    Serial.write(0xFF);
    Serial.write(1);
    
    Serial.write(map(dato1,0,1023,0,253));
  
    Serial.write(0xFE);
    
    timestamp = millis();
  }

}
