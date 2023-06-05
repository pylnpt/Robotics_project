

// Motor A connections
int enA = 9;
int in1 = 8;
int in2 = 7;
// Motor B connections
int enB = 3;
int in3 = 5;
int in4 = 4;

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