/////////////////////////////////////////////////////////////////
/*                      4. September 2023 
Einführung Servo_Motorsteuerung.cpp (main-Datei)
Dieser Code enthält den eigentlichen Code um einen Servomotor anzusteuern.
Um den Servomotor anzusteuern muss zuerst eine Pin vergeben werden.
Anschliessend kann der Servo-Motor auf die einzelnen Positionen bewegt werden. 
*/
/////////////////////////////////////////////////////////////////
/*                     HIER NICHTS ÄNDERN                      */


#include "Servo_Motorsteuerung.h"
#include "Arduino.h"
#include <Servo.h>

Servo ServoMotor;


/// @brief Servo wird auf angegebenen Pin gestartet
void StartServo(uint8_t Anschlusspin) {

  ServoMotor.attach(Anschlusspin);
}


/// @brief Servo wird gemäss mitgegebener Gradangabe positioniert, nur Werte von 0-180° möglich
void PositioniereServo(uint8_t Winkel) {
  ServoMotor.write(Winkel);
}