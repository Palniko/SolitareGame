#ifndef MESSAGE_H
#define MESSAGE_H

#include "coloredConsole.h"

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class message_c
{
public:
    uint8_t messageColor;
    string message = "";

    message_c(uint8_t messageColor, string message);

    ~message_c();

    void rainbowText(string text);

    void print();
};

#endif // MESSAGE_H