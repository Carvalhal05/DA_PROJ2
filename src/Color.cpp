#include "Color.hpp"
#include <iostream>
using namespace std;
using std::istream;

namespace prog {
    Color::Color() {
        RED=0;
        GREEN= 0;
        BLUE=0;
        //Default == Black (RGB(0,0,0)).
    }

    Color::Color(const Color &other) {
        RED=other.RED;
        GREEN=other.GREEN;
        BLUE=other.BLUE;
        //Copy constructor.
    }

    Color::Color(rgb_value r, rgb_value g, rgb_value b) {
        RED=r;
        GREEN=g;
        BLUE=b;
        //(RGB).
    }

    //Individual RGB color channels:
    rgb_value Color::red() const {
        return RED;
    }

    rgb_value Color::green() const {
        return GREEN;
    }

    rgb_value Color::blue() const {
        return BLUE;
    }

    //Get (mutable) references for individual RGB color channels:
    rgb_value &Color::red() {
        return RED;
    }

    rgb_value &Color::green() {
        return GREEN;
    }

    rgb_value &Color::blue() {
        return BLUE;
    }
}


// Use to read color values from a script file.
istream &operator>>(istream &input, prog::Color &c) {
    int r, g, b;
    input >> r >> g >> b;
    c.red() = r;
    c.green() = g;
    c.blue() = b;
    return input;
}

std::ostream &operator<<(std::ostream &output, const prog::Color &c) {
    output << (int) c.red() << ":" << (int) c.green() << ":" << (int) c.blue();
    return output;
}
