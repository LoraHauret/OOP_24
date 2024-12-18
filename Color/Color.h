#pragma once
// #include "Color.h"
#include <iostream>
#include <bitset>
#include <math.h>
#include <string>

using namespace std;

class Color
{
private:
    Color();
    
public:
    struct RGB
    {
	unsigned char red;	  //  
	unsigned char green;      // 0 - 255
	unsigned char blue;	  // 
	explicit operator std::string() const
	{
	    string ret = "RGB color model:RGB\nR: " + to_string(red) + "\nG: " + to_string(green) + "\nB: " + to_string(blue) + "\n";
	    return ret;
	}
	//friend ostream& operator<<(ostream& os, const RGB&);
    };
    struct CMYK
    {
	float cyan;		  // 
	float magenta;	          //  0% - 100%
	float yellow;	          // 
	float black;	          // 
	explicit operator std::string() const
	{
	    string ret = "CMYK color model:CMYK\nCyan:  \t" + to_string(cyan) + "%\nMagenta:" + to_string(magenta) + "%\n Yellow:\t" + to_string(yellow) + "%\nBlack: \t" + to_string(black) + "%\n";
	    return ret;
	}
	//friend ostream& operator<<(ostream& os, const CMYK&);
    };
    struct HSL
    {
	unsigned short hue;   //  Оттенок от 0 до 360	   
	float saturation;	  //  Насыщенность 0% - 100%
	float brightness;	  //  Яркость 0% - 100% 
	explicit operator std::string() const
	{
	    string ret = "HSL color model:HSL\nHue:\t\t" + to_string((short)hue) + to_string((char)248) + "\nSaturation:\t" + to_string(roundf(saturation * 100)) + "%\nBrightness:\t" + to_string(roundf(brightness * 100)) + "%\n";
	    return ret;
	}
	//friend ostream& operator<<(ostream& os, const HSL&);
    };
    struct HSV
    {
	unsigned short hue;   //  Оттенок от 0 до 360	
	float saturation;	  //  Насыщенность 0% - 100%
	float value;
	explicit operator std::string() const
	{
	    string ret = "HSL color model: HSV\nHue:\t\t" + to_string((short)hue) + to_string((char)248) + "\nSaturation:\t" + to_string(roundf(saturation * 100)) + "%\nValue:\t" + to_string(roundf(value * 100)) + "%\n";
	    return ret;
	}
	// friend ostream& operator << (ostream & os, const HSV&);
	    
    };

    union ColorModel
    {
	RGB rgb;
	CMYK cmyk;
	HSL hsl;
	HSV hsv;
    };

    static float max(float& a, float& b)
    {
	return a > b ? a : b;
    }
    static float max(float& a, float& b, float& c)
    {
	float m = max(a, b);
	return max(m, c);
    }
    static float min(float& a, float& b)
    {
	return a < b ? a : b;
    }
    static float min(float& a, float& b, float& c)
    {
	float m = min(a, b);
	return min(m, c);
    }

private:
    static int count;
    ColorModel* color_model;    
    float opacity;   	  //  Прозрачность  0% - 100%    
    float tint;           //  тон  0% - 100%   
    char model_flag;      // флаг для понимания, какая именно цветовая модель используется 1 установленный бит - ргб, 2 бит - cmyk, 3 бит - hsl, 4 бит - hsv

    bool is_RGB_valid(unsigned char val);
    bool is_hue_valid(unsigned short);
    bool is_saturation_valid(int);
    bool is_saturation_valid(float);
    bool is_brightness_valid(int);
    bool is_brightness_valid(float);
    bool is_value_valid(int);
    bool is_value_valid(float);
    //bool is_CMYK_valid(size_t);
    bool is_CMYK_valid(float);

    RGB* hsl_to_rgb();
    RGB* hsv_to_rgb();
    HSL* rgb_to_hsl();
    HSL* hsv_to_hsl();
    HSV* rgb_to_hsv();
    HSV* hsl_to_hsv();
    CMYK* rgb_to_cmyk();
    CMYK* hsv_to_cmyk();
    CMYK* hsl_to_cmyk();

    void set_opacity(float);
    void set_tint(float);
    void set_RGB(Color::RGB);
    void set_CMYK(Color::CMYK);
    void set_HSL(Color::HSL);
    void set_HSV(Color::HSV);
public:
    Color(RGB, float, float);
    Color(CMYK, float, float);
    Color(HSL, float, float);
    Color(HSV, float, float);
    Color(const Color& other);
    Color(Color&& other);
    ~Color();
    Color& operator=(const Color& other);
    explicit operator std::string() const;

    RGB* GetRGB();
    CMYK* GetCMYK();
    HSL* GetHSL();
    HSV* GetHSV();
    short GetColorModel();
    int GetClassCount() { return Color::count; }

    void SetRGB(const unsigned char&, const unsigned char&, const unsigned char&);
    void SetCMYK(const float&, const float&, const float&, const float&);
    void SetHSL(const unsigned short&, const float&, const float&);
    void SetHSV(const unsigned short&, const float&, const float&);

    bool operator==(const Color& other);
    bool operator!=(const Color& other);
    bool operator<(const  Color& other);
    bool operator>(const  Color& other);
    bool operator<=(const Color& other);
    bool operator>=(const Color& other);
    //friend ostream& operator<<(ostream& os, const Color&);
};
