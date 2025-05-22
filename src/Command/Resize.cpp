//
// Created by anacc on 13/05/2025.
//
#include "Command/Resize.hpp"
#include "Image.hpp"
#include "Color.hpp"

namespace prog {

    namespace command
    {
        Resize::Resize(int X, int Y, int w, int h) : Command("Resize"), X(X), Y(Y), w(w), h(h){}

        Resize::~Resize(){}

        Image* Resize::apply(Image* img) //img -> inicialização da Classe IMAGE.
        {
            int w_img = img->width(); //Tamanho da largura da figura original.
            int h_img = img->height(); //Tamanho da altura da figura original.

            Image* resultado = new Image(w,h); //Nova imagem.
            Color& fill = img->at(0,0); //Fill color da imagem img.

            //Primeiro vem a altura(linhas).
            for (int y = 0;y < h; y++){//Percore toda a nova altura da imagem (linhas).
                for (int x = 0; x < w; x++){//Percore toda a nova largura da imagem (colunas).
                    if (x+X>=X && y+Y>=Y && x+X<w_img && y+Y<h_img)//Verifica se o pixel(x+X,y+Y) pertence a dimensão da imagem original.
                    {
                        Color& pixel = img->at(x+X,y+Y); //Pega a cor do pixel(x+X,y+Y) da imagem original.
                        resultado->at(x,y) = pixel; //Coloca no pixel(x,y) da nova imagem a cor da imagem original.
                        //Aqui não tem x+X e y+Y porque estamos colocando nos "pixels iniciais" da nova imagem.
                    }else
                    {
                        resultado->at(x,y) = fill;//Caso o pixel(x+X,y+Y) não pertença a imagem original, o pixel(x,y) da nova imagem vai ser preenchido com a color fill.
                    }
                }
            }
            return resultado;//Retorna a nova imagem.
        }
    }
}

