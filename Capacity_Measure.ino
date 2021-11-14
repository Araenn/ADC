int switchState;
int switchStateInit = 1;
int N;
int t1;
int t2;
int dt;

void setup() {
  Serial.begin(9600);
  pinMode(7, INPUT_PULLUP);
  pinMode(8, OUTPUT);
  digitalWrite(8, 0);
}

void loop() {
  switchState = digitalRead(7);
  int R = 10000;
  
  if (switchState != switchStateInit && switchState == 0) {
    t1 = micros();
    N = analogRead(A0);
    digitalWrite(8, 1);
  
    while (N < 645.12) { // 63% of 1024 (i.e of Vcc)
      N = analogRead(A0);
    }

    t2 = micros();
    dt = t2 - t1;
    float C = (float) (dt * (10^(-6)))/R;
    Serial.print("C value = ");
    Serial.println(C);
    digitalWrite(8, 0);
    delay(1000);
    }
  switchStateInit = switchState;
}
