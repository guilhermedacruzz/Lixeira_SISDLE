#ifndef _BUTTON_
#define _BUTTON_

extern const int button_pin;

void startButton() {
    pinMode(button_pin, INPUT_PULLUP);
}

bool checkButton() {
    return digitalRead(button_pin) == LOW;
}

#endif