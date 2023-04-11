#pragma once

#include "elemento.hpp"
#include "departamento.hpp"
#include <iostream>
using namespace std;

class listaDepartamentos
{
private:
    int cont_dep;
    int numero_dep;
    char nome[30];

    elemento<Departamento> *pElDepartamentoPrim;
    elemento<Departamento> *pElDepartamentoAtual;

public:
    listaDepartamentos(int nd = 1000, const char *n = "");
    ~listaDepartamentos();

    void setNome(const char *n);

    void incluiDepartamento(Departamento *pDe);
    void listeDepartamentos();
    void listeDepartamentos2();

    void salveDepartamentos();
    void carregueDepartamentos();

    void limpaLista();
    Departamento *localizar(const char *n);
};