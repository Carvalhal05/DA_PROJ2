//
// Created by anacc on 13/05/2025.
//

#ifndef MOVE_H
#define MOVE_H

#include "Command.hpp"
#include "Color.hpp"
using namespace std;

namespace prog {
    namespace command {
        class Move : public Command
        {
        public:

            Move(int X, int Y);//Constructor.
            ~Move();//Destructor.
            Image *apply(Image *img) override;//AQUI É FEITA A TRANSFORMAÇÃO DAS IMAGENS.

        private:
            int X,Y;

        };
    }
}

#endif //MOVE_H
