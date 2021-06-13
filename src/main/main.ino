#include <SoftwareSerial.h>  
   
   
SoftwareSerial mySerial(10, 11); // RX, TX  
String command = ""; // Stores response of bluetooth device  
            // which simply allows \n between each  
            // response.   
long int data;
const int LEDSystemOn = 9; 
const int LEDSystemOff = 8;
const int LEDPUMP = A0;
const int LEDNIVEL = A1;
int speakerPin  = 12;
const int pump = 7;
int pumpLED = 6;
const int nivel = 5; //mido el nivel de agua a la DI9

//  Extern Functions
extern void putWater();
extern void song();
extern void beep();
extern void StartEnconder();
extern void StartEnconderSond();
   
void setup()   
{  
  pinMode(LEDSystemOn, OUTPUT);
  pinMode(LEDSystemOff, OUTPUT);
  pinMode(speakerPin , OUTPUT);
  pinMode(LEDPUMP , OUTPUT);
  pinMode(LEDNIVEL , OUTPUT);
  pinMode(nivel, INPUT);
  StartEnconder();
  song();
  
  // Open serial communications and wait for port to open:  
  Serial.begin(115200);  
  Serial.println("\n-------------");
  Serial.println("Welcome!\nSystem Booting, waiting for bluetooth connection!");  
  Serial.println("-------------\n"); 
  // SoftwareSerial "com port" data rate. JY-MCU v1.03 defaults to 9600.  
  mySerial.begin(9600);  
  
  //  Trun ON/Off base pins
  digitalWrite(LEDSystemOn, HIGH);
  digitalWrite(LEDSystemOff, HIGH);
  digitalWrite(LEDNIVEL, HIGH);
  digitalWrite(LEDPUMP, HIGH);
  delay(600);
  digitalWrite(LEDSystemOn, LOW);
  digitalWrite(LEDSystemOff, HIGH);
  digitalWrite(LEDNIVEL, LOW);
  digitalWrite(LEDPUMP, LOW);
}  
   
void loop()  
{ 
  /*int SensorNivel = digitalRead(nivel); //leemos lo que marca el niv
  if (SensorNivel==1) 
  {
   Serial.println("Nivel de agua correcto, se puede regar");
   digitalWrite(LEDSystemOn, HIGH);
   delay(1000);
   digitalWrite(LEDSystemOn, LOW);
   delay(500);
   }
    if (SensorNivel==0)
  { Serial.println(" Nivel bajo de Agua. Rellenar el tanque"); 
   digitalWrite(LEDSystemOff, HIGH);
   digitalWrite(LEDSystemOn, HIGH);
   delay(1000);
   digitalWrite(LEDSystemOff, LOW);
   digitalWrite(LEDSystemOn, LOW);
   delay(500);
  }*/
  
  if (mySerial.available()) 
  {  
    digitalWrite(LEDSystemOn, HIGH);
    digitalWrite(LEDSystemOff, LOW);
     while(mySerial.available()) 
     { // While there is more to be read, keep reading.  
        if(mySerial.available() > 0){
            data = mySerial.parseInt();
            Serial.println(data);
            switch(data)
            {
              case 0:
                digitalWrite(LEDSystemOn, LOW);
                digitalWrite(LEDSystemOff, HIGH);
                Serial.println("Device has disconnected");
            break;
            case 1:
                  beep(speakerPin, 1047, 100);
                  delay(80);
                  beep(speakerPin, 880, 100);
                  delay(300);
                  Serial.println("\nDevice has been connected");
            break;
            }
        }
     } 
  } 
 /* 
  *  // Read device output if available.  
  if (mySerial.available()) 
  {  
    digitalWrite(LEDSystemOn, HIGH);
    digitalWrite(LEDSystemOff, LOW);
     while(mySerial.available()) 
     { // While there is more to be read, keep reading.  
       command += (char)mySerial.read();  
     }  
   Serial.println(command);  
   command = ""; // No repeats  
  }  
  
  // Read user input if available.  
  if (Serial.available())
  {  
    delay(10); // The DELAY!  
    mySerial.write(Serial.read());  
  }  */
   
}// END loop()  
