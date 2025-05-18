#ifndef DEBUG_H
#define DEBUG_H

#include <fmt/format.h>

namespace dbg 
{
    template <typename T>
    inline void outputColor(const T& col) 
    {
        std::cout << "Color RGB:\n"
                  << "Red: "   << static_cast<unsigned int>(col.r) << '\n'
                  << "Green: " << static_cast<unsigned int>(col.g) << '\n'
                  << "Blue: "  << static_cast<unsigned int>(col.b) << '\n'
                  << "Alpha: " << static_cast<unsigned int>(col.a) << '\n'; 
    }
}

#endif