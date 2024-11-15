#pragma once
#include "Color.h"

int main()
{


    Color::RGB rgb{ 10,1,15 };
    cout << rgb << "\n";

    Color rgb_c(rgb, 1, 0);
    cout << rgb_c << "\n";

    Color::HSL* hsl = rgb_c.GetHSL();
    cout << *hsl << "\n";
    delete hsl;

    Color::HSV* hsv = rgb_c.GetHSV();
    cout << *hsv << "\n";
    delete hsv;

    Color::CMYK* cmyk = rgb_c.GetCMYK();
    cout << *cmyk << "\n";
    delete cmyk;


    rgb_c.SetRGB(33, 44, 55);
    cout << rgb_c << "\n";
    return 0;
}
