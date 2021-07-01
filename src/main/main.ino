#include <SoftwareSerial.h>  
   
SoftwareSerial mySerial(10, 11); // RX, TX  
String command = ""; // Stores response of bluetooth device  
            // which simply allows \n between each  
            // response.   
long int data;
const int LEDSystemOn = 9; 
int speakerPin  = 12;
const int pump = 8;
const int nivel = 7; // water sensor

//  Extern Functions
extern void putWater();
extern void CancelWater();
extern void song();
extern void beep();
extern void StartEnconder();
extern void StartEnconderSond();
extern void StartEnconderDisplay();
extern void DisplayStatus();
extern void testPump();
   
void setup()   
{  
  pinMode(LEDSystemOn, OUTPUT);
  pinMode(speakerPin , OUTPUT);
  pinMode(pump , OUTPUT);
  pinMode(nivel, INPUT);
  StartEnconder();
  StartEnconderDisplay();
  song();
  
  // Open serial communications and wait for port to open:  
  Serial.begin(115200);  
  Serial.println("\n-------------");
  Serial.println("Welcome!\nSystem Booting, waiting for bluetooth connection!");  
  Serial.println("-------------\n"); 
  // SoftwareSerial "com port" data rate. JY-MCU v1.03 defaults to 9600.  
  mySerial.begin(9600);  
  
  DisplayStatus(0);
}  
   
void loop()  
{ 
  if (mySerial.available()) 
  {  
    digitalWrite(LEDSystemOn, HIGH);
     while(mySerial.available()) 
     { // While there is more to be read, keep reading.  
        if(mySerial.available() > 0){
            data = mySerial.parseInt();
            Serial.print("Request: ");
            Serial.println(data);
            switch(data)
            {
              case 0:
                digitalWrite(LEDSystemOn, LOW);  
                DisplayStatus(0);
                Serial.println("Device has disconnected");
            break;
            case 1:
                  beep(speakerPin, 1047, 100);
                  delay(80);
                  beep(speakerPin, 880, 100); 
                  delay(300);
                  digitalWrite(LEDSystemOn, HIGH);
                  DisplayStatus(1);
                  Serial.println("Device has been connected");
            break;
            case 10:
                  Serial.println("Put Water");
                  if (digitalRead(nivel) == 0){
                      putWater();
                  }else{
                    beep(speakerPin, 1047, 100);
                    delay(80);
                    beep(speakerPin, 880, 100); 
                    delay(80);
                    beep(speakerPin, 1047, 100);
                  }
            break;
            case 12:
                  CancelWater();
                  Serial.println("\nCancel Water");
            break;
            case 158:
                  testPump();
                  Serial.println("\nCancel Water");
            break;
            }
        }
     } 
  }

  //  Code to configure 
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
