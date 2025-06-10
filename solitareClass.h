#ifndef SOLITARE_H
#define SOLITARE_H

#pragma once
#include "cardClass.h"
#include "stackClass.h"
#include "snapShotClass.h"
#include "messageClass.h"
#include "defines.h"

#include <Windows.h>
#include <conio.h>
#include <string>
#include <vector>
#include <random>

using namespace std;

class solitare_c
{
private:
    int32_t selectedX,
            selectedY,
            currentX,
            currentY,
            undoPoints;

    uint32_t moveCounter;

    uint64_t tickStarted;

    uint8_t cheat;

    vector<char> userInput;
    vector<snapShot_c> snapShots;
    stack_c deck;
    stack_c tempStack;
    stack_c reserveStack;
    vector<columStack_c> colums;
    vector<endStack_c> endStacks;

    card_c tempCard;

#include "messages.h"

    uint32_t mapY = 20, mapX = 11;
    bool map[20][12] = {
    {1,1,1,1,1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1,1,1,1,1},
    {0,1,1,1,1,1,1,1,0,0,0,0},
    {0,1,1,1,1,1,1,1,0,0,0,0},
    {0,1,1,1,1,1,1,1,0,0,0,0},
    {0,1,1,1,1,1,1,1,0,0,0,0},
    {0,1,1,1,1,1,1,1,0,0,0,0},
    {0,1,1,1,1,1,1,1,0,0,0,0},
    {0,1,1,1,1,1,1,1,0,0,0,0},
    {0,1,1,1,1,1,1,1,0,0,0,0},
    {0,1,1,1,1,1,1,1,0,0,0,0},
    {0,1,1,1,1,1,1,1,0,0,0,0},
    {0,1,1,1,1,1,1,1,0,0,0,0},
    {0,1,1,1,1,1,1,1,0,0,0,0},
    {0,1,1,1,1,1,1,1,0,0,0,0},
    {0,1,1,1,1,1,1,1,0,0,0,0},
    {0,1,1,1,1,1,1,1,0,0,0,0},
    {0,1,1,1,1,1,1,1,0,0,0,0},
    {0,1,1,1,1,1,1,1,0,0,0,0},
    {0,1,1,1,1,1,1,1,0,0,0,0}
    };

    void setup();
    void printTable(message_c message);
    void menu();
    bool checkForKonami();
    bool sureToQuit();
    bool sureToUndo();
    void winner();
    string getUsername();
    message_c randomMsg();
    uint64_t calculateTime();
    void saveSnapShot();
    void loadLastestSnapShot(bool bySystem = false);
    bool checkForCurrent(int32_t x, int32_t y);
    bool checkForSelected(int32_t x, int32_t y);
    void printSelectedArrow();
    void printCurrentArrow();
    void checkForArrow(int32_t x, int32_t y);
    void tryMoveArrow(int32_t x, int32_t y);

public:
    solitare_c();

    ~solitare_c();

    void play();
};

#endif // SOLITARE_H