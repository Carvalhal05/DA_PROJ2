//
// Created by anacc on 13/05/2025.
//

#ifndef RESIZE_H
#define RESIZE_H

#include "Command.hpp"
#include "Color.hpp"
using namespace std;

namespace prog {
    namespace command {
        class Resize : public Command
        {
        public:

            Resize(int X, int Y,int w, int h); // constructor.
            ~Resize(); // Destructor.
            Image *apply(Image *img) override; // AQUI É FEITA A TRANSFORMAÇÃO DAS IMAGENS.
        private:
            int X,Y,w,h;

        };
    }
}

#endif //RESIZE_H
