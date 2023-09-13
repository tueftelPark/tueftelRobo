/////////////////////////////////////////////////////////////////
/*                      4. September 2023 
Einführung Servo_Motorsteuerung.h (Header-Datei)
Dieser Codeenthält ein Nachschlagewerk der einzelnen Funktionen in der main-Datei.
Um den Servomotor anzusteuern muss zuerst eine Pin vergeben werden.
Anschliessend kann der Servo-Motor auf die einzelnen Positionen bewegt werden. 
*/
/////////////////////////////////////////////////////////////////
/*                     HIER NICHTS ÄNDERN                      */
/* Diese Datei dient als Orientierung der einzelnen Funktionen */

#ifndef SERVOMOTORSTEUERUNG_H
#define SERVOMOTORSTEUERUNG_H

#include "Arduino.h"

/// @brief Servo wird auf angegebenen Pin gestartet
void StartServo(uint8_t Anschlusspin);


/// @brief Servo wird gemäss mitgegebener Gradangabe positioniert, nur Werte von 0-180° möglich
void PositioniereServo(uint8_t Winkel);

#endif