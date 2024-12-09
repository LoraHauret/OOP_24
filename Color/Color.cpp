#pragma once
#include "Color.h"


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
    else 
    {
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
    os << "RGB color model:\n";
    os << "R: " << (short)rgb.red << "\n";
    os << "G: " << (short)rgb.green << "\n";
    os << "B: " << (short)rgb.blue << "\n";
    return os;
}
ostream& operator<<(ostream& os, const Color::CMYK& cmyk)
{
    os << "CMYK color model:\n";
    os << "Cyan:  \t" << (short)cmyk.cyan << "%\n";
    os << "Magenta:" << (short)cmyk.magenta << "%\n";
    os << "Yellow:\t" << (short)cmyk.yellow << "%\n";
    os << "Black: \t" << (short)cmyk.black << "%\n";
    return os;
}
ostream& operator<<(ostream& os, const Color::HSL& hsl)
{
    os << "HSL color model:\n";
    os << "Hue:\t\t" << (short)hsl.hue << (char)248 << "\n";
    os << "Saturation:\t" << roundf(hsl.saturation * 100) << "%\n";
    os << "Brightness:\t" << roundf(hsl.brightness * 100) << "%\n";
    return os;
}
ostream& operator<<(ostream& os, const Color::HSV& hsv)
{
    os << "HSV color model:\n";
    os << "Hue:\t\t" << (short)hsv.hue << (char)248 << "\n";
    os << "Saturation:\t" << roundf(hsv.saturation * 100) << "%\n";
    os << "Value:\t\t" << roundf(hsv.value * 100) << "%\n";
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


void Color::SetRGB(const unsigned char& r, const unsigned char& g, const unsigned char& b)
{
    if (GetColorModel() == 1 && is_RGB_valid(r) && is_RGB_valid(g) && is_RGB_valid(b))
    {
	if (color_model == nullptr)
	{
	    color_model = new ColorModel();
	    model_flag = 0b00000001;
	}
	    
	this->color_model->rgb.red = r;
	this->color_model->rgb.green = g;
	this->color_model->rgb.blue = b;
    }
    else
	cout << "RGB color is not set!";
}
void Color::SetCMYK(const float& c, const float& m, const float& y, const float& k)
{
    if (GetColorModel() == 2 && is_CMYK_valid(c) && is_CMYK_valid(m) && is_CMYK_valid(y) && is_CMYK_valid(k))
    {
	if (color_model == nullptr)
	{
	    color_model = new ColorModel();
	    model_flag = 0b00000010;
	}    

	this->color_model->cmyk.cyan = c * 100;
	this->color_model->cmyk.magenta = m * 100;
	this->color_model->cmyk.yellow = y * 100;
	this->color_model->cmyk.black = k * 100;
    }
    else {
	cout << "the object isn't initialized!!!";
    }
}
void Color::SetHSL(const unsigned short& hue, const float& saturation, const float& brightness)
{
    if (GetColorModel() == 3 && is_hue_valid(hue) && is_saturation_valid(saturation) && is_brightness_valid(brightness))
    {
	if (color_model == nullptr)
	{
	    color_model = new ColorModel();
	    model_flag = 0b00000100;
	}

	this->color_model->hsl.hue = hue;
	this->color_model->hsl.saturation = saturation;
	this->color_model->hsl.brightness = brightness;	
    }
    else {
	cout << "the object isn't initialized!!!";
    }
}
void Color::SetHSV(const unsigned short& hue, const float& saturation, const float& value)
{
    if (GetColorModel() == 3 && is_hue_valid(hue) && is_saturation_valid(saturation) && is_value_valid(value))
    {
	if (color_model == nullptr)
	{
	    color_model = new ColorModel();
	    model_flag = 0b00001000;
	}

	this->color_model->hsv.hue = hue;
	this->color_model->hsv.saturation = saturation;
	this->color_model->hsv.value = value;
    }
    else {
	cout << "the object isn't initialized!!!";
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
 Color::RGB* Color::GetRGB()
{
    RGB* ret = nullptr;
    if (color_model != nullptr)
    {
	switch (GetColorModel())
	{
	case 1:
	    ret = new RGB();
	    ret->red = this->color_model->rgb.red;
	    ret->green = this->color_model->rgb.green;
	    ret->blue = this->color_model->rgb.blue;
	    break;
	case 2: // значит модель cmyk и возвращаю нулевой указатель	
	    break;
	case 3:  // значит модель hsl
	    ret = hsl_to_rgb();
	    break;
	case 4:  // значит модель hsv
	    ret = hsv_to_rgb();
	default:
	    throw("model type is not defined");
	}
    }

    return ret;
}
 Color::CMYK* Color::GetCMYK()
{
    CMYK* ret = nullptr;
    if (color_model != nullptr)
    {
	switch (GetColorModel())
	{
	case 1:
	    ret = rgb_to_cmyk();
	    break;
	case 2:
	    ret = new CMYK();
	    ret->cyan = this->color_model->cmyk.cyan;
	    ret->magenta = this->color_model->cmyk.magenta;
	    ret->yellow = this->color_model->cmyk.yellow;
	    ret->black = this->color_model->cmyk.black;
	    break;
	case 3:
	    ret = hsl_to_cmyk();
	    break;
	case 4:
	    ret = hsv_to_cmyk();
	    break;
	default:
	    throw("model type is not defined");
	}
    }
    return ret;
}
 Color::HSL* Color::GetHSL()
{
    HSL* ret = nullptr;
    if (color_model != nullptr)
    {
	switch (GetColorModel())
	{
	case 1:
	    ret = rgb_to_hsl();
	    break;
	case 2:

	    break;
	case 3:
	    ret = new HSL();
	    ret->hue = this->color_model->hsl.hue;
	    ret->saturation = this->color_model->hsl.saturation;
	    ret->brightness = this->color_model->hsl.brightness;
	    break;
	case 4:
	    ret = hsv_to_hsl();
	    break;
	default:
	    throw("model type is not defined");
	}
    }
    return ret;
}
 Color::HSV* Color::GetHSV()
{
    HSV* ret = nullptr;
    if (color_model != nullptr)
    {
	switch (GetColorModel())
	{
	case 1:
	    ret = rgb_to_hsv();
	    break;
	case 2:
	    break;
	case 3:
	    ret = hsl_to_hsv();
	    break;
	case 4:
	    ret = new HSV();
	    ret->hue = this->color_model->hsv.hue;
	    ret->saturation = this->color_model->hsv.saturation;
	    ret->value = this->color_model->hsv.value;
	    break;
	default:
	    throw("model type is not defined");
	}
    }
    return ret;
}

