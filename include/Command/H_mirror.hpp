//
// Created by anacc on 12/05/2025.
//

#ifndef H_MIRROR_H
#define H_MIRROR_H

#include "Command.hpp"
#include "Color.hpp"
using namespace std;

namespace prog {
    namespace command {
        class H_mirror : public Command
        {
        public:

            H_mirror(); //Constructor.
            ~H_mirror(); //Destructor.
            Image *apply(Image *img) override; //AQUI É FEITA A TRANSFORMAÇÃO DAS IMAGENS.
        };
    }
}

#endif //H_MIRROR_H
