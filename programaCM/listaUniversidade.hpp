#pragma once

#include "elemento.hpp"
#include "universidade.hpp"

class listaUniversidades
{
private:
    int cont_univ;
    int num_univ;
    char nome[30];

    elemento<Universidade> *pElUniPrimeiro;
    elemento<Universidade> *pElUniAtual;

public:
    listaUniversidades(int nu = 1000, const char *n = "");
    ~listaUniversidades();

    void incluiUniversidade(Universidade *pU);
    void listeUniversidades();
    void listeUniversidades2();
    Universidade *localizar(const char *n);
};