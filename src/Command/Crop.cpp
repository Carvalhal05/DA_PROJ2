#include "Command/Crop.hpp"
#include "Image.hpp"
#include "Color.hpp"

namespace prog {

    namespace command {

        Crop::Crop(int X, int Y, int w, int h) : Command("Crop"), X(X), Y(Y), w(w), h(h){}

        Crop::~Crop(){}

        int Crop::valor_min(int x, int y) //Função para econtrar o valor minimo
        {
            if (x<=y)
            {
                return x;
            }
            return y;
        }


        Image* Crop::apply(Image* img) //img -> inicialização da Classe IMAGE.
        {
            int w_img = img->width(); //Tamanho da largura da figura original.
            int h_img = img->height(); //Tamanho da altura da figura original.
            //"Top-left corner (X,Y), width w, and height h".
            int w_max = X+w; //Largura máxima.
            int h_max = Y+h; //Altura máxima.
            int w_min = valor_min(w_img,w_max); //achar o menor valor.
            int h_min = valor_min(h_img,h_max); //achar o menor valor.

            Image* result = new Image(w_min-X,h_min-Y); //A dimensão da nova imagem precisa ser o menor valor entre o "top-left corner" e a imagem original.

            //Primeiro vem as linhas
            for (int y = Y; y < h_min; y++)//Acessa as linhas.
            {
                for (int x = X; x < w_min; x++)//Acessa as colunas de uma certa linha.
                {
                    Color& pixel = img->at(x,y); //Pixel da posição (x,y) da imagem original
                    result->at(x-X,y-Y) = pixel; //A posição do novo pixel é igual ao intervalo do "top-left' com o valor menor menos o "top-left" corner (dessa maneira a imagem é reduzida).
                }
            }
            return result; //Retorna a nova imagem.
        }
    }
}