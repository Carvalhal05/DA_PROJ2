#include "Command/Rotate_left.hpp"
#include "Image.hpp"
#include "Color.hpp"

namespace prog {

    namespace command {

        Rotate_left::Rotate_left() : Command("Rotate_left"){}
        Rotate_left::~Rotate_left(){}

        Image* Rotate_left::apply(Image* img)
        {
            int width = img->width(); //Largura da imagem original.
            int heigth = img->height(); //Altura da imagem original.
            //Nova imagem:
            Image* resultado = new Image(heigth, width); //Como a imagem roda 90 graus para a esquerda seus dimensões  trocam.

            //Primeiro vem as linhas.
            for (int y = 0; y < heigth; y++) //Acessa as linhas.
            {
                for (int x = 0; x < width; x++) //Acessa as colunas de uma certa linha.
                {
                    Color& pixel = img->at(x, y); // Pega o pixel da imagem na posição (x,y).
                    resultado->at(y, width - 1 - x) = pixel; //Coloca na sua nova posição o pixel da posição antiga.
                    //https://pt.stackoverflow.com/questions/136858/girar-imagem-ppm-em-90-graus-em-c (fórmula)
                }
            }
            return resultado;//Retorna uma nova imagem.
        }
    }
}