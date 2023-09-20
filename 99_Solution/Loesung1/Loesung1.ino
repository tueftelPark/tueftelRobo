/*
31.05.2023

Autonomes Fahrzeug mit Seitenkontrolle


Ablauf:
Fahrzeug fährt gerade aus solange kein Objekt sich näher befindet als GrenzeDistanz.
In diesem Zustand kontrolliert der Sensor ob sich links un rechts ein Objekt/Wand befindet.
Falls ja, korrigiert das Fahrzeug nur leicht in entgegengesetzte Richtung und behält dabei seine Spur.
Das Objekt/die Wand darf dabei die distanz MaxGrenzedistanz nicht unterschreiten.

Falls ein Objekt sich vor dem Fahrzeug befindet, hält das Fahrzeug an und kontrolliert ob leicht links oder leicht rechts Ausweichmöglichkeiten vorhanden sind.
Das Fahrzeug dreht sich dann ab , wo mehr Platz zur Verfügung steht.

Sonstige Infos:

Steuerung der Motoren erfolgt über die Datei MotorSteuerung.cpp. Die Header-Datei MotorSteuerung MotorSteurung.h dient als Zuordnung der Funktionen*/

#include <Servo.h>
#include <NewPing.h>
#include "Motorsteuerung.h"

// Veränderbare Variabeln je nach Fahrzeug
const uint8_t GrenzeDistanz = 80;    // Distanz in cm zum ausweichen
const uint8_t MaxGrenzeDistanz = 30; // Distanz in cm. In diesem Radius darf sich nichts zum Fahrzeug befinden. Dient als Einstellung für die Spurhaltung

const uint32_t AusweichZeit = 800;  // Wie lange das Fahrzeug dem Objekt ausweicht bis es wieder gerade aus fahrt
const uint32_t KorrekturZeit = 300; // Wie lange ein Fahrzeug sich auskorrigiert zu der Seitenspur





// Pindeklarierungen und feste Werte Programmablauf
// Nur bei Bedarf abändern

// Pins Sensor   Analog!
#define TrigerPin A1
#define EchoPin A2
const uint32_t MaximaleDistanz = 500; // Maximale Distanz die der Sensor auslesen kann in cm

// Pins Servo    Digital
const uint8_t ServoPin = 3;

// Hilfsvariabeln
volatile uint32_t distanz[4] = {MaximaleDistanz, MaximaleDistanz, MaximaleDistanz, MaximaleDistanz}; //[0] = gerade [1]=links [2]=rechts [3]=Notdistanz
const uint8_t WinkelGerade = 90;
const uint8_t WinkelLinks = 55;
const uint8_t WinkelRechts = 125;
const uint8_t WinkelLinksAnschlag = 0;
const uint8_t WinkelRechtsAnschlag = 180; // 0=Setup 1= Geradeaus fahren 2=links fahren  3=rechts fahren 4=Fahrbahnkorrektur 5=Stopp

volatile uint64_t StartZeit;
const uint16_t Wartezeit = 300; // Damit Arduino die Tasks erledigen kann. Wichtig zwischen Sensormessung und Servorotierung



NewPing sensor(TrigerPin, EchoPin, MaximaleDistanz);
Servo ServoMotor;



//Funktionsdeklarierung
void warten(uint32_t);
void SetMaxDistanz(void);

void setup()
{
  // Init Servo
  ServoMotor.attach(ServoPin);
  InitialisierungMotor();
}

void loop()
{
  //Grundzustand des Fahrzeugs, vorausschauend und gerade fahrend
  ServoMotor.write(90);
  warten(Wartezeit);
  GeradeFahren();

  // Solange nichts vor dem Fahrzeug ist, muss das Fahrzeug nur das auskorrigieren nach Links und Rechts kontrollieren
  do
  {
    // Kontrolliere Gerade aus
    ServoMotor.write(WinkelGerade);
    warten(Wartezeit);
    distanz[0] = sensor.ping_cm();
    warten(Wartezeit);

    //Falls sich etwas vor dem Fahrzeug befindrt, breche die Seitenkontrolle ab und suche nach Ausweichmöglichkeiten
    if (distanz[0] <= GrenzeDistanz)
    {
      break;
    }

    // Kontrolliere Links
    ServoMotor.write(WinkelLinksAnschlag);
    warten(Wartezeit);
    distanz[1] = sensor.ping_cm();
    warten(Wartezeit);

    // Kontrolliere Rechts
    ServoMotor.write(WinkelRechtsAnschlag);
    warten(Wartezeit);
    distanz[2] = sensor.ping_cm();
    warten(Wartezeit);

    //Falls der minimale Abstand unterschschrittem wir wird und die Distanz links kleine ist als rechts, drehe Rechts ab
    if ((distanz[1] < MaxGrenzeDistanz) && (distanz[1] <= distanz[2]))
    {
      RechtsFahren();
      warten(KorrekturZeit);
      GeradeFahren();
    }

    //Falls der minimale Abstand unterschschrittem wir wird und die Distanz rechts kleiner ist als links, drehe Links ab
    if ((distanz[2] < MaxGrenzeDistanz) && (distanz[2] <= distanz[1]))
    {
      LinksFahren();
      warten(KorrekturZeit);
      GeradeFahren();
    }

  } while (distanz[0] >= GrenzeDistanz);


  StoppFahren();

  // Kontrolliere Linke Ausweichmöglichkeit
  ServoMotor.write(WinkelLinks);
  warten(Wartezeit);
  distanz[1] = sensor.ping_cm();
  warten(Wartezeit);


  // Kontrolliere Rechte Ausweichmöglichkeit
  ServoMotor.write(WinkelRechts);
  warten(Wartezeit);
  distanz[2] = sensor.ping_cm();
  warten(Wartezeit);
  ServoMotor.write(WinkelGerade);


  if (distanz[1] < distanz[2])
  {
    RechtsFahren();
    warten(AusweichZeit);
    GeradeFahren();
    SetMaxDistanz();
  }

  if (distanz[2] < distanz[1])
  {
    LinksFahren();
    warten(AusweichZeit);
    GeradeFahren();
    SetMaxDistanz();
  }
}




/// @brief nicht blockierende Delayfunktion
/// @param warteZeit Zeit in ms
void warten(uint32_t warteZeit)
{
  StartZeit = millis();
  while (millis() - StartZeit < warteZeit)
  {
  }
}

/// @brief Zurücksetzen des Distanzarrays auf die MaximaleDistanz
void SetMaxDistanz ()
{
 for (int i = 0; i <3; i++)
    {
      distanz[i] = MaximaleDistanz;
    }
}
