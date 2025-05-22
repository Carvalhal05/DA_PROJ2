#include "Command/Rotate_right.hpp"
#include "Image.hpp"
#include "Color.hpp"

namespace prog {

    namespace command {

        Rotate_right::Rotate_right() : Command("Rotate_right"){}
        Rotate_right::~Rotate_right(){}

        Image* Rotate_right::apply(Image* img)
        {
            int width = img->width();//Largura da imagem original.
            int height = img->height();//Altura da imagem original.
            Image* resultado = new Image(height, width); //Como a imagem roda 90 graus para a direita seus dimensões  trocam.

            for (int y = 0; y < height; y++){//Acessa as linhas.
                for (int x = 0; x < width; x++){//Acessa as colunas de uma certa linha.
                    Color& pixel = img->at(x,y);//Pega o pixel da imagem na posição (x,y).
                    resultado->at(height-1-y,x) = pixel;//Coloca na sua nova posição o pixel da posição antiga.
                    //https://pt.stackoverflow.com/questions/136858/girar-imagem-ppm-em-90-graus-em-c (fórmula)
                }
            }
            return resultado;//Retorna uma nova imagem
        }
    }
}