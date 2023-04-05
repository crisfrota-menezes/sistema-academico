#pragma once

#include <string.h>
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

class Pessoa
{
protected:
    int
        diaP;
    int
        mesP;
    int
        anoP;
    int
        idadeP;
    char
        nomeP[30];
    int
        id;

public:
    Pessoa(int diaNa, int mesNa, int anoNa, const char *nome);
    Pessoa();
    void
    inicializa(int diaNa, int mesNa, int anoNa, const char *nome);
    void
    calcula_idade(int diaAT, int mesAT, int anoAT);
    int getIdade();
    void setId(int i) { id = i; }
    int getId() { return id; }
    char *getNome() { return nomeP; };
    void setNome(const char *nome) { strcpy(nomeP, nome); }
};