#include "Image.h"

#define STB_IMAGE_IMPLEMENTATION
#include "stb/stb_image.h"

#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb/stb_image_write.h"

Image::Image() {
    this->bpp = 0;
    this->width = 0;
    this->height = 0;
    this->channelCount = 0;
}

Image::Image(const char* filepath) {
    this->channelCount = 4;
    this->pixels = stbi_load(filepath, &this->width, &this->height, &this->bpp, channelCount);
    if (!pixels) {
        this->bpp = 0;
        this->width = 0;
        this->height = 0;
        this->channelCount = 0;
    }
}

Image::~Image() {
    if (pixels) {
        stbi_image_free(pixels);
    }
}

int Image::GetBpp() {
    return bpp;
}

void Image::SetBpp(int bpp) {
    this->bpp = bpp;
}

int Image::GetChannelCount() {
    return channelCount;
}

void Image::SetChannelCount(int channelCount) {
    this->channelCount = channelCount;
}

int Image::GetHeight() {
    return height;
}

void Image::SetHeight(int height) {
    this->height = height;
}

unsigned char* Image::GetPixels() {
    return pixels;
}

void Image::SetPixels(unsigned char* pixels) {
    this->pixels = pixels;
}

int Image::GetWidth() {
    return width;
}

void Image::SetWidth(int width) {
    this->width = width;
}

std::string Image::toGrayScale() {
    std::string path("");

    if (pixels) {
        // Indica el indice en el cuál estoy parado
        unsigned long long index = 0;
        unsigned char* jpg = new unsigned char[width * height * 3];

        for (int x = 0; x < width; x++) {
            for (int y = 0; y < height; y++) {
                unsigned char block = channelCount;
                // Defino un arreglo que contiene todo el bloque de datos que me interesa
                unsigned char* pixel = pixels + (y + height * x) * block;

                int red = (int) pixel[0];
                int green = (int) pixel[1];
                int blue = (int) pixel[2];
                // int alpha = (int) channelCount >= 4 ? pixel[3] : 0xff;

                // int gray = 0.299 * red + 0.587 * green + 0.114 * blue;
                int gray = (red + green + blue) / 3;
                for (int c = 0; c < 3; c++) {
                    jpg[index] = gray;
                    index += 1;
                }
            }
        }

        path = "gris.jpg";
        stbi_write_jpg(path.c_str(), width, height, 3, jpg, 100);

        delete[] jpg;
    }

    return path;
}