//
// Created by anacc on 12/05/2025.
//
#include "Command/Fill.hpp"
#include "Image.hpp"
#include "Color.hpp"

namespace prog {

    namespace command {

        Fill::Fill(int X, int Y, int w, int h, Color fill) : Command("Fill"), X(X), Y(Y), w(w), h(h), fill(fill) {} //Constructor.

        Fill::~Fill(){} //Destructor.

        Image* Fill::apply(Image* img) //img -> Inicialização da Classe IMAGE.
        {
            int W = img->width();
            int H = img->height();

            //Primeiro vem as linhas.
            for (int y = Y; y < Y+h; y++) //y <= y' < y + h
            {
                for (int x = X; x < X+w; x++) //x <= x' < x + w
                {
                    if (x >= 0 && x < W && y >= 0 && y < H) //Verifica se a imagem está dentro do  esperado (largura e altura).
                    {
                        Color& pixel = img->at(x, y);//Pega o pixel da imagem na posição (x,y).
                        pixel.red()= fill.red();
                        pixel.green()= fill.green();
                        pixel.blue()= fill.blue();
                        //Acessa o pixel da determinada posição e altera seus valores.
                    }
                }
            }
            return img; //Retorna uma nova imagem.
        }
    }
}