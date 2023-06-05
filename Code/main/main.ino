

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


  //Set motor speed
	
	// Turn off motors - Initial state
  digitalWrite(in1, LOW);
	digitalWrite(in2, LOW);
	digitalWrite(in3, LOW);
	digitalWrite(in4, LOW);


  
  Serial.begin(9600);
}

void loop() {
  if(analogRead(A1) < 500){
    digitalWrite(in1, HIGH);
  } else {
     digitalWrite(in1, LOW);
  }

  if(analogRead(A0) < 500){
    digitalWrite(in3, HIGH);
  } else {
    digitalWrite(in3, LOW);
  }

}

}

}