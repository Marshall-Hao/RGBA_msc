// if not defined, then will define otherwise use the current one
#ifndef RGBA_H_
#define RGBA_H_

struct RGBA
{
    unsigned char r=0;
    unsigned char g=0;
    unsigned char b=0;
    unsigned char a=255;
    // * to initialize the object structure
    RGBA() = default;
    // * take four parameter r g b a, and the data type is unsigned char
    RGBA(unsigned char _r, unsigned char _g, unsigned char _b ,unsigned char _a)
    : r{_r}, g{_g}, b{_b}, a{_a} {};

    void set(unsigned char _r, unsigned char _g,  unsigned char _b,  unsigned char _a) 
    {
        r=_r;
        g=_g;
        b=_b;
        a=_a;
    }

    //  * It ensures that the value falls within the specified range and returns the clamped value. 
    void clamp(unsigned char _min, unsigned char _max)
    {
        // * build-in clamp function introduced in c++17
        r = std::clamp(r,_min, _max);
        g = std::clamp(g,_min, _max);
        b = std::clamp(b,_min, _max);
        a = std::clamp(a,_min, _max);
    }
};

#endif