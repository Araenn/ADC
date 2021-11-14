//The purpose of this program is to perform the analogue to digital conversion, 
//the display of the digital value N and the corresponding voltage Vm (calculated from N) on the serial monitor.
//The sampling period is 1000 ms.

int N;
float Vm;

void setup() {
  Serial.begin(9600);
}

void loop() {
  N = analogRead(A0);
  Serial.print("N = ");
  Serial.println(N);

  Vm = (float) (N*5)/1024;
  Serial.print("Vm = ");
  Serial.println(Vm);

  delay(1000); //1000ms instead of 500 because of the speed//
}
