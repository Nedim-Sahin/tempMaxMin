#include<LiquidCrystal.h>
LiquidCrystal lcd(8,9,10,11,12,13);
const int buttonPin = 2;
const int buttonPinMaxMin = 3;
int buttonState = 0;
int buttonStateMaxMin = 0;
int buttonPushCounter = 0;   
int buttonPushCounterMaxMin = 0;   
int lastButtonState = 0;     
float tempMax = 0;
float tempMin = 50;



#define sensor A0
byte degree[8] =
{
0b00011,
0b00011,
0b00000,
0b00000,
0b00000,
0b00000,
0b00000,
0b00000
};

void setup()
{
pinMode(5, OUTPUT); 
pinMode(buttonPin, INPUT);
pinMode(buttonPinMaxMin, INPUT);
lcd.begin(16,2);
lcd.createChar(1, degree);
lcd.setCursor(0,0);
lcd.print(" Digital ");
lcd.setCursor(0,1);
lcd.print(" Thermometer ");
delay(2000);
lcd.clear();
Serial.begin(9600);
}

void loop()
{
buttonState = digitalRead(buttonPin);
float reading=analogRead(sensor);
float temperature=reading*(5.0/1023.0)*100;
delay(10); 

if(temperature > tempMax){
tempMax=temperature              //Calculated Maximum Temperature
}

if(temperature < tempMin){
tempMin=temperature              //Calculated Minimum Temperature
}

delay(10); 
int buttonPushCounter=counter();
int buttonPushCounterMaxMin=maxmin();


        if (buttonPushCounter == 1)
        {  
        lcd.clear();
        lcd.setCursor(2,0);
        lcd.print("Temperature in K");
        lcd.setCursor(4,1);
        lcd.print(temperature+273);
        lcd.write(1);
        lcd.print("K");  
        Serial.println("1.");
        Serial.print("number of button pushes: ");
        Serial.println(buttonPushCounter);
        delay(500);
        {if(temperature >= 30){
          digitalWrite(5, HIGH);  
           delay(1000); }
           else
           digitalWrite(5, LOW);  
           delay(1000); 
           }
            
          } 
          else if (  buttonPushCounter == 2){
            lcd.clear();
        lcd.setCursor(2,0);
        lcd.print("Temperature in C");
        lcd.setCursor(4,1);
        lcd.print(temperature);
        lcd.write(1);
        lcd.print("C");
        delay(500);
        Serial.println("2.");
        Serial.print("number of button pushes: ");
        Serial.println(buttonPushCounter);
         {if(temperature >= 30){
          digitalWrite(5, HIGH);  
           delay(1000); }
           else
           digitalWrite(5, LOW);  
           delay(1000); 
           }
            
          }
        
            else if (  buttonPushCounter == 3){
        lcd.clear();
        lcd.setCursor(2,0);
        lcd.print("Temperature in F");
        lcd.setCursor(4,1);
        lcd.print((temperature*9/5)+32);
        lcd.write(1);
        lcd.print("F");
        delay(500);
        Serial.println("3.");
        Serial.print("number of button pushes: ");
        Serial.println(buttonPushCounter);
        {if(temperature >= 30){
          digitalWrite(5, HIGH);  
           delay(1000); }
           else
           digitalWrite(5, LOW);  
           delay(1000); 
           }
            
          }
          else if (buttonPushCounter==4){
        lcd.clear();
        lcd.setCursor(2,0);
        lcd.print("Temperature in R");
        lcd.setCursor(4,1);
        lcd.print(((temperature*9/5)+32)+459.67);
        lcd.write(1);
        lcd.print("R");
        delay(500);
        Serial.println("Last Stamaen");
        Serial.print("number of button pushes: ");
        Serial.println(buttonPushCounter);
        {if(temperature >= 30){
          digitalWrite(5, HIGH);  
           delay(1000); }
           else
           digitalWrite(5, LOW);  
           delay(1000); 
           }
        
              }
              
        }

int counter(){
if (buttonState == HIGH) {
   
 
   buttonPushCounter++;
      
      Serial.println("on");
      Serial.print("number of button pushes: ");
      Serial.println(buttonPushCounter);
      }{
    if (buttonPushCounter == 5)
    {
    buttonPushCounter = 0;     
    }  }
      return buttonPushCounter;
      
}


int maxmin(){
if (buttonStateMaxMin == HIGH) {
   
 
   buttonPushCounterMaxMin++;
      
      Serial.println("maxmin");
      Serial.print("number of button pushes: ");
      Serial.println(buttonPushCounterMaxMin);
      }{
    if (buttonPushCounterMaxMin == 2)
    {
    buttonPushCounterMaxMin = 0;     
    }  }
      return buttonPushCounterMaxMin;
      
}
     

