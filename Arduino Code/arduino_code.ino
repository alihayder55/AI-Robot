#include <Servo.h>
#include <NewPing.h>

#define SERVO_PIN 10
#define ULTRASONIC_SENSOR_TRIG 11
#define ULTRASONIC_SENSOR_ECHO 12
#define MAX_REGULAR_MOTOR_SPEED 75
#define MAX_MOTOR_ADJUST_SPEED 150
#define DISTANCE_TO_CHECK 15
#define m1a 2                  
#define m1b 3                  //left motor 2nd pin
#define m2a 4                  
#define m2b 5 
#define m3a 6                  
#define m3b 7 
#define m4a 8                  
#define m4b 9 

NewPing mySensor(ULTRASONIC_SENSOR_TRIG, ULTRASONIC_SENSOR_ECHO, 400);
Servo myServo;
void setup()
{
  // put your setup code here, to run once:
  pinMode(m1a, OUTPUT);     
  pinMode(m1b, OUTPUT);     
  pinMode(m2a, OUTPUT);     
  pinMode(m2b, OUTPUT);     
  pinMode(m3a, OUTPUT);     
  pinMode(m3b, OUTPUT);     
  pinMode(m4a, OUTPUT);     
  pinMode(m4b, OUTPUT); 
  Serial.begin(9600);
  myServo.attach(SERVO_PIN);
  myServo.write(90);
digitalWrite(m1a, LOW);
    digitalWrite(m1b, LOW);
    digitalWrite(m2a, LOW);
    digitalWrite(m2b, LOW);
    digitalWrite(m3a, LOW);
    digitalWrite(m3b, LOW);
    digitalWrite(m4a, LOW);
    digitalWrite(m4b, LOW);
    delay(3000); }

void loop()
{

  int distance = mySensor.ping_cm();
Serial.println(distance);
  //If distance is within 30 cm then adjust motor direction as below
  if (distance > 0 && distance < DISTANCE_TO_CHECK)
  {
    //Stop motors
    digitalWrite(m1a, LOW);
    digitalWrite(m1b, LOW);
    digitalWrite(m2a, LOW);
    digitalWrite(m2b, LOW);
    digitalWrite(m3a, LOW);
    digitalWrite(m3b, LOW);
    digitalWrite(m4a, LOW);
    digitalWrite(m4b, LOW); 
    delay(500);  
       
    //Reverse motors
    digitalWrite(m1a, LOW);
    digitalWrite(m1b, HIGH);
    digitalWrite(m2a, HIGH);
    digitalWrite(m2b, HIGH);
    digitalWrite(m3a, HIGH);
    digitalWrite(m3b, HIGH);
    digitalWrite(m4a, LOW);
    digitalWrite(m4b, HIGH);       
    delay(500);
    
    //Stop motors
    digitalWrite(m1a, LOW);
    digitalWrite(m1b, LOW);
    digitalWrite(m2a, LOW);
    digitalWrite(m2b, LOW);
    digitalWrite(m3a, LOW);
    digitalWrite(m3b, LOW);
    digitalWrite(m4a, LOW);
    digitalWrite(m4b, LOW); 
    delay(500);
    
    //Rotate servo to left    
    myServo.write(180);
    delay(1000);

    //Read left side distance using ultrasonic sensor
    int distanceLeft = mySensor.ping_cm();    

    //Rotate servo to right
    myServo.write(0);    
    delay(1000);    

    //Read right side distance using ultrasonic sensor   
    int distanceRight = mySensor.ping_cm();

    //Bring servo to center
    myServo.write(90); 
    delay(1000);        
    
    if (distanceLeft == 0 )
    {//right
      digitalWrite(m1a, LOW);
    digitalWrite(m1b, HIGH);
    digitalWrite(m2a, HIGH);
    digitalWrite(m2b, HIGH);
    digitalWrite(m3a, HIGH);
    digitalWrite(m3b, LOW);
    digitalWrite(m4a, HIGH);
    digitalWrite(m4b, HIGH);
      delay(500);
    }
    else if (distanceRight == 0 )
    {
     digitalWrite(m1a, HIGH);
    digitalWrite(m1b, HIGH);
    digitalWrite(m2a, HIGH);
    digitalWrite(m2b, HIGH);
    digitalWrite(m3a, HIGH);
    digitalWrite(m3b, HIGH);
    digitalWrite(m4a, HIGH);
    digitalWrite(m4b, HIGH); 
      delay(500);
    }
    else if (distanceLeft >= distanceRight)
    {
       digitalWrite(m1a, HIGH);
    digitalWrite(m1b, HIGH);
    digitalWrite(m2a, HIGH);
    digitalWrite(m2b, HIGH);
    digitalWrite(m3a, HIGH);
    digitalWrite(m3b, HIGH);
    digitalWrite(m4a, HIGH);
    digitalWrite(m4b, HIGH); 
      delay(500);
    }
    else
    {
     digitalWrite(m1a, LOW);
    digitalWrite(m1b, HIGH);
    digitalWrite(m2a, HIGH);
    digitalWrite(m2b, HIGH);
    digitalWrite(m3a, HIGH);
    digitalWrite(m3b, LOW);
    digitalWrite(m4a, HIGH);
    digitalWrite(m4b, HIGH);
      delay(500);      
    }
    //Stop motors
    digitalWrite(m1a, LOW);
    digitalWrite(m1b, LOW);
    digitalWrite(m2a, LOW);
    digitalWrite(m2b, LOW);
    digitalWrite(m3a, LOW);
    digitalWrite(m3b, LOW);
    digitalWrite(m4a, LOW);
    digitalWrite(m4b, LOW);    
    delay(500);     
  }
  else
  {
    digitalWrite(m1a, HIGH);
    digitalWrite(m1b, HIGH);
    digitalWrite(m2a, LOW);
    digitalWrite(m2b, HIGH);
    digitalWrite(m3a, HIGH);
    digitalWrite(m3b, LOW);
    digitalWrite(m4a, HIGH);
    digitalWrite(m4b, HIGH);
  }
}


// void rotateMotor(int rightMotorSpeed, int leftMotorSpeed)
// {
//   if (rightMotorSpeed < 0)
//   {
//     digitalWrite(rightMotorPin1,LOW);
//     digitalWrite(rightMotorPin2,HIGH);    
//   }
//   else if (rightMotorSpeed >= 0)
//   {
//     digitalWrite(rightMotorPin1,HIGH);
//     digitalWrite(rightMotorPin2,LOW);      
//   }

//   if (leftMotorSpeed < 0)
//   {
//     digitalWrite(leftMotorPin1,LOW);
//     digitalWrite(leftMotorPin2,HIGH);    
//   }
//   else if (leftMotorSpeed >= 0)
//   {
//     digitalWrite(leftMotorPin1,HIGH);
//     digitalWrite(leftMotorPin2,LOW);      
//   }

//   analogWrite(enableRightMotor, abs(rightMotorSpeed));
//   analogWrite(enableLeftMotor, abs(leftMotorSpeed));    
// }