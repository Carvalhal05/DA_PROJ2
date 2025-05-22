//
// Created by anacc on 12/05/2025.
//
#include "Command/Invert.hpp"
#include "Image.hpp"
#include "Color.hpp"

namespace prog {

    namespace command {

        Invert::Invert() : Command("Invert") {}

        Invert::~Invert(){}

        Image* Invert::apply(Image* img) //img -> inicialização da Classe IMAGE.
        {
            int width = img->width();
            int height = img->height();
            //Primeiro vem as linhas.
            for (int y = 0; y < height; y++){ //Acessa as linhas.
                for (int x = 0; x < width; x++){ //Acessa as colunas de uma certa linha.
                    Color& pixel = img->at(x, y); //Pega o pixel da imagem na posição (x,y).
                    pixel.red() = 255 - pixel.red(); //Inverte o vermelho.
                    pixel.green()= 255 - pixel.green(); //Inverte o verde.
                    pixel.blue() = 255 - pixel.blue(); //Inverte o azul.
                }
            }
            return img; // Retorna a nova imagem.
        }

    }
}