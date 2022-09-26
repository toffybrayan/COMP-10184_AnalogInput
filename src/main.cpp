#include <Arduino.h>
/*  I, Adebowale Atofarati, student number 000789108, certify that all code submitted is my own work;
that I have not copied it from any other source.
I also certify that I have not allowed my work to be copied by others.
*/

void setup() {
  // configure the USB serial monitor
  Serial.begin(115200);

}

void loop() {
  int iVal;
   double val;
   String judgement;

    // read digitized value from the D1 Mini's A/D convertor
 iVal = analogRead(A0);
 val = map(iVal, 0, 1023, 0, 5000);
 analogWrite(9, val);

 if(iVal < 10){
  judgement = " cold";
} 
else if( iVal >= 10 && iVal <= 15){
    judgement = "cool";
} 
else if( iVal >= 15 && iVal <= 25){
  judgement = " Perfect";
} 
else if( iVal >= 25 && iVal <= 30){
  judgement = "Warm";
} 
else if(iVal >= 30 && iVal <= 35){ 
  judgement = "Hot";
}
else if(iVal < 35){
  judgement = "Too hot";
}

 // print value to the USB port
Serial.println("Digitized Value of " + String(iVal) + 
 " is equivalent to a temperature input of " + (val/100) + "deg. C, which is " + judgement);
 // wait 0.5 seconds (500 ms)
 delay(500);

}