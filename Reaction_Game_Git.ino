/*
Program written by Collin Milliron

This program was written for and tested on the Arduino Mega 2560 R3 by Elegoo

Hook up a Pot with the wiper plugged into A0

Hook up LEDs from outputs 1-13 each through a resistor to Ground

*/

// These constants won't change. They're used to give names to the pins used:
const int buttonPin = 2;
int led3 = 3; // digital output to LED
int led4 = 4; // digital output to LED
int led5 = 5; // digital output to LED
int led6 = 6; // digital output to LED
int led7 = 7; // digital output to LED
int led8 = 8; // digital output to LED
int led9 = 9; // digital output to LED
int led10 = 10; // digital output to LED
int led11 = 11; // digital output to LED
int led_win = 12; // digital output to GREEN LED
int led_lose = 13; // digital output to RED LED

// variables will change:
int buttonState = 0;  // variable for reading the pushbutton status

int game = false; // 
int sensorPin = A0;   // select the input pin for the potentiometer
int sensorValue = 0;        // value read from the pot
int speed = 100;

void setup() {
  // Initialize Serial Output
  Serial.begin(9600);
  // initialize digital pins powering the LEDs as an output.
  //pinMode(0, Button);
  pinMode(2, INPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
}

void loop() {

  // read the value from the sensor:
  sensorValue = analogRead(sensorPin);

  //outputValue = map(sensorValue, 0, 1023, 0, 255);
  speed = map(sensorValue, 0, 1023, 10, 150);

    // read the state of the pushbutton value:
  buttonState = digitalRead(buttonPin);

    if (buttonState == HIGH & game == true) {
  digitalWrite(led_win, HIGH);    //
  delay (500);
  digitalWrite(led_win, 0);
  }
  
  else if (buttonState == HIGH & game == false) {
  digitalWrite(led_lose, 1);    //
  delay (500);
  digitalWrite(led_lose, 0);
  }
  

  digitalWrite(led11, 1);    // LED on
    delay(speed);                      //The delay determines the game sensorValue. Can be changed.

  digitalWrite(led10, 1);    // LED on
    delay(speed);                      //The delay determines the game sensorValue. Can be changed.

  digitalWrite(led9, 1);    // LED on
    delay(speed);                      //The delay determines the game sensorValue. Can be changed.

  digitalWrite(led8, 1);    // LED on
    delay(speed);                      //The delay determines the game sensorValue. Can be changed.

  digitalWrite(led7, 1);    // LED on
    delay(speed);                      //The delay determines the game sensorValue. Can be changed.

  digitalWrite(led6, 1);    // LED on
    delay(speed);                      //The delay determines the game sensorValue. Can be changed.

  digitalWrite(led5, 1);    // LED on
    delay(speed);                      //The delay determines the game sensorValue. Can be changed.

  digitalWrite(led4, 1);    // LED on
    delay(speed);                      //The delay determines the game sensorValue. Can be changed.

  game = true;
  delay(2);
  digitalWrite(led3, 1);    // LED on
  delay(speed);                     //The delay determines the game sensorValue. Can be changed.



  game = false;
  digitalWrite(led3, 0);    // Turn all Leds off to restart the game
  digitalWrite(led4, 0);
  digitalWrite(led5, 0);
  digitalWrite(led6, 0);
  digitalWrite(led7, 0);
  digitalWrite(led8, 0);
  digitalWrite(led9, 0);
  digitalWrite(led10, 0);
  digitalWrite(led11, 0);
  digitalWrite(led11, 0);

  Serial.print("button = ");
  Serial.print(buttonState);
  Serial.print("game = ");
  Serial.print(game);
  Serial.print("\t game speed = ");
  Serial.println(speed);
  
  delay(speed);
  }

