#include "Functions.h"

void MostrarGrupo()
{
    std::cout << std::endl << "Taller 1 Computacion paralela y distribuida" << std::endl;
    std::cout << "Desarrollado por: " << std::endl;
    std::cout << "German Contreras Amestica" << std::endl;
    std::cout << "Benjamin Cristi Simonsen" << std::endl;
    std::cout << "Luciano Grandi Morales" << std::endl;
}

float ColorMax(float r, float g, float b){
    if(r > g){
        if(r > b){
            return r;
        } else return b;
    } else if(g > b){
        return g;
    } else return b;
}

float ColorMin(float r, float g, float b){
    if(r < g){
        if(r < b){
            return r;
        } else return b;
    } else if(g < b){
        return g;
    } else return b;
}

float CalcularHue(float cmin, float cmax, float diff, float r, float g, float b){
    if(cmax == 0 && cmin == 0){
        return 0;
    } else if(cmax == r){
        return (float)((60* ((g - b) / diff) + 360) / (float) 360);
    } else if(cmax == g){
        return (float)((60* ((b - r) / diff) + 120) / (float) 360);
    } else return (float)((60 *((r-g) / diff) + 240) / (float) 360);

}

float CalcularSaturacion(float cmax, float diff){
    if(cmax == 0){
        return 0;
    } else return ((diff / cmax)*100);
}

float CalcularValue(float cmax){
    return cmax*100;
}