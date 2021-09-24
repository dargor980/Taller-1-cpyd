#include <iostream>

#include "Convertidor.h"
#include "Functions.cpp"

int main(int argc, char **argv)
{
    MostrarGrupo();
    std::cout << "hello world " << argv[0] << std::endl;
    Convertidor img(argv[1]);
    std::cout << std::endl << img.Gray2Color() << std::endl;
    return 0;
}
