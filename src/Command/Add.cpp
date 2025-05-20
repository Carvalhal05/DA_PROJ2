//
// Created by anacc on 13/05/2025.
//
#include "Command/Add.hpp"

#include <PNG.hpp>

#include "Image.hpp"
#include "Color.hpp"

namespace prog
{
    namespace command
    {
        Add::Add(string filename,Color fill, int X, int Y): Command("Add"), filename(filename),fill(fill), X(X), Y(Y) {}

        Add::~Add(){}


        Image* Add::apply(Image* img) //img -> inicialização da Classe IMAGE.
        {
            Image* png = loadFromPNG(filename); //Conceito obtido através da classe Open.cpp.
            //Tamanho da imagem png.
            int w_png = png->width();
            int h_png = png->height();
            //Tamanho da nova imagem.
            int w_img = img->width();
            int h_img = img->height();

            //Primeiro vem as linhas.

            for (int y = 0; y < h_png; y++){//Acessa as linhas (Imagem original (png)).
                for (int x = 0; x < w_png; x++){//Acessa as colunas de uma certa linha (Imagem original (png)).
                    Color& pixel = png->at(x, y);//Pega o pixel da imagem png na posição (x,y).
                    if (pixel.red() == fill.red() && pixel.green() == fill.green() && pixel.blue() == fill.blue()) // Verifica se a existencia de pixels com a "neutral color".
                    {

                    }else
                    {
                        //X e Y = (x,y) top-left corner
                        int w = X+x; //Distância do novo pixel (horizontal).
                        int h = Y+y; //Distância do novo pixel (vertical).
                        if (w>=0 && w<w_img && h>=0 && h<h_img) //Verifica se o novo pixel está dentro dos limites.
                        {
                            img->at(w,h) = pixel; //Coloca no posiçao (w,h) a cor do pixel da imagem png na nova imagem img.
                        }
                    }
                }
            }
            return img; //Retorna a nova imagem
        }
    }
}