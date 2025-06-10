#include "solitareClass.h"

solitare_c::solitare_c() {}

solitare_c::~solitare_c() {}

uint64_t solitare_c::calculateTime() {
    return (GetTickCount64() - tickStarted) / 1000;
}

void solitare_c::setup() {
    userInput.clear();
    selectedX = -1;
    selectedY = -1;
    currentX = 5;
    currentY = 5;
    moveCounter = 0;
    undoPoints = 3;

    tickStarted = GetTickCount64();

    cheat = false;

    userInput.clear();
    snapShots.clear();
    deck = stack_c();
    tempStack = stack_c();
    colums.clear();
    endStacks.clear();
    for (int32_t i = 0; i < 7; i++)
        colums.push_back(columStack_c());
    for (int32_t i = 0; i < 4; i++)
        endStacks.push_back(endStack_c(i));
    reserveStack = stack_c();
    for (int32_t i = 0; i < 4; i++)
        for (int32_t j = 0; j < 13; j++)
            deck.addCard(card_c(j,i,false));
    deck.shuffle();
    for (int32_t i = 0; i < 7; i++)
        for (int32_t j = 0; j < i + 1; j++)
            colums[i].addCard(deck.getCard(-1, true));
    reserveStack.stack = deck.stack;
    deck.stack.clear();
    reserveStack.revealAll();
    for (int32_t i = 0; i < 7; i++)
        colums[i].revealTop();
}

string solitare_c::getUsername() {
    char username[257];
    DWORD len = 257;

    if (GetUserNameA(username, &len)) {
        return string(username);
    }
    else {
        return "Guest";
    }
}

bool solitare_c::checkForCurrent(int32_t x, int32_t y) {
    if (currentX == x && currentY == y)
        return true;
    return false;
}

bool solitare_c::checkForSelected(int32_t x, int32_t y) {
    if (selectedX == x && selectedY == y)
        return true;
    return false;

}

void solitare_c::printSelectedArrow() {
    cout << color::red << " < ";
}

void solitare_c::printCurrentArrow() {
    cout << color::bright_yellow << " < ";
}

void solitare_c::checkForArrow(int32_t x, int32_t y) {
    if (checkForCurrent(x, y)) printCurrentArrow(); else if (checkForSelected(x, y)) printSelectedArrow(); else cout << "   ";
}

void solitare_c::printTable(message_c message) {
    system("cls");
    cout << color::magenta << "                     SOLITARE\n" << color::reset << "     MOVES: " << color::bright_yellow << moveCounter << color::reset << "     UNDO POINTS: " << color::bright_yellow << undoPoints << color::reset << "   TIME: " << color::bright_yellow << calculateTime(); if (cheat) cout << color::red << "   KONAMI CODE ACTIVATED!"; cout << '\n';
    cout << color::reset << "   RE"; checkForArrow(0,0);
    for (int32_t i = 0; i < 7; i++) {
        cout << color::bright_yellow << 'C' << i + 1; checkForArrow(1+i,0);
    }
    cout << color::reset << 'C' << (char)0x06; checkForArrow(8, 0); cout << color::red << 'C' << (char)0x03; checkForArrow(9, 0); cout << color::bright_blue << 'C' << (char)0x04; checkForArrow(10, 0); cout << color::green << 'C' << (char)0x05; checkForArrow(11, 0); cout << '\n';
    for (int32_t i = 0; i < 20; i++) {
        if (i == 0) {
            cout << "   "; reserveStack.getCard().printCard(); checkForArrow(0, 1);
        }
        else
            cout << "        ";
        for (int32_t j = 0; j < 7; j++) {
            tempCard = colums[j].getCard(i);
            tempCard.printCard();
            checkForArrow(1 + j, 1 + i);
        }
        if (i == 0) {
            for (int32_t j = 0; j < 4; j++) {
                tempCard = endStacks[j].getCard();
                tempCard.printCard();
                checkForArrow(8 + j, 1);
            }
        }
        cout << '\n';
    }
    cout << color::bright_yellow << "CONTROLS: q " << color::reset << "- quit   " << color::bright_yellow << "c " << color::reset << "- undo   " << color::bright_yellow << "enter " << color::reset << "- proceed   " << color::bright_yellow << "arrows " << color::reset << "- navigate\n     ";
    message.print();
}

void solitare_c::menu() {
    system("cls");
    cout << color::magenta;
    cout << " .oooooo..o   .oooooo.   ooooo        ooooo ooooooooooooo       .o.       ooooooooo.   oooooooooooo " << std::endl;
    cout << "d8P'    `Y8  d8P'  `Y8b  `888'        `888' 8'   888   `8      .888.      `888   `Y88. `888'     `8 " << std::endl;
    cout << "Y88bo.      888      888  888          888       888          .8\"888.      888   .d88'  888         " << std::endl;
    cout << " `\"Y8888o.  888      888  888          888       888         .8' `888.     888ooo88P'   888oooo8    " << std::endl;
    cout << "     `\"Y88b 888      888  888          888       888        .88ooo8888.    888`88b.     888    \"    " << std::endl;
    cout << "oo     .d8P `88b    d88'  888       o  888       888       .8'     `888.   888  `88b.   888       o " << std::endl;
    cout << "8\"\"88888P'   `Y8bood8P'  o888ooooood8 o888o     o888o     o88o     o8888o o888o  o888o o888ooooood8 " << std::endl;
    cout << color::reset << "                          Made for " << color::bright_yellow << "GIGATHON" << color::reset << " competition by " << color::blue <<  "Palnikowyyy\n";
    cout << color::reset << "                               press any key to start new game...";
    _getch();
}

bool solitare_c::sureToQuit() {
    system("cls");
    cout << color::red;
    cout << "    ,o888888o.     8 8888      88  8 8888 8888888 8888888888" << endl;
    cout << " . 8888     `88.   8 8888      88  8 8888       8 8888       " << endl;
    cout << ",8 8888       `8b  8 8888      88  8 8888       8 8888       " << endl;
    cout << "88 8888        `8b 8 8888      88  8 8888       8 8888       " << endl;
    cout << "88 8888         88 8 8888      88  8 8888       8 8888       " << endl;
    cout << "88 8888     `8. 88 8 8888      88  8 8888       8 8888       " << endl;
    cout << "88 8888      `8,8P 8 8888      88  8 8888       8 8888       " << endl;
    cout << "`8 8888       ;8P  ` 8888     ,8P  8 8888       8 8888       " << endl;
    cout << " ` 8888     ,88'8.   8888   ,d8P   8 8888       8 8888       " << endl;
    cout << "    `8888888P'  `8.   `Y88888P'    8 8888       8 8888       " << endl;
    cout << color::reset << "are you sure to quit ?\npress " << color::bright_yellow << "ENTER" << color::reset << " to quit";
    if (_getch() == '\r')
        return true;
    return false;
}

void solitare_c::winner() {
    system("cls");
    cout << color::bright_yellow;
    cout << " `8.`888b                 ,8'  8 8888 b.             8 b.             8 8 8888888888   8 888888888o.   " << std::endl;
    cout << "  `8.`888b               ,8'   8 8888 888o.          8 888o.          8 8 8888         8 8888    `88.  " << std::endl;
    cout << "   `8.`888b             ,8'    8 8888 Y88888o.       8 Y88888o.       8 8 8888         8 8888     `88  " << std::endl;
    cout << "    `8.`888b     .b    ,8'     8 8888 .`Y888888o.    8 .`Y888888o.    8 8 8888         8 8888     ,88  " << std::endl;
    cout << "     `8.`888b    88b  ,8'      8 8888 8o. `Y888888o. 8 8o. `Y888888o. 8 8 888888888888 8 8888.   ,88'  " << std::endl;
    cout << "      `8.`888b .`888b,8'       8 8888 8`Y8o. `Y88888o8 8`Y8o. `Y88888o8 8 8888         8 888888888P'   " << std::endl;
    cout << "       `8.`888b8.`8888'        8 8888 8   `Y8o. `Y8888 8   `Y8o. `Y8888 8 8888         8 8888`8b       " << std::endl;
    cout << "        `8.`888`8.`88'         8 8888 8      `Y8o. `Y8 8      `Y8o. `Y8 8 8888         8 8888 `8b.     " << std::endl;
    cout << "         `8.`8' `8,`'          8 8888 8         `Y8o.` 8         `Y8o.` 8 8888         8 8888   `8b.   " << std::endl;
    cout << "          `8.`   `8'           8 8888 8            `Yo 8            `Yo 8 888888888888 8 8888     `88. " << std::endl;
    cout << color::reset << "   Made for " << color::bright_yellow << "GIGATHON" << color::reset << " competition by " << color::blue << "Palnikowyyy\n";
    cout << color::reset << "     MOVES: " << color::bright_yellow << moveCounter << color::reset << "     UNDO POINTS: " << color::bright_yellow << undoPoints << color::reset << "   TIME: " << color::bright_yellow << calculateTime(); if (cheat) cout << color::red << "   KONAMI CODE ACTIVATED!"; cout << '\n';
    cout << color::reset << "         press any key to continue...";
    _getch();
}

bool solitare_c::sureToUndo() {
    system("cls");
    cout << color::green;
    cout << "8 8888      88 b.             8 8 888888888o.          ,o888888o.     " << endl;
    cout << "8 8888      88 888o.          8 8 8888    `^888.    . 8888     `88.   " << endl;
    cout << "8 8888      88 Y88888o.       8 8 8888        `88. ,8 8888       `8b  " << endl;
    cout << "8 8888      88 .`Y888888o.    8 8 8888         `88 88 8888        `8b " << endl;
    cout << "8 8888      88 8o. `Y888888o. 8 8 8888          88 88 8888         88 " << endl;
    cout << "8 8888      88 8`Y8o. `Y88888o8 8 8888          88 88 8888         88 " << endl;
    cout << "8 8888      88 8   `Y8o. `Y8888 8 8888         ,88 88 8888        ,8P " << endl;
    cout << "` 8888     ,8P 8      `Y8o. `Y8 8 8888        ,88' `8 8888       ,8P  " << endl;
    cout << "  8888   ,d8P  8         `Y8o.` 8 8888    ,o88P'    ` 8888     ,88'   " << endl;
    cout << "   `Y88888P'   8            `Yo 8 888888888P'          `8888888P'     " << endl;
    cout << color::reset << "are you sure to undo ?\npress " << color::bright_yellow << "ENTER" << color::reset << " to undo";
    if (_getch() == '\r')
        return true;
    return false;
}

bool solitare_c::checkForKonami() {
    const char konamiCode[] = { 72, 72, 80, 80, 75, 77, 75, 77, 'b', 'a' };

    if (userInput.size() >= 10) {
        size_t start = userInput.size() - 10;
        for (int i = 0; i < 10; i++) {
            if (userInput[start + i] != konamiCode[i])
                return false;
        }
        return true;
    }

    return false;
}

void solitare_c::tryMoveArrow(int32_t x, int32_t y) {
    if (x == -1 || y == -1 || x > mapX || y > mapY)
        return;
    if (map[y][x] == true) {
        currentX = x;
        currentY = y;
    }
}

void solitare_c::saveSnapShot() {
    snapShot_c snap;
    snap.colums = colums;
    snap.endStacks = endStacks;
    snap.reserveStack = reserveStack;
    snapShots.push_back(snap);
}

void solitare_c::loadLastestSnapShot(bool bySystem) {
    if (snapShots.empty()) return;

    if (!bySystem) {
        undoPoints--;
        if (moveCounter != 0)
            moveCounter--;
    }

    colums = snapShots[snapShots.size() - 1].colums;
    endStacks = snapShots[snapShots.size() - 1].endStacks;
    reserveStack = snapShots[snapShots.size() - 1].reserveStack;

    snapShots.pop_back();
}

message_c solitare_c::randomMsg() {
    random_device randomDevice;
    mt19937 gen(randomDevice());
    uniform_int_distribution<> distr(0, randomMessages.size() - 1);
    return randomMessages[distr(gen)];
}

void solitare_c::play() {
    uint8_t userInput1, userInput2;

    message_c msg = randomMsg();

    setup();
    menu();
mainloop:
    for (int32_t i = 0; i < 7; i++)
        colums[i].revealTop();
    printTable(msg);
    msg = randomMsg();
    userInput1 = _getch();
    if (userInput1 == 0 || userInput1 == 224) {
        userInput1 = _getch();
        switch (userInput1) {
        case 72:
            tryMoveArrow(currentX, currentY - 1);
            break;
        case 80:
            tryMoveArrow(currentX, currentY + 1);
            break;
        case 75:
            tryMoveArrow(currentX - 1, currentY);
            break;
        case 77:
            tryMoveArrow(currentX + 1, currentY);
            break;
        }
        userInput.push_back(userInput1);
    }
    else {
        userInput.push_back(userInput1);
        if (userInput1 == 'q') {
            if (sureToQuit())
                return;
        }
        else if (userInput1 == 'c') {
            if (cheat) {
                if (sureToUndo())
                    loadLastestSnapShot();
            }
            else {
                if (undoPoints > 0) {
                    if (sureToUndo())
                        loadLastestSnapShot();
                }
                else {
                    msg = message_c(1, "not enough undo points !");
                }
            }
        }
        else if (userInput1 == 'v') {
            selectedX = -1;
            selectedY = -1;
        }
        else if (userInput1 == '\r') {
            if (currentX == 0 && currentY == 0) { // reserve button
                reserveStack.shuffle();
                selectedX = -1;
                selectedY = -1;
                moveCounter++;
                saveSnapShot();
            }
            else if (selectedX != -1 && selectedY != -1) {
                if (selectedX == currentX) {
                    selectedX = -1;
                    selectedY = -1;
                }
                if (selectedX == 0 && selectedY == 1) {
                    if (currentX > 7) {
                        if (endStacks[currentX - 8].legalToPutCard(reserveStack.getCard())) {
                            endStacks[currentX - 8].addCard(reserveStack.getCard(-1, true));
                            moveCounter++;
                            saveSnapShot();
                            selectedX = -1;
                            selectedY = -1;
                        }
                        else {
                            selectedX = -1;
                            selectedY = -1;
                        }
                    }
                    else {
                        if (colums[currentX - 1].legalToPutCard(reserveStack.getCard())) {
                            colums[currentX - 1].addCard(reserveStack.getCard(-1, true));
                            moveCounter++;
                            saveSnapShot();
                            selectedX = -1;
                            selectedY = -1;
                        }
                        else {
                            selectedX = -1;
                            selectedY = -1;
                        }
                    }
                selectedX = -1;
                selectedY = -1;
                }
                else if (selectedX > 7 && selectedY == 1) {
                    if (currentX > 0 && currentX < 8) {
                        if (colums[currentX - 1].legalToPutCard(endStacks[selectedX - 8].getCard())) {
                            colums[currentX - 1].addCard(endStacks[selectedX - 8].getCard(-1, true));
                            moveCounter++;
                            saveSnapShot();
                            selectedX = -1;
                            selectedY = -1;
                        }
                        else {
                            selectedX = -1;
                            selectedY = -1;
                        }
                    }
                    else {
                        selectedX = -1;
                        selectedY = -1;
                    }
                }
                if (selectedX > 0 && selectedX < 8) {
                    if (currentX > 0 && currentX < 8) {
                        saveSnapShot();
                        tempStack = colums[selectedX - 1].getStack(selectedY - 1, true);
                        if (colums[currentX - 1].legalToPutStack(tempStack)) {
                            colums[currentX - 1].addStack(tempStack);
                            selectedX = -1;
                            selectedY = -1;
                        }
                        else {
                            loadLastestSnapShot(true);
                            selectedX = -1;
                            selectedY = -1;
                        }
                    }
                    else if (currentX > 7) {
                        if (endStacks[currentX - 8].legalToPutCard(colums[selectedX - 1].getCard())) {
                            endStacks[currentX - 8].addCard(colums[selectedX - 1].getCard(-1, true));
                            moveCounter++;
                            saveSnapShot();
                            selectedX = -1;
                            selectedY = -1;
                        }
                        else {
                            loadLastestSnapShot(true);
                            selectedX = -1;
                            selectedY = -1;
                        }
                    }
                }
            }
            else {
                selectedX = currentX;
                selectedY = currentY;
            }
        }
    }
    if (cheat == false)
        cheat = checkForKonami();
    for (int32_t i = 0; i < 4; i++) {
        if (!(endStacks[i].getCard().value == 12))
            goto mainloop;
    }
winner:
    winner();
    return;
}