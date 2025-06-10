#pragma once
#include <ostream>
#include <iostream>

/*

  use cout, example:
  std::cout << clearConsole << color::red << "i am red " << color::reset << "i am white";

*/

namespace color {

    // Reset to default color
    template < class CharT, class Traits >
    constexpr std::basic_ostream< CharT, Traits >& reset(std::basic_ostream< CharT, Traits >& os) {
        return os << "\033[0m";
    }

    // Foreground colors (text)
    template < class CharT, class Traits >
    constexpr std::basic_ostream< CharT, Traits >& black(std::basic_ostream< CharT, Traits >& os) {
        return os << "\033[30m";
    }

    template < class CharT, class Traits >
    constexpr std::basic_ostream< CharT, Traits >& red(std::basic_ostream< CharT, Traits >& os) {
        return os << "\033[31m";
    }

    template < class CharT, class Traits >
    constexpr std::basic_ostream< CharT, Traits >& green(std::basic_ostream< CharT, Traits >& os) {
        return os << "\033[32m";
    }

    template < class CharT, class Traits >
    constexpr std::basic_ostream< CharT, Traits >& yellow(std::basic_ostream< CharT, Traits >& os) {
        return os << "\033[33m";
    }

    template < class CharT, class Traits >
    constexpr std::basic_ostream< CharT, Traits >& blue(std::basic_ostream< CharT, Traits >& os) {
        return os << "\033[34m";
    }

    template < class CharT, class Traits >
    constexpr std::basic_ostream< CharT, Traits >& magenta(std::basic_ostream< CharT, Traits >& os) {
        return os << "\033[35m";
    }

    template < class CharT, class Traits >
    constexpr std::basic_ostream< CharT, Traits >& cyan(std::basic_ostream< CharT, Traits >& os) {
        return os << "\033[36m";
    }

    template < class CharT, class Traits >
    constexpr std::basic_ostream< CharT, Traits >& white(std::basic_ostream< CharT, Traits >& os) {
        return os << "\033[37m";
    }

    // Bright foreground colors
    template < class CharT, class Traits >
    constexpr std::basic_ostream< CharT, Traits >& bright_black(std::basic_ostream< CharT, Traits >& os) {
        return os << "\033[90m";
    }

    template < class CharT, class Traits >
    constexpr std::basic_ostream< CharT, Traits >& bright_red(std::basic_ostream< CharT, Traits >& os) {
        return os << "\033[91m";
    }

    template < class CharT, class Traits >
    constexpr std::basic_ostream< CharT, Traits >& bright_green(std::basic_ostream< CharT, Traits >& os) {
        return os << "\033[92m";
    }

    template < class CharT, class Traits >
    constexpr std::basic_ostream< CharT, Traits >& bright_yellow(std::basic_ostream< CharT, Traits >& os) {
        return os << "\033[93m";
    }

    template < class CharT, class Traits >
    constexpr std::basic_ostream< CharT, Traits >& bright_blue(std::basic_ostream< CharT, Traits >& os) {
        return os << "\033[94m";
    }

    template < class CharT, class Traits >
    constexpr std::basic_ostream< CharT, Traits >& bright_magenta(std::basic_ostream< CharT, Traits >& os) {
        return os << "\033[95m";
    }

    template < class CharT, class Traits >
    constexpr std::basic_ostream< CharT, Traits >& bright_cyan(std::basic_ostream< CharT, Traits >& os) {
        return os << "\033[96m";
    }

    template < class CharT, class Traits >
    constexpr std::basic_ostream< CharT, Traits >& bright_white(std::basic_ostream< CharT, Traits >& os) {
        return os << "\033[97m";
    }

    // Background colors
    template < class CharT, class Traits >
    constexpr std::basic_ostream< CharT, Traits >& bg_black(std::basic_ostream< CharT, Traits >& os) {
        return os << "\033[40m";
    }

    template < class CharT, class Traits >
    constexpr std::basic_ostream< CharT, Traits >& bg_red(std::basic_ostream< CharT, Traits >& os) {
        return os << "\033[41m";
    }

    template < class CharT, class Traits >
    constexpr std::basic_ostream< CharT, Traits >& bg_green(std::basic_ostream< CharT, Traits >& os) {
        return os << "\033[42m";
    }

    template < class CharT, class Traits >
    constexpr std::basic_ostream< CharT, Traits >& bg_yellow(std::basic_ostream< CharT, Traits >& os) {
        return os << "\033[43m";
    }

    template < class CharT, class Traits >
    constexpr std::basic_ostream< CharT, Traits >& bg_blue(std::basic_ostream< CharT, Traits >& os) {
        return os << "\033[44m";
    }

    template < class CharT, class Traits >
    constexpr std::basic_ostream< CharT, Traits >& bg_magenta(std::basic_ostream< CharT, Traits >& os) {
        return os << "\033[45m";
    }

    template < class CharT, class Traits >
    constexpr std::basic_ostream< CharT, Traits >& bg_cyan(std::basic_ostream< CharT, Traits >& os) {
        return os << "\033[46m";
    }

    template < class CharT, class Traits >
    constexpr std::basic_ostream< CharT, Traits >& bg_white(std::basic_ostream< CharT, Traits >& os) {
        return os << "\033[47m";
    }

    // Bright background colors
    template < class CharT, class Traits >
    constexpr std::basic_ostream< CharT, Traits >& bg_bright_black(std::basic_ostream< CharT, Traits >& os) {
        return os << "\033[100m";
    }

    template < class CharT, class Traits >
    constexpr std::basic_ostream< CharT, Traits >& bg_bright_red(std::basic_ostream< CharT, Traits >& os) {
        return os << "\033[101m";
    }

    template < class CharT, class Traits >
    constexpr std::basic_ostream< CharT, Traits >& bg_bright_green(std::basic_ostream< CharT, Traits >& os) {
        return os << "\033[102m";
    }

    template < class CharT, class Traits >
    constexpr std::basic_ostream< CharT, Traits >& bg_bright_yellow(std::basic_ostream< CharT, Traits >& os) {
        return os << "\033[103m";
    }

    template < class CharT, class Traits >
    constexpr std::basic_ostream< CharT, Traits >& bg_bright_blue(std::basic_ostream< CharT, Traits >& os) {
        return os << "\033[104m";
    }

    template < class CharT, class Traits >
    constexpr std::basic_ostream< CharT, Traits >& bg_bright_magenta(std::basic_ostream< CharT, Traits >& os) {
        return os << "\033[105m";
    }

    template < class CharT, class Traits >
    constexpr std::basic_ostream< CharT, Traits >& bg_bright_cyan(std::basic_ostream< CharT, Traits >& os) {
        return os << "\033[106m";
    }

    template < class CharT, class Traits >
    constexpr std::basic_ostream< CharT, Traits >& bg_bright_white(std::basic_ostream< CharT, Traits >& os) {
        return os << "\033[107m";
    }

    // Text effects
    template < class CharT, class Traits >
    constexpr std::basic_ostream< CharT, Traits >& bold(std::basic_ostream< CharT, Traits >& os) {
        return os << "\033[1m";
    }

    template < class CharT, class Traits >
    constexpr std::basic_ostream< CharT, Traits >& underline(std::basic_ostream< CharT, Traits >& os) {
        return os << "\033[4m";
    }

    template < class CharT, class Traits >
    constexpr std::basic_ostream< CharT, Traits >& reversed(std::basic_ostream< CharT, Traits >& os) {
        return os << "\033[7m";
    }
}

template < class CharT, class Traits >
constexpr
std::basic_ostream< CharT, Traits >& clearConsole(std::basic_ostream< CharT, Traits >& os)
{
    return os << "cls";
}