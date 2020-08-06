int ftrig = 4; 
int fecho = A1; 
long flecture_fecho; 
long fcm;
int bltrig = 3; 
int blecho = A4; 
long bllecture_blecho; 
long blcm;
int brtrig = 2; 
int brecho = A2; 
long brlecture_brecho; 
long brcm;
int fon;
int rbon;
int lbon;
int ron = 7;
int lon = 6;
//int = max/min(5, 10); for the motor foward actavation
void setup() // happens once, this is for defining variables
{ 
  //front
  pinMode(ftrig, OUTPUT); //defining the variable type, OUT or INPUT
  digitalWrite(ftrig, LOW); //setting the variable to LOW 
  pinMode(fecho, INPUT); 
  //back left
  pinMode(bltrig, OUTPUT); 
  digitalWrite(bltrig, LOW); 
  pinMode(blecho, INPUT); 
  //back right
  pinMode(brtrig, OUTPUT); 
  digitalWrite(brtrig, LOW); 
  pinMode(brecho, INPUT);
  
  digitalWrite(9, HIGH);//setting the pin on the arduino for pin 9
  
  Serial.begin(9600);//starts the serial monitor 
}
void loop() //keeps repeting
{   
  //front
  digitalWrite(ftrig, HIGH); //starting the sensor 
  delayMicroseconds(10); //delaying for the ultrasound sensor
  digitalWrite(ftrig, LOW); //stopping the sencor
  flecture_fecho = pulseIn(fecho, HIGH); //setting the var, lecture_echo to read the pulse
  fcm = flecture_fecho / 58; //setting the dinsance on the serial monitor, what we see 
  //back left
  digitalWrite(bltrig, HIGH); 
  delayMicroseconds(10); 
  digitalWrite(bltrig, LOW); 
  bllecture_blecho = pulseIn(blecho, HIGH); 
  blcm = bllecture_blecho / 58;
  //back right
  digitalWrite(brtrig, HIGH); 
  delayMicroseconds(10); 
  digitalWrite(brtrig, LOW); 
  brlecture_brecho = pulseIn(brecho, HIGH); 
  brcm = brlecture_brecho / 58;
  //if front
  if (fcm > 7 && fcm < 318) { // if the front sensor sences anything=
   bool fon = true;// front is on
   analogWrite(10, fcm);// front right on
   analogWrite(6, fcm);// front left on
   digitalWrite(9, LOW);// back right on
   digitalWrite(11, LOW);// back left on
   delay(1000); // delay for one second   // 9 fr, 
   digitalWrite(6, 25);
   analogWrite(9, 100);
   digitalWrite(10, LOW);
   digitalWrite(11, LOW);
   delay(2000);
  } else {
   bool fon = false;
  }
  //if back left
 if (blcm > 7 && blcm < 318) {
   bool lbon = true;
   analogWrite(6, blcm);
   analogWrite(11, blcm);
  } else {
   bool lbon = false;
  }
  //if back right
    if (brcm > 7 && brcm < 318) {
   bool rbon = true;
   analogWrite(10, brcm);
   analogWrite(9, brcm);
  } else {
   bool rbon = false;
  }
  if (fon == true && rbon == true) {
   
  }
  delay(1); 
}
//bruh mometn gang
