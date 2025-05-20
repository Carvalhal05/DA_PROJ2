//
// Created by anacc on 13/05/2025.
//
#include "Command/Move.hpp"
#include "Image.hpp"
#include "Color.hpp"

namespace prog {

    namespace command {

        Move::Move(int X, int Y) : Command("move"), X(X), Y(Y){}

        Move::~Move(){}

        Image* Move::apply(Image* img){ //img -> inicialização da Classe IMAGE.
            int w = img->width();
            int h = img->height();
            Image* result= new Image(w, h);//Cria uma nova imagem result igual a imagem img.

            //Primeiro vem as linhas.
            for (int y = 0; y < h; y++){//Acessa as linhas.
                for (int x = 0; x < w; x++){//Acessa as colunas de uma certa linha.
                    Color& pixel = img->at(x,y);//Pega o pixel da imagem img na posição (x,y).
                    int novo_w = x + X; //Deslocamento do W.
                    int novo_h = y + Y; //Deslocamento do H.
                    if (novo_w >=0 && novo_h >= 0 && novo_w < w && novo_h < h) //Garante que o deslocamento está dentro dos limites da imagem.
                    {
                        result->at(novo_w,novo_h) = pixel; // Altera a cor daquele pixel na sua nova posição após o deslocamento.
                    }
                }
            }
            return result;//Retorna a nova imagem.
        }
    }
}
