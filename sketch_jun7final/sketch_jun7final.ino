int REDPIN1 = 11;
int YELLOWPIN1 = 10;
int GREENPIN1 = 9;

int REDPIN2 = 3;
int YELLOWPIN2 = 5;
int GREENPIN2 = 6;

void setup() {
    pinMode(REDPIN1, OUTPUT);
    pinMode(YELLOWPIN1, OUTPUT);
    pinMode(GREENPIN1, OUTPUT);
    pinMode(REDPIN2, OUTPUT);
    pinMode(YELLOWPIN2, OUTPUT);
    pinMode(GREENPIN2, OUTPUT);
    Serial.begin(9600);
}

void loop() {
    if (Serial.available()) {
        char signal = Serial.read();
        Serial.println(signal);  
        if (signal == '1') {
            Serial.println("Signal '1' reçu");
            // Emegency vehicles and siren detected : Green light 
            digitalWrite(REDPIN1, LOW);
            digitalWrite(YELLOWPIN1, LOW);
            digitalWrite(GREENPIN1, HIGH);
            digitalWrite(REDPIN2, HIGH);
            digitalWrite(YELLOWPIN2, LOW);
            digitalWrite(GREENPIN2, LOW);
            delay(3000); // waitting time 
        }
    }

    // Cycle des feux de circulation (si aucun signal n'est reçu)
    if (Serial.available() == 0) {
        // Phase 1: First Road Green, Second Road Red
        digitalWrite(GREENPIN1, HIGH);
        digitalWrite(YELLOWPIN1, LOW);
        digitalWrite(REDPIN1, LOW);
        digitalWrite(GREENPIN2, LOW);
        digitalWrite(YELLOWPIN2, LOW);
        digitalWrite(REDPIN2, HIGH);
        delay(5000);

        // Phase 2: First Road Yellow, Second Road Red
        digitalWrite(GREENPIN1, LOW);
        digitalWrite(YELLOWPIN1, HIGH);
        digitalWrite(REDPIN1, LOW);
        digitalWrite(GREENPIN2, LOW);
        digitalWrite(YELLOWPIN2, LOW);
        digitalWrite(REDPIN2, HIGH);
        delay(2000);

        // Phase 3: First Road Red, Second Road Green
        digitalWrite(GREENPIN1, LOW);
        digitalWrite(YELLOWPIN1, LOW);
        digitalWrite(REDPIN1, HIGH);
        digitalWrite(GREENPIN2, HIGH);
        digitalWrite(YELLOWPIN2, LOW);
        digitalWrite(REDPIN2, LOW);
        delay(5000);

        // Phase 4: First Road Red, Second Road Yellow
        digitalWrite(GREENPIN1, LOW);
        digitalWrite(YELLOWPIN1, LOW);
        digitalWrite(REDPIN1, HIGH);
        digitalWrite(GREENPIN2, LOW);
        digitalWrite(YELLOWPIN2, HIGH);
        digitalWrite(REDPIN2, LOW);
        delay(2000);
    }
}
