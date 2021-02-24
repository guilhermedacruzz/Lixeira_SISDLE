#ifndef _BUTTON_
#define _BUTTON_

void startButton(const int button_pin) {
    pinMode(button_pin, INPUT_PULLUP);
}

bool checkButton(const int button_pin) {
    return digitalRead(button_pin) == LOW;
}

#endif