#include <iostream>
#include <string>
#include <fstream>

// Leer archivo y almacenar informacion
std::string LeerArchivo(const std::string& nombreArchivo) {
    std::string contenido;

    std::ifstream archivo(nombreArchivo);

    if (archivo.is_open()) {

        std::string linea;
        while (std::getline(archivo, linea)) {
            contenido += linea;
        }

        archivo.close();
    } else {
        std::cerr << "No se pudo abrir el archivo." << std::endl;
    }

    return contenido;
}


std::string descifrarCesar(std::string mensajeCifrado, int clave) {
    std::string alfabeto = "abcdefghijklmnopqrstuvwxyz ";
    std::string mensajeDescifrado = "";

    for (char caracter : mensajeCifrado) {
        // Buscar el índice del carácter en el alfabeto
        size_t indice = alfabeto.find(caracter);

        // Si el carácter no está en el alfabeto, añadirlo tal cual al mensaje descifrado
        if (indice == std::string::npos) {
            mensajeDescifrado += caracter;
        } else {
            // Aplicar el desplazamiento inverso y asegurarse de que esté en el rango adecuado
            int indiceDescifrado = (indice - clave + alfabeto.length()) % alfabeto.length();
            mensajeDescifrado += alfabeto[indiceDescifrado];
        }
    }

    return mensajeDescifrado;
}

std::string cifrarCesar(std::string mensajeOriginal, int clave) {
    std::string alfabeto = "abcdefghijklmnopqrstuvwxyz ";
    std::string mensajeCifrado = "";

    for (char caracter : mensajeOriginal) {
        // Buscar el índice del carácter en el alfabeto
        size_t indice = alfabeto.find(caracter);

        // Si el carácter no está en el alfabeto, añadirlo tal cual al mensaje cifrado
        if (indice == std::string::npos) {
            mensajeCifrado += caracter;
        } else {
            // Aplicar el desplazamiento y asegurarse de que esté en el rango adecuado
            int indiceCifrado = (indice + clave) % alfabeto.length();
            mensajeCifrado += alfabeto[indiceCifrado];
        }
    }

    return mensajeCifrado;
}

int main() {
    int clave = 10;

    std::string nombreArchivo = "cipher1.txt";
    std::string contenido = LeerArchivo(nombreArchivo);
    std::cout << "Contenido del archivo:\n\n" << contenido;
    std::string mensajeDescifrado = descifrarCesar(contenido, clave);
    std::cout << "\n\nMensaje descifrado: \n\n" << mensajeDescifrado << std::endl << std::endl;

    std::string mensajeOriginal = "\nla clase de cyberseguridad es lo maximo";
    std::string mensajeCifrado = cifrarCesar(mensajeOriginal, clave);
    std::cout << "Mensaje original: " << mensajeOriginal << std::endl;
    std::cout << "Mensaje cifrado: " << mensajeCifrado << std::endl;
    std::string mensajeDescifrado2 = descifrarCesar(mensajeCifrado, clave);
    std::cout << "Mensaje descifrado: " << mensajeDescifrado2 << std::endl;

    return 0;
}
