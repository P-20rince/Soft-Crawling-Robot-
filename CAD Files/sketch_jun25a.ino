// Pin Definitions
int BLPumpPin = 1;    // Pump
int BLValvePin = 2;   // Back Left Valve
int FLValvePin = 3;   // Front Left Valve
int MDValvePin = 4;   // Middle/Body Valve
int FRValvePin = 5;   // Front Right Valve
int BRValvePin = 6;   // Back Right Valve

void setup() {
  // Set all valve pins and pump pin as output
  pinMode(BLPumpPin, OUTPUT);
  pinMode(BLValvePin, OUTPUT);
  pinMode(BRValvePin, OUTPUT);
  pinMode(MDValvePin, OUTPUT);
  pinMode(FLValvePin, OUTPUT);
  pinMode(FRValvePin, OUTPUT);

  // Start Serial
  Serial.begin(9600);

  // Turn ON the pump
  digitalWrite(BLPumpPin, HIGH);

  delay(1000);

  // Basic movement test
  crawlStep();
  delay(2000);
  ReleaseAll();
}

void loop() {
  // Repeat crawling every 3 seconds
  crawlStep();
  delay(3000);
}

// === Actuation Functions ===
void BL_up() { digitalWrite(BLValvePin, HIGH); }
void BL_down() { digitalWrite(BLValvePin, LOW); }

void BR_up() { digitalWrite(BRValvePin, HIGH); }
void BR_down() { digitalWrite(BRValvePin, LOW); }

void FL_up() { digitalWrite(FLValvePin, HIGH); }
void FL_down() { digitalWrite(FLValvePin, LOW); }

void FR_up() { digitalWrite(FRValvePin, HIGH); }
void FR_down() { digitalWrite(FRValvePin, LOW); }

void MD_up() { digitalWrite(MDValvePin, HIGH); }
void MD_down() { digitalWrite(MDValvePin, LOW); }

void ReleaseAll() {
  BL_down();
  BR_down();
  FL_down();
  FR_down();
  MD_down();
}

// === Sample Crawling Step ===
void crawlStep() {
  Serial.println("Crawling step started");

  // Lift right side
  FR_up();
  BR_up();
  delay(500);
  FR_down();
  BR_down();

  delay(500);

  // Lift middle
  MD_up();
  delay(500);
  MD_down();

  delay(500);

  // Lift left side
  FL_up();
  BL_up();
  delay(500);
  FL_down();
  BL_down();

  Serial.println("Crawling step completed");
}
