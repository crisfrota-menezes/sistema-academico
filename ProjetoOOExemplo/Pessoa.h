#ifndef _PESSOA_H_
#define _PESSOA_H_

#include "stdafx.h"

class Pessoa
{
protected:
    int diaP;
    int mesP;
    int anoP;
    int idadeP;
    string nomeP;

public:
    Pessoa(int diaNa, int mesNa, int anoNa, const char *nome = "");
    Pessoa();
    void Inicializa(int diaNa, int mesNa, int anoNa, const char *nome = "");
    void Calc_Idade(int diaAT, int mesAT, int anoAT);
    int informaIdade();

    void setNome(const char *n);
    const string getNome();

    virtual void informaProventos();
};

#endif
