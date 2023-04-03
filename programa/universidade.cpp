#include "universidade.hpp"
#include <string.h>

Universidade::Universidade()
{
}

Universidade::~Universidade()
{
}

void Universidade::setNome(const char *n)
{
  strcpy(nomeU, n);
}

char *
Universidade::getNome()
{
  return nomeU;
}

void Universidade::setDepartamento(Departamento *pDep, int ctd)
{
  pDpto.push_back(pDep);
  ctd = ctd;
}