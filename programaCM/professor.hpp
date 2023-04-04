#pragma once

#include "pessoa.hpp"
#include "universidade.hpp"

class Professor : public Pessoa
{
private:
    Universidade *pUnivFiliado;
    Departamento *pDptoFiliado;

public:
    Professor(int diaNa, int mesNa, int anoNa, const char *nome = "");
    Professor();
    ~Professor();

    void
    setUnivFiliado(Universidade *pU);
    void
    setDepartamento(Departamento *pDep);
    void
    ondeTrabalho();
    void
    departamentoQueTrabalho();
};