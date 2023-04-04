#include "elDepartamento.hpp"

elDepartamento::elDepartamento()
{
    pProx = NULL;
    pAnte = NULL;
}

elDepartamento::~elDepartamento()
{
    pProx = NULL;
    pAnte = NULL;
}

void elDepartamento::setDepartamento(Departamento *pd)
{
    pDepartamento = pd;
}

Departamento *elDepartamento::getDepartamento()
{
    return pDepartamento;
}

char *elDepartamento::getNome()
{
    return pDepartamento->getNome();
}