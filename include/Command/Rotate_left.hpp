#ifndef ROTATE_LEFT_H
#define ROTATE_LEFT_H

#include "Command.hpp"
#include "Color.hpp"
using namespace std;

namespace prog {
    namespace command {
        class Rotate_left : public Command
        {
        public:

            Rotate_left();//Constructor.
            ~Rotate_left();//Destructor.
            Image *apply(Image *img) override;//AQUI É FEITA A TRANSFORMAÇÃO DAS IMAGENS.

        };
    }
}

#endif //ROTATE_LEFT_H