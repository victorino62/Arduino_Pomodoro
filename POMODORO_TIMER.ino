// Definindo os pinos
const int startButton = 2;  // Botão Iniciar
const int pauseButton = 3;  // Botão Pausar
const int resetButton = 4;  // Botão Redefinir
const int ledStart = 5;     // LED para indicar "Start"
const int ledPaused = 6;    // LED para indicar "Pausa"
const int ledRunning = 7;   // LED para indicar "Clock"
const int buzzer = 9;       // Pino de controle do buzzer ativo

// Variáveis de controle do timer
bool timerRunning = false;
bool timerPaused = false;
bool timerCompleted = false; // Flag para indicar que o timer foi concluído
unsigned long lastMillis = 0;   // Armazena o último incremento de 1 segundo
unsigned long secondsPassed = 0; // Segundos contados
const unsigned long durationSeconds = 25 * 60; // 25 minutos


void setup() {
  // Configuração dos pinos
  pinMode(startButton, INPUT_PULLUP); // Botão Iniciar com pull-up interno
  pinMode(pauseButton, INPUT_PULLUP); // Botão Pausar com pull-up interno
  pinMode(resetButton, INPUT_PULLUP); // Botão Redefinir com pull-up interno
  pinMode(ledStart, OUTPUT);          // LED "Start"
  pinMode(ledPaused, OUTPUT);         // LED "Pausa"
  pinMode(ledRunning, OUTPUT);        // LED "Clock"
  pinMode(buzzer, OUTPUT);            // Buzzer ativo

  // Inicializa LEDs e buzzer desligados
  digitalWrite(ledRunning, LOW);
  digitalWrite(ledStart, LOW);
  digitalWrite(ledPaused, LOW);
  digitalWrite(buzzer, HIGH); // HIGH mantém o buzzer inativo (low-level trigger)

  // Inicializa o monitor serial para depuração
  Serial.begin(9600);
  Serial.println("Pomodoro Timer iniciado.");
}

void loop() {
  // Botão Iniciar
  if (digitalRead(startButton) == LOW && !timerRunning && !timerPaused) {
    timerRunning = true;
    timerCompleted = false; // Reseta a flag de conclusão
    secondsPassed = 0;      // Reseta os segundos contados
    lastMillis = millis();  // Armazena o momento inicial
    Serial.println("Timer iniciado!");
    digitalWrite(ledStart, HIGH); // Acende o LED "Start"
    delay(200);                   // Debounce
    digitalWrite(ledStart, LOW);  // Apaga o LED "Start"
    digitalWrite(ledRunning, HIGH); // Acende o LED "Clock"
  }

  // Botão Pausar
  if (digitalRead(pauseButton) == LOW && timerRunning) {
    timerPaused = !timerPaused;   // Alterna entre pausa e execução
    digitalWrite(ledPaused, timerPaused ? HIGH : LOW); // Atualiza LED "Pausa"
    digitalWrite(ledRunning, timerPaused ? LOW : HIGH); // Atualiza LED "Clock"
    Serial.println(timerPaused ? "Timer pausado." : "Timer retomado.");
    delay(200);                   // Debounce
  }

  // Botão Redefinir
  if (digitalRead(resetButton) == LOW) {
    timerRunning = false;
    timerPaused = false;
    timerCompleted = false;
    secondsPassed = 0;            // Reseta os segundos contados
    digitalWrite(ledRunning, LOW);  // Apaga o LED "Clock"
    digitalWrite(ledPaused, LOW);   // Apaga o LED "Pausa"
    digitalWrite(ledStart, LOW);    // Apaga o LED "Start"
    digitalWrite(buzzer, HIGH);     // Desliga o buzzer
    Serial.println("Timer redefinido.");
    delay(200);                     // Debounce
  }

  // Lógica do Timer
  if (timerRunning && !timerPaused) {
    unsigned long currentMillis = millis();

    // Verifica se passou 1 segundo
    if (currentMillis - lastMillis >= 1000) {
      lastMillis = currentMillis; // Atualiza o último momento
      secondsPassed++;            // Incrementa o contador de segundos

      // Exibe o tempo decorrido no monitor serial
      Serial.print("Segundos passados: ");
      Serial.println(secondsPassed);

      // Verifica se o tempo foi concluído
      if (secondsPassed >= durationSeconds && !timerCompleted) {
        timerRunning = false;      // Para o timer
        timerCompleted = true;     // Define o timer como concluído
        Serial.println("=== Timer concluído! ===");
        digitalWrite(ledRunning, LOW); // Apaga o LED "Clock"
        digitalWrite(ledStart, LOW);  // Apaga o LED "Start"
        digitalWrite(buzzer, LOW);    // Liga o buzzer (LOW para low-level trigger)
        delay(2000);                  // Mantém o buzzer ligado por 2 segundos
        digitalWrite(buzzer, HIGH);   // Desliga o buzzer
      }
    }
  }

  delay(10); // Pequeno atraso para evitar processamento excessivo
}
