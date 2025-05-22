#include "Command/Scaleup.hpp"
#include <Command.hpp>
#include "Image.hpp"
#include "Color.hpp"

namespace prog {

    namespace command {

        Scaleup::Scaleup(int X, int Y) : Command("move"), X(X), Y(Y){}

        Scaleup::~Scaleup(){}


        //CHAT
        Image* Scaleup::apply(Image* img) //img -> inicialização da Classe IMAGE.
        {
            int width = img->width();
            int height = img->height();

            Image* resultado = new Image(width*X, height*Y);//Nova imagem com largura X vezes maior que a original e altura Y vezes maior que a original.

            //Primeiro vem as linhas
            for (int y = 0; y < height; y++){//Acessa as linhas.
                for (int x = 0; x < width; x++){//Acessa as colunas de uma certa linha.
                    Color& pixel = img->at(x, y);//Pixel da posição (x,y) da imagem original
                //Como cada pixel aumentou (x*X,y*Y) é preciso pintar seu "novo bloco" de pixels.
                    for (int y_bloco = 0; y_bloco < Y; y_bloco++)//Acessa as linhas.
                    {
                        for (int x_bloco = 0; x_bloco < X; x_bloco++)//Acessa as colunas de uma certa linha.
                        {
                            resultado->at(x*X+x_bloco, y*Y+y_bloco) = pixel;//Pinta cada linha e coluna de desse bloco com a cloar do pixel original.

                        }
                    }
                }
            }
            return resultado;//Retorna uma nova imagem.
        }
    }
}