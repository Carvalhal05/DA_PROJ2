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
        /*Chain::Chain(string filename,vector<string> stack) : Command(filename), stack(stack){}

        Chain::~Chain() {}


        Image* Chain::apply(Image* img)
        {
            return img;
        }

        Image* Chain::advanced(const string& file, Image* img, vector<string>& done)
        {
            ScrimParser parser;
            for (auto string& filename : stack)
            {
                if (filename==file)
                {

                }else
                {
                    done.push_back(filename);
                    Command* cmd = parser.parse_command("chain",filename);
                }
            }

            done.push_back(file);*/


        //}


    }
}