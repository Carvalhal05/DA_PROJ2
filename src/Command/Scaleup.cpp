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
            int w = img->width();
            int h = img->height();

            Image* result = new Image(w*X, h*Y);//Nova imagem com largura X vezes maior que a original e altura Y vezes maior que a original.

            //Primeiro vem as linhas
            for (int y = 0; y < h; y++)//Acessa as linhas.
            {
                for (int x = 0; x < w; x++)//Acessa as colunas de uma certa linha.
                {
                    Color& pixel = img->at(x, y);//Pixel da posição (x,y) da imagem original
                //Como cada pixel aumentou (x*X,y*Y) é preciso pintar seu "novo bloco".
                    for (int dy = 0; dy < Y; dy++)//Acessa as linhas.
                    {
                        for (int dx = 0; dx < X; dx++)//Acessa as colunas de uma certa linha.
                        {
                            result->at(x*X+dx, y*Y+dy) = pixel;//Pinta cada linha e coluna de desse bloco com a cloar do pixel original.

                        }
                    }
                }
            }
            return result;//Retorna uma nova imagem.
        }
    }
}