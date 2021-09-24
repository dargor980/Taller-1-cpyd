#include "Convertidor.h"
#include "Functions.h"
#define STB_IMAGE_IMPLEMENTATION
#include "stb/stb_image.h"

#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb/stb_image_write.h"
Convertidor::Convertidor()
{
}

Convertidor::Convertidor(const char *filepath, const char *output)
{
    this->channelCount = 4;
    this->pixels = stbi_load(filepath, &this->width, &this->heigth, &this->bpp, channelCount);
    if (!pixels) {
        this->bpp = 0;
        this->width = 0;
        this->heigth = 0;
        this->channelCount = 0;
    }
    
    this->output = output;
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
    std::string path(this->output);

    if (pixels) {
        // Indica el indice en el cuál estoy parado
        unsigned long long index = 0;
        unsigned char* jpg = new unsigned char[width * heigth * 3];
        std::cout<<"Entro uwu ";
        int x, y;

        for (x = 0; x < width; x++) {
            for (y = 0; y < heigth; y++) {
                unsigned char block = channelCount;
                // Defino un arreglo que contiene todo el bloque de datos que me interesa
                unsigned char* pixel = pixels + (y + heigth * x) * block;

                float red = (float) pixel[0];
                float green = (float) pixel[1];
                float blue = (float) pixel[2];

                float h=-1,s=-1,v=-1;
               
                float cmax = ColorMax(red,green,blue);
                float cmin = ColorMin(red,green,blue);
                float diff = cmax - cmin;
                
                //EN esas 3 funciones esta el problema

                h = CalcularHue(cmin,cmax,diff,red,green,blue);
                s = CalcularSaturacion(cmax, diff);
                v = CalcularValue(cmax);

                int gray = (red + green + blue) / 3;

                int c = 0;
                for (c = 0; c < 3; c++) {
                    if(c == 0){
                        jpg[index] = h+gray;
                    } else{
                        if(c == 1){
                            jpg[index] = s+gray;
                        } else {
                            jpg[index] = v+gray;
                        }
                    }
                    index += 1;
                }  
            }
        }
        path += "gris.jpg";
        stbi_write_jpg(path.c_str(), width, heigth, 3, jpg, 100);

        delete[] jpg;
    }
    return path;
}
