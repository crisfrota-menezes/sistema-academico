#include "universidade.hpp"
#include <string.h>

Universidade::Universidade() : ObjLDepartamentos()
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
char *Universidade::getNome()
{
  return nomeU;
}
void Universidade::incluiDepartamento(Departamento *pd)
{
  ObjLDepartamentos.incluirInfo(pd);
}
void Universidade::listeDepartamentos()
{
  ObjLDepartamentos.listarInfos();
}
void Universidade::listeDepartamentos2()
{
  // ObjLDepartamentos.listeDepartamentos2();
}