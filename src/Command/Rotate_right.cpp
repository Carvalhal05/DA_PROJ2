#include "Command/Rotate_right.hpp"
#include "Image.hpp"
#include "Color.hpp"

namespace prog {

    namespace command {

        Rotate_right::Rotate_right() : Command("Rotate_right"){}
        Rotate_right::~Rotate_right(){}

        Image* Rotate_right::apply(Image* img)
        {
            int w = img->width();//Largura da imagem original.
            int h = img->height();//Altura da imagem original.
            Image* result = new Image(h, w); //Como a imagem roda 90 graus para a direita seus dimensões  trocam.

            for (int y = 0; y < h; y++)//Acessa as linhas.
            {
                for (int x = 0; x < w; x++)//Acessa as colunas de uma certa linha.
                {
                    Color& pixel = img->at(x,y);//Pega o pixel da imagem na posição (x,y).
                    result->at(h-1-y,x) = pixel;//Coloca na sua nova posição o pixel da posição antiga.
                }
            }


            return result;//Retorna uma nova imagem
        }
    }
}