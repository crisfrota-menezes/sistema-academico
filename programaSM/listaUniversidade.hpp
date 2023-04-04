#pragma once

#include "elUniversidade.hpp"
#include "universidade.hpp"

class listaUniversidades
{
private:
    int cont_univ;
    int num_univ;
    char nome[30];

    elUniversidade *pElUniPrimeiro;
    elUniversidade *pElUniAtual;

public:
    listaUniversidades(int nu = 1000, const char *n = "");
    ~listaUniversidades();

    void incluiUniversidade(Universidade *pU);
    void listeUniversidades();
    void listeUniversidades2();
};