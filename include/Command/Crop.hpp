#ifndef CROP_H
#define CROP_H

#include "Command.hpp"
#include "Color.hpp"
using namespace std;

namespace prog {
    namespace command {
        class Crop : public Command
        {
        public:

            Crop(int X, int Y,int w, int h); //Constructor.
            ~Crop();//Destructor.
            Image *apply(Image *img) override; // AQUI É FEITA A TRANSFORMAÇÃO DAS IMAGENS.
            int valor_min(int x, int y); // Função para encontrar o valor minimo

        private:
            int X,Y,w,h;

        };
    }
}

#endif //CROP_H
