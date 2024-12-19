#pragma once
#include "Color.h"

int main()
{


    Color::RGB rgb{ 10,1,15 };
    cout << static_cast<string> (rgb) << "\n";

    Color rgb_c(rgb, 1, 0);
    cout << static_cast<string> (rgb_c) << "\n";

    Color::HSL* hsl = rgb_c.GetHSL();
    cout << static_cast<string> (*hsl) << "\n";
    delete hsl;

    Color::HSV* hsv = rgb_c.GetHSV();
    cout << static_cast<string> (*hsv) << "\n";
    delete hsv;

    Color::CMYK* cmyk = rgb_c.GetCMYK();
    cout << static_cast<string>(*cmyk) << "\n";
    delete cmyk;


    rgb_c.SetRGB(33, 44, 55);
    cout << static_cast<string> (rgb_c) << "\n";
    return 0;
}
