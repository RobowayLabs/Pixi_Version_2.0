// Define stepper motor connections and steps per revolution:
#define dirPin2 4
#define stepPin2 5
#define dirPin 2
#define stepPin 3





#define stepsPerRevolution 420

void setup() {
  // Declare pins as output:
  pinMode(stepPin, OUTPUT);
  pinMode(dirPin, OUTPUT);
  pinMode(stepPin2, OUTPUT);
  pinMode(dirPin2, OUTPUT);
  Serial.begin(9600);
}

void loop() {

 

  // Set the spinning direction clockwise:
  digitalWrite(dirPin, HIGH);

  if(Serial.available()>0) {
    char state = Serial.read();

    if (state=='a') {
      // Spin the stepper motor 5 revolutions fast:
  for (int i = 0; i < 5 * stepsPerRevolution; i++) {
    // These four lines result in 1 step:
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(1500);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(1500);
  }

  delay(1000);
    }

    else if(state == 's') {

      digitalWrite(dirPin, LOW);

  // Spin the stepper motor 5 revolutions fast:
  for (int i = 0; i < 5 * stepsPerRevolution; i++) {
    // These four lines result in 1 step:
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(5000);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(5000);
  }

  delay(1000);
      
    }


      else if(state == 'x') {

      digitalWrite(dirPin2, LOW);

  // Spin the stepper motor 5 revolutions fast:
  for (int i = 0; i < 5 * stepsPerRevolution; i++) {
    // These four lines result in 1 step:
    digitalWrite(stepPin2, HIGH);
    delayMicroseconds(1500);
    digitalWrite(stepPin2, LOW);
    delayMicroseconds(1500);
  }

  delay(1000);
      
    }

      else if(state == 'y') {

      digitalWrite(dirPin2, HIGH);

  // Spin the stepper motor 5 revolutions fast:
  for (int i = 0; i < 5 * stepsPerRevolution; i++) {
    // These four lines result in 1 step:
    digitalWrite(stepPin2, HIGH);
    delayMicroseconds(1500);
    digitalWrite(stepPin2, LOW);
    delayMicroseconds(1500);
  }

  delay(1000);
      
    }
  }


  
  

  

  // Set the spinning direction counterclockwise:
  
}
