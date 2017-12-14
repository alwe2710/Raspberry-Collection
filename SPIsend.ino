//Load this script to Arduino
int vol = 0;
void setup() {
  Serial.begin(9600);
}
void loop() {
  vol = ((analogRead(2) - 22) / 10);
  if (vol < 0)
  {
    vol = 0;
  }
  Serial.println(vol);

  delay(10);
}
