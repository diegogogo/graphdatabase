#include "stdafx.h"
#include "Nodo.h"


Nodo::Nodo(string nombre)
{
	name = nombre;
}


Nodo::~Nodo()
{
	
}

void Nodo::setName(string nombre)
{
	name = nombre;
}

string Nodo::getName(void)
{
	return name;
}

void Nodo::insertDepartment(Nodo *x)
{
	department.push_front(x);
}

void Nodo::insertDoctor(Nodo *x)
{
	doctor.push_front(x);
}

void Nodo::insertStudent(Nodo *x)
{
	student.push_front(x);
}

void Nodo::insertSubject(Nodo *x)
{
	subject.push_front(x);
}

void Nodo::deleteDepartment(Nodo *x)
{
	department.remove(x);
}

void Nodo::deleteDoctor(Nodo *x)
{
	doctor.remove(x);
}

void Nodo::deleteStudent(Nodo *x)
{
	student.remove(x);
}

void Nodo::deleteSubject(Nodo *x)
{
	subject.remove(x);
}