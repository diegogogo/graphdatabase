#ifndef LEXICO_H_INCLUDED
#define LEXICO_H_INCLUDED

#include <iostream>
#include <string.h>

using namespace std;

enum{SELECT,CREATE,NEAR_BY, DELETE, TOKEN_NODO, TOKEN_NODOTIPO,ANDOR, GBAJO,
PARENI, PAREND, FROM, WHERE,SPACE,STOP, IGUAL,  DIGIT, LETTER, PCOMA,COMA, DPUNTOS, ERROR};

class Lexico{
public:
    char nextChar;
    int charClass;
    string lexeme;

private:
    string input;

public:
    int lex();
    void setNewInput(string in);
    Lexico(string in="");
    virtual ~Lexico();

private:
    void addChar();
    void getChar();
};

#endif // LEXICO_H_INCLUDED
