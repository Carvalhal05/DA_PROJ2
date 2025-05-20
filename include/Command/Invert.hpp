//
// Created by anacc on 12/05/2025.
//

#ifndef INVERT_H
#define INVERT_H

#include "Command.hpp"
#include "Color.hpp"
using namespace std;

namespace prog {
    typedef unsigned char rgb_value;
    namespace command {
        class Invert : public Command
        {
        public:

            Invert(); //Constructor.
            ~Invert(); //Destructor.
            Image *apply(Image *img) override; //AQUI É FEITA A TRANSFORMAÇÃO DAS IMAGENS.
        };
    }
}

#endif //INVERT_H
