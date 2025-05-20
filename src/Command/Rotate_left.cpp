#include "Command/Rotate_left.hpp"
#include "Image.hpp"
#include "Color.hpp"

namespace prog {

    namespace command {

        Rotate_left::Rotate_left() : Command("Rotate_left"){}
        Rotate_left::~Rotate_left(){}

        Image* Rotate_left::apply(Image* img)
        {
            int w = img->width(); //Largura da imagem original.
            int h = img->height(); //Altura da imagem original.
            //Nova imagem:
            Image* result = new Image(h, w); //Como a imagem roda 90 graus para a esquerda seus dimensões  trocam.

            //Primeiro vem as linhas.
            for (int y = 0; y < h; y++) //Acessa as linhas.
            {
                for (int x = 0; x < w; x++) //Acessa as colunas de uma certa linha.
                {
                    Color& pixel = img->at(x, y); // Pega o pixel da imagem na posição (x,y).
                    result->at(y, w - 1 - x) = pixel; //Coloca na sua nova posição o pixel da posição antiga.
                }
            }

            return result;//Retorna uma nova imagem.
        }
    }
}