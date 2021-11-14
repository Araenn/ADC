//The resistance is measured when the push button is pressed (input D7 with pull-up resistor).
//The measuring bridge is then supplied with Ve = 5V (output D8) and the voltage Vm can be measured on the analogue input A0.
//The following program can be used to calculate and display Rm (here a 10kOhm resistor is connected)://

int switchState;
int switchStateInit = 1;
int N;

void setup() {
  Serial.begin(9600);
  pinMode(7, INPUT_PULLUP);
  pinMode(8, OUTPUT);
  digitalWrite(8, 0);
}

void loop() {
  switchState = digitalRead(7);
  int Rm;
  N = analogRead(A0);
  float Vm;
  int R = 10000;
  int Ve = 5;
  
  if (switchState != switchStateInit && switchState == 0) {
    digitalWrite(8,1);
    Vm = (float) (N*5)/1024;
    Rm = (Vm*R)/(Ve-Vm);
    Serial.print("Valeur de la Resistance = ");
    Serial.println(Rm);
   }
}
