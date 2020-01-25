#include <SoftwareSerial.h>
SoftwareSerial mySerial(9, 10);
const int buzzerPin1 = 12;
const int flamePin1 = 11;
int Flame1 = HIGH;
int redled1 = 5;
int greenled1 = 6;



void setup() 
{
  pinMode(buzzerPin1, OUTPUT);
  pinMode(redled1, OUTPUT);
  pinMode(greenled1, OUTPUT);
  pinMode(flamePin1, INPUT);
  mySerial.begin(9600);   
  Serial.begin(9600);    
  delay(100);
}

void loop() 
{
  Flame1 = digitalRead(flamePin1);
  if (Flame1== LOW)
  {
    
      Serial.println("ATD*****MOB*****;"); // ATDxxxxxxxxxx; semicolon should be at the last ;AT command that follows UART protocol;
    digitalWrite(buzzerPin1, HIGH);
    digitalWrite(redled1, HIGH);
    digitalWrite(greenled1, LOW);
       mySerial.println("AT+CMGF=1");    //Sets the GSM Module in Text Mode
     delay(1000);  // Delay of 1 second
     mySerial.println("AT+CMGS=\"+91*****MOB*****\"\r"); // Replace * with mobile number
     mySerial.println("FIRE IN THE HOUSE");// The SMS text you want to send
     mySerial.println((char)26);// ASCII code of CTRL+Z for saying the end of sms to  the module 
     //delay(100);
     
    
  }
  else
  {

    digitalWrite(buzzerPin1, LOW);
    digitalWrite(greenled1, HIGH);
    digitalWrite(redled1, LOW);
  }
}
