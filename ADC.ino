//The purpose of this program is to perform the analogue to digital conversion, 
//the display of the digital value N and the corresponding voltage Vm (calculated from N) on the serial monitor.
//The sampling period is 1000 ms.

int N;
float Vm;

void setup() {
  Serial.begin(9600);
}

void loop() {
  int T1 = micros(); //to measure the time of conversion//
  N = analogRead(A0);
  int T2 = micros();
  Serial.print("N = ");
  Serial.println(N);

  Vm = (float) (N*5)/1024;
  Serial.print("Vm = ");
  Serial.println(Vm);

  Serial.print("Conv time = ");
  Serial.println(T2 - T1);
  delay(1000); //1000ms instead of 500 because of the speed//
}

