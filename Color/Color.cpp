#pragma once
// #include "Color.h"
#include <iostream>
#include <bitset>
#include <math.h>
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

	friend ostream& operator<<(ostream& os, const RGB&);
    };
    struct CMYK
    {
	float cyan;		  // 
	float magenta;	          //  0% - 100%
	float yellow;	          // 
	float black;	          // 
	friend ostream& operator<<(ostream& os, const CMYK&);
    };
    struct HSL
    {
	unsigned short hue;   //  Оттенок от 0 до 360	   
	float saturation;	  //  Насыщенность 0% - 100%
	float brightness;	  //  Яркость 0% - 100% 
	friend ostream& operator<<(ostream& os, const HSL&);
    };
    struct HSV
    {
	unsigned short hue;   //  Оттенок от 0 до 360	
	float saturation;	  //  Насыщенность 0% - 100%
	float value;
	friend ostream& operator<<(ostream& os, const HSV&);
    };

    union ColorModel
    {
	RGB rgb;
	CMYK cmyk;
	HSL hsl;
	HSV hsv;
    };

public: //private:
    ColorModel* color_model;
    float opacity;   	  //  Прозрачность  0% - 100%    
    float tint;           //  тон  0% - 100%   
    char model_flag;      // флаг для понимания, какая именно цветовая модель используется 1 установленный бит - ргб, 2 бит - cmyk, 3 бит - hsl, 4 бит - hsv
public:
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
    RGB* hsl_to_rgb();
    RGB* hsv_to_rgb();
    HSL* rgb_to_hsl();
    HSL* hsv_to_hsl();
    HSV* rgb_to_hsv();
    HSV* hsl_to_hsv();
    CMYK* rgb_to_cmyk();
    CMYK* hsv_to_cmyk();
    CMYK* hsl_to_cmyk();



public: 
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


public:

    Color(RGB, float, float);
    Color(CMYK, float, float);
    Color(HSL, float, float);
    Color(HSV, float, float);
    short GetColorModel();

    friend ostream& operator<<(ostream& os, const Color&);
};



Color::Color(RGB rgb, float opacity = 1, float tint = 0)
{
    model_flag = 0b00000001;
    if (is_RGB_valid(rgb.red) && is_RGB_valid(rgb.green) && is_RGB_valid(rgb.blue))
    {
	this->opacity = opacity;
	this->tint = tint;

	this->color_model = new ColorModel();
	this->color_model->rgb.red = rgb.red;
	this->color_model->rgb.green = rgb.green;
	this->color_model->rgb.blue = rgb.blue;
    }
    else {
	this->color_model = nullptr;
	cout << "the object isn't initialized!!!\n";
    }
}

Color::Color(CMYK cmyk, float opacity = 1, float tint = 0)
{
    model_flag = 0b00000010;
    if (is_CMYK_valid(cmyk.cyan) && is_CMYK_valid(cmyk.magenta) && is_CMYK_valid(cmyk.yellow) && is_CMYK_valid(cmyk.black))
    {

	this->opacity = opacity;
	this->tint = tint;

	this->color_model = new ColorModel();
	this->color_model->cmyk.cyan = cmyk.cyan;
	this->color_model->cmyk.magenta = cmyk.magenta;
	this->color_model->cmyk.yellow = cmyk.yellow;
	this->color_model->cmyk.black = cmyk.black;
	cout << std::bitset<8>(model_flag) << "\n";
	cout << model_flag << "\n";
    }
    else {
	this->color_model = nullptr;
	cout << "the object isn't initialized!!!\n";
    }
}

Color::Color(HSL hsl, float opacity = 1, float tint = 0)
{
    model_flag = 0b00000100;
    if (is_hue_valid(hsl.hue) && is_saturation_valid(hsl.saturation) && is_brightness_valid(hsl.brightness))
    {
	this->opacity = opacity;
	this->tint = tint;
	this->color_model = new ColorModel();
	this->color_model->hsl.hue = hsl.hue;
	this->color_model->hsl.saturation = hsl.saturation;
	this->color_model->hsl.brightness = hsl.brightness;
    }
    else
    {
	this->color_model = nullptr;
	cout << "the object isn't initialized!!!\n";
    }

    // cout << std::bitset<8>(model_flag) << "\n";
     //cout << model_flag << "\n";
}

Color::Color(HSV hsv, float opacity = 1, float tint = 0)
{
    model_flag = 0b00001000;
    if (is_hue_valid(hsv.hue) && is_saturation_valid(hsv.saturation) && is_value_valid(hsv.value))
    {
	this->opacity = opacity;
	this->tint = tint;

	this->color_model = new ColorModel();
	this->color_model->hsv.hue = hsv.hue;
	this->color_model->hsv.saturation = hsv.saturation;
	this->color_model->hsv.value = hsv.value;
	cout << std::bitset<8>(model_flag) << "\n";
	cout << model_flag << "\n";
    }
    else
    {
	this->color_model = nullptr;
	cout << "the object isn't initialized!!!\n";
    }
}

short Color::GetColorModel()
{
    if (model_flag & 1)
	return 1;
    else if ((model_flag >> 1) & 1)
	return 2;
    else if ((model_flag >> 2) & 1)
	return 3;
    else if ((model_flag >> 3) & 1)
	return 4;
    return 0;
}

bool Color::is_RGB_valid(unsigned char val)
{
    return val >= 0 && val <= 255;
}
bool Color::is_hue_valid(unsigned short h)
{
    return h >= 0 && h <= 360;
}
bool Color::is_saturation_valid(int val)
{
    return val >= 0 && val <= 100;
}
bool Color::is_saturation_valid(float val)
{
    return val >= 0.0f && val <= 1.0f;
}
bool Color::is_brightness_valid(int val)
{
    return val >= 0 && val <= 100;
}
bool Color::is_brightness_valid(float val)
{
    return val >= 0.0f && val <= 1.0f;
}
bool Color::is_value_valid(int val)
{
    return val >= 0 && val <= 100;
}
bool Color::is_value_valid(float val)
{
    return val >= 0.0f && val <= 1.0f;
}
bool Color::is_CMYK_valid(float val)
{
    return val >= 0.0f && val <= 1.0f;
}

ostream& operator<<(ostream& os, const Color& color)
{
    if (color.color_model != nullptr)
    {	
	if (color.model_flag & 1)    // определяю, какой бит установлен
	{
	    /*os << "R: " << (short)color.color_model->rgb.red << "\n";
	    os << "G: " << (short)color.color_model->rgb.green << "\n";
	    os << "B: " << (short)color.color_model->rgb.blue << "\n";*/
	    os << color.color_model->rgb;	
	    os << "Tint: " << color.tint << "\n";
	    os << "Opacity: " << color.opacity << "\n";
	}
	else if ((color.model_flag >> 1) & 1)
	{
	    /*os << "Cyan:  \t" << (short)color.color_model->cmyk.cyan << "%\n";
	    os << "Magenta:" << (short)color.color_model->cmyk.magenta << "%\n";
	    os << "Yellow:\t" << (short)color.color_model->cmyk.yellow << "%\n";
	    os << "Black: \t" << (short)color.color_model->cmyk.cyan << "%\n";*/
	    os << color.color_model->cmyk << "\n";
	    os << "Tint: " << color.tint << "\n";
	    os << "Opacity: " << color.opacity << "\n";
	}
	else if ((color.model_flag >> 2) & 1)
	{
	    /*os << "Hue:" << (short)color.color_model->hsl.hue << "\n";
	    os << "Saturation:" << (short)color.color_model->hsl.saturation << "\n";
	    os << "Brightness:" << (short)color.color_model->hsl.brightness << "\n";*/
	    os << color.color_model->hsl << "\n";
	    os << "Tint: " << color.tint << "\n";
	    os << "Opacity: " << color.opacity << "\n";
	}
	else if ((color.model_flag >> 3) & 1)
	{
	    os << color.color_model->hsv << "\n";
	    os << "Tint: " << color.tint << "\n";
	    os << "Opacity: " << color.opacity << "\n";
	}
	else
	    os << "The color model is not defined\n";
    }
    else
	os << "not initialized object!\n";

    return os;
}
ostream& operator<<(ostream& os, const Color::RGB& rgb)
{
    cout << "RGB color model:\n";
    cout << "R: " << (short)rgb.red << "\n";
    cout << "G: " << (short)rgb.green << "\n";
    cout << "B: " << (short)rgb.blue << "\n";
    return os;
}
ostream& operator<<(ostream& os, const Color::CMYK& cmyk)
{
    cout << "CMYK color model:\n";
    cout << "Cyan:  \t" << (short)cmyk.cyan << "%\n";
    cout << "Magenta:" << (short)cmyk.magenta << "%\n";
    cout << "Yellow:\t" << (short)cmyk.yellow << "%\n";
    cout << "Black: \t" << (short)cmyk.black << "%\n";
    return os;
}
ostream& operator<<(ostream& os, const Color::HSL& hsl)
{
    cout << "HSL color model:\n";
    cout << "Hue:\t\t" << (short)hsl.hue << (char)248 << "\n";
    cout << "Saturation:\t" << roundf(hsl.saturation * 100) << "%\n";
    cout << "Brightness:\t" << roundf(hsl.brightness * 100) << "%\n";
    return os;
}
ostream& operator<<(ostream& os, const Color::HSV& hsv)
{
    cout << "HSV color model:\n";
    cout << "Hue:\t\t" << (short)hsv.hue << (char)248 << "\n";
    cout << "Saturation:\t" << roundf(hsv.saturation * 100) << "%\n";
    cout << "Value:\t\t" << roundf(hsv.value * 100) << "%\n";
    return os;
}

Color::RGB* Color::hsl_to_rgb()
{
    RGB* ret = new RGB();
   
    if (GetColorModel() == 3)
    {
	if (this->color_model->hsl.saturation == 0)                                // если насыщенность == 0, то это серый цвет
	{
	    ret->red = ret->green = ret->blue = static_cast<unsigned char>(this->color_model->hsl.brightness * 255);  // одинаковое распределение по каналам
	    return ret;
	}
	else
	{
	    float c = (1 - (2 * this->color_model->hsl.brightness - 1)) * this->color_model->hsl.saturation; // 0.5
	    float temp = c * (1 - this->color_model->hsl.hue / 60 / 2 - 1);
	    float m = this->color_model->hsl.brightness - c / 2;

	    //temp = roundf((temp + m) * 255);
	    // c = roundf((c + m) * 255);
	    // unsigned char default_color = static_cast<unsigned char>(roundf(m * 255));

	    float r, g, b;
	    if (this->color_model->hsl.hue < 60 && this->color_model->hsl.hue >= 0)
	    {
		r = c;
		g = temp;
		b = 0;
	    }
	    else if (this->color_model->hsl.hue < 120)
	    {
		r = temp;
		g = c;
		b = 0;
	    }
	    else if (this->color_model->hsl.hue < 180)
	    {
		r = 0;
		g = c;
		b = temp;
	    }
	    else if (this->color_model->hsl.hue < 240)
	    {
		r = 0;
		g = temp;
		b = c;
	    }
	    else if (this->color_model->hsl.hue < 300)
	    {
		r = temp;
		g = 0;
		b = c;
	    }
	    else if (this->color_model->hsl.hue < 360)
	    {
		r = c;
		g = 0;
		b = temp;
	    }
	    ret->red = static_cast<unsigned char> ((r + m) * 255);
	    ret->green = static_cast<unsigned char> ((g + m) * 255);
	    ret->blue = static_cast<unsigned char> ((b + m) * 255);
	}

	return ret;
    }
    else
	throw("not valid type!");
    
}
Color::RGB* Color::hsv_to_rgb()
{
    if (GetColorModel() == 4)
    {
	RGB* ret = new RGB();

	float c = (1 - std::abs(2 * this->color_model->hsv.value - 1)) * this->color_model->hsv.saturation;
	float x = c * (1 - std::abs(std::fmod(this->color_model->hsv.hue / 60.0, 2) - 1));
	float m = this->color_model->hsv.value - c / 2;

	float r, g, v;

	if (this->color_model->hsv.hue < 60)
	{
	    r = c;
	    g = x;
	    v = 0;
	}
	else if (this->color_model->hsv.hue < 120)
	{
	    r = x;
	    g = c;
	    v = 0;
	}
	else if (this->color_model->hsv.hue < 180)
	{
	    r = 0;
	    g = c;
	    v = x;
	}
	else if (this->color_model->hsv.hue < 240)
	{
	    r = 0;
	    g = x;
	    v = c;
	}
	else if (this->color_model->hsv.hue < 300)
	{
	    r = x;
	    g = 0;
	    v = c;
	}
	else
	{
	    r = c;
	    g = 0;
	    v = x;
	}

	ret->red = static_cast<unsigned char>((r + m) * 255);
	ret->green = static_cast<unsigned char>((g + m) * 255);
	ret->blue = static_cast<unsigned char>((v + m) * 255);


	return ret;
    }
    else
	throw("not valid type!");

   
}
Color::HSL* Color::rgb_to_hsl()
{
    if (GetColorModel() == 1)
    {
	HSL* hsl = new HSL();
	float r = this->color_model->rgb.red / 255.;
	float g = this->color_model->rgb.green / 255.;
	float b = this->color_model->rgb.blue / 255.;
	float max_value = Color::max(r, g, b);
	float min_value = Color::min(r, g, b);

	if (max_value - min_value == 0) // цвет серый
	{
	    hsl->saturation = 0;
	    hsl->hue = 0;
	    hsl->brightness = r;
	}
	else
	{
	    if (max_value == r)
	    {
		hsl->hue = 60 * ((g - b) / (max_value - min_value));
	    }
	    else if (max_value == g)
	    {
		hsl->hue = 60 * ((b - r) / (max_value - min_value) + 2);
	    }
	    else if (max_value == b)
	    {
		hsl->hue = 60 * ((r - g) / (max_value - min_value) + 4);
	    }
	    hsl->brightness = (max_value + min_value) / 2;
	    hsl->saturation = (max_value - min_value) / (1 - abs(2 * hsl->brightness - 1));
	}

	return hsl;
    }
    else
	throw("not valid type!");
    
}
Color::HSL* Color::hsv_to_hsl()
{
    if (GetColorModel() == 4)
    {
	HSL* hsl = new HSL();
	hsl->hue = this->color_model->hsv.hue;
	hsl->brightness = this->color_model->hsv.value * (1 - this->color_model->hsv.saturation / 2);
	if (hsl->brightness == 0 || hsl->brightness == 1)
	    hsl->saturation = 0;
	else
	{
	    float temp = 1 - hsl->brightness;
	    hsl->saturation = (this->color_model->hsv.value - hsl->brightness) / Color::min(hsl->brightness, temp);
	}

	return hsl;
    }
    else
	throw("not valid type!");
    
}
Color::HSV* Color::rgb_to_hsv()
{
    if (GetColorModel() == 1)
    {
	HSV* hsv = new HSV();
	float r = this->color_model->rgb.red / 255.;
	float g = this->color_model->rgb.green / 255.;
	float b = this->color_model->rgb.blue / 255.;
	float max_value = Color::max(r, g, b);
	float min_value = Color::min(r, g, b);
	if (max_value - min_value == 0) // цвет серый
	{
	    hsv->saturation = 0;
	    hsv->hue = 0;
	    hsv->value = r;
	}
	else
	{
	    if (max_value == r)
	    {
		hsv->hue = 60 * ((g - b) / (max_value - min_value));
	    }
	    else if (max_value == g)
	    {
		hsv->hue = 60 * ((b - r) / (max_value - min_value) + 2);
	    }
	    else if (max_value == b)
	    {
		hsv->hue = 60 * ((r - g) / (max_value - min_value) + 4);
	    }
	    if (hsv->hue < 0)
		hsv->hue += 360;
	    hsv->saturation = (max_value - min_value) / max_value;
	    hsv->value = max_value;
	}
	return hsv;
    }
    else
	throw("not valid type!");
    
}
Color::HSV* Color::hsl_to_hsv()
{
    if (GetColorModel() == 3)
    {
	HSV* hsv = new HSV();
	hsv->hue = this->color_model->hsl.hue;
	float temp = 1.0f - this->color_model->hsl.brightness;
	hsv->value = this->color_model->hsl.brightness + this->color_model->hsl.saturation * Color::min(this->color_model->hsl.brightness, temp);
	if (bool(hsv->value)) // если не ноль
	    hsv->saturation = 2 * (1 - this->color_model->hsl.brightness / hsv->value);
	else
	    hsv->saturation = 0;
	return hsv;
    }
    else
	throw("not valid type!");
    
}
Color::CMYK* Color::rgb_to_cmyk()
{
    if (GetColorModel() == 1)
    {
	float r, g, b, black;
	r = this->color_model->rgb.red / 255.; // нормализация цвета
	g = this->color_model->rgb.green / 255.;
	b = this->color_model->rgb.blue / 255.;
	black = 1 - max(r, g, b);
	float temp = 1 - min(r, g, b);

	CMYK* ret = new CMYK();
	ret->cyan = roundf(((1 - r - black) / (1 - black)) * 100);
	ret->magenta = roundf(((1 - g - black) / (1 - black)) * 100);
	ret->yellow = roundf(((1 - b - black) / (1 - black)) * 100);
	ret->black = roundf(black * 100);

	return ret;
    }
    else
	throw("not valid type!");
    
}
Color::CMYK* Color::hsv_to_cmyk()
{
    if (GetColorModel() == 4)
    {
	RGB* rgb = this->hsl_to_rgb();
	Color temp(*rgb);
	delete rgb;
	return temp.rgb_to_cmyk();
    }
    else
	throw("not valid type!");    
}
Color::CMYK* Color::hsl_to_cmyk()
{
    if (GetColorModel() == 3)
    {
	RGB* rgb = this->hsl_to_rgb();
	Color temp(*rgb);
	delete rgb;
	return temp.rgb_to_cmyk();
    }
    else
	throw("not valid type!");    
}


int main()
{
   

    Color::RGB rgb{ 10,1,15 };
    cout << rgb<<"\n";

    Color rgb_c(rgb, 1, 0);
    cout << rgb_c << "\n";

    Color::HSL* hsl = rgb_c.rgb_to_hsl();
    cout << *hsl<<"\n";
    delete hsl;

    Color::HSV* hsv = rgb_c.rgb_to_hsv();
    cout << *hsv << "\n";
    delete hsv;

    Color::CMYK* cmyk = rgb_c.rgb_to_cmyk();
    cout << *cmyk << "\n";
    delete cmyk;
   
    return 0;
}
