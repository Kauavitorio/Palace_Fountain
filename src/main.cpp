#include <SoftwareSerial.h>  
#include <avr/wdt.h>
#include <Servo.h>

#define NOTE_B0  31
#define NOTE_C1  33
#define NOTE_CS1 35
#define NOTE_D1  37
#define NOTE_DS1 39
#define NOTE_E1  41
#define NOTE_F1  44
#define NOTE_FS1 46
#define NOTE_G1  49
#define NOTE_GS1 52
#define NOTE_A1  55
#define NOTE_AS1 58
#define NOTE_B1  62
#define NOTE_C2  65
#define NOTE_CS2 69
#define NOTE_D2  73
#define NOTE_DS2 78
#define NOTE_E2  82
#define NOTE_F2  87
#define NOTE_FS2 93
#define NOTE_G2  98
#define NOTE_GS2 104
#define NOTE_A2  110
#define NOTE_AS2 117
#define NOTE_B2  123
#define NOTE_C3  131
#define NOTE_CS3 139
#define NOTE_D3  147
#define NOTE_DS3 156
#define NOTE_E3  165
#define NOTE_F3  175
#define NOTE_FS3 185
#define NOTE_G3  196
#define NOTE_GS3 208
#define NOTE_A3  220
#define NOTE_AS3 233
#define NOTE_B3  247
#define NOTE_C4  262
#define NOTE_CS4 277
#define NOTE_D4  294
#define NOTE_DS4 311
#define NOTE_E4  330
#define NOTE_F4  349
#define NOTE_FS4 370
#define NOTE_G4  392
#define NOTE_GS4 415
#define NOTE_A4  440
#define NOTE_AS4 466
#define NOTE_B4  494
#define NOTE_C5  523
#define NOTE_CS5 554
#define NOTE_D5  587
#define NOTE_DS5 622
#define NOTE_E5  659
#define NOTE_F5  698
#define NOTE_FS5 740
#define NOTE_G5  784
#define NOTE_GS5 831
#define NOTE_A5  880
#define NOTE_AS5 932
#define NOTE_B5  988
#define NOTE_C6  1047
#define NOTE_CS6 1109
#define NOTE_D6  1175
#define NOTE_DS6 1245
#define NOTE_E6  1319
#define NOTE_F6  1397
#define NOTE_FS6 1480
#define NOTE_G6  1568
#define NOTE_GS6 1661
#define NOTE_A6  1760
#define NOTE_AS6 1865
#define NOTE_B6  1976
#define NOTE_C7  2093
#define NOTE_CS7 2217
#define NOTE_D7  2349
#define NOTE_DS7 2489
#define NOTE_E7  2637
#define NOTE_F7  2794
#define NOTE_FS7 2960
#define NOTE_G7  3136
#define NOTE_GS7 3322
#define NOTE_A7  3520
#define NOTE_AS7 3729
#define NOTE_B7  3951
#define NOTE_C8  4186
#define NOTE_CS8 4435
#define NOTE_D8  4699
#define NOTE_DS8 4978


   
SoftwareSerial mySerial(10, 11); // RX, TX  
String command = ""; // Stores response of bluetooth device  
            // which simply allows \n between each  
            // response.  
long int data;
int LED = 7;
int LEDGREEN = 6;
int LEDRED = 5;
int ledPin = 13; //For visual as well
int speakerPin  = 4;
long int password1 = 92;
long int password2 = 79;
long int connectpass = 0;
char state = 0;
Servo myservo;
int pos = 0;

   
void setup()   
{
  wdt_disable();
  pinMode(ledPin, OUTPUT); // Setting both pins to outputs
  pinMode(LED, OUTPUT);
  pinMode(LEDGREEN, OUTPUT);
  pinMode(LEDRED, OUTPUT);
  pinMode(speakerPin , OUTPUT);
  digitalWrite(LED, LOW);
  digitalWrite(LEDGREEN, LOW);
  digitalWrite(LEDRED, HIGH);
  myservo.attach(12);
  myservo.write(0);  
  song();
  
  // Open serial communications and wait for port to open:  
  Serial.begin(115200);  
  Serial.println("Bem Vindo!");  
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
  Serial.println("LED OFF "); 

  }
  if(data == 00){
  digitalWrite(LED, LOW); 
  Serial.println("LED OFF "); 
  digitalWrite(LEDGREEN, LOW);
  digitalWrite(LEDRED, HIGH);
  //wdt_enable(WDTO_1S);
  //wdt_reset();
  }
  if(data == 01){
    
  digitalWrite(LEDGREEN, HIGH);
  digitalWrite(LEDRED, LOW);
  delay(200);
  digitalWrite(LEDGREEN, LOW);
  digitalWrite(LEDRED, HIGH);
  delay(200);
  digitalWrite(LEDGREEN, HIGH);
  digitalWrite(LEDRED, LOW);
  beep(speakerPin, NOTE_C6, 100);
  delay(80);
  beep(speakerPin, NOTE_A5, 100);
  delay(300);
  }



  
  // Read device output if available.  
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
   
}// END loop()  

void putWater(){
  digitalWrite(LED, HIGH);
  Serial.println("Puting Water ");
  myservo.write(380);              // tell servo to go to position in variable 'pos'
  delay(2000);
      
  myservo.write(0);              // tell servo to go to position in variable 'pos'
  delay(90);
  digitalWrite(LED, LOW);
  delay(305);
  digitalWrite(LED, HIGH);
  delay(305);
  digitalWrite(LED, LOW);
  delay(100);
  Serial.println("Puting Water End ");
  beep(speakerPin, NOTE_F5, 100);
  delay(100);
  beep(speakerPin, NOTE_G5, 100);
  delay(100);
  beep(speakerPin, NOTE_E5, 100);
  delay(500);
}

void beep (unsigned char speakerPin, int frequencyInHertz, long timeInMilliseconds)  //code for working out the rate at which each note plays and the frequency.
{
  digitalWrite(ledPin, HIGH);
  int x;     
  long delayAmount = (long)(1000000/frequencyInHertz);
  long loopTime = (long)((timeInMilliseconds*1000)/(delayAmount*2));
  for (x=0;x<loopTime;x++)   
  {   
    digitalWrite(speakerPin,HIGH);
    delayMicroseconds(delayAmount);
    digitalWrite(speakerPin,LOW);
    delayMicroseconds(delayAmount);
  }   
  digitalWrite(ledPin, LOW);
  delay(20);
}    


void song()  //here is where all the notes for the song are played.
{       
  beep(speakerPin, NOTE_D5, 100);  //   beep( -PIN OF SPEAKER-, -THE NOTE WANTING TO BE PLAYED-, -DURATION OF THE NOTE IN MILISECONDS- )
  delay(80);
  beep(speakerPin, NOTE_F5, 100);
  delay(80);
  beep(speakerPin, NOTE_D6, 200);
  delay(250);
 
  beep(speakerPin, NOTE_D5, 100);
  delay(80);
  beep(speakerPin, NOTE_F5, 100);
  delay(80);
  beep(speakerPin, NOTE_D6, 200);
  delay(250);
 
  beep(speakerPin, NOTE_E6, 200);
  delay(200);
  beep(speakerPin, NOTE_F6, 100);
  delay(100);
  beep(speakerPin, NOTE_E6, 100);
  delay(80);
  beep(speakerPin, NOTE_F6, 100);
  delay(80);
  beep(speakerPin, NOTE_E6, 100);
  delay(80);
  beep(speakerPin, NOTE_C6, 100);
  delay(80);
  beep(speakerPin, NOTE_A5, 100);
  delay(300);
 
  beep(speakerPin, NOTE_A5, 200);
  delay(100);
  beep(speakerPin, NOTE_D5, 200);
  delay(100);
  beep(speakerPin, NOTE_F5, 100);
  delay(100);
  beep(speakerPin, NOTE_G5, 100);
  delay(100);
  beep(speakerPin, NOTE_A5, 100);
  delay(500);
 
  beep(speakerPin, NOTE_A5, 200);
  delay(100);
  beep(speakerPin, NOTE_D5, 200);
  delay(100);
  beep(speakerPin, NOTE_F5, 100);
  delay(100);
  beep(speakerPin, NOTE_G5, 100);
  delay(100);
  beep(speakerPin, NOTE_E5, 100);
  digitalWrite(ledPin, HIGH);
}