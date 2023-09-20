#include "MotorSteuerung.h"
#include <Arduino.h>



    // Pins MotorDriver    Digital
const uint8_t LinkerMotorVorwaerts = 10;    // In2
const uint8_t LinkerMotorRueckwarts = 9;  // In1
const uint8_t RechterMotorVorwaerts = 6;   // In4
const uint8_t RechterMotorRueckwaerts = 7; // In3



/// @brief Alle Motorenpins werden initialisiert
void InitialisierungMotor ()
{
      // Init MotorDriver
  pinMode(LinkerMotorVorwaerts, OUTPUT);
  pinMode(LinkerMotorVorwaerts, OUTPUT);
  pinMode(RechterMotorVorwaerts, OUTPUT);
  pinMode(RechterMotorRueckwaerts, OUTPUT);



  digitalWrite(LinkerMotorVorwaerts, LOW);
  digitalWrite(LinkerMotorRueckwarts, LOW);
  digitalWrite(RechterMotorVorwaerts, LOW);
  digitalWrite(RechterMotorRueckwaerts, LOW);

}



/// @brief Fahrzeug fährt gerade aus. 
void GeradeFahren()
{
  digitalWrite(LinkerMotorVorwaerts, HIGH);
  digitalWrite(LinkerMotorRueckwarts, LOW);
  digitalWrite(RechterMotorVorwaerts, HIGH);
  digitalWrite(RechterMotorRueckwaerts, LOW);
}



/// @brief Fahrzeug fährt nach links. 
void LinksFahren()
{
  digitalWrite(LinkerMotorVorwaerts, LOW);
  digitalWrite(LinkerMotorRueckwarts, LOW);
  digitalWrite(RechterMotorVorwaerts, HIGH);
  digitalWrite(RechterMotorRueckwaerts, LOW);
}




/// @brief Fahrzeug fährt nach rechts. 
void RechtsFahren()
{
  digitalWrite(LinkerMotorVorwaerts, HIGH);
  digitalWrite(LinkerMotorRueckwarts, LOW);
  digitalWrite(RechterMotorVorwaerts, LOW);
  digitalWrite(RechterMotorRueckwaerts, LOW);
}



/// @brief  Fahrzeug stoppt. 
void StoppFahren()
{
  digitalWrite(LinkerMotorVorwaerts, LOW);
  digitalWrite(LinkerMotorRueckwarts, LOW);
  digitalWrite(RechterMotorVorwaerts, LOW);
  digitalWrite(RechterMotorRueckwaerts, LOW);
}
