                                                                                                                                                                                    /*
  Button

  Turns on and off posting button state to serial port,
  when pressing a pushbutton attached to pin 2.

  The circuit:
  - pushbutton attached to pin 2 from GND

  This code is in the public domain.

  http://www.arduino.cc/en/Tutorial/Button
  https://miliohm.com/arduino-button-without-resistor-pull-up-or-pull-down/
*/

// constants won't change. They're used here to set pin numbers:
const int buttonPin = 2;     // the number of the pushbutton pin


// variables will change:
int buttonState = 0;         // variable for reading the pushbutton status
int pressed = false;

void setup() {
  Serial.begin(9600);
  // initialize the pushbutton pin as an input using internal resistor:
  pinMode(buttonPin, INPUT_PULLUP);
}

void loop() {
  // read the state of the pushbutton value:
  buttonState = digitalRead(buttonPin);

  // check if the pushbutton is pressed. If it is, the buttonState is LOW:
  if (buttonState == LOW ) {
    if(!pressed) {
      pressed = true;
      // post state to serial:
      Serial.println(buttonState);
     }
  } else {
    pressed = false;
  }
  
}
