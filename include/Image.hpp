#ifndef __prog_Image_hpp__
#define __prog_Image_hpp__

#include "Color.hpp"
#include <vector>
using namespace std;

namespace prog {
    class Image {
    private:
        // TODO: define private fields for image state
        int W,H ; //W=Width, H=Height.
        vector<vector<Color>> pixel; //2D matrix of colors with these dimensions (vetor de vetores).
    public:
        Image(int w, int h, const Color &fill = {255, 255, 255});

        ~Image();

        int width() const;

        int height() const;

        Color &at(int x, int y);

        const Color &at(int x, int y) const;
    };
}
#endif
