//
// Created by anacc on 13/05/2025.
//

#ifndef SLIDE_H
#define SLIDE_H

#include "Command.hpp"
#include "Color.hpp"
using namespace std;

namespace prog {
    namespace command {
        class Slide : public Command
        {
        public:

            Slide(int X, int Y);//Constructor.
            ~Slide();//Destructor.
            Image *apply(Image *img) override;//AQUI É FEITA A TRANSFORMAÇÃO DAS IMAGENS.

        private:
            int X,Y;

        };
    }
}

#endif //SLIDE_H
