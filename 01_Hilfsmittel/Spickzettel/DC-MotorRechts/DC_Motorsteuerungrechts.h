/////////////////////////////////////////////////////////////////
/*                      4. September 2023 
Einführung DC_Motorsteuerungrechts (Header-Datei)
Dieser Codeenthält ein Nachschlagewerk der einzelnen Funktionen in der main-Datei.
Der rechte Motor muss zuerst gestartet werden, anschliessend kann der nach Wunsch drehen/stoppen.
*/
/////////////////////////////////////////////////////////////////
/*                     HIER NICHTS ÄNDERN                      */
/* Diese Datei dient als Orientierung der einzelnen Funktionen */

#ifndef DCMOTORSTEUERUNGRECHTS_H
#define DCMOTORSTEUERUNGRECHTS_H

#include "Arduino.h"


/// @brief Rechter motor wird gestartet. Pins angeben auf dem sich der Motor befindet
void StartRecherMotor(uint8_t InDrei, uint8_t InVier);

/// @brief Der rechte Motor hört auf zu drehen.
void RechterMotorStoppt(void);

/// @brief Der rechte Motor dreht vorwärts.
void RechterMotorVorwaerts(void);

/// @brief Der rechte Motor dreht rückwärts.
void RechterMotorRueckwaerts(void);


#endif