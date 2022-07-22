//== Hardware ==
int led = 10;
int PIR = 11;
// == functional ==
int state = LOW;
int val = 0;

void setup() {
  pinMode(led, OUTPUT);
  pinMode(PIR, INPUT);
  Serial.begin(9600);
}

void loop(){
  val = digitalRead(PIR); // read PIR data - Sense  
  if (val == HIGH) { // consider PIR data - Think
    digitalWrite(led, HIGH); // respond to situation - Act
    delay(500);
    
    if (state == LOW) {
      Serial.println("Motion detected"); 
      state = HIGH;
    }
  } 
  else {
      digitalWrite(led, LOW);
      delay(500);
      
      if (state == HIGH){
        Serial.println("No motion");
        state = LOW;
    }
  }
}
