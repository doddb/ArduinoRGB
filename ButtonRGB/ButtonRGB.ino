/*
Simple program using a button to change the state of 
 an RGB LED. 
 ON startup light is OFF.
 Press the button:
 1. Red Light
 2. Green Light
 3. Blue Light
 4. Cycle
 5. *Hold until OFF*

Authors: Billy & Carolina
Date: November 14, 2020

*/

const int buttonPin = 2; // Input pin for da button
const int red_light_pin = 6; // Red 
const int green_light_pin = 11; // Green
const int blue_light_pin = 5; // Blue

int buttonState = 0;
int lightState = 0; 
int r;
int g;
int b;


// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  //pinMode(LED_BUILTIN, OUTPUT);
  pinMode(buttonPin, INPUT);
  pinMode(green_light_pin, OUTPUT);
  pinMode(red_light_pin, OUTPUT);
  pinMode(blue_light_pin, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  //check state of button
  buttonState = digitalRead(buttonPin);
 
  //is the button pressed? (HIGH)
  if (buttonState == 1) {
      //first button press change to red
      if (lightState == 0) {
        RGB_color(50, 0, 0); // Pure Red
        delay(375);
        lightState = 1;
      }
      
      //second button press turn to green
      else if (lightState == 1){
        RGB_color(0, 50, 0);
        delay(375);
        lightState = 2;
      }
      
      ///third button press turn to blue
      else if (lightState == 2) {
        RGB_color(0, 0, 50);
        lightState = 3;
        delay(375);        
      }
      
      //fourth button cycle rgb
      else if (lightState == 3) {
        //Logic is outside the parent conditional
        //  at the end of the loop
        //change light state to 4 
        //   delay
        lightState = 4;
        delay(375);
      }
      
      ///fifth button press turn light off
      else {
        RGB_color(0, 0, 0);
        delay(375);
        lightState = 0;
      }
  } // End Button Pressd conditional




  //Logic for the RGB Cycle
  //   Press and hold until light turns off
  //
  if (lightState == 4) {
     //reset the channel incrementers
     r = 0;
     g = 0;
     b = 0;

     //build up the red
     for (r = 0; r < 200; r++) {
        RGB_color(r,g,b);
     }
     delay(300);
     //decrement the red and start increasing green
     for (r = 200; r > 0; r--) {        
        if (r < 100){
          //start increasing green
          g += 1;
        }
        RGB_color(r,g,b);
     }
     delay(300);
     
     //finsih building up the green
     for (g = 100; g < 200; g++) {
        RGB_color(r,g,b);
     }     
     delay(300);
     
     //decrement the green and start building up the blue
     for (int g = 200; g > 0; g--) {
        if ( g < 100) {
          b += 1;
        }
        RGB_color(r,g,b);
     }
     delay(300);
     
     //finsih building up the blue
     for (b = 100; b < 200; b++) {
        RGB_color(r,g,b);
     }
     delay(300);
      
     //decrement the blue
     for (b = 200; b > 0; b--) {
        RGB_color(r,g,b);
     }
  }
}

//Function for changing the various channels
void RGB_color(int red_light_value, int green_light_value, int blue_light_value){
  analogWrite(red_light_pin, red_light_value);
  analogWrite(green_light_pin, green_light_value);
  analogWrite(blue_light_pin, blue_light_value);
}
