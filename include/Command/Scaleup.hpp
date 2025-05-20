#ifndef SCALEUP_H
#define SCALEUP_H

#include "Command.hpp"
#include "Color.hpp"

using namespace std;

namespace prog {
    namespace command {
        class Scaleup : public Command
        {
        public:

            Scaleup(int X, int Y); //Constructor.
            ~Scaleup(); //Destructor.
            Image *apply(Image *img) override; //AQUI É FEITA A TRANSFORMAÇÃO DAS IMAGENS.

        private:
            int X,Y;
        };
    }
}

#endif //SCALEUP_H
