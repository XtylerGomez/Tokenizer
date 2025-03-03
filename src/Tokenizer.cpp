#include "Tokenizer.hpp"

char Tokenizer::nextChar(){
    return input[pos++];
}

void Tokenizer::retract(){
    pos--;  
}


void Tokenizer::getToken(){
    int state = 0;
    char c;
    while (true) {
        switch (state) {
            case 0:
                attribute = "";
                c = nextChar();
                if (isdigit((c))) state = 1;
                else if (c == '+') state = 11;
                else if (isspace(c)) state = 12;
                else state = 14; //error
                break;
            case 1:
                attribute += c;
                c = nextChar();
                if (isdigit(c)) state = 1;
                else if (c == '.') state = 2;
                else {
                    type = "Entero"; //state 6
                    retract();
                    return;
                }
                break;

            case 2:
                attribute += c;
                c = nextChar();
                if (isdigit(c)) state = 3;
                else {
                    state = 14;
                }
                break;
            
            case 3:
                attribute += c;
                c = nextChar();
                if (isdigit(c)) state = 3;
                else if (c == 'e' || c == 'E') state = 4;
                else {
                    type = "Flotante"; //state 5
                    retract();
                    return;
                }
                break;
            
            case 4:
                attribute += c;
                c = nextChar();
                if (c == '+' || c == '-') state = 7;
                else {
                    state = 14;
                }
                break;
            case 7:
                attribute += c;
                c = nextChar();
                if (isdigit(c)) state = 8;
                else {
                    state = 14;
                }
                break;
                
            case 8:
                attribute += c;
                c = nextChar();
                if (isdigit(c)) state = 8;
                else {
                    type = "Exponente"; //state 9
                    retract();
                    return;
                }
                break;

            case 11:
                attribute += c;
                c = nextChar();
                if (c == '+') {
                    type = "Incremento"; //state 10
                    return;
                } else {
                    retract();
                    type = "Suma"; //state 13
                    return;
                }
                break;

            case 12:
                attribute = "";
                type = "Space";
                return;
                break;

            case 14:    //error
                while (!isblank(c) && c != '\0') {
                    attribute += c;
                    c = nextChar();
                }
                type = "Error";
                return;
                break;
        }

    }
}
/* void Tokenizer::getRelop(){
    int state = 0;
    char c;

    while (true) {
        switch (state) {
            case 0:
                c = nextChar();
                if (c == '<') state = 1;
                else if (c == '>') state = 5;
                else if (c == '=') state = 8;
                else fail();
                break;

            case 1:
                c = nextChar();
                if (c == '=') {
                    attribute = LE;  // <=
                    return;
                } else {
                    retract();
                    attribute = LT;  // <
                    return;
                }
                break;

            case 5:
                c = nextChar();
                if (c == '=') {
                    attribute = GE;  // >=
                    return;
                } else {
                    retract();
                    attribute = GT;  // >
                    return;
                }
                break;

            case 8:
                attribute = EQ;  // =
                return;

            default:
                fail();
        }
    }
}*/