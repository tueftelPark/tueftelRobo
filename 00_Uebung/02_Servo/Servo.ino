//Dieses Programm lässt den ServoMotor hin und her schwenken.
//Das "ServoMotor.write(x); ist dafür verantwortlich wie der Servo positioniert wird.
//Spiele den Code auf das Elektroauto und sieh was passiert.
//Nachdem kannst du die Zahlen in der "ServoMotor.write(x);" ändern.
//Spiele den Code erneut rüber und siehe was passiert.



#include <Servo.h>

const uint8_t = 3;

Servo ServoMotor;

void setup()
{
  ServoMotor.attach(ServoMotor);
}

void loop()
{
  ServoMotor.write(0);
  delay(1000);
  ServoMotor.write(90);
delay(1000);