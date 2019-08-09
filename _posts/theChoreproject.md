---
layout: post
title:  "The Trash Can Project"
permalink: /13/
---
 
### The Trash Can Project

Over the past two weeks, I have built a robot that will potentially take your trash can to the road everyweek, so you don't have to. Here is how i did it, the idea, and how you can do it too!

<h1> The materials</h1>
<p1> First things first you will need a few things to start here is the list:
	- motordriver
	- dc geared motor x2
	- arduino nano or micro
	- acryllic sheet 1/4 in
	- laser cutter
	- fusion 360
	- arduino ide desktop
	- ultrasonic sonar sensor
	- sautering iron
	- fan
	- swivel wheel


these supplies are necessary and shouldnt cost more than 30 dollars! 
</p1>
<h1>The Hardware Assembled</h1>
<img src="2019-08-07.png" alt="fritzing">
Here is the hardware diagram and how you should connect and wire your bot. I highly recommend trial and error as a process for getting your exact digram right. 

<h1>The software</h1>
For software here is the code is used:
<xmp>
	int servoPin = 5;
#define trigPin 3
#define echoPin 2
int LightPin = 0;
int threshold = 980;
unsigned long previousMillis = 0;
const long interval = 1000;
int ledState = LOW;


int n;
long duration, distance;
String readString;


void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(9, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(7, OUTPUT);
 

}

void loop() {

  Serial.println(analogRead(LightPin));

  digitalWrite(trigPin, HIGH);
  _delay_ms(500);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration / 2) / 29.1;
  
  if (distance < 70) {

    digitalWrite(9, LOW);//blue2
    digitalWrite(6, LOW);//grey-4
    digitalWrite(8, HIGH);//purple3
    digitalWrite(7, HIGH);//green-1
    delay(1000); 
    digitalWrite(9, LOW);
    digitalWrite(6, HIGH);
    digitalWrite(8, LOW);
    digitalWrite(7, HIGH);
    delay(4000); 
    digitalWrite(9, HIGH);
    digitalWrite(6, HIGH);
    digitalWrite(8, LOW);
    digitalWrite(7, LOW);
    delay(1000);
    
    
    


  }
  else {
    digitalWrite(9, LOW);
    digitalWrite(6, HIGH);
    digitalWrite(8, LOW);
    digitalWrite(7, HIGH);

  }
}
</xmp>

The code shown is a very simple program that will make the sonar sensor sense continuously and when it senses objects within 70 mm it will turn go forward and turn back and go forward onto the original path. 

<h1> The created hardware </h1>
In order to create the frame and wheels of the robot you will have to use fusion 360 i have attached the files below. 

[Wheel 3D](https://a360.co/2MOxa5W)

[Frame 3D](https://a360.co/2OJWAUI)

The wheels are actually almost entirely silicon. The only piece not made of silicon is the core. Make these wheels you will have to 3d print the silicon wheel mold (print two because you will have to destroy them to remove the wheels) and the core. After printing place the core around the molded spindle and SLOWLY pour a silicon mix into the mold. 
<img src="IMG_6753.JPG" alt="Wheel">


Next, you will have to lasercut the frame out of acrylic! Power settings on your laser cutter will likely have to be changed so I recommend looking up suggested power settigns specifically for your laser cutter.
Just do it. 
After you laser cut the frame I recommend using super glue, epoxy, or acrylic glue to piece the pieces together. Brush both sides with the glue give a second and press together. they dont have to be perfect but it looks better if you take your time. 
After glueing all the pieces together you will have to attach the swivel wheel;however, I recommend adding that peice last after you confirm everything works.

Now, place your electronics into hard frame and pray it works lol.
if it works you are done and can add the swivel!!!!!!
<img src="IMG_6754" alt="the product">

