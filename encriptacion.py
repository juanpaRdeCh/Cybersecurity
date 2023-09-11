# Elaborado por Juan Pablo Ruiz y Martin Palomares
# Problema 2 
def elCifrador(texto, clave):
    textoCifrado = ""
    alfabeto = "abcdefghijklmnopqrstuvwxyz " # 27 caracteres contando el espacio

    for i, caracter in enumerate(texto):
        if caracter in alfabeto:
            letraClave = clave[i % len(clave)]
            desplazar = alfabeto.index(letraClave)
            caracterCifrado = alfabeto[(alfabeto.index(caracter) + desplazar) % len(alfabeto)]
            textoCifrado += caracterCifrado
        else:
            textoCifrado += caracter
        
    return textoCifrado

def podremosDescifrar(textoCifrado, clave):
    textoDescifrado = ""
    alfabeto = "abcdefghijklmnopqrstuvwxyz " # 27 caracteres contando el espacio

    for i, caracter in enumerate(textoCifrado):
        if caracter in alfabeto:
            letraClave = clave[i % len(clave)]
            desplazar = alfabeto.index(letraClave)
            caracterDescifrado = alfabeto[(alfabeto.index(caracter) - desplazar) % len(alfabeto)]
            textoDescifrado += caracterDescifrado
        else:
            textoDescifrado += caracter
        
    return textoDescifrado

def main():
    texto_prueba = "Un joven padawan aun eres"
    clave_prueba = "yoda"
    textoCifrado = elCifrador(texto_prueba, clave_prueba)

    print(f"Texto original: {texto_prueba}")
    print(f"Clave: {clave_prueba}")
    print(f"Texto cifrado: {textoCifrado}")
    print("")
    textoDescifrado = podremosDescifrar(textoCifrado, clave_prueba)
    print(f"Texto descifrado: {textoDescifrado}")

if __name__ == "__main__":
    main()