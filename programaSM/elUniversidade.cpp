#include "elUniversidade.hpp"

elUniversidade::elUniversidade()
{
    pProx = NULL;
    pAnte = NULL;
}

elUniversidade::~elUniversidade()
{
    pProx = NULL;
    pAnte = NULL;
}

void elUniversidade::setUniversidade(Universidade *pU)
{
    pUniversidade = pU;
}

Universidade *elUniversidade::getUniversidade()
{
    return pUniversidade;
}

char *elUniversidade::getNome()
{
    return pUniversidade->getNome();
}