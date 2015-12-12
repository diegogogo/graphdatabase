#ifndef SINTACTICO_H_INCLUDED
#define SINTACTICO_H_INCLUDED

#include<iostream>
#include<string>
#include "Lexico.h"

using namespace std;

/*
rezamos para que funcione con las siguientes producciones

<S>::=<CREATE>|<DELETE>|<NEARBY>|<SELECT>
<DELETE>::=DELETE PARENI TOKEN_NODO PAREND STOP
<NEARBY>::=NEARBY PARENI TOKEN_NODO PAREND STOP
<CREATE>::=CREATE PARENI TOKEN_NODO DPUNTOS TOKEN_TIPONODO PCOMA [TOKEN_NODO [{COMA TOKEN_NODO}] DPUNTOS TOKEN_TIPONODO]PCOMA [TOKEN_NODO [{COMA TOKEN_NODO}] DPUNTOS TOKEN_TIPONODO]PCOMA [TOKEN_NODO [{COMA TOKEN_NODO}] DPUNTOS TOKEN_TIPONODO]PCOMA PAREND STOP
<SELECT>::=SELECT PARENI TOKEN_NODO [FROM TOKEN_NODO [WHERE TOKEN_NODO IGUAL TOKEN_NODO [AND TOKEN_NODO IGUAL TOKEN_NODO|OR TOKEN_NODO IGUAL TOKEN_NODO] ] ] PAREND STOP

*/

class Sintactico{
public:
    void syntax();
    void setNewInput(string in);
    Sintactico(string in);
    virtual ~Sintactico();

private:
    void S();
    void DELETE_();
    void NEAR_BY_();
    void CREATE_();
    void SELECT_();

private:
    Lexico LA;
    int nextToken;
};

#endif // SINTACTICO_H_INCLUDED
