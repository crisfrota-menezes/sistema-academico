#pragma once

#include "universidade.hpp"

class elUniversidade
{
private:
    Universidade *pUniversidade;

public:
    elUniversidade();
    ~elUniversidade();

    elUniversidade *pProx;
    elUniversidade *pAnte;

    void setUniversidade(Universidade *pU);
    Universidade *getUniversidade();

    char *getNome();
};
