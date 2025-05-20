#ifndef CHAIN_H
#define CHAIN_H

#include "Command.hpp"
#include "Color.hpp"
using namespace std;

namespace prog {
    namespace command {
        class Chain : public Command
        {
        /*public:

            Chain(string filenam,vector<string> stack);//Constructor.
            ~Chain();//Destructor.
            Image *apply(Image *img) override;//AQUI É FEITA A TRANSFORMAÇÃO DAS IMAGENS.
        private:
            string filename;
            vector<string> stack;
            Image* advanced(const string& file, Image* img, vector<string>& done);*/
        };
    }
}


#endif //CHAIN_H
