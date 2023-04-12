#include "universidade.hpp"
#include "bibliotecasPadrao.hpp"

Universidade::Universidade() : ObjLDepartamentos()
{
}
Universidade::~Universidade()
{
}
void Universidade::setNome(const char *n)
{
  strcpy(nomeU, n);
  //ObjLDepartamentos.setNome(n);
}
char *Universidade::getNome()
{
  return nomeU;
}
Universidade *Universidade::localizarUni()
{
  return this;
}
void Universidade::incluiDepartamento(Departamento *pd)
{
  ObjLDepartamentos.incluaInfo(pd);
}
void Universidade::listeDepartamentos()
{
  //ObjLDepartamentos.listarInfos();
}
void Universidade::listeDepartamentos2()
{
  // ObjLDepartamentos.listeDepartamentos2();
}