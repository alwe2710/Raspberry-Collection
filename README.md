# Raspberry-Collection
This collection of programs was mainly made for the Wii U Gamepad Raspberry Pi project(combined with Teensy 2 or Teensy 2++). All components can be used for different projects as well<br><br>

Teensy is being used as Controller and Keyboard+Mouse<br><br>

To use the Teensy in the Arduino IDE follow this guide: https://www.pjrc.com/teensy/teensyduino.html<br>
Documentation of Device Emulation of Teensy:<br>
-DirectInput Controller: https://www.pjrc.com/teensy/td_joystick.html<br>
-Keyboard: https://www.pjrc.com/teensy/td_keyboard.html<br>
-Mouse: https://www.pjrc.com/teensy/td_mouse.html<br><br>

Teensy and Arduino can be simply connected to Raspberry Pi via USB, for that you have to set 'USB Type' to 'Serial'( + Keyboard + Mouse + Joystick, if you want to use it as gamepad as well)<br><br>

WARNING: Using Teensy as Serial device AND controller will end in slow reading of the serial input on the Raspberry Pi(even 3B). Therefore use Arduino as separated serial-send device and Teensy just for input emulation<br><br>

TODO:<br> 
-Make script whisch installs both script parts to autostart of Raspberry Pi<br>
-Finish support of Keyboard+Mouse of Wii_U_Gamepad<br>
