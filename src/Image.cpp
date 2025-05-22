#include "Image.hpp"

using namespace std;

namespace prog {
    Image::Image(int w, int h, const Color &fill) {
        W=w; //W=Width.
        H=h; //H=Height.
        pixel = vector<vector<Color>>(H, vector<Color>(W, fill));//H linhas,W colunas e preencha todas as posições com a cor fill. https://www.geeksforgeeks.org/2d-vector-in-cpp-with-user-defined-size/.
    }


    Image::~Image() {
    } //will won´t use

    int Image::width() const {
        return W; //Get image width.
    }

    int Image::height() const {
        return H; //Get image height.
    }

    Color &Image::at(int x, int y)
    {
        //X->Largura Y-> altura (Ver Figura 2).
        if (x < 0 || x >= W || y < 0 || y >= H){ //Fora dos limites da imagem.
            exit (EXIT_FAILURE); //https://cplusplus.com/reference/cstdlib/exit/.
        }
        return pixel[y][x]; //Primeiro vem as linhas(H) (Matriz).
    }

    const Color &Image::at(int x, int y) const { //X->Largura Y-> altura (Ver Figura 2)
        return pixel[y][x]; //Primeiro vem as linhas(H) (Matriz).
    }
}
