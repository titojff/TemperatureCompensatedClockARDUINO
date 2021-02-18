#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,2,1,0,4,5,6,7,3,POSITIVE);  // Set the LCD I2C address


float tempF;
float tempC;
float PPM;

unsigned long T1=0;
unsigned long T2;
int S=05;
int M=20;
int H=22;
long uS=0;


void setup()
{
  
  
  
 
  lcd.begin(16,2);               // initialize the lcd 
//  lcd.home ();                   // go home
//  lcd.print(tempC);  
//  lcd.setCursor ( 0, 1 );        // go to the next line
//  lcd.print (PPM);      
}

void loop()
{

//  Serial.print(PPM);

T2=millis();
if (T2>(T1+1000)) {  //if 1 second passed
    
  S=S+1; 


if (S > 59)  
//basic clock algo minutes
//this runs every one minute to add to uS deviation of the previous minutes
{  
  S=0; M=M+1; 
  tempF = float(analogRead(A0)*0.49);//Fº
  tempC= (tempF-32)/1.8 ;  // ºC
  PPM = 0.29*tempC - 7.3; //ppm deviation in function og ºC
  uS=PPM*60+uS; // u seconds deviation in one minute
}

if (M > 59) {M=0; H=H+1; } //basic clock algo hours

if (H == 24) { H=0; }   //basic clock algo days

  

  lcd.home ();
  
  lcd.print (H);
  lcd.print ("-");
  lcd.print (M);
  lcd.print ("-");
  lcd.print (S);
  lcd.print ("   ");//to prevent ghost numbers 

  lcd.setCursor ( 0, 1 );
    
  lcd.print (uS);
  lcd.print ("        ");//to prevent ghost numbers 

  T1=T2;

}

}
