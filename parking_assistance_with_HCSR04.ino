#define redLed 7
#define blueLed 6
#define greenLed 5
#define trig 9
#define echo 10


long duration;
  int distance;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(redLed,OUTPUT);
  pinMode(blueLed,OUTPUT);
  pinMode(greenLed,OUTPUT);
  pinMode(echo,INPUT);
  
  pinMode(trig,OUTPUT);
}

void loop() {
 
  digitalWrite(trig,LOW);
  delayMicroseconds(2);
  digitalWrite(trig,HIGH);
  delayMicroseconds(10);
  digitalWrite(trig,LOW);
  duration = pulseIn(echo,HIGH);
  distance = (duration*0.0343)/2;
  Serial.println(distance);
  Serial.println(duration);
  if(distance<10){
    digitalWrite(redLed,HIGH);
    digitalWrite(blueLed,LOW);
    digitalWrite(greenLed,LOW);
    Serial.println("red zone");
    
  }
  else if((distance>10)&&(distance<30)){
    digitalWrite(redLed,LOW);
    digitalWrite(blueLed,HIGH);
    digitalWrite(greenLed,LOW);
    Serial.println("blue zone");
    //digitalWrite(trig,HIGH);
  }
  else if((distance>30)&&(distance<100)){
    digitalWrite(redLed,LOW);
    digitalWrite(blueLed,LOW);
    digitalWrite(greenLed,HIGH);
    Serial.println("green zone");
    //digitalWrite(trig,HIGH);
  }
  else{
    digitalWrite(redLed,LOW);
    digitalWrite(blueLed,LOW);
    digitalWrite(greenLed,LOW);
    Serial.println("out of zone");
  }
  
  
  // put your main code here, to run repeatedly:

}
