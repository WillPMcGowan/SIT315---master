
// == Module 1 - Task 1.2P - Iterrupts  ==

// Hardware
int led = 10;
int PIR = 2;

// Functional
volatile bool state = false;

void setup() {
  Serial.begin(9600);
  pinMode(led, OUTPUT);
  pinMode(PIR, INPUT);
  //Interrupt
  attachInterrupt(digitalPinToInterrupt(PIR), led_interrupt, CHANGE);
}

void loop(){
  delay(2000);
}
void led_interrupt()
{
  // serial information
  Serial.print("PIR interrupt triggered - ");
  if(state == false){Serial.println("motion detected");}
  else {Serial.println("motion stopped");}
  state = !state;
  digitalWrite(led, state);
}
