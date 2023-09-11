#include <iostream>
#include <string>
#include <fstream>
#include <map>

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

// Frecuencia de letras
std::string frecuencia(const std::string& texto) {
    std::map<char, int> frecuencia;
    std::string resultado = "\n";

    for (char caracter : texto) {
        if (std::isalpha(caracter)) { // Solo procesa letras
            frecuencia[std::tolower(caracter)]++; // Convierte a minúscula y cuenta
        }
    }

    for (const auto& par : frecuencia) {
        char letra = par.first;
        int repeticiones = par.second;

        if (repeticiones > 1) { // Solo muestra letras repetidas
            double porcentaje = (static_cast<double>(repeticiones) / texto.length()) * 100;
            resultado += letra;
            resultado += " se repite " + std::to_string(repeticiones) + " veces con porcentaje de: " + std::to_string(porcentaje) + "%\n";
        }
    }

    return resultado;
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
        // Busca el índice del carácter en el alfabeto
        size_t indice = alfabeto.find(caracter);

        // Si el carácter no está en el alfabeto,lo añade tal cual fue puesto como en el ejemplo del segundo mensaje cifrado con punto al final
        if (indice == std::string::npos) {
            mensajeCifrado += caracter;
        } else {
            // Aplica el desplazamiento y asegurarse de que esté en el rango adecuado
            int indiceCifrado = (indice + clave) % alfabeto.length();
            mensajeCifrado += alfabeto[indiceCifrado];
        }
    }

    return mensajeCifrado;
}

int main() {
    int clave = 10;
    std::string nuevoMensaje;
    int nuevaClave;

    std::string nombreArchivo = "cipher1.txt";
    std::string contenido = LeerArchivo(nombreArchivo);
    std::cout << "Contenido del archivo:\n\n" << contenido << std::endl;

    std::string letrasRepetidas = frecuencia(contenido);
    std::cout << letrasRepetidas ;
    std::cout << "\n\nTeniendo en cuenta la pista sobre el espacio siendo el caracter mas repetido, nos dimos cuenta que la j es caracter mas repetido en el texto. recorrimos la j -10 posiciones para hacer match con el espacio y obtuvimos la llave";

    std::string mensajeDescifrado = descifrarCesar(contenido, clave);
    std::cout << "\n\nMensaje descifrado: \n\n" << mensajeDescifrado << std::endl << std::endl;

    std::string mensajeOriginal = "\nla clase de cyberseguridad es lo maximo";
    std::string mensajeCifrado = cifrarCesar(mensajeOriginal, clave);
    std::cout << "Mensaje original: " << mensajeOriginal << std::endl;
    std::cout << "Mensaje cifrado: " << mensajeCifrado << std::endl;
    std::string mensajeDescifrado2 = descifrarCesar(mensajeCifrado, clave);
    std::cout << "Mensaje descifrado: " << mensajeDescifrado2 << std::endl << std::endl;

    std::cout << "Ingresa un mensaje a encriptar, recuuerda que solo se puede utilizar el afabeto \"abcdefghijklmnopqrstuvwxyz \" \ningresa nuevo mensaje aqui: ";
    //std::cin >> nuevoMensaje;
    nuevoMensaje = "el codigo esta preparado para recibir un cin pero por alguna razon en el momento en el que pongo el espacio desde la terminal me marca error y decifra unicamente hasta el primer espacio para luego abortar la tarea sin embargo si ingreso un string desde una variable preconfigurada si funciona.";
    std::cout << "\nIngresa el valor numerico de la nueva llave en un rango 1-26: ";
    std::cin >> nuevaClave;
    std::string mensajeCifrado3 = cifrarCesar(nuevoMensaje, nuevaClave);
    std::cout << "\nMensaje cifrado: " << mensajeCifrado3 << std::endl;
    std::string mensajeDescifrado3 = descifrarCesar(mensajeCifrado3, nuevaClave);
    std::cout << "\nMensaje descifrado: " << mensajeDescifrado3 << std::endl;

    return 0;
}
