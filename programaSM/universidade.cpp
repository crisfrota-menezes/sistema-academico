#include "universidade.hpp"
#include <string.h>

Universidade::Universidade() : ObjLDepartamentos(-1, "")
{
}

Universidade::~Universidade()
{
}

void Universidade::setNome(const char *n)
{
  strcpy(nomeU, n);
  ObjLDepartamentos.setNome(n);
}

char *
Universidade::getNome()
{
  return nomeU;
}

void Universidade::incluiDepartamento(Departamento *pd)
{
  ObjLDepartamentos.incluiDepartamento(pd);
}

void Universidade::listeDepartamentos()
{
  ObjLDepartamentos.listeDepartamentos();
}

void Universidade::listeDepartamentos2()
{
  ObjLDepartamentos.listeDepartamentos2();
}