# Pomodoro Timer com Arduino

Este projeto implementa um **Pomodoro Timer** utilizando o Arduino, com controle por botões, LEDs de estado e um buzzer para notificar o final do tempo. O timer pode ser configurado para diferentes durações e utiliza incrementos de tempo de 1 segundo para garantir precisão, mesmo em intervalos longos.

## Funcionalidades

- **Início, Pausa e Reinício do Timer**:
  - Botões permitem iniciar, pausar e redefinir o temporizador.
- **Indicação Visual por LEDs**:
  - LEDs indicam os estados de "Iniciado", "Em Pausa" e "Executando".
- **Alarme Sonoro**:
  - Um buzzer ativo emite um som ao final do tempo.
- **Configuração de Tempo**:
  - O tempo pode ser configurado em segundos para fácil personalização.

## Componentes Utilizados

- **Arduino Uno** (ou compatível)
- **Protoboard** e **Jumpers**
- **3 LEDs** (vermelho, amarelo, verde) com resistores de 220Ω
- **3 Botões Push-Button** com resistores de 10kΩ
- **Buzzer Ativo**
- Fonte de alimentação (via USB ou bateria)

## Diagrama de Conexão

1. **Botões**:
   - Conecte um terminal ao pino designado no Arduino (`2`, `3`, `4`).
   - O outro terminal deve ser conectado ao **GND** via resistor de 10kΩ (pull-down).
2. **LEDs**:
   - Conecte os ânodos aos pinos designados (`5`, `6`, `7`) com resistores de 220Ω.
   - Conecte os cátodos ao **GND**.
3. **Buzzer**:
   - Conecte o pino `VCC` ao **5V**, o pino `GND` ao **GND**, e o pino de controle (`I/O`) ao pino `9` do Arduino.

## Código Fonte

O código foi projetado para rastrear o tempo em incrementos de 1 segundo, evitando problemas relacionados ao uso de `millis()` para intervalos longos. O arquivo principal está disponível em [`pomodoro_timer.ino`](./pomodoro_timer.ino).

### Principais Recursos no Código

- **Contagem de Segundos**:
  - O timer usa incrementos de 1 segundo, garantindo precisão e confiabilidade.
- **Debouncing dos Botões**:
  - Pequenos atrasos evitam leituras incorretas dos botões.
- **Mensagens no Monitor Serial**:
  - Informações de depuração sobre o progresso do tempo.

## Como Usar

1. Clone este repositório:
   ```bash
   git clone https://github.com/seu-usuario/pomodoro-timer-arduino.git
   cd pomodoro-timer-arduino
