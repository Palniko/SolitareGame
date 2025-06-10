#ifndef STACK_H
#define STACK_H

#include "cardClass.h"
#include "defines.h"

#include <vector>
#include <random>

using namespace std;

class stack_c
{
public:
    vector<card_c> stack;

    stack_c();

    ~stack_c();

    void shuffle();
    void reverse();
    void revealTop();
    void hideAll();
    void revealAll();
    uint32_t getStackSize();
    card_c getCard(uint32_t index = -1, bool deleteIt = false);
    void addCard(card_c card, uint32_t index = -1);
    void deleteCard(uint32_t index = -1);
    void printCard(uint32_t index = -1);
    void clear();
    stack_c getStack(uint32_t index, bool deleteIt);
    void addStack(stack_c incomingStack);
};

class columStack_c : public stack_c
{
public:
    columStack_c();
    ~columStack_c();
    bool legalToPutStack(stack_c incomingStack);
    bool legalToPutCard(card_c card);
};

class reserve_c : public stack_c
{
public:
    uint32_t index = 0;
    reserve_c();
    ~reserve_c();
};

class endStack_c : public stack_c
{
public:
    uint8_t stackSuit;
    endStack_c(uint8_t stackSuit);
    ~endStack_c();
    bool legalToPutCard(card_c card);
};

#endif // STACK_H