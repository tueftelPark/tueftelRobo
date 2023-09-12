// Definiere die Pins für Trig und Echo
const int trigPin = A1;
const int echoPin = A2;

// Variablen für die Zeitmessung
long duration;
int distance;

void setup() {
  // Initialisiere die serielle Kommunikation
  Serial.begin(9600);

  // Setze den Trig-Pin als Ausgang und den Echo-Pin als Eingang
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  // Sende einen Ultraschallimpuls
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Messe die Zeit, die der Ultraschall benötigt, um zurückzukehren
  duration = pulseIn(echoPin, HIGH);

  // Berechne die Entfernung in Zentimetern
  distance = duration * 0.034 / 2;

  // Gib die gemessene Entfernung in der Arduino IDE aus
  Serial.print("Entfernung: ");
  Serial.print(distance);
  Serial.println(" cm");

  // Warte einen Moment, bevor du die nächste Messung durchführst
  delay(1000);
}
