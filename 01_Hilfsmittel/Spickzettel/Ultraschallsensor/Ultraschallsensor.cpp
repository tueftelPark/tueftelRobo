/////////////////////////////////////////////////////////////////
/*                      4. September 2023 
Einführung Ultraschallsensor.cpp (main-Datei)
Dieser Code enthält den eigentlichen Code um den Ultraschallsensor auszulesen.
Die Distanzen können direkt in Zentimeter zurückgegeben werden.
*/
/////////////////////////////////////////////////////////////////
/*                     HIER NICHTS ÄNDERN                      */

#include "Ultraschallsensor.h"
#include "Arduino.h"
#include <NewPing.h>

#define TrigerPin A1
#define EchoPin A2

const uint32_t MaximaleDistanz = 500; // Maximale Distanz die der Sensor auslesen kann in cm

NewPing Sensor(TrigerPin,EchoPin,MaximaleDistanz);



/// @brief Die Distanz zum Hindernis wird ein Mal gemessen und zurückgegeben.
uint16_t DistanzZumHindernis()
{
return Sensor.ping_cm();
}

