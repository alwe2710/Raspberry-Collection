
const int MODE  = 9;    // TV/Control Button
const int LED   = 6;     // 11 on Teensy 2.0; 6 on Teensy++ 2.0; for further information go to: https://www.pjrc.com/teensy/pinout.html
const int Up    = 17;
const int Down  = 16;
const int Left  = 15;
const int Right = 14;
const int A     = 18;
const int B     = 19;
const int x     = 20;
const int y     = 21;
const int START = 22;
const int SELECT = 23;
const int R     = 24;
const int ZR    = 25;
const int L     = 13;
const int ZL    = 12;
const int R_click = 11;
const int L_click = 10;
//Definition of Keyboard Actions
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

  pinMode(A, INPUT_PULLUP);       // 01 A
  pinMode(B, INPUT_PULLUP);       // 02 B
  pinMode(x, INPUT_PULLUP);       // 03 X
  pinMode(y, INPUT_PULLUP);       // 04 Y
  pinMode(START, INPUT_PULLUP);   // 05 Start
  pinMode(SELECT, INPUT_PULLUP);  // 06 Select
  pinMode(R, INPUT_PULLUP);       // 07 R
  pinMode(ZR, INPUT_PULLUP);      // 08 ZR
  pinMode(Up, INPUT_PULLUP);      // 09 Up
  pinMode(Down, INPUT_PULLUP);    // 13 Down
  pinMode(Left, INPUT_PULLUP);    // 14 Left
  pinMode(Right, INPUT_PULLUP);   // 15 Right
  pinMode(L, INPUT_PULLUP);       // 19 L
  pinMode(ZL, INPUT_PULLUP);      // 20 ZL
  pinMode(LED, OUTPUT);           // LED
  pinMode(MODE, INPUT_PULLUP);    // Control Button

}

void loop_joystick() {
  if (digitalRead(A) == LOW)
  {
    Joystick.button(1, 1);
  }
  else
  {
    Joystick.button(1, 0);
  }
  if (digitalRead(B) == LOW)
  {
    Joystick.button(2, 1);
  }
  else
  {
    Joystick.button(2, 0);
  }
  if (digitalRead(x) == LOW)
  {
    Joystick.button(3, 1);
  }
  else
  {
    Joystick.button(3, 0);
  }
  if (digitalRead(y) == LOW)
  {
    Joystick.button(4, 1);
  }
  else
  {
    Joystick.button(4, 0);
  }
  if (digitalRead(START) == LOW)
  {
    Joystick.button(5, 1);
  }
  else
  {
    Joystick.button(5, 0);
  }
  if (digitalRead(SELECT) == LOW)
  {
    Joystick.button(6, 1);
  }
  else
  {
    Joystick.button(6, 0);
  }
  if (digitalRead(R) == LOW)
  {
    Joystick.button(7, 1);
  }
  else
  {
    Joystick.button(7, 0);
  }
  if (digitalRead(ZR) == LOW)
  {
    Joystick.button(8, 1);
  }
  else
  {
    Joystick.button(8, 0);
  }
  if (digitalRead(L) == LOW)
  {
    Joystick.button(9, 1);
  }
  else
  {
    Joystick.button(9, 0);
  }
  if (digitalRead(ZL) == LOW)
  {
    Joystick.button(10, 1);
  }
  else
  {
    Joystick.button(10, 0);
  }
  /*if (digitalRead(R_click) == LOW)
  {
    Joystick.button(11, 1);
  }
  else
  {
    Joystick.button(11, 0);
  }
   if (digitalRead(L_click) == LOW)
  {
    Joystick.button(12, 1);
  }
  else
  {
    Joystick.button(12, 0);
  }*/

  //D-Pad
  if (digitalRead(Up) == LOW || digitalRead(Down) == LOW || digitalRead(Left) == LOW || digitalRead(Right) == LOW)
  {
    //Horizontal/Vertical
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

    //Diagonal
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
  Joystick.Z(rL);
  Joystick.Zrotate(rR);
}


void loop_keyboard() {
  if (digitalRead(A) == LOW || digitalRead(B) == LOW)
  {
    if (digitalRead(A) == LOW && digitalRead(B) == HIGH)
    {
      Mouse.set_buttons(1, 0, 0);
    }
    if (digitalRead(B) == LOW && digitalRead(A) == HIGH)
    {
      Mouse.set_buttons(0, 0, 1);
    }
    if (digitalRead(A) == LOW && digitalRead(B) == LOW)
    {
      Mouse.set_buttons(1, 0, 1);
    }
  }
  else
  {
    Mouse.set_buttons(0, 0, 0);
  }
  if (digitalRead(x) == LOW)
  {
    Keyboard.press(BTN_X);
  }
  else
  {
    Keyboard.release(BTN_X);
  }
  if (digitalRead(y) == LOW)
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
  if (digitalRead(Left) == LOW)
  {
    Keyboard.press(BTN_Left);
  }
  else
  {
    Keyboard.release(BTN_Left);
  }
  if (digitalRead(Right) == LOW)
  {
    Keyboard.press(BTN_Right);
  }
  else
  {
    Keyboard.release(BTN_Right);
  }
  int MouseX = analogRead(1);
  MouseX = MouseX / 20 - 24.5;
  int realX = MouseX;
  if (MouseX > 10)
    MouseX = 10;
  if (MouseX < -10)
    MouseX = -10;
  if (MouseX <= 0.5 && MouseX >= -0.5)
    MouseX = 0;

  int MouseY = analogRead(0);
  MouseY = (MouseY / 20) * -1 + 24.5;
  int realY = MouseY;
  if (MouseY > 10)
    MouseY = 10;
  if (MouseY < -10)
    MouseY = -10;
   if (MouseY <= 0.5 && MouseY >=-0.5)
    MouseY = 0;
  Mouse.move(MouseX, MouseY);
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
