/**
 * Simple traffic light control sketch for Arduino Uno
 * 
 * Traffic light program for Arduino Uno.
 * Board is quite simple setup. each led cathode is connected 
 * to ground via 220 Ohm resistor and each anode to their 
 * respective digital pin. Switch is plugged between ground 
 * via 10 kOhm resistor and to it's own digital pin.
 * 
 * @author Jonna Judin
 * @version 1.0 * 
*/
// digital pin for the switch
int const SWITCH = 1;

// light pins need to be next to each other due to init routine
int const RED    = 11;
int const YELLOW = 10;
int const GREEN  = 9;

// initially no lights are lit
int const NONE  = -1;

int switchState = 0;
int oldSwitchState = LOW;
int currentLight = NONE;

void setup() {
  // all lights set as output and off 
  for(int pin = GREEN ; pin <= RED ; pin++){
      pinMode(pin, OUTPUT);
      digitalWrite(pin, LOW);
  }
  // setup switch for input
  pinMode(SWITCH, INPUT);  
}

void loop() {
  // Check switch status
  switchState = digitalRead(SWITCH);
  // Check if switch has been pressed and released
  if (switchState == LOW && oldSwitchState == HIGH) {
    changeLights();    
  }  
  oldSwitchState = switchState;
  delay(100);  
}

/**
 * Maintain the lights transferring in correct order
 * Red -> Green -> Yellow -> Red ...
 * Button is used only to switch out from either green
 * or red. Yellow is shown only briefly and switched
 * automatically
 */
void changeLights(){
  switch(currentLight) {
    case NONE: // on first run turn on red   
      digitalWrite(RED, HIGH);
      currentLight = RED;
      break;
    case GREEN: // light yellow one briefly then move to red
      digitalWrite(GREEN, LOW);
      digitalWrite(YELLOW, HIGH);
      delay(1000); 
      digitalWrite(YELLOW, LOW);        
      digitalWrite(RED, HIGH);
      currentLight = RED;
      break;
    case RED: // no yellow shown on red->green transition
      digitalWrite(RED, LOW);
      digitalWrite(GREEN, HIGH);        
      currentLight = GREEN;
      break;    
    default:
      currentLight = NONE;
      break;
  }
}
