#ifndef TOKENIZER_HPP
#define TOKENIZER_HPP
#include <iostream>
#include <cstring>
#include <cctype>
#include <string>

using namespace std;
class Tokenizer{

    public:
    string type; //Tipo de Token (Entero, Flotante, Error, etc)
    string attribute; //Atributo del Token (el valor del token)

    const char *input; //Entrada a tokenizar

    int pos = 0; //Posición actual en la entrada

    char nextChar(); //Funcion para avanzar un caracter
    void retract(); //Funcion para retroceder un caracter

    void getToken(); //Tokenizador
    
};

#endif //TOKENIZER_HPP