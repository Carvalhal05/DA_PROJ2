//
// Created by anacc on 13/05/2025.
//
#include "Command/Chain.hpp"

#include <forward_list>
#include <PNG.hpp>

#include "Image.hpp"
#include "Color.hpp"
#include "ScrimParser.hpp"

namespace prog
{
    namespace command
    {
        Chain::Chain(string filename) : Command(filename){}

        Chain::~Chain() {}


        Image* Chain::apply(Image* img)
        {
            return img;
        }



    }
}