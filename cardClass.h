#ifndef CARD_H
#define CARD_H

#include "coloredConsole.h"

#include <iostream>

using namespace std;

class card_c
{
public:
    unsigned char value; // 0-A 1-2 ... 9-T 10-J 11-Q 12-K    T = 10
    unsigned char suits; // 0-? 1-? 2-? 3-? wartoœci jak w bryd¿u :v
    bool revealed = false;

    card_c(unsigned char value = 0, unsigned char suits = 0, bool revealed = false);

    ~card_c();

    void printCard();

    bool checkError();
};

#endif // CARD_H