  
#define NOTE_F5  698
#define NOTE_G5  784
#define NOTE_E5  659

void putWater();
void StartEnconder();

extern int LED;
extern Servo myservo;
extern int speakerPin;



void StartEnconder(){
  pinMode(LED, OUTPUT);
  pinMode(speakerPin , OUTPUT);
  myservo.attach(12);
  myservo.write(0);  
  // Open serial communications and wait for port to open:  
  Serial.begin(115200);  
  Serial.println("Bem Vindo!");  
  // SoftwareSerial "com port" data rate. JY-MCU v1.03 defaults to 9600.  
  mySerial.begin(9600);
}

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