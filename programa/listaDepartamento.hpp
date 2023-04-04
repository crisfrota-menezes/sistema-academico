#pragma once

#include "departamento.hpp"
#include "elDepartamento.hpp"

class listaDepartamentos
{
    private:
    int cont_dep;
    int numero_dep;
    char nome[30];

    elDepartamento *pElDepartamentoPrim;
    elDepartamento *pElDepartamentoAtual;

    public:
    listaDepartamentos(int nd = 1000, const char *n = "");
    ~listaDepartamentos();

    void setNome(const char *n);
    void incluiDepartamento(Departamento *pDe);
    void listeDepartamentos();
    void listeDepartamentos2();
};