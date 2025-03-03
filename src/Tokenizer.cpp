#include "Tokenizer.hpp"

char Tokenizer::nextChar(){
    return input[pos++];
}
void Tokenizer::retract(){
    pos--;  
}

void Tokenizer::getToken(){
    int state = 0; //Estado inicial
    char c; //Caracter actual
    while (true) {
        switch (state) {
            case 0: //Estado inicial
                attribute = "";
                c = nextChar();
                if (isdigit((c))) state = 1; //se va al estado de entero
                else if (c == '+') state = 11; //se va al estado de incremento
                else state = 14; //estado de error
                break;
            case 1:
                attribute += c; //con esto se va a ir concatenando los caracteres
                c = nextChar();
                if (isdigit(c)) state = 1; //se repite
                else if (c == '.') state = 2; //se va al estado de punto
                else {
                    type = "Entero"; //estado 6, se retorna el token
                    retract();
                    return;
                }
                break;

            case 2:
                attribute += c;
                c = nextChar();
                if (isdigit(c)) state = 3; //se va al estado de flotante
                else {
                    state = 14; //estado de error
                }
                break;
            
            case 3:
                attribute += c;
                c = nextChar();
                if (isdigit(c)) state = 3;
                else if (c == 'e' || c == 'E') state = 4; //se va al estado de exponente
                else {
                    type = "Flotante"; //estado 6, se retorna el token
                    retract();
                    return;
                }
                break;
            
            case 4:
                attribute += c;
                c = nextChar();
                if (c == '+' || c == '-') state = 7; //continua al estado de exponente
                else {
                    state = 14; //estado de error
                }
                break;
            case 7:
                attribute += c;
                c = nextChar();
                if (isdigit(c)) state = 8; //Continua al estado de exponente
                else {
                    state = 14; //estado de error
                }
                break;
                
            case 8:
                attribute += c;
                c = nextChar();
                if (isdigit(c)) state = 8;
                else {
                    type = "Exponente"; //estado 6, se retorna el token
                    retract();
                    return;
                }
                break;

            case 11:
                attribute += c;
                c = nextChar();
                if (c == '+') {
                    type = "Incremento"; //estado 10, se retorna el token
                    return;
                } else {
                    retract();
                    type = "Suma"; //estado 13, se retorna el token
                    return;
                }
                break;

            case 14:    //error
                while (!isblank(c) && c != '\0') { //mientras no se termine la entrada
                    attribute += c;               //se va concatenando la entrada de error
                    c = nextChar();
                }
                type = "Error";
                return;
                break;
        }

    }
}
