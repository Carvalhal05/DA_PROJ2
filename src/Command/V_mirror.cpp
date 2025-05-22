//
// Created by anacc on 15/05/2025.
//
//
// Created by anacc on 12/05/2025.
//
#include "Command/V_mirror.hpp"
#include "Image.hpp"
#include "Color.hpp"

namespace prog {

    namespace command {

        V_mirror::V_mirror() : Command("H_mirror") {}

        V_mirror::~V_mirror() {}

        Image* V_mirror::apply(Image* img) //img -> inicialização da Classe IMAGE.
        {
            int width = img->width();
            int height = img->height();

            //As linhas vem primeiro.
            for (int y = 0; y < height/2; y++) //0 <= y < height()/2
            {
                for (int x = 0; x < width; x++)
                {
                    Color& pixel = img->at(x, y);//Pega o pixel da imagem na posição (x,y).
                    Color& pixel_swap = img->at(x, height-y-1);//Pega o pixel da imagem na posição (x,h-1-y).
                    //Método clássico de troca
                    Color temp = pixel;
                    pixel = pixel_swap;
                    pixel_swap = temp;
                    //Troca os pixels (referência)
                }
            }
            return img; //Retorna uma nova imagem.
        }
    }
}