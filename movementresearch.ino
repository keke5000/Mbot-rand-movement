/* Ohjelma on tehty MakeBlock mbot robotille.
 Tarkoituksena on ollut saada mbot liikkumaan itsenäisesti ja sattumanvaraisesti, väistäen kuitenkin esteen tullessa tielle.
 Väistäminen on toteutettu Ultrasonic-sensorin avulla, mutta toimii vielä välttävästi. Ajon aikana mbot saa liikekäskyn jota se ei lopeta ennen kuin valittu aikamääre umpeutuu. 

		KOMMENTTIRAITAKOKEILU :)

 -Keke5000
*/

#include <Arduino.h>
#include <Wire.h>
#include <SoftwareSerial.h>

#include <MeMCore.h>

MeDCMotor motor_9(9);
MeDCMotor motor_10(10);		
MeUltrasonicSensor ultra(PORT_3);
MeBuzzer buzzer;
MeLEDMatrix ledMx;

void buzzerOn()
{
  buzzer.tone(500);
}
void buzzerOff()
{
  buzzer.noTone(); 
}


void ultrasonic()
{
  uint8_t d = ultra.distanceCm(70);
  static long time = millis();
  randomSeed(analogRead(6));
  uint8_t randNumber = random(2);
}

void move(int direction, int speed)
{
      int leftSpeed = 0;
      int rightSpeed = 0;
      if(direction == 1){
        	leftSpeed = speed;
        	rightSpeed = speed;
      }else if(direction == 4){ //taaksepäin
        	leftSpeed = -speed;
        	rightSpeed = -speed;
      }else if(direction == 3){
        	leftSpeed = -speed;
        	rightSpeed = speed;
      }else if(direction == 2){ // vasen
        	leftSpeed = speed;
        	rightSpeed = -speed;
      }
      motor_9.run((9)==M1?-(leftSpeed):(leftSpeed));
      motor_10.run((10)==M1?-(rightSpeed):(rightSpeed));
}
				
double angle_rad = PI/180.0;
double angle_deg = 180.0/PI;

int i;
int aika;

void setup(){
 delay(2000);
 
}

void loop()
{
    i = random(1,(5)+1);
    if(i == 0)
    {
      i = 1;
    }
    delay(1000);
    aika = 0;

    uint8_t d = ultra.distanceCm();
    static long time = millis();
    randomSeed(analogRead(6));
    uint8_t randNumber = random(2);
    
    if((d > 20) || (d == 0))
    {
        while(aika < random(1,(10)+1))
           {
              move(i -1,random(50,(200)+1));
              aika += 1;
           }
    } else
    {
      switch (randNumber)
      {
        case 0:
          move(4, 150);
          move(3, 50);
          delay(800);
          break;
        case 1:
          move(4, 100);
          move(4, 100);
          delay(800);
          break;
      }
    }
    delay(100);
        
     buzzerOn();
     delay(1000);
    
}
