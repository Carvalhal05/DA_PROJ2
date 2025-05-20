#ifndef ROTATE_RIGHT_H
#define ROTATE_RIGHT_H

#include "Command.hpp"
#include "Color.hpp"
using namespace std;

namespace prog {
    namespace command {
        class Rotate_right : public Command
        {
        public:

            Rotate_right(); // constructor.
            ~Rotate_right(); // Destructor.
            Image *apply(Image *img) override; // AQUI É FEITA A TRANSFORMAÇÃO DAS IMAGENS.
        };
    }
}

#endif //ROTATE_RIGHT_H

