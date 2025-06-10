#include "cardClass.h"

using namespace std;

card_c::card_c(unsigned char value, unsigned char suits, bool revealed)
    : value(value), suits(suits), revealed(revealed) {}

card_c::~card_c() {}

void card_c::printCard() {
    const char valueBoard[] = "A23456789TJQK";
    const char suitsBoard[] = { 0x06, 0x03, 0x04, 0x05 }; // as CHAR not WCHAR

    if (suits > 3 || value > 12) {
        cout << color::reset << "  ";
        return;
    }

    if (revealed == false) {
        cout << color::reset << "??";
        return;
    }

    switch (suits)
    {
    case 0: cout << color::white; break;
    case 1: cout << color::red; break;
    case 2: cout << color::bright_blue; break;
    default: cout << color::green; break;
    }
    cout << valueBoard[value] << suitsBoard[suits];
}

bool card_c::checkError() {
    if (suits > 3 || value > 12)
        return true;
    return false;
}