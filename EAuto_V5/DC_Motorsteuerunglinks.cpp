/////////////////////////////////////////////////////////////////
/*                      4. September 2023 
Einführung DC_Motorsteuerunglinks.cpp (main-Datei)
Dieser Code enthält den eigentlichen Code um den linken DC-Motor anzusteuern.
Der Linke Motor muss zuerst gestartet werden, anschliessend kann der nach Wunsch drehen/stoppen.
*/
/////////////////////////////////////////////////////////////////
/*                     HIER NICHTS ÄNDERN                      */

#include "DC_Motorsteuerunglinks.h"
#include "Arduino.h"

uint8_t PinEins;
uint8_t PinZwei;

/// @brief Linker Motor wird gestartet. Pins angeben auf dem sich der Motor befindet
void StartLinkerMotor(uint8_t InEins, uint8_t InZwei) {
  pinMode(InEins, OUTPUT);
  pinMode(InZwei, OUTPUT);

  PinEins = InEins;
  PinZwei = InZwei;
}

/// @brief Der linke Motor hört auf zu drehen.
void LinkerMotorStoppt() {
  digitalWrite(PinEins, LOW);
  digitalWrite(PinZwei, LOW);
}

/// @brief Der linke Motor dreht vorwärts
void LinkerMotorVorwaerts() {
  digitalWrite(PinEins, LOW);
  digitalWrite(PinZwei, HIGH);
}

/// @brief Der linke Motor dreht rückwärts
void LinkerMotorRueckwaerts() {
  digitalWrite(PinEins, HIGH);
  digitalWrite(PinZwei, LOW);
}