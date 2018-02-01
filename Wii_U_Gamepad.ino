
const int MODE  = 23;    // TV/Control Button
const int LED   = 6;     // 11 on Teensy 2.0; 6 on Teensy++ 2.0; for further information go to: https://www.pjrc.com/teensy/pinout.html
const int Up    = 0;
const int Down  = 1;
const int Left  = 3;
const int Right = 2;
const int A     = 13;
const int B     = 12;
const int x     = 11;
const int y     = 10;
const int START = 9;
const int SELECT = 14;
const int R     = 15;
const int ZR    = 8;
const int L     = 4; //4
const int ZL    = 5;
const int R_click = 21;
const int L_click = 18;
const int Hotkey = 22;
//Definition of Keyboard Actions
const int BTN_A       = KEY_ENTER;
const int BTN_B       = KEY_BACKSPACE;
const int BTN_X       = 0;
const int BTN_Y       = 0;
const int BTN_start   = KEY_ESC;
const int BTN_select  = 0;
const int BTN_Up      = KEY_W;
const int Stick_Up    = KEY_W;
const int BTN_Down    = KEY_S;
const int Stick_Down  = KEY_S;
const int BTN_Left    = KEY_A;
const int Stick_Left  = KEY_A;
const int BTN_Right   = KEY_D;
const int Stick_Right = KEY_D;

int vol = 0;
int buttonPushCounter = 0;   // counter for the number of button presses
int buttonState = 0;         // current state of the button
int lastButtonState = 0;

void setup() {

  pinMode(A, INPUT_PULLUP);
  pinMode(B, INPUT_PULLUP);
  pinMode(x, INPUT_PULLUP);
  pinMode(y, INPUT_PULLUP);
  pinMode(START, INPUT_PULLUP);
  pinMode(SELECT, INPUT_PULLUP);
  pinMode(R, INPUT_PULLUP);
  pinMode(ZR, INPUT_PULLUP);
  pinMode(Up, INPUT_PULLUP);
  pinMode(Down, INPUT_PULLUP);
  pinMode(Left, INPUT_PULLUP);
  pinMode(Right, INPUT_PULLUP);
  pinMode(L, INPUT_PULLUP);
  pinMode(ZL, INPUT_PULLUP);
  pinMode(R_click, INPUT_PULLUP);
  pinMode(L_click, INPUT_PULLUP);
  pinMode(Hotkey, INPUT_PULLUP);
  pinMode(LED, OUTPUT);           // LED
  pinMode(MODE, INPUT_PULLUP);    // Control Button
  pinMode(19, INPUT_PULLUP);
  Serial.begin(9600);

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
  if (digitalRead(R_click) == LOW)
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
  }
  while (digitalRead(Hotkey) == LOW)
  {
    Joystick.button(5, 1);
    Joystick.button(6, 1);
  }

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
  int rR = analogRead(4);
  rR = (rR - 512) * 1.5 + 512 - 75;
  if (rR > 1023)
    rR = 1023;
  if (rR < 0)
    rR = 0;

  int rZ = analogRead(5);
  rZ = (rZ - 512) * 1.5 + 512 - 100;
  if (rZ > 1023)
    rZ = 1023;
  if (rZ < 0)
    rZ = 0;
  rZ = abs(1023 - rZ);

  int rX = analogRead(0);
  rX = (rX - 512) * 1.5 + 512 + 21;
  if (rX > 1023)
    rX = 1023;
  if (rX < 0)
    rX = 0;

  int rY = analogRead(1);
  rY = (rY - 512) * 1.5 + 512 + 26;
  if (rY > 1023)
    rY = 1023;
  if (rY < 0)
    rY = 0;

  Joystick.X(rX);
  Joystick.Y(rY);
  Joystick.Z(rZ);
  Joystick.Zrotate(rR);
}

void loop_keyboard() {
  if (digitalRead(ZR) == LOW || digitalRead(ZL) == LOW)
  {
    if (digitalRead(ZR) == LOW && digitalRead(ZL) == HIGH)
    {
      Mouse.set_buttons(1, 0, 0);
    }
    if (digitalRead(ZR) == HIGH && digitalRead(ZL) == LOW)
    {
      Mouse.set_buttons(0, 0, 1);
    }
    if (digitalRead(ZR) == LOW && digitalRead(ZL) == LOW)
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
    while (digitalRead(x) == LOW)
    {
      Keyboard.press(BTN_X);
    }
  }
  else
  {
    Keyboard.release(BTN_X);
  }
  if (digitalRead(y) == LOW)
  {
    while (digitalRead(y) == LOW)
    {
      Keyboard.press(BTN_Y);
    }
  }
  else
  {
    Keyboard.release(BTN_Y);
  }
  if (digitalRead(Up) == LOW)
  {
    while (digitalRead(Up) == LOW)
    {
      Keyboard.press(BTN_Up);
    }
  }
  else
  {
    Keyboard.release(BTN_Up);
  }
  if (digitalRead(Down) == LOW)
  {
    while (digitalRead(Down) == LOW)
    {
      Keyboard.press(BTN_Down);
    }
  }
  else
  {
    Keyboard.release(BTN_Down);
  }
  if (digitalRead(Left) == LOW)
  {
    while (digitalRead(Left) == LOW)
    {
      Keyboard.press(BTN_Left);
    }
  }
  else
  {
    Keyboard.release(BTN_Left);
  }
  if (digitalRead(Right) == LOW)
  {
    while (digitalRead(Right) == LOW)
    {
      Keyboard.press(BTN_Right);
    }
  }
  else
  {
    Keyboard.release(BTN_Right);
  }
  if (digitalRead(START) == LOW)
  {
    while (digitalRead(START) == LOW)
    {
      Keyboard.press(BTN_start);
    }
  }
  else
  {
    Keyboard.release(BTN_start);
  }
  if (digitalRead(A) == LOW)
  {
    while (digitalRead(A) == LOW)
    {
      Keyboard.press(BTN_A);
    }
  }
  else
  {
    Keyboard.release(BTN_A);
  }
  if (digitalRead(B) == LOW)
  {
    while (digitalRead(B) == LOW)
    {
      Keyboard.press(BTN_B);
    }
  }
  else
  {
    Keyboard.release(BTN_B);
  }
  if (digitalRead(R) == LOW)
  {
    while (digitalRead(R) == LOW)
    {
      Mouse.scroll(-1);
      delay (100);
    }
  }
  if (digitalRead(L) == LOW)
  {
    while (digitalRead(L) == LOW)
    {
      Mouse.scroll(1);
      delay (100);
    }

  }


  int StickX = analogRead(1);
  StickX = StickX - 512 - 25;
  if (StickX <= -100)
  {
    Keyboard.press(Stick_Left);
  }
  if (StickX >= 100)
  {
    Keyboard.press(Stick_Right);
  }
  int StickY = analogRead(0);
  StickY = StickY - 512 - 25;
  if (StickY <= -100)
  {
    Keyboard.press(Stick_Down);
  }
  if (StickY >= 100)
  {
    Keyboard.press(Stick_Up);
  }
  else
  {
    Keyboard.release(Stick_Up);
    Keyboard.release(Stick_Down);
    Keyboard.release(Stick_Left);
    Keyboard.release(Stick_Right);
  }

  int MouseX = analogRead(4);
  MouseX = (MouseX / 20 - 25.5) / 2.5;
  /* int realX = MouseX;
    if (MouseX > 10)
     MouseX = 10;
    if (MouseX < -10)
     MouseX = -10;
    if (MouseX <= 0.5 && MouseX >= -0.5)
     MouseX = 0;*/

  int MouseY = analogRead(5);
  MouseY = ((MouseY / 20) * -1 + 26) / 2.5;
  /*int realY = MouseY;
    if (MouseY > 10)
    MouseY = 10;
    if (MouseY < -10)
    MouseY = -10;
    if (MouseY <= 0.5 && MouseY >= -0.5)
    MouseY = 0;*/
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
