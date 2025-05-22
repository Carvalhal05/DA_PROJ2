//
// Created by JBispo on 05/04/2025.
//
#include "ScrimParser.hpp"

#include "Command/Blank.hpp"
#include "Command/Save.hpp"
#include "Command/Open.hpp"
#include "Command/Invert.hpp"
#include "Command/To_gray_scale.hpp"
#include "Command/Replace.hpp"
#include "Command/Fill.hpp"
#include "Command/H_mirror.hpp"
#include "Command/V_mirror.hpp"
#include "Command/Add.hpp"
#include "Command/Move.hpp"
#include "Command/Slide.hpp"
#include "Command/Crop.hpp"
#include "Command/Resize.hpp"
#include "Command/Rotate_left.hpp"
#include "Command/Rotate_right.hpp"
#include "Command/Scaleup.hpp"
#include "Command/Chain.hpp"
#include "Logger.hpp"

#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>

using std::ifstream;
using std::istream;
using std::string;
using std::vector;

namespace prog {
    ScrimParser::ScrimParser() {
    };

    ScrimParser::~ScrimParser() {
    };


    Scrim *ScrimParser::parseScrim(std::istream &input) {
        // Create vector where commands will be stored
        vector<Command *> commands;

        // Parse commands while there is input in the stream
        string command_name;
        while (input >> command_name) {
            Command *command = parse_command(command_name, input);

            if (command == nullptr) {
                // Deallocate already allocated commands
                for (Command *allocated_command: commands) {
                    delete allocated_command;
                }


                *Logger::err() << "Error while parsing command\n";
                return nullptr;
            }

            commands.push_back(command);
        }

        // Create a new image pipeline
        return new Scrim(commands);
    }


    Scrim *ScrimParser::parseScrim(const std::string &filename) {
        ifstream in(filename);
        return parseScrim(in);
    }

    Command *ScrimParser::parse_command(string command_name, istream &input) {
        if (command_name == "blank") {
            // Read information for Blank command
            int w, h;
            Color fill;
            input >> w >> h >> fill;
            return new command::Blank(w, h, fill);
        }

        if (command_name == "save") {
            // Read information for Save command
            string filename;
            input >> filename;
            return new command::Save(filename);
        }

        if (command_name == "open") {
            string filename;
            input >> filename;
            return new command::Open(filename);
        }

        // TODO: implement cases for the new commands

        if (command_name == "invert")
        {
            return new command::Invert();
        }

        if (command_name == "to_gray_scale")
        {
            return new command::To_gray_scale();
        }

        if (command_name == "replace")
        {
            Color fill, fill_R;
            input >> fill >> fill_R;
            return new command::Replace(fill, fill_R);
        }

        if (command_name == "fill")
        {
            int w,h,X,Y;
            Color fill;
            input >> X >> Y >> w >> h>> fill;
            return new command::Fill(X,Y,w,h,fill);
        }

        if (command_name == "h_mirror")
        {
            return new command::H_mirror();
        }

        if (command_name == "v_mirror")
        {
            return new command::V_mirror();
        }

        if (command_name == "add")
        {
            string filename;
            Color fill;
            int X,Y;
            input >> filename;
            input >> fill;
            input >> X >> Y;
            return new command::Add(filename, fill, X, Y);
        }

        if (command_name == "move")
        {
            int X,Y;
            input >> X >> Y;
            return new command::Move(X, Y);
        }

        if (command_name == "slide")
        {
            int X,Y;
            input >> X >> Y;
            return new command::Slide(X, Y);
        }

        if (command_name == "crop")
        {
            int X,Y,w,h;
            input >>X >> Y >> w >> h;
            return new command::Crop(X,Y,w,h);
        }

        if (command_name == "resize")
        {
            int X,Y,w,h;
            input >>X >> Y >> w >> h;
            return new command::Resize(X,Y,w,h);
        }

        if (command_name == "rotate_left")
        {

            return new command::Rotate_left();
        }

        if (command_name == "rotate_right")
        {

            return new command::Rotate_right();
        }

        if (command_name == "scaleup") {
            int X, Y;
            input >> X >> Y;
            return new command::Scaleup(X, Y);
        }

        if (command_name == "chain")
        {
            string filename;
            input >> filename;
            cout<<filename<<endl;
            while ( filename!="end")
            {
                input >> filename;
                cout<<filename<<endl;
            }

            return new command::Chain(filename);
        }

        *Logger::err() << "Command not recognized: '" + command_name + "'\n";
        return nullptr;
    }
}
