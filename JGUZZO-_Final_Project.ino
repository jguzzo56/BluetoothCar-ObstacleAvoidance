//Joseph Guzzo
//ECE314L-02
//Final Project-RC Bluetooth Car

int E1 = 5;     
int E2 = 6;     
int M1 = 4;    
int M2 = 7;
int velocity = 255;

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

void left(int a, int b) {
  analogWrite (E1, a);
  digitalWrite(M1, LOW);
  analogWrite (E2, b);
  digitalWrite(M2, HIGH);
}

void right(int a, int b) {
  analogWrite (E1, a);
  digitalWrite(M1, HIGH);
  analogWrite (E2, b);
  digitalWrite(M2, LOW);
}

void setup(void) {
  pinMode(E1, OUTPUT);
  pinMode(E2, OUTPUT);
  pinMode(M1, OUTPUT);
  pinMode(M2, OUTPUT);
  Serial.begin(115200);      
}

void loop(void) {
  if (Serial.available()) {
    char data = Serial.read();
      switch(data) {
        case 'A': //forward
          forward(velocity, velocity);  
          Serial.println("Move Forward");
          break;
        case 'C': //backward
          Serial.println("Move Backward");
          backward(velocity, velocity);  
          break;
        case 'D': //left
          Serial.println("Turn Left");
          left(velocity, velocity);
          break;
        case 'B': //right
          Serial.println("Turn Right");
          right(velocity, velocity);
          break;
        case 'F': //stop
          Serial.println("Stop");
          stop();
          break;
        case 'e': //speed up
          Serial.println("Speed up");
          Serial.println(velocity);
          velocity = velocity + 10;
          if (velocity > 255) {
            velocity = 255;
          }
          break;
        case 'g': //slow down
          Serial.println("Speed down");
          Serial.println(velocity);
          velocity = velocity - 10;
          if (velocity < 0) {
            velocity = 0;
          }
          break;
      }
  }
}
