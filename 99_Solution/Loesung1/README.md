# Autonomes Fahrzeug mit Seitenkontrolle
<h3>Ablauf</h3>
Fahrzeug fährt gerade aus solange kein Objekt sich näher befindet als GrenzeDistanz.
In diesem Zustand kontrolliert der Sensor ob sich links un rechts ein Objekt/Wand befindet.
Falls ja, korrigiert das Fahrzeug nur leicht in entgegengesetzte Richtung und behält dabei seine Spur.
Das Objekt/die Wand darf dabei die distanz MaxGrenzedistanz nicht unterschreiten.

Falls ein Objekt sich vor dem Fahrzeug befindet, hält das Fahrzeug an und kontrolliert ob leicht links oder leicht rechts Ausweichmöglichkeiten vorhanden sind.
Das Fahrzeug dreht sich dann ab , wo mehr Platz zur Verfügung steht.

<h3>Sonstige Infos</h3>

Steuerung der Motoren erfolgt über die Datei MotorSteuerung.cpp. Die Header-Datei MotorSteuerung MotorSteurung.h dient als Zuordnung der Funktionen*/

