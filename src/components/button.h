#ifndef _BUTTON_
#define _BUTTON_

// Protótipos de Função 
void startButton();
bool checkButton();

// Extensão do pino correspondente do botão
extern const int button_pin;

// Inicializa o Botão
void startButton() {
    pinMode(button_pin, INPUT_PULLUP);
}

// Verifica o estado do botão
bool checkButton() {
    return digitalRead(button_pin) == LOW;
}

#endif