#include<Servo.h>
Servo s1;
int ldr_1;
int ldr_2;
int pos1 = -90 ;

void setup() {
  Serial.begin(9600);
  pinMode(A1, INPUT);
  pinMode(A0, INPUT);
  s1.attach(9);
}

void loop() {
    ldr_1 = analogRead(A1);
    Serial.print(ldr_1);
    Serial.print(",");
    ldr_2 = analogRead(A0);
    Serial.print(ldr_2);
    Serial.print(",");
     Serial.print(ldr_1-ldr_2);
    Serial.print("\n");
    if(ldr_1>1000 && ldr_2>1000)//NIGHT TIME bring the motor 1 to "0 angle"=EAST
    {
        s1.attach(9);
        s1.write(pos1);
        pos1 = -90;
      
    }
    else if(1000>ldr_1>850 && 1000>ldr_2>850)//CLOUDY DAY 
    {
      s1.attach(9);
      s1.write(pos1);
      pos1 = 0;
      
    }
    else if(ldr_2-ldr_1>50)//less difference slow turn (ldr2>ldr1)
    {
      s1.attach(9);
     s1.write(pos1);
     pos1++;
    }
    else if(ldr_2-ldr_1>90)//more difference rapid turn (ldr2>ldr1)
    {
     s1.attach(9);
     s1.write(pos1);
     pos1=pos1+2;
    }
    else if(ldr_1-ldr_2>50)//less difference slow turn (ldr1>ldr2)
    {
      s1.attach(9);
     s1.write(pos1);
     pos1--;
    }
    else if(ldr_1-ldr_2>90)//more difference rapid turn (ldr1>ldr2)
    {
     s1.attach(9);
     s1.write(pos1);
     pos1=pos1-2;
    }  
  
}
