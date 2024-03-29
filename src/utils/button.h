#ifndef _BUTTON_
#define _BUTTON_

extern void clearNVS();

// Protótipos de Função 
void startButton();
void checkButton();

// Extensão do pino correspondente do botão
extern const int button_pin;

// Inicializa o Botão
void startButton() {
  pinMode(button_pin, INPUT_PULLUP);
}

// Verifica o estado do botão
void checkButton() {
	if(digitalRead(button_pin) == LOW) {
		clearNVS();
		WiFi.disconnect();
		ESP.restart();
	}
}

#endif