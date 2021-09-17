 /*-------definning Inputs------*/
int LS = D1;     // left sensor
int RS  = D2;      // right sensor

/*-------definning Outputs------*/
int LM1 = D3;      // left motor
int LM2 =  D4;       // left motor
int RM1 =  D5;       // right motor
int RM2 =  D6;       // right motor

/*-------PWM ควบคุมความเร็วมอเตอร์-----*/
int PWM1 = D7;    // PWM left motor
int PWM2 = D8;    // PWM right motor
int SPEED = 125;  // Speed PWM สามารถปรับความเร็วได้ถึง 255


int LS_show = 0;
int RS_show = 0;

void setup()
{
  pinMode(LS, INPUT);
  pinMode(RS, INPUT);
  pinMode(LM1, OUTPUT);
  pinMode(LM2, OUTPUT);
  pinMode(RM1, OUTPUT);
  pinMode(RM2, OUTPUT);
  pinMode(PWM1, OUTPUT);
  pinMode(PWM2, OUTPUT);
  Serial.begin(9600);

}
void loop()
{
  LS_show = digitalRead(LS);
  RS_show = digitalRead(RS);
  Serial.print("ซ้าย = "); 
  Serial.print(LS_show); 
  Serial.print("   ขวา = ");
  Serial.println(RS_show);

  if (!(digitalRead(LS)) && !(digitalRead(RS)))    // Move Forward
  {
    analogWrite(PWM1, SPEED);
    digitalWrite(LM1, HIGH);
    digitalWrite(LM2, LOW);
    analogWrite(PWM2, SPEED);
    digitalWrite(RM1, HIGH);
    digitalWrite(RM2, LOW);
  }


  if (!(digitalRead(LS)) && digitalRead(RS))    // Turn right
  {
    digitalWrite(LM1, HIGH);
    digitalWrite(LM2, LOW);
    analogWrite(PWM2, SPEED);
    digitalWrite(RM1, LOW);
    digitalWrite(RM2, LOW);
  }

  if (digitalRead(LS) && !(digitalRead(RS)))    // turn left
  {
    analogWrite(PWM1, SPEED);
    digitalWrite(LM1, LOW);
    digitalWrite(LM2, LOW);
    digitalWrite(RM1, HIGH);
    digitalWrite(RM2, LOW);
  }

 if (digitalRead(LS) && digitalRead(RS))    // stop
  {
    digitalWrite(LM1, LOW);
    digitalWrite(LM2, LOW);
    digitalWrite(RM1, LOW);
    digitalWrite(RM2, LOW);
  }

}
