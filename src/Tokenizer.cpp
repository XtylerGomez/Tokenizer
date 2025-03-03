#include "Tokenizer.hpp"

char Tokenizer::nextChar(){
    return input[pos++];
}

void Tokenizer::retract(){
    pos--;  
}

void Tokenizer::fail(){
    std::cout << "Error léxico: no es un operador relacional." << std::endl;
    exit(1);
}

void Tokenizer::getRelop(){
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
}