
const int MODE  = 19;    // TV/Control Button
const int LED   = 6;     // 11 on Teensy 2.0; 6 on Teensy++ 2.0; for further information go to: https://www.pjrc.com/teensy/pinout.html
const int Up    = 26;
const int Down  = 25;
const int Left  = 24;
const int Right = 23;
//Definition of Keyboard Actions
const int BTN_A       = 0;
const int BTN_B       = 0;
const int BTN_X       = 0;
const int BTN_Y       = 0;
const int BTN_start   = KEY_ESC;
const int BTN_select  = 0;
const int BTN_R       = 0;
const int BTN_ZR      = 0;
const int BTN_Up      = KEY_W;
const int BTN_Down    = KEY_S;
const int BTN_Left    = KEY_A;
const int BTN_Right   = KEY_D;
const int BTN_L       = 0;
const int BTN_ZL      = 0;

int vol = 0;
int buttonPushCounter = 0;   // counter for the number of button presses
int buttonState = 0;         // current state of the button
int lastButtonState = 0;

void setup() {

  pinMode(0, INPUT_PULLUP);       // 01 A
  pinMode(1, INPUT_PULLUP);       // 02 B
  pinMode(2, INPUT_PULLUP);       // 03 X
  pinMode(3, INPUT_PULLUP);       // 04 Y
  pinMode(4, INPUT_PULLUP);       // 05 Start
  pinMode(5, INPUT_PULLUP);       // 06 Select
  pinMode(7, INPUT_PULLUP);       // 07 R
  pinMode(8, INPUT_PULLUP);       // 08 ZR
  pinMode(Up, INPUT_PULLUP);      // 09 Up
  pinMode(Down, INPUT_PULLUP);    // 13 Down
  pinMode(Left, INPUT_PULLUP);    // 14 Left
  pinMode(Right, INPUT_PULLUP);   // 15 Right
  pinMode(22, INPUT_PULLUP);      // 19 L
  pinMode(21, INPUT_PULLUP);      // 20 ZL
  pinMode(LED, OUTPUT);           // LED
  pinMode(MODE, INPUT_PULLUP);    // Control Button

}

void loop_joystick() {
  if (digitalRead(0) == LOW)
  {
    Joystick.button(1, 1);
  }
  else
  {
    Joystick.button(1, 0);
  }
  if (digitalRead(1) == LOW)
  {
    Joystick.button(2, 1);
  }
  else
  {
    Joystick.button(2, 0);
  }
  if (digitalRead(2) == LOW)
  {
    Joystick.button(3, 1);
  }
  else
  {
    Joystick.button(3, 0);
  }
  if (digitalRead(3) == LOW)
  {
    Joystick.button(4, 1);
  }
  else
  {
    Joystick.button(4, 0);
  }
  if (digitalRead(4) == LOW)
  {
    Joystick.button(5, 1);
  }
  else
  {
    Joystick.button(5, 0);
  }
  if (digitalRead(5) == LOW)
  {
    Joystick.button(6, 1);
  }
  else
  {
    Joystick.button(6, 0);
  }
  if (digitalRead(7) == LOW)
  {
    Joystick.button(7, 1);
  }
  else
  {
    Joystick.button(7, 0);
  }
  if (digitalRead(8) == LOW)
  {
    Joystick.button(8, 1);
  }
  else
  {
    Joystick.button(8, 0);
  }
  if (digitalRead(22) == LOW)
  {
    Joystick.button(9, 1);
  }
  else
  {
    Joystick.button(9, 0);
  }
  if (digitalRead(21) == LOW)
  {
    Joystick.button(10, 1);
  }
  else
  {
    Joystick.button(10, 0);
  }

  //D-Pad
  if (digitalRead(Up) == LOW || digitalRead(Down) == LOW || digitalRead(Left) == LOW || digitalRead(Right) == LOW)
  {
    //Horizontal
    if (digitalRead(Up) == LOW && digitalRead(Left) == HIGH && digitalRead(Right) == HIGH)
    {
      Joystick.hat(0);
    }
    if (digitalRead(Right) == LOW && digitalRead(Up) == HIGH && digitalRead(Down) == HIGH)
    {
      Joystick.hat(90);
    }
    if (digitalRead(Down) == LOW && digitalRead(Left) == HIGH && digitalRead(Right) == HIGH)
    {
      Joystick.hat(180);
    }
    if (digitalRead(Left) == LOW && digitalRead(Up) == HIGH && digitalRead(Down) == HIGH)
    {
      Joystick.hat(270);
    }

    //Vertical
    if (digitalRead(Up) == LOW && digitalRead(Right) == LOW)
    {
      Joystick.hat(45);
    }
    if (digitalRead(Right) == LOW && digitalRead(Down) == LOW)
    {
      Joystick.hat(135);
    }
    if (digitalRead(Down) == LOW && digitalRead(Left) == LOW)
    {
      Joystick.hat(225);
    }
    if (digitalRead(Left) == LOW && digitalRead(Up) == LOW)
    {
      Joystick.hat(315);
    }
  }
  else
  {
    Joystick.hat(-1);
  }

  //Control Sticks
  int rX = analogRead(4);
  rX = (rX - 512) * 1.5 + 512 - 75;
  if (rX > 1023)
    rX = 1023;
  if (rX < 0)
    rX = 0;

  int rY = analogRead(5);
  rY = (rY - 512) * 1.5 + 512 - 100;
  if (rY > 1023)
    rY = 1023;
  if (rY < 0)
    rY = 0;
  rY = abs(1023 - rY);

  int rL = analogRead(0);
  rL = (rL - 512) * 1.5 + 512 + 21;
  if (rL > 1023)
    rL = 1023;
  if (rL < 0)
    rL = 0;

  int rR = analogRead(1);
  rR = (rR - 512) * 1.5 + 512 + 26;
  if (rR > 1023)
    rR = 1023;
  if (rR < 0)
    rR = 0;

  Joystick.X(rX);
  Joystick.Y(rY);
  Joystick.sliderLeft(rL);
  Joystick.sliderRight(rR);
}


void loop_keyboard() {

  if (digitalRead(0) == LOW)
  {
    Keyboard.press(BTN_A);
  }
  else
  {
    Keyboard.release(BTN_A);
  }
  if (digitalRead(1) == LOW)
  {
    Keyboard.press(BTN_B);
  }
  else
  {
    Keyboard.release(BTN_B);
  }
  if (digitalRead(2) == LOW)
  {
    Keyboard.press(BTN_X);
  }
  else
  {
    Keyboard.release(BTN_X);
  }
  if (digitalRead(3) == LOW)
  {
    Keyboard.press(BTN_Y);
  }
  else
  {
    Keyboard.release(BTN_Y);
  }
  if (digitalRead(Up) == LOW)
  {
    Keyboard.press(BTN_Up);
  }
  else
  {
    Keyboard.release(BTN_Up);
  }
  if (digitalRead(Down) == LOW)
  {
    Keyboard.press(BTN_Down);
  }
  else
  {
    Keyboard.release(BTN_Down);
  }
}
void loop() {

  buttonState = digitalRead(MODE);
  if (buttonState != lastButtonState) {
    if (buttonState == HIGH) {
      buttonPushCounter++;
    }
    else {
    }
  }
  lastButtonState = buttonState;

  if (buttonPushCounter % 2 == 0) {
    digitalWrite(LED, HIGH);
  } else {
    digitalWrite(LED, LOW);
  }


  if (digitalRead(LED) == LOW)
  {
    loop_joystick();
  }
  else
  {

    loop_keyboard();
  }
}

