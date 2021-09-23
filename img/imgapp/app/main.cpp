#include <iostream>

#include "Image.h"

int main(int argc, char** argv) {

    if (argc < 2) {
        std::cerr << "Se necesita especificar un archivo" << std::endl;
        return 1;
    }


    Image img(argv[1]);
    std::cout << std::endl << img.toGrayScale() << std::endl;

    return 0;
}
