#include "Functions.h"

void MostrarGrupo()
{
    std::cout << std::endl << "Taller 1 Computacion paralela y distribuida" << std::endl;
    std::cout << "Desarrollado por: " << std::endl;
    std::cout << "German Contreras Amestica" << std::endl;
    std::cout << "Benjamin Cristi Simonsen" << std::endl;
    std::cout << "Luciano Grandi Morales" << std::endl;
}

int ColorMax(int r, int g, int b){
    if(r > g){
        if(r > b){
            return r;
        } else return b;
    } else if(g > b){
        return g;
    } else return b;
}

int ColorMax(int r, int g, int b){
    if(r < g){
        if(r < b){
            return r;
        } else return b;
    } else if(g < b){
        return g;
    } else return b;
}

int CalcularHue(int cmin, int cmax, int diff, int r, int g, int b){
    if(cmax == 0 && cmin == 0){
        return 0;
    } else if(cmax == r){
        return (60* ((g - b) / diff) + 360) % 360;
    } else if(cmax == g){
        return (60* ((b - r) / diff) + 120) % 360;
    } else return (60 *((r-g) / diff) + 240) % 360;

}

int CalcularSaturacion(int cmax, int diff){
    if(cmax == 0){
        return 0;
    } else return (diff / cmax)*100;
}

int CalcularValue(int cmax){
    return cmax*100;
}