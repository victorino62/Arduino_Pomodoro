const int buzzerPin = 9; // Pino onde o pino I/O do buzzer está conectado

void setup() {
  pinMode(buzzerPin, OUTPUT); // Configura o pino como saída
}

void loop() {
  digitalWrite(buzzerPin, LOW); // Liga o buzzer (LOW para low-level trigger)
  delay(1000);                 // Mantém ligado por 1 segundo
  digitalWrite(buzzerPin, HIGH); // Desliga o buzzer (HIGH para low-level trigger)
  delay(1000);                 // Mantém desligado por 1 segundo
}
