#include <IRremote.h>
#include "pins_arduino.h"
int RECV_PIN = 3;//Pin should be PWM

IRrecv irrecv(RECV_PIN);

decode_results results;
int led1 = 1;
int headlight = 0;


void setup()
{ 
  Serial.begin(9600);
  irrecv.enableIRIn(); // Start the receiver
  
  //for headlights
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  
  //for motor(wheels)
  pinMode(13, OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(11,OUTPUT); 
  pinMode(12,OUTPUT);  
  
  digitalWrite(13, HIGH);
}
void loop() {
  
  if (irrecv.decode(&results)) {
      switch(results.value)
      {        
        case 16582903:	Serial.println("headlights on");
        				digitalWrite(5,HIGH);
                        digitalWrite(6,HIGH);
                       	break;
        
        case 16599223:	Serial.println("headlights off");
        				digitalWrite(5,LOW);
                        digitalWrite(6,LOW);
                       	break;
        
        case 16615543:  Serial.println("Forward"); // Button 2  
                         digitalWrite(8,LOW);
                         digitalWrite(9,HIGH);
                         digitalWrite(10,LOW);
                         digitalWrite(11,HIGH);
        				digitalWrite(12,LOW);
                         break;       
        case 16591063:  Serial.println("Left"); // Button 4
                         digitalWrite(8,HIGH);
                         digitalWrite(9,LOW);
                         digitalWrite(10,LOW);
                         digitalWrite(11,HIGH);
        				digitalWrite(12,LOW);
                         break; 
        case 16623703:  Serial.println("Stop"); // Button 5
                         digitalWrite(8,HIGH);
                         digitalWrite(9,HIGH);
                         digitalWrite(10,HIGH);
                         digitalWrite(11,HIGH);
        				digitalWrite(12,HIGH);
                         break; 
        case 16607383:  Serial.println("Right"); // Button 6
                         digitalWrite(8,LOW);
                         digitalWrite(9,HIGH);
                         digitalWrite(10,HIGH);
                         digitalWrite(11,LOW);
        				digitalWrite(12,LOW);
                         break;         
        case 16619623:  Serial.println("Back"); // Button 8  
                         digitalWrite(8,HIGH);
                         digitalWrite(9,LOW);
                         digitalWrite(10,HIGH);
                         digitalWrite(11,LOW);
        				digitalWrite(12,LOW);
                         break;   
        default: Serial.println(results.value);     
      }  
    irrecv.resume(); // Receive the next value
  }
  
}