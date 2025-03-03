#include "./src/Tokenizer.hpp"

#include <iostream>
#include <cstring>
#include <cctype>

using namespace std;

int main(){

    Tokenizer t;
    t.input = "4 +3.4 +98.1E5";  
    cout << "Entrada : " << t.input << endl;

    while (t.pos < strlen(t.input)) {
        while (isspace(t.input[t.pos])) t.pos++;  
        if (t.pos >= strlen(t.input)) break;

        t.getToken();

        cout<<"<"<<t.type<<", "<<t.attribute<<">";
    }

    return 0;
}