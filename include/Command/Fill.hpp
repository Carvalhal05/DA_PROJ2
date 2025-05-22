//
// Created by anacc on 12/05/2025.
//

#ifndef FILL_H
#define FILL_H

#include "Command.hpp"
#include "Color.hpp"

namespace prog {
    typedef unsigned char rgb_value;

    namespace command {
        class Fill : public Command {
        public:

            Fill(int w, int h, int X, int Y, Color fill);//Constructor.
            ~Fill();//Destructor.
            Image *apply(Image *img) override;//AQUI É FEITA A TRANSFORMAÇÃO DAS IMAGENS.

        private:
            int X,Y,w,h; //Ordem do input.
            Color fill; //Conceito inspirado no command Blank.
        };
    }
}

#endif //FILL_H
