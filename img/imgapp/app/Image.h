#ifndef IMAGE_H
#define IMAGE_H

#include <iostream>
#include <string>
#include<math.h>


class Image {
public:
    /**
     * Constructor vacío, inicializa en Cero
     */
    Image();

    /**
     * Inicializa los datos en función del archivo pasado como argumento.
     * @param filepath Ruta a un archivo con la imagen
     */
    Image(const char* filepath);

    /**
     * Destructor por defecto, libera la memoria
     */
    virtual ~Image();

    /**
     * 
     * @return La cantidad de bytes por pixel
     */
    int GetBpp();

    /**
     * 
     * @param bpp La cantidad de bytes por pixel
     */
    void SetBpp(int bpp);

    /**
     * 
     * @return La cantidad de canales que tiene la imagen
     */
    int GetChannelCount();

    /**
     * 
     * @param channelCount La cantidad de canales que tiene la imagen
     */
    void SetChannelCount(int channelCount);

    /**
     * 
     * @return El alto de la imagen.
     */
    int GetHeight();

    /**
     * 
     * @param height El alto de la imagen.
     */
    void SetHeight(int height);

    /**
     * 
     * @return la representación binaria de la imagen.
     */
    unsigned char* GetPixels();

    /**
     * 
     * @param pixels la representación binaria de la imagen.
     */
    void SetPixels(unsigned char* pixels);

    /**
     * 
     * @return Ancho de la imagen
     */
    int GetWidth();

    /**
     * 
     * @param width Ancho de la imagen
     */
    void SetWidth(int width);

    /**
     * 
     * @return El nombre de archivo generado.
     */
    std::string toGrayScale();
    std::string toColorScale();

private:
    int width;
    int height;
    int bpp;
    int channelCount;
    unsigned char* pixels;
};

#endif /* IMAGE_H */

