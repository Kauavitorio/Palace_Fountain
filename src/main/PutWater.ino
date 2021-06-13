
#define NOTE_F5  698
#define NOTE_G5  784
#define NOTE_E5  659

void putWater();
void StartEnconder();

extern int pumpLED;
extern int speakerPin;
extern const int pump;



void StartEnconder(){
  pinMode(pumpLED, OUTPUT);
  pinMode(speakerPin , OUTPUT);
  pinMode(pump, OUTPUT);
  // Open serial communications and wait for port to open:  
  Serial.begin(115200);  
  // SoftwareSerial "com port" data rate. JY-MCU v1.03 defaults to 9600.  
  mySerial.begin(9600);
}


void putWater(){
  digitalWrite(pump, HIGH);
  digitalWrite(pumpLED, HIGH);
  delay(1000);
  digitalWrite(pump, LOW);
  digitalWrite(pumpLED, LOW);
  /*Serial.println("Puting Water "); 
  for (pos = 0; pos <= 390; pos += 1) { // goes from 0 degrees to 380 degrees
    // in steps of 1 degree
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(10);                       // waits 10ms for the servo to reach the position
  }
  for (pos = 390; pos >= 0; pos -= 1) { // goes from 390 degrees to 0 degrees
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(10);                       // waits 15ms for the servo to reach the position
  }
  delay(500);
  Serial.println("Puting Water End ");
  beep(speakerPin, NOTE_F5, 100);
  delay(100);
  beep(speakerPin, NOTE_G5, 100);
  delay(100);
  beep(speakerPin, NOTE_E5, 100);
  delay(500);*/
}
