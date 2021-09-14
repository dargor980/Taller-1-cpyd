#include "Convertidor.h"

Convertidor::Convertidor()
{
}

Convertidor::Convertidor(const char *filepath)
{
}

Convertidor::~Convertidor()
{
}

int Convertidor::GetWidth()
{
    return width;
}

void Convertidor::SetWidth(int width)
{
    this->width = width;
}

int Convertidor::GetHeigth()
{
    return heigth;
}

void Convertidor::SetHeigth(int heigth)
{
    this->heigth = heigth;
}

int Convertidor::GetBpp()
{
    return bpp;
}

void Convertidor::SetBpp(int bpp)
{
    this->bpp = bpp;
}

int Convertidor::GetChannelCount()
{
    return channelCount;
}

void Convertidor::SetChannelCount(int channelCount)
{
    this->channelCount = channelCount;
}

unsigned char *Convertidor::GetPixels()
{
    return pixels;
}

void Convertidor::SetPixels(unsigned char *pixels)
{
    this->pixels = pixels;
}

std::string Convertidor::Gray2Color()
{
}
