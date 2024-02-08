#include <iostream>
#include <fstream>

int main() {
    // Crear un objeto de tipo ifstream (entrada de archivo)
    std::ifstream archivo("mi_archivo.txt");

    // Verificar si el archivo se abrió correctamente
    // good == (!fail() && !eof())
    if (!archivo.fail() && !archivo.eof()) {
        std::cout << "El archivo se abrió correctamente." << std::endl;
        // Realizar operaciones con el archivo...
    }
    else {
        std::cout << "Error al abrir o leer el archivo." << std::endl;
    }

    // Cerrar el archivo
    archivo.close();

    return 0;
}
