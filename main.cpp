#include "./src/Tokenizer.hpp"

#include <iostream>
#include <cstring>
#include <cctype>

using namespace std;

int main(){

    Tokenizer t;
    t.input = "4 +3.4 +98.1E5";  
    cout << "Entrada : " << t.input << endl;

    while (t.pos < strlen(t.input)) { //Mientras no se haya llegado al final de la entrada
        while (isspace(t.input[t.pos])) t.pos++;  //Ignorar espacios en blanco
        if (t.pos >= strlen(t.input)) break;

        t.getToken(); //se manda a Tokenizar

        cout<<"<"<<t.type<<", "<<t.attribute<<">"; //Se imprime el token
    }

    return 0;
}