#include "./src/Tokenizer.hpp"

#include <iostream>
#include <cstring>
#include <cctype>

using namespace std;

int main(){

    Tokenizer t;
    t.input = "<= > >= < ==";  
    cout << "Analizando: " << t.input << endl;

    while (t.pos < strlen(t.input)) {
        while (isspace(t.input[t.pos])) t.pos++;  
        if (t.pos >= strlen(t.input)) break;

        t.getRelop();
        switch (t.attribute) {
            case LT: cout << "Token: LT (<)" << endl; break;
            case LE: cout << "Token: LE (<=)" << endl; break;
            case GT: cout << "Token: GT (>)" << endl; break;
            case GE: cout << "Token: GE (>=)" << endl; break;
            case EQ: cout << "Token: EQ (=)" << endl; break;
            default: cout << "Token desconocido" << endl;
        }
    }

    return 0;
}