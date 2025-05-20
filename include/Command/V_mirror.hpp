//
// Created by anacc on 12/05/2025.
//

#ifndef V_MIRROR_H
#define V_MIRROR_H

#include "Command.hpp"
#include "Color.hpp"
using namespace std;

namespace prog {
    namespace command {
        class V_mirror : public Command
        {
        public:

            V_mirror();//Constructor.
            ~V_mirror();//Destructor.
            Image *apply(Image *img) override;//AQUI É FEITA A TRANSFORMAÇÃO DAS IMAGENS.
        };
    }
}

#endif //V_MIRROR_H
