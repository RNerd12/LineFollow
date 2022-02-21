
// the setup function is for initialize variables
void setup() {
  pinMode(10, INPUT);     //sensor1
  pinMode(11, INPUT);     //sensor2
  pinMode(4, OUTPUT);     //motor 1
  pinMode(5, OUTPUT);     //motor 1
  pinMode(6, OUTPUT);     //motor 2
  pinMode(7, OUTPUT);     //motor 2
}

// the loop function runs over and over again forever
void loop() {
  int ls = digitalRead(10), rs = digitalRead(11);
  if(ls == HIGH && rs == HIGH)
  {
      digitalWrite(4,HIGH);
      digitalWrite(5,LOW);
      digitalWrite(6,HIGH);
      digitalWrite(7,LOW);
  }
  if(ls == LOW && rs == HIGH)
  {
      digitalWrite(4,LOW);
      digitalWrite(5,LOW);
      digitalWrite(6,HIGH);
      digitalWrite(7,LOW);
  }
  if(ls == HIGH && rs == LOW)
  {
      digitalWrite(4,HIGH);
      digitalWrite(5,LOW);
      digitalWrite(6,LOW);
      digitalWrite(7,LOW);
  }
  if(ls == LOW && rs == LOW)
  {
      digitalWrite(4,LOW);
      digitalWrite(5,LOW);
      digitalWrite(6,LOW);
      digitalWrite(7,LOW);
  }
}
