//
// Created by anacc on 13/05/2025.
//

#ifndef ADD_H
#define ADD_H

#include "Command.hpp"
#include "Color.hpp"
using namespace std;

namespace prog {
    typedef unsigned char rgb_value;
    namespace command {
        class Add : public Command
        {
        public:

            Add(string filename,Color fill, int X, int Y); //Constructor.
            ~Add(); //Destructor.
            Image *apply(Image *img) override; //AQUI É FEITA A TRANSFORMAÇÃO DAS IMAGENS.
        private:
            std::string filename;
            Color fill;
            int X,Y;
        };
    }
}

#endif //ADD_H
