// IR Sensors
const int leftSensor = A0;
const int rightSensor = A1;

// Motor control pins (connected to L293D)
const int in1 = 8;
const int in2 = 9;
const int in3 = 10;
const int in4 = 11;

void setup() {
  pinMode(leftSensor, INPUT);
  pinMode(rightSensor, INPUT);

  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
}

void loop() {
  int left = digitalRead(leftSensor);
  int right = digitalRead(rightSensor);

  if (left == LOW && right == LOW) {
    moveForward();
  } else if (left == LOW && right == HIGH) {
    turnLeft();
  } else if (left == HIGH && right == LOW) {
    turnRight();
  } else {
    stopMotors();
  }
}

void moveForward() {
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}

void turnLeft() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}

void turnRight() {
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}

void stopMotors() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}
