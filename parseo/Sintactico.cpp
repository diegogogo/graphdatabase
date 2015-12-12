#include "Sintactico.h"
#include <iostream>
#include <string>
#include <cstdlib>


Sintactico::Sintactico(string in)
{
    LA.setNewInput(in);
    cout<<"input: "<<in<<endl;
    nextToken=LA.lex();
}

Sintactico::~Sintactico()
{
}

void Sintactico::setNewInput(string in)
{
    LA.setNewInput(in);
    cout<<"input: "<<in<<endl;
    nextToken=LA.lex();
}

void Sintactico::syntax()
{
    S();
    if(nextToken==STOP) cout <<"Sintaxis correcta\n";
    else{cout<<"Error\n"; exit(1);}
}

/*
rezamos para que funcione con las siguientes producciones

<S>::=<CREATE>|<DELETE>|<NEARBY>|<SELECT>
<DELETE>::=DELETE PARENI TOKEN_NODO PAREND STOP
<NEARBY>::=NEARBY PARENI TOKEN_NODO PAREND STOP
<CREATE>::=CREATE PARENI TOKEN_NODO DPUNTOS TOKEN_TIPONODO PCOMA [TOKEN_NODO [{COMA TOKEN_NODO}] DPUNTOS TOKEN_TIPONODO]PCOMA [TOKEN_NODO [{COMA TOKEN_NODO}] DPUNTOS TOKEN_TIPONODO]PCOMA [TOKEN_NODO [{COMA TOKEN_NODO}] DPUNTOS TOKEN_TIPONODO]PCOMA PAREND STOP
<SELECT>::=SELECT PARENI TOKEN_NODO [FROM TOKEN_NODO [WHERE TOKEN_NODO IGUAL TOKEN_NODO [AND TOKEN_NODO IGUAL TOKEN_NODO|OR TOKEN_NODO IGUAL TOKEN_NODO] ] ] PAREND STOP

*/
void Sintactico::S()
{
    switch(nextToken){
    case DELETE:
        DELETE_();
        break;
   // case NEAR_BY:
   //     NEAR_BY();
//    break;
    default:
        exit(1);
        break;
    }
}
//<DELETE>::=DELETE PARENI TOKEN_NODO PAREND STOP
void Sintactico::DELETE_(){
    if(nextToken==DELETE){
        nextToken = LA.lex();
        if(nextToken==PARENI){
            nextToken=LA.lex();
            if(nextToken==TOKEN_NODO){
                nextToken=LA.lex();
                if(nextToken==PAREND){
                    nextToken=LA.lex();
                }
            }
        }
    }
}

