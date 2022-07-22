// == Module 1 - Task 1.3C - Multiple Interupts ==

// Hardware
const uint8_t pir_led = 10;
const uint8_t button_led = 12;
const uint8_t PIR = 2;
const uint8_t button = 3;

// Functional
volatile bool pir_state = false;
volatile bool button_state = false;
int val = 0;

void setup() {
  Serial.begin(9600);
  pinMode(button_led, OUTPUT);
  //pinMode(pir_led, OUTPUT);
  pinMode(PIR, INPUT);
  pinMode(button, INPUT);
  
  //Interrupts
  attachInterrupt(digitalPinToInterrupt(PIR), led_interrupt, CHANGE);
  attachInterrupt(digitalPinToInterrupt(button), button_interrupt, FALLING);
}

void loop(){
  delay(1000);
}


void led_interrupt()
{
  // serial information
  Serial.print("PIR interrupt triggered - ");
  if(!pir_state){Serial.println("motion detected");}
  else {Serial.println("motion stopped");}
  pir_state = !pir_state;
  digitalWrite(pir_led, pir_state);
}
void button_interrupt()
{
  // serial information
  Serial.print("button interrupt triggered - ");
  if(!button_state){Serial.println("button on");}
  else {Serial.println("button off");}
  button_state = !button_state;
  digitalWrite(button_led, button_state);

}
