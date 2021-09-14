#ifndef COVERTIDOR_H
#define CONVERTIDOR_H

#include <iostream>

class Convertidor
{
public:
    /**
     * 
     * Constructor por defecto de la clase
     * */
    Convertidor();

    Convertidor(const char *path);

    /**
     * Destructor de la clase
     * */
    virtual ~Convertidor();

    /**
     * 
     * @return Ancho de la imagen (width).
     * */
    int GetWidth();

    /**
     * @param width Ancho de la imagen.
     * */
    void SetWidth(int width);

    /**
     * @return Alto de la imagen (heigth).
     * */
    int GetHeigth();

    /**
     * @param heigth Alto de la imagen.
     * */
    void SetHeigth(int heigth);

    /**
     * @return Cantidad de bytes por pixel de la imagen.
     * */
    int GetBpp();

    /**
     * @param bpp Cantidad de bytes por pixel de la imagen.
     * */
    void SetBpp(int bpp);

    /**
     * @return Cantidad de canales que posee la imagen.
     * */
    int GetChannelCount();

    /**
     * @param channelCount Cantidad de canales que posee la imagen.
     * */
    void SetChannelCount(int channelCount);

    /**
     * @return Representación binaria de la imagen.
     * */
    unsigned char *GetPixels();

    /**
     * @param pixels Representación binaria de la imagen.
     * */
    void SetPixels(unsigned char *pixels);

    /**
     * @return Archivo generado.
     * */
    std::string Gray2Color();

private:
    int width;
    int heigth;
    int bpp;
    int channelCount;
    unsigned char *pixels;
};

#endif /* CONVERTIDOR_H */