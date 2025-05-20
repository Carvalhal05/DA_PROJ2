//
// Created by anacc on 12/05/2025.
//

#ifndef REPLACE_H
#define REPLACE_H

#include "Command.hpp"
#include "Color.hpp"
#include <string>

namespace prog {
    typedef unsigned char rgb_value;

    namespace command {
        class Replace : public Command {
        public:

            Replace(Color &fill, Color &fill_R); //Constructor.
            ~Replace(); //Destructor.
            Image *apply(Image *img) override; //AQUI É FEITA A TRANSFORMAÇÃO DAS IMAGENS.

        private:
            Color fill, fill_R; //Conceito inspirado no command Blank.
        };
    }
}

#endif //REPLACE_H
