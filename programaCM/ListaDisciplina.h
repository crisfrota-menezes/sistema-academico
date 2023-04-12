#pragma once
#include "lista.hpp"
#include "elemento.hpp"

class Disciplina;

class ListaDisciplinas
{
private:

	int cont_disc;
	int numero_disc;
	char nome[150];

	lista<Disciplina> LTdisciplinas;

public:

	ListaDisciplinas(int nd = 1000, const char* n = "");
	~ListaDisciplinas();

	void setNome(char* n);
	void incluaDisciplina(Disciplina* pd);
    void listeDisciplinas();
    void listeDisciplinas2();
};

