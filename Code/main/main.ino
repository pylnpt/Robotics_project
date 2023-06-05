

// Motor A connections
int enA = 9;
int in1 = 8;
int in2 = 7;
// Motor B connections
int enB = 3;
int in3 = 5;
int in4 = 4;
//Led A connections
int ledARed = 10;
int ledAGreen = 11;
int ledABlue = 12; 

int ledBRed = 2;
int ledBGreen = 6;
int ledBBlue = 13; 

bool driveR;
bool driveL;

void setup() {
	// Set all the motor control pins to outputs
	pinMode(enA, OUTPUT);
	pinMode(enB, OUTPUT);
	pinMode(in1, OUTPUT);
	pinMode(in2, OUTPUT);
	pinMode(in3, OUTPUT);
	pinMode(in4, OUTPUT);

	pinMode(A0, INPUT);
	pinMode(A1, INPUT);

  pinMode(ledARed, OUTPUT);
  pinMode(ledAGreen, OUTPUT);
  pinMode(ledABlue, OUTPUT);

  pinMode(ledBRed, OUTPUT);
  pinMode(ledBGreen, OUTPUT);
  pinMode(ledBBlue, OUTPUT);

  driveR = false;
  driveL = false;

  //Set motor speed
  analogWrite(enA, 80);
	analogWrite(enB, 80);
	
	// Turn off motors - Initial state
  digitalWrite(in1, LOW);
	digitalWrite(in2, LOW);
	digitalWrite(in3, LOW);
	digitalWrite(in4, LOW);

  setALOW();
  setBLOW();

  delay(5000);
  
  Serial.begin(9600);
}

void loop() {
  if(analogRead(A1) < 500){
    digitalWrite(in1, HIGH);
    driveL = true;
  } else {
     digitalWrite(in1, LOW);
     driveL = false;
  }

  if(analogRead(A0) < 500){
    digitalWrite(in3, HIGH);
    driveR = true;
  } else {
    digitalWrite(in3, LOW);
    driveR = false;
  }

  if(driveL == true && driveR == true){
    setALOW();
    setBLOW();
  } else if (driveL == true && driveR == false){
    setARed();
    setBLOW();
  } else if (driveL == false && driveR == true){
    setBRed();
    setALOW();
  } else if (driveL == false && driveR == false ){
    setABlue();
    setBBlue();
  }
}

void setALOW(){
  digitalWrite(ledABlue, LOW);
  digitalWrite(ledAGreen, LOW);
  digitalWrite(ledARed, LOW);
}
void setARed(){
  digitalWrite(ledABlue, LOW);
  digitalWrite(ledAGreen, LOW);
  digitalWrite(ledARed, HIGH);
}
void setABlue(){
  digitalWrite(ledAGreen, LOW);
  digitalWrite(ledARed, LOW);
  digitalWrite(ledABlue, HIGH);
}

void setBLOW(){
  digitalWrite(ledBBlue, LOW);
  digitalWrite(ledBGreen, LOW);
  digitalWrite(ledBRed, LOW);
}
void setBRed(){
  digitalWrite(ledBBlue, LOW);
  digitalWrite(ledBGreen, LOW);
  digitalWrite(ledBRed, HIGH);
}
void setBBlue(){
  digitalWrite(ledBGreen, LOW);
  digitalWrite(ledBRed, LOW);
  digitalWrite(ledBBlue, HIGH);
}