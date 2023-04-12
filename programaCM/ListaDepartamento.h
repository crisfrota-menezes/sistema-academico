#pragma once
#include "lista.hpp"
#include "elemento.hpp"
#include "departamento.hpp"

class ListaDepartamento
{
    public:
        ListaDepartamento(int nd = 1000, const char* n = "");
        virtual ~ListaDepartamento();
        void setNome (char* n);
        void incluaDepartamento(Departamento* pd);
        void listeDepartamentos();
        void listeDepartamentos2();
        Departamento *localizar(char *n);

    private:

        int cont_dep;
        int numero_dep;
        char nome[150];
        lista<Departamento> LTDepartamento;
};
