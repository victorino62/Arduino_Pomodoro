const int buttonPin = 2; // Pino do botão

void setup() {
  pinMode(buttonPin, INPUT_PULLUP); // Configura o pino com pull-up interno
  Serial.begin(9600); // Inicia o monitor serial
}

void loop() {
  int buttonState = digitalRead(buttonPin); // Lê o estado do botão
  Serial.println(buttonState); // Imprime o estado no monitor serial
  delay(200);
}
