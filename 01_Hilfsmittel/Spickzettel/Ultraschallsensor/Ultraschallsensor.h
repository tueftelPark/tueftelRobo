/////////////////////////////////////////////////////////////////
/*                      4. September 2023 
Einführung Ultraschallsensor.h(Header-Datei)
Dieser Codeenthält ein Nachschlagewerk der einzelnen Funktionen in der main-Datei.
Die Distanzen können direkt in Zentimeter zurückgegeben werden.
*/
/////////////////////////////////////////////////////////////////
/*                     HIER NICHTS ÄNDERN                      */
/* Diese Datei dient als Orientierung der einzelnen Funktionen */


#include <stdint.h>
#ifndef ULTRASCHALLSENSOR_H
#define ULTRASCHALLSENSOR_H

#include "Arduino.h"

/// @brief Die Distanz zum Hindernis wird ein Mal gemessen und zurückgegeben.
uint16_t DistanzZumHindernis(void);

#endif
