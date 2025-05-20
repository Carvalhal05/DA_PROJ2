//
// Created by anacc on 12/05/2025.
//
#include "Command/Replace.hpp"
#include "Image.hpp"
#include "Color.hpp"

namespace prog {

    namespace command {

        Replace::Replace(Color &fill, Color &fill_R) : Command("Replace"), fill(fill), fill_R(fill_R) {}

        Replace::~Replace(){}

        Image* Replace::apply(Image* img) //img -> inicialização da Classe IMAGE.
        {
            int w = img->width();
            int h = img->height();

            //Primeiro vem a linhas.

            for (int y = 0; y < h; y++){ //Acessa as linhas.
                for (int x = 0; x < w; x++){ //Acessa as colunas de uma certa linha.
                    Color& pixel = img->at(x, y); //Pega o pixel da imagem na posição (x,y)
                    //fill -> Representa os valores (RGB) que devem ser trocados.
                    if (pixel.red()== fill.red() && pixel.green()== fill.green() && pixel.blue()== fill.blue()) //Procura na imagem original os valores RGB que devem ser trocados.
                    {
                        //fill_R -> Representa os novos valores RGB.
                        pixel.red()= fill_R.red(); //Altera o valor dos pixels.
                        pixel.green()= fill_R.green(); //Altera o valor dos pixels.
                        pixel.blue()= fill_R.blue(); //Altera o valor dos pixels.
                    }
                }
            }
            return img;//Retorna a nova imagem.
        }
    }
}