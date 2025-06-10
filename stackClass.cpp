#include "stackClass.h"

using namespace std;

stack_c::stack_c() {}

stack_c::~stack_c() {}

void stack_c::reverse() {
    vector<card_c> placeHolder = stack;
    int32_t counter = stack.size();
    for (int i = 0; i < counter; ++i) {
        stack[i] = placeHolder[counter - 1 - i];
    }
}

void stack_c::shuffle() {
    random_device randomDevice;
    mt19937 gen(randomDevice());
    uniform_int_distribution<> distr(0, stack.size() - 1);

    card_c placeHolder;
    int target;

    for (int i = 0; i < stack.size(); i++) {
        target = distr(gen);
        placeHolder.value = stack[target].value;
        placeHolder.suits = stack[target].suits;

        stack[target].value = stack[i].value;
        stack[target].suits = stack[i].suits;

        stack[i].value = placeHolder.value;
        stack[i].suits = placeHolder.suits;
    }
}

void stack_c::revealAll() {
    for (int i = 0; i < stack.size(); i++)
        stack[i].revealed = true;
}

void stack_c::hideAll() {
    for (int i = 0; i < stack.size(); i++)
        stack[i].revealed = false;
}

void stack_c::revealTop() {
    if (stack.empty())
        return;
    stack[stack.size() - 1].revealed = true;
}

uint32_t stack_c::getStackSize() {
    return stack.size();
}

card_c stack_c::getCard(uint32_t index, bool deleteIt) {
    card_c placeHolder;
    if (index == -1) {
        if (!stack.empty()) {
            placeHolder = stack[stack.size() - 1];
            if (deleteIt)
                deleteCard();
            return placeHolder;
        }
    }
    else {
        if (stack.size() > index) {
            placeHolder = stack[index];
            if (deleteIt)
                deleteCard(index);
            return placeHolder;
        }
    }
    return card_c(255, 255, 1); // function need to return it will return corrupted card
}

void stack_c::deleteCard(uint32_t index) {
    if (stack.empty()) return;

    if (index == -1 || index >= stack.size()) {
        stack.pop_back();
    }
    else {
        stack.erase(stack.begin() + index);
    }
}

void stack_c::addCard(card_c card, uint32_t index) {
    if (index == -1 || index >= stack.size()) {
        stack.push_back(card);
    }
    else {
        stack.insert(stack.begin() + index, card);
    }
}

void stack_c::printCard(uint32_t index) {
    if (stack.empty()) return;

    if (index == -1 || index >= stack.size()) {
        stack.back().printCard();
    }
    else {
        stack[index].printCard();
    }
}

void stack_c::clear() {
    stack.clear();
}

// columStack_c
columStack_c::columStack_c() {}

columStack_c::~columStack_c() {}

bool columStack_c::legalToPutCard(card_c card) {
    card_c tempCard = getCard();
    if (stack.empty())
        if (card.value == 12)
            return true;

    if (tempCard.value - 1 == card.value) {

        bool tempIsBlack = (tempCard.suits == SPADES || tempCard.suits == CLUBS);
        bool cardIsRed = (card.suits == DIAMONDS || card.suits == HEARTS);

        bool tempIsRed = (tempCard.suits == DIAMONDS || tempCard.suits == HEARTS);
        bool cardIsBlack = (card.suits == SPADES || card.suits == CLUBS);

        if ((tempIsBlack && cardIsRed) || (tempIsRed && cardIsBlack)) {
            return true;
        }
    }

    return false;
}

bool columStack_c::legalToPutStack(stack_c incomingStack) {
    if (incomingStack.getStackSize() == 0)
        return false;

    // Pierwsza karta w incomingStack (czyli ta, która pójdzie na wierzch)
    card_c incomingCard = incomingStack.getCard(0, false);

    return legalToPutCard(incomingCard);
}

void stack_c::addStack(stack_c incomingStack) {
    for (int32_t i = 0; i < incomingStack.stack.size(); i++)
        stack.push_back(incomingStack.stack[i]);
}

stack_c stack_c::getStack(uint32_t index, bool deleteIt) {
    stack_c result;

    if (index >= stack.size())
        return result; // pusty stos

    for (uint32_t i = index; i < stack.size(); ++i) {
        result.addCard(stack[i]);
    }

    if (deleteIt) {
        stack.erase(stack.begin() + index, stack.end());
    }

    return result;
}

// endStack_c
endStack_c::endStack_c(uint8_t stackSuit) : stackSuit(stackSuit) {}

endStack_c::~endStack_c() {}

bool endStack_c::legalToPutCard(card_c card) {
    card_c tempCard = getCard();
    if (card.value == 0)
        if (card.suits == stackSuit)
            return true;
    if (tempCard.value + 1 == card.value)
        if (card.suits == stackSuit) 
                return true;
    return false;
}