#pragma once
#include <string>
#include <list>

using namespace std;

class Nodo
{
	public:
		list< Nodo* > student;
		list< Nodo* > subject;
		list< Nodo* > department;
		list< Nodo* > doctor;
		string name;
		void setName(string);
		string getName(void);
		void insertStudent(Nodo *);
		void insertSubject(Nodo *);
		void insertDoctor(Nodo *);
		void insertDepartment(Nodo *);
		void deleteStudent(Nodo *);
		void deleteSubject(Nodo *);
		void deleteDoctor(Nodo *);
		void deleteDepartment(Nodo *);

		Nodo(string);
		~Nodo();
};

