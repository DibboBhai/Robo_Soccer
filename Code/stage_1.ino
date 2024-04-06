int ch2;  //for left motor
int enA = 5;
int a=4; int b=6; 
 
int ch3; //for right motor
int enB = 9;
int c=8; int d=10; 

// Serring up limits for the channel 2 and 3
int ch2_high = 1800;
int ch2_low = 1200;
int ch3_high = 1700;
int ch3_low = 1200;

// for polynomial value
float ch2_poly;
float ch3_poly;

// for original values
int original_ch3;
int original_ch2;

void setup()
{
  Serial.begin(9600);
 
  pinMode(2,INPUT);
  pinMode(enA, OUTPUT);
  pinMode(a,OUTPUT); pinMode(b,OUTPUT);
 
  pinMode(3,INPUT);
  pinMode(enB, OUTPUT);
  pinMode(c,OUTPUT); pinMode(d,OUTPUT);

}

void polynomial(int original_ch2, int original_ch3)
{
  ch3 = map(pulseIn(2,HIGH), ch3_low , ch3_high, 0, 255);
  ch2 = map(pulseIn(3,HIGH), ch2_low , ch2_high, 0, 255);

  ch2_poly = (1.0 / 255) * pow(ch2, 2);
  ch3_poly = (1.0 / 255) * pow(ch3, 2);

  analogWrite(enA, ch2_poly);
  analogWrite(enB, ch3_poly);

}


void loop() {
  ch3 = map(pulseIn(2,HIGH), ch3_low , ch3_high, -254, 254);
  ch2 = map(pulseIn(3,HIGH), ch2_low , ch2_high, -254, 254);
  original_ch3 = pulseIn(2, HIGH);
  original_ch2 = pulseIn(3, HIGH);

  if(ch2>254){
    ch2=254;
    }
  if(ch3>254){
    ch3=254;
    }
  if(ch2< -254){
    ch2=-254;
    }
  if(ch3< -254){
    ch3=-254;
    }

  if(ch2>0 && ch3>0){                                    //  FORWARD MOVEMENT
    digitalWrite(a, HIGH);digitalWrite(b, LOW);
    digitalWrite(c, LOW);digitalWrite(d, HIGH);
  }
  else if(ch2<0 && ch3<0){                                // BACKWARD MOTION
    digitalWrite(a, LOW);digitalWrite(b, HIGH);
    digitalWrite(c, HIGH);digitalWrite(d, LOW);
  }

  else if(ch2>0 && ch3<0){                                // RIGHTWARD MOTION
    digitalWrite(a, HIGH);digitalWrite(b, LOW);
    digitalWrite(c, HIGH);digitalWrite(d, LOW);
  }

  else if (ch2<0 && ch3>0){                               //LEFTWARD MOTION
    digitalWrite(a, LOW);digitalWrite(b, HIGH);
    digitalWrite(c, LOW);digitalWrite(d, HIGH);
  }

  else{                                                 // STABLE
    digitalWrite(a, LOW);digitalWrite(b, LOW);
    digitalWrite(c, LOW);digitalWrite(d, LOW);    
  }

  polynomial(original_ch2,original_ch3);

}