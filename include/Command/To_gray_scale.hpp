//
// Created by anacc on 12/05/2025.
//

#ifndef TO_GRAY_SCALE_H
#define TO_GRAY_SCALE_H

#include "Command.hpp"
#include "Color.hpp"
using namespace std;

namespace prog {
    typedef unsigned char rgb_value;
    namespace command {
        class To_gray_scale : public Command
        {
        public:

            To_gray_scale(); //Constructor.
            ~To_gray_scale(); //Destructor.
            Image *apply(Image *img) override; //AQUI É FEITA A TRANSFORMAÇÃO DAS IMAGENS.
        };
    }
}

#endif //TO_GRAY_SCALE_H
