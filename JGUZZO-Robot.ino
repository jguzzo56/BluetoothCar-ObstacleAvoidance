//Joseph Guzzo
//ECE314L-02
//Final Project- Obstacle Avoidance Car

int E1 = 5;     
int E2 = 6;     
int M1 = 4;    
int M2 = 7;
int trigPin = 3;
int echoPin = 2;
long duration;
long distance;

void setup(void) {
  pinMode(E1, OUTPUT);
  pinMode(E2, OUTPUT);
  pinMode(M1, OUTPUT);
  pinMode(M2, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(115200);  
  delay(15000);      
}

void stop() { 
  digitalWrite(E1, LOW);
  digitalWrite(E2, LOW);
}

void forward(int a, int b) {         
  analogWrite (E1, a);     
  digitalWrite(M1, HIGH);
  analogWrite (E2, b);
  digitalWrite(M2, HIGH);
}

void backward(int a, int b) {        
  analogWrite (E1, a);
  digitalWrite(M1, LOW);
  analogWrite (E2, b);
  digitalWrite(M2, LOW);
}

void turn(int a, int b) {
  analogWrite (E1, a);
  digitalWrite(M1, LOW);
  analogWrite (E2, b);
  digitalWrite(M2, HIGH);
}

void loop() {
  forward(255, 255);
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = duration * .034 / 2;

  if (distance < 15) {
    stop();
    delay(5);
    turn(255, 255);
    delay(1500);
    stop();
    delay(10);
    forward(255, 255);
  }
   
}
