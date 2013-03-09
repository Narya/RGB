/*
  Blink RGB
  Make nice colors
*/

// Pin 13 has an LED connected on most Arduino boards.
// give it a name:
// int rood = 15; // analog pin
// int groen = 16; // analog pin
// int blauw = 17; // analog pin
int rood = 9; // digital pin
int groen = 10; // digital pin
int blauw = 11; // digital pin

// delay time
int mytime = 5;

// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
  pinMode(rood, OUTPUT);     
  pinMode(groen, OUTPUT);     
  pinMode(blauw, OUTPUT);  
  Serial.begin(9600);
  switchOff();
}

// the loop routine runs over and over again forever:
void loop() {
//  purpleFade();
  rainbowFade();
}

void switchOn(int r,int g,int b) {
  // reverse pin output (0 is high, 255 is low with a combined anode)
//  Serial.print(r);
//  Serial.print(" ");
//  Serial.print(g);
//  Serial.print(" ");
//  Serial.println(b);
  r = 255 - r;
  g = 255 - g;
  b = 255 - b;
  // change the colors
  analogWrite(rood, r);   // turn the LED on with LOW
  analogWrite(groen, g);   // turn the LED on with LOW
  analogWrite(blauw, b);   // turn the LED on with LOW
  delay(mytime);               // wait for some time
}

void switchOff() {
  analogWrite(rood, 255);   // turn the LED off (HIGH is the voltage level)
  analogWrite(groen, 255);   // turn the LED off (HIGH is the voltage level)
  analogWrite(blauw, 255);   // turn the LED off (HIGH is the voltage level)
}

void purpleFade() {
  for (int i=1; i<256; i++) {
    switchOn(i,0,i);
  }
  for (int i=254; i>=0; i--) {
    switchOn(i,0,i);
  }
}

void rainbowFade() {
  for (int i=255; i>=0; i--) { // red to green
    int j = 255 - i;
    switchOn(i,j,0);
  }
  for (int i=255; i>=0; i--) { // green to blue
    int j = 255 - i;
    switchOn(0,i,j);
  }
  for (int i=255; i>=0; i--) { // blue to red
    int j = 255 - i;
    switchOn(j,0,i);
  }
}

