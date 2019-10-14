#include <Servo.h>

/* @file CustomKeypad.pde
|| @version 1.0
|| @author Alexander Brevig
|| @contact alexanderbrevig@gmail.com
||
|| @description
|| | Demonstrates changing the keypad size and key values.
|| #
*/
#include <Keypad.h>
#define password_length 3
char A[password_length];
char B[password_length]="12";
int data_count=0,master_count =0;
bool pass_is_good;
int mator =9;
const byte ROWS = 4; //four rows
const byte COLS = 4; //four columns
//define the cymbols on the buttons of the keypads
char a[4];
char hexaKeys[ROWS][COLS] = {
   {'1','2','3','a'},
  {'4','5','6','b'},
  {'7','8','9','c'},
  {'*','0','#','d'}
};
byte rowPins[ROWS] = {10,8,7, 6}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {5,4,3, 2}; //connect to the column pinouts of the keypad

//initialize an instance of class NewKeypad
Keypad customKeypad = Keypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS); 
Servo myservo;

void setup(){
  myservo.attach(11); 
  Serial.begin(9600);
   pinMode (mator,OUTPUT);
    clearData();
    myservo.write(0);                  // sets the servo position according to the scaled value
    
}
  
void loop(){
  
 
  m();
 
char customKey = customKeypad.getKey();

 if (customKey){
    Serial.println(customKey);
    A[data_count]=customKey;
    data_count++;
  }
    if (data_count==password_length-1){
       
      if(!strcmp(A,B)){
         Serial.println("good");
        myservo.write(0);                  
 // delay(5000);
             
  
     clearData();}
else {
   // delay(1000);
myservo.write(90);       
    clearData();
}

}
}
void clearData(){
  while(data_count!=0){
    A[data_count--]=0;
    
  }
  return;
}
void m(){ int val=analogRead(A0);
  //Serial.println(val);
 //delay(400);
  

 if(val>900){
digitalWrite(mator,HIGH);

 } else if(val<400){
digitalWrite(mator,LOW);
 }}
