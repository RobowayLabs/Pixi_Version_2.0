//stepper motor

#define dirPin2 4
#define stepPin2 5
#define dirPin 2
#define stepPin 3
#define stepsPerRevolution 420

//motor1, motor3 and motor5
int RPWM_1 = 7;
int LPWM_1 = 6;

//motor2, motor4 and motor 6
int RPWM_2 = 8;
int LPWM_2 = 9;


int speed1 = 100;
int speed2 = 100;

;



void setup() {
  //define pinmode

  //for Stepper Motor

  pinMode(stepPin, OUTPUT);
  pinMode(dirPin, OUTPUT);
  pinMode(stepPin2, OUTPUT);
  pinMode(dirPin2, OUTPUT);
  
  //motor1, motor3 and motor5
  pinMode(RPWM_1 , OUTPUT);
  pinMode(LPWM_1, OUTPUT);

  //motor2, motor4 and motor6
  pinMode(RPWM_2 , OUTPUT);
  pinMode(LPWM_2, OUTPUT);
  Serial.begin(9600);
}

void loop(){
  if (Serial.available()>0) {
  char state = Serial.read();

  if (state == 'w') {
    forward();
  }
  else if (state == 'x') {
   reset();
  }
  else if (state == 's') {
   backward();
  }
  else if (state == 'a') {
   right();
  }
  else if (state == 'd') {
   left();
  }
  else if(state == '1') {
    kadhUp();
  }

  else if(state == '2') {
    kadhDown();
  }

  else if(state == '3') {
    elobowUp();
  }

  else if(state == '2') {
    elbowDown();
  }
  
 }
  
}
  


void forward() {
  analogWrite(RPWM_1, speed1);
  analogWrite(RPWM_2, speed1);
  analogWrite(LPWM_1, LOW);
  analogWrite(LPWM_2, LOW);
}

void backward() {
  analogWrite(LPWM_1, speed1);
  analogWrite(LPWM_2, speed1);
  analogWrite(RPWM_1, LOW);
  analogWrite(RPWM_2, LOW);
}


void right() {
  analogWrite(RPWM_1, speed2);
  analogWrite(LPWM_2, speed2);
  analogWrite(RPWM_2, LOW);
  analogWrite(LPWM_1, LOW);
  
}

void left() {
  
  analogWrite(RPWM_2, speed2);
  analogWrite(LPWM_1, speed2);
  analogWrite(RPWM_1, LOW);
  analogWrite(LPWM_2, LOW);
}

void reset() {
  analogWrite(RPWM_1, LOW);
  analogWrite(LPWM_2, LOW);
  analogWrite(RPWM_2, LOW);
  analogWrite(LPWM_1, LOW);
  
}

void kadhUp() {
  digitalWrite(dirPin, HIGH);
  for (int i = 0; i < 5 * stepsPerRevolution; i++) {
    // These four lines result in 1 step:
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(1500);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(1500);
  }

  delay(1000);
  
}


void kadhDown() {

  digitalWrite(dirPin, LOW);
  for (int i = 0; i < 5 * stepsPerRevolution; i++) {
    // These four lines result in 1 step:
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(1500);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(1500);
  }

  delay(1000);
}

void elobowUp() {

  digitalWrite(dirPin2, HIGH);
  for (int i = 0; i < 5 * stepsPerRevolution; i++) {
    // These four lines result in 1 step:
    digitalWrite(stepPin2, HIGH);
    delayMicroseconds(1500);
    digitalWrite(stepPin2, LOW);
    delayMicroseconds(1500);
  }

  delay(1000);
  
}

void elbowDown() {

  digitalWrite(dirPin2, LOW);
  for (int i = 0; i < 5 * stepsPerRevolution; i++) {
    // These four lines result in 1 step:
    digitalWrite(stepPin2, HIGH);
    delayMicroseconds(1500);
    digitalWrite(stepPin2, LOW);
    delayMicroseconds(1500);
  }

  delay(1000);
  
}
