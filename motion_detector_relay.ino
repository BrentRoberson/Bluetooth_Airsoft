int relay= 12;
int motionDetector= 4;
int received = 0;
int PIR= 0;
int state= LOW;
int lastReceived=3;
void setup() {
  // put your setup code here, to run once:
pinMode(relay,OUTPUT);
pinMode(motionDetector,INPUT);
pinMode(5,OUTPUT);
pinMode(6,OUTPUT);
pinMode(3,OUTPUT);
pinMode(10,OUTPUT);
pinMode(13,OUTPUT);

Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(5,HIGH);
  digitalWrite(6,HIGH);
  digitalWrite(3,LOW);
  digitalWrite(10,LOW);
  digitalWrite(13,LOW);
while (Serial.available()>0)
  {
    received= Serial.read();
  }
  delay(5);
 if (received == '1')
{    
    digitalWrite(12,HIGH);
   
}
   if (received == '2')
   {
      PIR= digitalRead(motionDetector);
        if( PIR==HIGH)
        {
          Serial.write("d");
           digitalWrite(relay, HIGH);   // turn LED ON
          delay(300);                // delay 100 milliseconds
          digitalWrite(relay,LOW);
          delay(500);
          if (state == LOW) {
            Serial.println("Kill it!");
            state = HIGH;       // update variable state to HIGH
          }
        }
        else {
            digitalWrite(relay, LOW); // turn LED OFF
            delay(200);             // delay 200 milliseconds
           
            if (state == HIGH){
              Serial.println("It is done!");
              state = LOW;       // update variable state to LOW
                }
                   }
   }
    if (received == '3')
      {
        digitalWrite(relay,HIGH);
      }
       

      if (received == '4')
      {
        digitalWrite(relay,LOW);
      }
       
           
  }
