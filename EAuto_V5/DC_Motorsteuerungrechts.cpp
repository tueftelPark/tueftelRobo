/////////////////////////////////////////////////////////////////
/*                      4. September 2023 
Einführung DC_Motorsteuerungrechts.cpp (main-Datei)
Dieser Code enthält den eigentlichen Code um den rechts DC-Motor anzusteuern.
Der rechte Motor muss zuerst gestartet werden, anschliessend kann der nach Wunsch drehen/stoppen.
*/
/////////////////////////////////////////////////////////////////
/*                     HIER NICHTS ÄNDERN                      */

#include "DC_Motorsteuerungrechts.h"
#include "Arduino.h"

uint8_t PinDrei;
uint8_t PinVier;

/// @brief Rechter motor wird gestartet. Pins angeben auf dem sich der Motor befindet
void StartRecherMotor(uint8_t InDrei, uint8_t InVier) {
  pinMode(InDrei, OUTPUT);
  pinMode(InVier, OUTPUT);

  PinDrei = InDrei;
  PinVier = InVier;
}

/// @brief Der rechte Motor hört auf zu drehen.
void RechterMotorStoppt() {
  digitalWrite(PinDrei, LOW);
  digitalWrite(PinVier, LOW);
}

/// @brief Der rechte Motor dreht vorwärts.
void RechterMotorVorwaerts() {
  digitalWrite(PinDrei, LOW);
  digitalWrite(PinVier, HIGH);
}

/// @brief Der rechte Motor dreht rückwärts.
void RechterMotorRueckwaerts() {
  digitalWrite(PinDrei, HIGH);
  digitalWrite(PinVier, LOW);
}
