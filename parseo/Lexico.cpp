#include "Lexico.h"

Lexico::Lexico(string in): input(in), charClass(ERROR), nextChar(' '), lexeme("")
{
    getChar();
}

Lexico::~Lexico()
{
}

void Lexico::setNewInput(string in)
{
    input=in;
    getChar();
}

//clasifica los tokens segun los char, es decir aquellos que no son de expreisones regulares
void Lexico::getChar()
{
    //obtenemos el primer caracter y lo borramos del input
    if(input.size()>0){
        nextChar=input[0];
        input.erase(0,1);
    }
    //si no la cadena está vacía, marcamos fin de cadena con $
    else nextChar='$';

    charClass=ERROR;
//verificamos si el char es una letra
    if((nextChar > 64 && nextChar<91) || (nextChar > 96 && nextChar < 123)){
        charClass= LETTER;
    }
    //verificamos si el char es un digito
    if(nextChar > 47 && nextChar<58){
        charClass=DIGIT;
    }

    if(nextChar=='(')charClass=PARENI;
    if(nextChar==')')charClass=PAREND;
    if(nextChar==';')charClass=PCOMA;
    if(nextChar==':')charClass=DPUNTOS;
    if(nextChar=='=')charClass=IGUAL;
    if(nextChar==' ')charClass=SPACE;
    if(nextChar=='_')charClass=GBAJO;
    if(nextChar==',')charClass=COMA;
    if(nextChar=='$')charClass=STOP;
}

void Lexico::addChar(){
    lexeme+=nextChar;
}

//comenzamos el analisi lexico
int Lexico::lex()
{
    lexeme="";
    while(charClass == SPACE) getChar();

    if(charClass==ERROR){addChar(); getChar(); return ERROR;}
    if(charClass==STOP){return STOP;}

    switch(charClass){
        case LETTER:
            addChar();
            getChar();
            while(charClass == LETTER || charClass==DIGIT || charClass==GBAJO){
                addChar();
                getChar();
            }
            if(lexeme=="SELECT")
                return SELECT;
            else if(lexeme=="CREATE")
                return CREATE;
            else if(lexeme=="NEAR_BY")
                return NEAR_BY;
            else if(lexeme=="DELETE")
                return DELETE;
            else if(lexeme=="ALUMNO"||lexeme=="DOCTOR"||lexeme=="MATERIA"||lexeme=="ESPECIALIDAD")
                return TOKEN_NODOTIPO;
            else if(lexeme=="AND"||lexeme=="OR")
                return ANDOR;
            else if(lexeme=="FROM")
                return FROM;
            else if(lexeme=="WHERE")
                return WHERE;
            else
                return TOKEN_NODO;
            break;
        case DIGIT:
            addChar();
            getChar();
            while(charClass== DIGIT){
                addChar();
                getChar();
            }
            return ERROR;
            break;
        case GBAJO:
            addChar();
            getChar();
            return ERROR;
            break;
        case PARENI:
                addChar();
                getChar();
            return PARENI;
            break;
        case PAREND:
                addChar();
                getChar();
            return PAREND;
            break;
        case PCOMA:
            addChar();
            getChar();
            return PCOMA;
            break;
        case COMA:
            addChar();
            getChar();
            return COMA;
            break;
        case DPUNTOS:
            addChar();
            getChar();
            return DPUNTOS;
            break;
    }
}


/*
int main(){
Lexico LA("SELECT(NEAR_BY;a3b  223  ALUMNOvd3 ghg  g 1234 ALUMNO,DOCTOR");
	int token=SPACE;
	while (token!=STOP) {
		token = LA.lex();
		cout<<"lexeme: \""<<LA.lexeme<<"\"   token: "<<token<<endl;
	}
cout<<endl;
Lexico LA2("CREATE(arturo:ALUMNO)");
	token=SPACE;
	while (token!=STOP) {
		token = LA2.lex();
		cout<<"lexeme: \""<<LA2.lexeme<<"\"   token: "<<token<<endl;
	}
return 0;
} */

