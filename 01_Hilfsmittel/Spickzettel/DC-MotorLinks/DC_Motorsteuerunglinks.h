/////////////////////////////////////////////////////////////////
/*                      4. September 2023 
Einführung DC_Motorsteuerunglinks (Header-Datei)
Dieser Codeenthält ein Nachschlagewerk der einzelnen Funktionen in der main-Datei.
Der linke Motor muss zuerst gestartet werden, anschliessend kann der nach Wunsch drehen/stoppen.
*/
/////////////////////////////////////////////////////////////////
/*                     HIER NICHTS ÄNDERN                      */
/* Diese Datei dient als Orientierung der einzelnen Funktionen */


#ifndef DCMOTORSTEUERUNGLINKS_H
#define DCMOTORSTEUERUNGLINKS_H

#include "Arduino.h"

/// @brief Linker Motor wird gestartet. Pins angeben auf dem sich der Motor befindet
void StartLinkerMotor(uint8_t InEins, uint8_t InZwei);

/// @brief Der linke Motor hört auf zu drehen.
void LinkerMotorStoppt(void);

/// @brief Der linke Motor dreht vorwärts
void LinkerMotorVorwaerts(void);

/// @brief Der linke Motor dreht rückwärts
void LinkerMotorRueckwaerts(void);


#endif