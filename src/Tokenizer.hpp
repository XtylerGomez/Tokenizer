#ifndef TOKENIZER_HPP
#define TOKENIZER_HPP
#include <iostream>
#include <cstring>
#include <cctype>
#include <string>

using namespace std;



class Tokenizer{

    public:
    string type;
    string attribute;

    const char *input;

    int pos = 0;

    char nextChar();
    void retract();

    void getToken();
    
};

#endif //TOKENIZER_HPP