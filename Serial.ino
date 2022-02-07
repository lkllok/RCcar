int motorA1 = 6;
int motorA2 = 11;
int motorB1 = 3;
int motorB2 = 5;

String Speed;
char  LorR;
int  i, s;

byte DataToRead[6];

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  pinMode(motorA1, OUTPUT);
  pinMode(motorA2, OUTPUT);
  pinMode(motorB1, OUTPUT);
  pinMode(motorB2, OUTPUT);
  analogWrite(motorA2, 0);
  analogWrite(motorB2, 0);
  analogWrite(motorA1, 0);
  analogWrite(motorB1, 0);
}

void loop() {
  DataToRead[5] = '\n';
  Serial.readBytesUntil(char(13), DataToRead, 5);
  
/* For Debugging, send string to RPi */
  for (i = 0; i < 6; i++) {
    Serial.write(DataToRead[i]);
    if (DataToRead[i] == '\n') break;
  }
/* End of Debugging */

  LorR = DataToRead[0];
  Speed = "";
  for (i = 1; (DataToRead[i] != '\n') && (i < 6); i++) {
    Speed += DataToRead[i];
  }
  s = Speed.toInt();
  if (LorR == 'L') {
    analogWrite(motorB1, s * 190);
  }
  else if (LorR == 'R') {
    analogWrite(motorA1, s * 190); 
  }
  delay(2000); 
}
