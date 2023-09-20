/*
23.05.2023 

Autonomes Fahrzeug 

Ablauf:
Fahrzeug fährt gerade aus solange kein Objekt sich näher befindet als GrenzeDistanz.
Falls ein Objekt sich vor dem Fahrzeug befindet. Wird kontrolliert ob leicht links oder leicht rechts Ausweichmöglichkeiten vorhanden sind.
Das Fahrzeug dreht sich dann ab , wo mehr Platz zur Verfügung steht.




(Potentielle) Issues:
Kontrolle ob leicht links oder rechts Objekt. Während der Messung fährt das Fahrzeug weiter. 
Dies hat einen Störeinfluss zur Folge da die zurückgelegte Distanz nicht ausgeglichen wird zwischen den einzelnen Werten.

Zwischen Servobewegung und Sensorauslesung muss eine Verzögerung gelegt werden da ansonsten der Sensor falsch ausgerichtet sein kann bei Messbeginn.*/
#include <Arduino.h>
#include <Servo.h>
#include <NewPing.h>






//Veränderbare Variabeln je nach Fahrzeug
//Distanzgrenzen für die Entscheidung der Richtung
const uint8_t GrenzeDistanz= 70;              //Distanz in zum beginnen ausweichen
const uint8_t MaxGrenzeDistanz= 20;

const uint32_t AusweichZeit = 1000;             //Wie lange das Fahrzeug dem Objekt ausweicht bis es wieder gerade aus fahrt



//Pindeklarierungen und feste Werte Programmablauf
//Nur bei Bedarf abändern

//Pins Sensor   Analog!
#define TrigerPin A1
#define EchoPin A2
const uint32_t MaximaleDistanz = 500;               //Maximale Distanz in cm

//Pins Servo    Digital
const uint8_t ServoPin = 3;

//Pins MotorDriver    Digital
const uint8_t LinkerMotorVorwaerts = 6;     //In2
const uint8_t LinkerMotorRueckwaerts = 7;   //In1
const uint8_t RechterMotorVowaerts = 10;    //In4
const uint8_t RechterMotorRueckwaerts = 9;  //In3



//Hilfsvariabeln
volatile uint32_t distanz[4] = {MaximaleDistanz,MaximaleDistanz,MaximaleDistanz,MaximaleDistanz};       //[0] = gerade [1]=links [2]=rechts [3]=Notdistanz
const uint8_t WinkelGerade = 90;
const uint8_t WinkelLinks = 55;
const uint8_t WinkelRechts = 125;

volatile uint64_t StartZeit;
const uint32_t WarteZeit = 200;                 //Warte Zeit zwischen den einzelnen Servo/ Sensor-Befehlen


//Objektdeklarierung
NewPing sensor(TrigerPin,EchoPin,MaximaleDistanz);
Servo ServoMotor;




//Funktionsdeklarierung
void GeradeFahren(void);
void LinksFahren(void);
void RechtsFahren(void);
void StoppFahren(void);
void warten(uint32_t);





void setup() {

  //Init Servo
ServoMotor.attach(ServoPin);

//Init MotorDriver
 pinMode(LinkerMotorVorwaerts,OUTPUT);
 pinMode(LinkerMotorRueckwaerts,OUTPUT);
 pinMode(RechterMotorVowaerts,OUTPUT);
 pinMode(RechterMotorRueckwaerts,OUTPUT);

digitalWrite(LinkerMotorVorwaerts,LOW);
digitalWrite(LinkerMotorRueckwaerts,LOW);
digitalWrite(RechterMotorVowaerts,LOW);
digitalWrite(RechterMotorRueckwaerts,LOW);
}



void loop() {
  //Grundzustand ist gerade aus fahren
ServoMotor.write(WinkelGerade);
 GeradeFahren();
 distanz[0] = sensor.ping_cm();
 warten(WarteZeit);


//Falls Distanz unterschritten wird, schwenkt der Sensorkopf währenddessen das Fahrzeug fährt. 
//Werte werden abgespeichert und später verwertet
 if(distanz[0] <= GrenzeDistanz)
 {
  ServoMotor.write(WinkelLinks);
  warten(WarteZeit);
 distanz[1] = sensor.ping_cm();
 warten(WarteZeit);

 ServoMotor.write(WinkelRechts);
 warten(WarteZeit);
 distanz[2] = sensor.ping_cm();
 warten(WarteZeit);

 ServoMotor.write(WinkelGerade);
 }


//Fahrzeug weicht nach Links aus wenn Distanz zu klein ist
if((distanz[1] <= GrenzeDistanz) && (distanz[1]<=distanz[2]))
{
  RechtsFahren();
  warten(AusweichZeit);
for (int i=0;i<=3;++i)
{
  distanz[i]=MaximaleDistanz;
}
}
 
 //Fahrzeug weicht nach Rechts aus wenn Distanz zu klein ist
if((distanz[2] <= GrenzeDistanz) && (distanz[2]<distanz[1]))
{
  LinksFahren();
  warten(AusweichZeit);
 for (int i=0;i<=3;++i)
{
  distanz[i]=MaximaleDistanz;
}
}






}



/// @brief nicht blockierende Delayfunktion
/// @param warteZeit Zeit in ms
void warten(uint32_t warteZeit)
{
  StartZeit = millis();
  while(millis()-StartZeit < warteZeit)
  {

  }
}


/// @brief Fahrzeug fährt gerade aus. Zustand wird auf 1 gesetzt
void GeradeFahren ()
{
  digitalWrite(LinkerMotorVorwaerts,HIGH);
  digitalWrite(LinkerMotorRueckwaerts,LOW);
  digitalWrite(RechterMotorVowaerts,HIGH);
  digitalWrite(RechterMotorRueckwaerts,LOW);
}

/// @brief Fahrzeug fährt nach links. Zustand wird auf 1 gesetzt
void LinksFahren()
{
  digitalWrite(LinkerMotorVorwaerts,LOW);
  digitalWrite(LinkerMotorRueckwaerts,HIGH);
  digitalWrite(RechterMotorVowaerts,HIGH);
  digitalWrite(RechterMotorRueckwaerts,LOW);
}

/// @brief Fahrzeug fährt nach rechts. Zustand wird auf 1 gesetzt
void RechtsFahren()
{
  digitalWrite(LinkerMotorVorwaerts,HIGH);
  digitalWrite(LinkerMotorRueckwaerts,LOW);
  digitalWrite(RechterMotorVowaerts,LOW);
  digitalWrite(RechterMotorRueckwaerts,HIGH);
}

/// @brief  Fahrzeug stoppt. 
void StoppFahren()
{
digitalWrite(LinkerMotorVorwaerts,LOW);
digitalWrite(LinkerMotorRueckwaerts,LOW);
digitalWrite(RechterMotorVowaerts,LOW);
digitalWrite(RechterMotorRueckwaerts,LOW);
}