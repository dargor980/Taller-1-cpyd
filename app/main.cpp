#include <iostream>

#include "Convertidor.h"
#include "Functions.cpp"

int main(int argc, char **argv)
{
    MostrarGrupo();
    if(argc < 3){
        std::cout << std::endl;
        std::cerr << "Se necesita especificar un archivo y una ruta de salida" << std::endl;
        return 1;
    }
    Convertidor img(argv[1], argv[2]);
    std::cout << std::endl << img.Gray2Color() << std::endl;
    return 0;
}
