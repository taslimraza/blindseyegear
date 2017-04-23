const int trigPin = 3;
const int echoPin = 4;
const int speaker = 7;

long duration;
int distance;

void setup() {
Serial.begin(9600); // Starts the serial communication
pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
pinMode(echoPin, INPUT); // Sets the echoPin as an Input
pinMode(speaker, OUTPUT); // Sets the speaker as an Output
}

void loop() {
// Clears the trigPin
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
// Reads the echoPin, returns the sound wave travel time in microseconds
duration = pulseIn(echoPin, HIGH);
// Calculating the distance
distance= duration*0.034/2;
// Prints the distance on the Serial Monitor
Serial.print("Distance: ");
Serial.println(distance);

if(distance < 200 && distance > 100) {
  tone(speaker, 1000);
  delay(200);
  noTone(speaker);
  delay(600);
}else if(distance < 100 && distance > 50){
  tone(speaker, 1000);
  delay(200);
  noTone(speaker);
  delay(300);;
}else if(distance < 50){
  tone(speaker, 1000);
  delay(200);
  noTone(speaker);
  delay(100);
}

}
