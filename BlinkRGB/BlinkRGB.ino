/*
  Make nice colors with RGB LED
*/

// define which color is controlled by which pin
int red = 9; // digital pin
int green = 10; // digital pin
int blue = 11; // digital pin

// delay time
int mytime = 5;

// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
  pinMode(red, OUTPUT);     
  pinMode(green, OUTPUT);     
  pinMode(blue, OUTPUT);  
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
  r = 255 - r;
  g = 255 - g;
  b = 255 - b;
  // change the colors
  analogWrite(red, r);
  analogWrite(green, g);
  analogWrite(blue, b);
  delay(mytime); // wait for some time
}

void switchOff() {
  // turn the LED off (high nr is off in case of common anode)
  analogWrite(red, 255);
  analogWrite(green, 255);
  analogWrite(blue, 255);
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

