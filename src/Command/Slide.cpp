//
// Created by anacc on 13/05/2025.
//
#include "Command/Slide.hpp"
#include "Image.hpp"
#include "Color.hpp"

namespace prog {

    namespace command {

        Slide::Slide(int X, int Y) : Command("move"), X(X), Y(Y){}

        Slide::~Slide(){}

        Image* Slide::apply(Image* img) //img -> inicialização da Classe IMAGE.
        {
            int w = img->width();
            int h = img->height();
            Image* result = new Image(w, h); //Cria uma nova imagem result igual a imagem img.

            //Primeiro vem as linhas.
            for (int y = 0; y < h; y++)//Acessa as linhas.
            {
                for (int x = 0; x < w; x++)//Acessa as colunas de uma certa linha.
                {
                    Color& pixel = img->at(x,y); //Pixel da posição (x,y) da imagem original
                    int novo_w = (x + X) % w; //Deslocamento do W
                    int novo_h = (y + Y) % h; //Deslocamento do H
                    Color& pixel_2 = img->at(novo_w,novo_h); //Pixel da nova posição após o deslocamento (ainda na imagem original).
                    result->at(novo_w,novo_h) = pixel; //Pega o pixel da posição (x,y) da imagem original  e coloca na nova posição da nova imagem.
                    result->at(x,y) = pixel_2; //Pega o pixel da posição deslocada da imagem original e coloca no sua nova posição da nova imagem.
                }
            }
            return result;//Retorna a nova imagem.
        }
    }
}