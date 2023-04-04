#pragma once

#include "departamento.hpp"

class elDepartamento
{
private:
    Departamento *pDepartamento;

public:
    elDepartamento();
    ~elDepartamento();

    elDepartamento *pProx;
    elDepartamento *pAnte;

    void setDepartamento(Departamento *pd);
    Departamento *getDepartamento();

    char *getNome();
};