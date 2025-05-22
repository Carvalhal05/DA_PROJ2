//
// Created by anacc on 12/05/2025.
//

#include "Command/H_mirror.hpp"
#include "Image.hpp"
#include "Color.hpp"

namespace prog {

    namespace command {

        H_mirror::H_mirror() : Command("H_mirror") {}

        H_mirror::~H_mirror() {}

        Image* H_mirror::apply(Image* img) //img -> inicialização da Classe IMAGE.
        {
            int width = img->width();
            int height = img->height();

            //Primeiro vem as linhas.
            for (int y = 0; y < height; y++)
            {
                for (int x = 0; x < width/2; x++) //0 <= x < width()/2.
                {
                    Color& pixel = img->at(x, y);//Pega o pixel da imagem na posição (x,y).
                    Color& pixel_swap = img->at(width-1-x, y);//Pega o pixel da imagem na posição (w-1-x,y).
                    //Método clássico de troca
                    Color temp = pixel;
                    pixel = pixel_swap;
                    pixel_swap = temp;
                    //Troca os pixels (referência)
                }
            }
            return img;//Retorna uma nova imagem.
        }
    }
}
