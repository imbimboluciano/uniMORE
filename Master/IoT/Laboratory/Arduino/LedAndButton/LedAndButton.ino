void setup(){

	pinMode(13,OUTPUT);
	pinMode(3,INPUT);
}

void loop(){

	if(digitalRead(3) == LOW){
		digitalWrite(13,HIGH);
	}else{
		digitalWrite(13,LOW);
	}
}