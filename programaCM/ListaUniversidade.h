#pragma once
#include "universidade.hpp"
#include "elemento.hpp"
#include "lista.hpp"

class ListaUniversidade
{
public:
    ListaUniversidade(int nu = 1000, const char *n = "");
    virtual ~ListaUniversidade();

    void incluaUniversidade(Universidade *pu);
    void listeUniversidades();
    void listeUniversidades2();

    Universidade *localizar(char *n);

protected:
private:
    int cont_univ;
    int numero_univ;
    char nome[150];
    lista<Universidade> LTUniversidade;
};
