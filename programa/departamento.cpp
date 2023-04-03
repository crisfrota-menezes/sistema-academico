#include "departamento.hpp"
#include <string.h>
#include "universidade.hpp"
#include "disciplina.hpp"
#include "listaDisciplinas.hpp"

Departamento::Departamento()
{
  pObjLDisciplinas = new listaDisciplinas(-1, "");
}

Departamento::~Departamento()
{
  if (pObjLDisciplinas)
  {
    delete pObjLDisciplinas;
  }
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
  pObjLDisciplinas->incluiDisciplina(pdi);
}

void Departamento::listeDisciplinas()
{
  pObjLDisciplinas->listeDisciplinas();
}

void Departamento::listeDisciplinas2()
{
  pObjLDisciplinas->listeDisciplinas2();
}