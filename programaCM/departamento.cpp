#include "departamento.hpp"
#include <string.h>
#include "universidade.hpp"
#include "disciplina.hpp"

Departamento::Departamento(int i)
{
  id = i;
  pObjLDisciplinas = new lista<Disciplina>();
}
Departamento::Departamento()
{
  pObjLDisciplinas = new lista<Disciplina>();
}
Departamento::~Departamento()
{
  if (pObjLDisciplinas)
  {
    delete pObjLDisciplinas;
  }
}
void Departamento::setId(int i)
{
  id = i;
}
int Departamento::getId()
{
  return id;
}
void Departamento::setNome(const char *n)
{
  strcpy(nomeD, n);
  pObjLDisciplinas->setNome(n);
}
char *
Departamento::getNome()
{
  return nomeD;
}
void Departamento::setUniversidade(Universidade *dU)
{
  depUni = dU;
}
Universidade *Departamento::getUniversidade()
{
  return depUni;
}
void Departamento::incluiDisciplina(Disciplina *pdi)
{
  pObjLDisciplinas->incluirInfo(pdi, pdi->getNome());
}
void Departamento::listeDisciplinas()
{
  pObjLDisciplinas->listarInfos();
}
void Departamento::listeDisciplinas2()
{
  // pObjLDisciplinas->listeDisciplinas2();
}