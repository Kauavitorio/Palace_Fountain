#include <SoftwareSerial.h>  
#include <Servo.h>

SoftwareSerial mySerial(10, 11); // RX, TX  
String command = ""; // Stores response of bluetooth device  
            // which simply allows \n between each  
            // response.  
long int data;
int LED = 7;
int LEDGREEN = 6;
int LEDRED = 5;
int speakerPin  = 4;
long int password1 = 92;
long int password2 = 79;
long int connectpass = 0;
char state = 0;
Servo myservo;
int pos = 0;
int playSong = 0;

//  Extern Functions
extern void putWater();
extern void song();
extern void beep();
extern void StartEnconder();
extern void StartEnconderSond();

   
void setup()   
{
  StartEnconderSond();
  StartEnconder(); 
  song();
  pinMode(LED, OUTPUT);
  pinMode(LEDGREEN, OUTPUT);
  pinMode(LEDRED, OUTPUT);
  pinMode(speakerPin , OUTPUT);

  //  Trun Off pins
  digitalWrite(LED, LOW);
  digitalWrite(LEDGREEN, LOW);
  digitalWrite(LEDRED, HIGH);

  //  Set Servo port and position
  myservo.attach(12);
  myservo.write(0);  

  
  // Open serial communications and wait for port to open:  
  Serial.begin(115200);  
  Serial.println("-------------");
  Serial.println("Welcome!\nSystem Booting, waiting for bluetooth connection!");  
  Serial.println("-------------");
  // SoftwareSerial "com port" data rate. JY-MCU v1.03 defaults to 9600.  
  mySerial.begin(9600);


}  
void loop()  
{
  
  while (mySerial.available() != 0){
  digitalWrite(LEDGREEN, LOW);
  digitalWrite(LEDRED, HIGH);
  }
  
  while (mySerial.available() == 0);
  digitalWrite(LEDGREEN, HIGH);
  digitalWrite(LEDRED, LOW);
  if(mySerial.available() > 0){
    data = mySerial.parseInt();
  }
  delay(200);
  if(data == password1){
  putWater();
  }
  
  if(data == password2){
  digitalWrite(LED, HIGH);
  Serial.println("LED ON "); 
  }
  if(data == 78){
  digitalWrite(LED, LOW); 
  Serial.println("LED OFF "); 
  }
  if(data == 00){
  digitalWrite(LED, LOW); 
  digitalWrite(LEDGREEN, LOW);
  digitalWrite(LEDRED, HIGH);
  Serial.println("Device has disconnected");
  data = mySerial.parseInt();
  }
  if(data == 01){
  beep(speakerPin, 1047, 100);
  delay(80);
  beep(speakerPin, 880, 100);
  delay(300);
  digitalWrite(LEDGREEN, HIGH);
  digitalWrite(LEDRED, LOW);
  Serial.println("Device has been connected");
  }


  //  Commands for config bluetooth
  //  Read device output if available.  
  /*if (mySerial.available()) 
  {  
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

  /*
  * AT
  * AT+NAME:****
  * AT+PSWD:""
  */
   
}// END loop()  