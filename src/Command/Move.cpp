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
            int width = img->width();
            int height = img->height();
            Image* resultado= new Image(width, height);//Cria uma nova imagem result igual a imagem img.

            //Primeiro vem as linhas.
            for (int y = 0; y < height; y++){//Acessa as linhas.
                for (int x = 0; x < width; x++){//Acessa as colunas de uma certa linha.
                    Color& pixel = img->at(x,y);//Pega o pixel da imagem img na posição (x,y).
                    int novo_width = x + X; //Deslocamento do W.
                    int novo_height = y + Y; //Deslocamento do H.
                    if (novo_width >=0 && novo_height >= 0 && novo_width < width && novo_height < height) //Garante que o deslocamento está dentro dos limites da imagem.
                    {
                        resultado->at(novo_width,novo_height) = pixel; // Altera a cor daquele pixel na sua nova posição após o deslocamento.
                    }
                }
            }
            return resultado;//Retorna a nova imagem.
        }
    }
}
