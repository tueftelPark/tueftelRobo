//Spiele den unten stehenden Code auf das Arduino. Was erkennst du? <br/>
//Erweitere den Code mit pinMode(x,x); und digitalWrite(x,x); damit das Fahrzeug im Uhrzeigersinn fährt.

const uint8_t LinkerMotorVorwaerts = 10;    // In2
const uint8_t LinkerMotorRueckwarts = 9;  // In1
const uint8_t RechterMotorVorwaerts = 6;   // In4
const uint8_t RechterMotorRueckwaerts = 7; // In3

void setup() {

  pinMode(LinkerMotorVorwaerts, OUTPUT);
  pinMode(LinkerMotorVorwaerts, OUTPUT);
  pinMode(RechterMotorRueckwaerts, OUTPUT);
  pinMode(RechterMotorVorwaerts, OUTPUT);
}

void loop() {
  digitalWrite(LinkerMotorVorwaerts, LOW);
  digitalWrite(LinkerMotorRueckwarts, HIGH);
  digitalWrite(RechterMotorRueckwaerts, LOW);
  digitalWrite(RechterMotorVorwaerts, HIGH);

}