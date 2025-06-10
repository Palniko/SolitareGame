#include "messageClass.h"

using namespace std;

message_c::message_c(uint8_t messageColor, string message)
    : messageColor(messageColor), message(message) {}

message_c::~message_c() {}

void message_c::rainbowText(std::string text) {
    const auto numColors = 6;

    const char* colors[] = {
        "\033[31m", // red
        "\033[33m", // yellow
        "\033[32m", // green
        "\033[36m", // cyan
        "\033[34m", // blue
        "\033[35m"  // magenta
    };

    for (int i = 0; i < text.length(); ++i) {
        std::cout << colors[i % numColors] << text[i];
    }
}

void message_c::print() {
	switch (messageColor)
	{
	case 0: cout << color::reset; break;
	case 1: cout << color::red; break;
	case 2: cout << color::yellow; break;
	case 3: cout << color::green; break;
	case 4: cout << color::blue; break;
    case 5: cout << color::cyan; break;
    case 6: cout << color::magenta; break;
    case 7: rainbowText(message); return; break;
	default:
		break;
	}
	cout << message;
}