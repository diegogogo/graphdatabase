// GraphDataBase.cpp: define el punto de entrada de la aplicación de consola.
//

#include "stdafx.h"
using namespace std;


int main()
{
	Nodo doctor1 = Nodo("Raul");
	Nodo materia1 = Nodo("Automatas");
	Nodo departamento1 = Nodo("Computacion");
	Nodo alumno1 = Nodo("Diego");
	list< Nodo *>::iterator i;
	
	alumno1.insertDoctor(&doctor1);
	

	
	cout << alumno1.getName() << endl;

	for (i = alumno1.doctor.begin(); i != alumno1.doctor.end(); ++i)
		cout << (*i)->name << endl;
	
	system("pause");
    return 0;
}

