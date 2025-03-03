#ifndef TOKENIZER_HPP
#define TOKENIZER_HPP
#include <iostream>
#include <cstring>
#include <cctype>

typedef enum {RELOP} TokenType;
typedef enum {LT, LE, GT, GE, EQ, ERROR} RelopType;

class Tokenizer{

    public:
    TokenType type;
    RelopType attribute;

    const char *input;

    int pos = 0;

    char nextChar();
    void retract();
    void fail();

    void getRelop();
    
};

#endif //TOKENIZER_HPP