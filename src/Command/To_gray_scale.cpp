//
// Created by anacc on 12/05/2025.
//
#include "Command/To_gray_scale.hpp"
#include "Command/Invert.hpp"
#include "Image.hpp"
#include "Color.hpp"

namespace prog {

    namespace command {

        To_gray_scale::To_gray_scale() : Command("To_gray_scale") {}

        To_gray_scale::~To_gray_scale(){}

        Image* To_gray_scale::apply(Image* img) //img -> inicialização da Classe IMAGE
        {
            int w = img->width();
            int h = img->height();

            //Primeiro vem as linhas.
            for (int y = 0; y < h; y++) //Acessa as linhas.
            {
                for (int x = 0; x < w; x++) //Acessa as colunas de uma certa linha.
                {
                    Color& pixel = img->at(x, y); //Pega o pixel da imagem na posição (x,y).
                    rgb_value v = 0;
                    rgb_value r = pixel.red();
                    rgb_value g = pixel.green();
                    rgb_value b = pixel.blue();
                    v = (rgb_value)((r+g+b)/3); //Calcula o novo valor
                    pixel.red() = v; //Modifica o valor do pixel vermelho para o novo valor.
                    pixel.green() = v; //Modifica o valor do pixel verde para o novo valor.
                    pixel.blue() = v; //Modifica o valor do pixel azul para o novo valor.
                }
            }
            return img; //Retorna a nova imagem.
        }





    }
}