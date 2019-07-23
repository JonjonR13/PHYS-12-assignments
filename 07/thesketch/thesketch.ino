//rx_tx02  Robert Hart Mar 2019.
//  Program to use transmit-receive across space between two conductors.
//  One conductor attached to pin4, one to A0
//
//  Optionally, two resistors (1 MOhm or greater) can be placed between 5V and GND, with
//  the signal connected between them so that the steady-state voltage is 2.5 Volts.
//
//  Signal varies with electric field coupling between conductors, and can
//  be used to measure many things related to position, overlap, and intervening material
//  between the two conductors.
//


int val;
int read_high;
int read_low;
int diff;
long int sum;
int N_samples = 100;

void setup() {
  
  pinMode(4, OUTPUT);
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(5, OUTPUT);
  Serial.begin(9600);

}

void loop() {

  sum = 0;

  for (int i = 0; i < N_samples; i++) {
    digitalWrite(4, HIGH);             //Step the voltage high on conductor 1.
    read_high = analogRead(A0);        //Measure response of conductor 2.
    delayMicroseconds(100);            //Delay to reach steady state.
    digitalWrite(4, LOW);              //Step the voltage to zero on conductor 1.
    read_low = analogRead(A0);         //Measure response of conductor 2.
    diff = read_high - read_low;       //desired answer is the difference between high and low.
    sum += diff;                       //Sums up N_samples of these measurements.
  }
  
  
  //sum = map(sum, 19, 75, 0, 5);
  Serial.println(sum);
  
  if ( sum >= 13000) {
    digitalWrite(13, HIGH);
    digitalWrite(12, HIGH);
    digitalWrite(9, LOW);
    digitalWrite(8, LOW);
    digitalWrite(6, HIGH);
    delay(10000);

    digitalWrite(13, LOW);
    digitalWrite(12, LOW);
    digitalWrite(9, HIGH);
    digitalWrite(8, HIGH);
    digitalWrite(6, HIGH);
    delay(10000);
    tone(9, sum);
  } else {
    digitalWrite(13, LOW);
    digitalWrite(12, LOW);
    digitalWrite(9, LOW);
    digitalWrite(8, LOW);
  }







}
