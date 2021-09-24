#include "Convertidor.h"
#include "Functions.h"
#define STB_IMAGE_IMPLEMENTATION
#include "stb/stb_image.h"

#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb/stb_image_write.h"
Convertidor::Convertidor()
{
}

Convertidor::Convertidor(const char *filepath)
{
    this->channelCount = 4;
    this->pixels = stbi_load(filepath, &this->width, &this->heigth, &this->bpp, channelCount);
    if (!pixels) {
        this->bpp = 0;
        this->width = 0;
        this->heigth = 0;
        this->channelCount = 0;
    }
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

std::string Convertidor::Gray2Color() {
    std::string path("");

    if (pixels) {
        // Indica el indice en el cuál estoy parado
        unsigned long long index = 0;
        unsigned char* jpg = new unsigned char[width * heigth * 3];
        std::cout<<"Entro uwu ";
        for (int x = 0; x < width; x++) {
            for (int y = 0; y < heigth; y++) {
                unsigned char block = channelCount;
                // Defino un arreglo que contiene todo el bloque de datos que me interesa
                unsigned char* pixel = pixels + (y + heigth * x) * block;

                int red = (int) pixel[0];
                int green = (int) pixel[1];
                int blue = (int) pixel[2];

                int h,s,v;
                red = (int) red / 255;
                green = (int) green / 255;
                blue = (int) blue / 255;
                int cmax = ColorMax(red,green,blue);
                int cmin = ColorMin(red,green,blue);
                int diff = cmax - cmin;
                
                //EN esas 3 funciones esta el problema
                h = CalcularHue(cmin,cmax,diff,red,green,blue);
                s = CalcularSaturacion(cmax, diff);
                v = CalcularValue(cmax);
                

                
                for (int c = 0; c < 3; c++) {
                    if(index == 0){
                        jpg[index] = h;
                    }else if( index == 1){
                        jpg[index] = s;
                    }else{
                        jpg[index] = v;
                    }
                    index += 1;
                } 
            }
        }

        path = "gris.jpg";
        stbi_write_jpg(path.c_str(), width, heigth, 3, jpg, 100);

        delete[] jpg;
    }

    return path;
}
