#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

// Este codigo responde al problema 3 de la creacion de un OTP
// Elaborado por Juan Pablo Ruiz y Martin Palomares

std::string alfabeto = "abcdefghijklmnopqrstuvwxyz"; // Esta OTP unicamente utilizara el alfabeto establecido.

// Función para generar una llave aleatoria del mismo tamaño que el mensaje
std::string generarOTP(int longitud) {
    std::string llave;
    for (int i = 0; i < longitud; ++i) {
        llave += alfabeto[rand() % alfabeto.length()]; // Usamos rand para garantizar que generemos una llave al azar y length para que sea del tamaño del texto
    }
    return llave;
}

std::string cifrarOTP(std::string mensajeOriginal, std::string llave) {

    std::string mensajeCifrado;
    for (size_t i = 0; i < mensajeOriginal.length(); ++i) {
        char caracterOriginal = mensajeOriginal[i];
        char caracterClave = llave[i];
        size_t indiceOriginal = alfabeto.find(caracterOriginal);
        size_t indiceClave = alfabeto.find(caracterClave);

        if (indiceOriginal != std::string::npos && indiceClave != std::string::npos) {
            char caracterCifrado = alfabeto[(indiceOriginal + indiceClave) % alfabeto.length()];
            mensajeCifrado += caracterCifrado;
        } else {
            mensajeCifrado += caracterOriginal; // Mantener caracteres no cifrables tal cual
        }
    }

    return mensajeCifrado;
}

std::string descifrarOTP(std::string mensajeCifrado, std::string llave) {

    std::string mensajeDescifrado;
    for (size_t i = 0; i < mensajeCifrado.length(); ++i) {
        char caracterCifrado = mensajeCifrado[i];
        char caracterClave = llave[i];
        size_t indiceCifrado = alfabeto.find(caracterCifrado); // Se usa size_T por si tenemos un indice negativo
        size_t indiceClave = alfabeto.find(caracterClave);

        if (indiceCifrado != std::string::npos && indiceClave != std::string::npos) {
            char caracterDescifrado = alfabeto[(indiceCifrado - indiceClave + alfabeto.length()) % alfabeto.length()];
            mensajeDescifrado += caracterDescifrado;
        } else {
            mensajeDescifrado += caracterCifrado;
        }
    }

    return mensajeDescifrado;
}

int main() {
    srand(time(nullptr));
    
    std::string nuevoMensaje;
    std::string mensaje = "hola amigos";
    std::string llave = generarOTP(mensaje.length());
    
    std::string mensajeCifrado = cifrarOTP(mensaje, llave);
    std::string mensajeDescifrado = descifrarOTP(mensajeCifrado, llave);
    
    std::cout << "Mensaje original: " << mensaje << std::endl;
    std::cout << "Clave generada: " << llave << std::endl;
    std::cout << "Mensaje cifrado: " << mensajeCifrado << std::endl;
    std::cout << "Mensaje descifrado: " << mensajeDescifrado << std::endl << std::endl;

    std::cout << "Ingresa un nuevo mensaje para cifrar: ";
    //std::cin >> nuevoMensaje;
    nuevoMensaje = "al igual que en el codigo cifrado cesar aparece un error en el momento en el que introduzco un espacio desde la terminal y por esa razon creo una variable predefinida para mostrar el funionamiento en lugar de un input desde teclado";
    std::string llave2 = generarOTP(nuevoMensaje.length());
    std::string mensajeCifrado2 = cifrarOTP(nuevoMensaje, llave2);
    std::string mensajeDescifrado2 = descifrarOTP(mensajeCifrado2, llave2);
    std::cout << "Mensaje original: " << nuevoMensaje << std::endl;
    std::cout << "Clave generada: " << llave2 << std::endl;
    std::cout << "Mensaje cifrado: " << mensajeCifrado2 << std::endl;
    std::cout << "Mensaje descifrado: " << mensajeDescifrado2 << std::endl;
    
    
    return 0;
}
