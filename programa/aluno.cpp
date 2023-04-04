#include "aluno.hpp"
#include "disciplina.hpp"

Aluno::Aluno(int diaNa, int mesNa, int anoNa, const char *nome) : Pessoa(diaNa, mesNa, anoNa, nome)
{
}

Aluno::Aluno(int i) : Pessoa()
{
  id = i;
  RA = 0;
}

Aluno::~Aluno()
{
}

void Aluno::setRa(int ra)
{
  RA = ra;
}

int Aluno::getRa()
{
  return RA;
}

void Aluno::setDepartamento(Departamento *d)
{
  DeptoAssociado = d;
}

Departamento *Aluno::getDepartamento()
{
  return DeptoAssociado;
}

void Aluno::setId(int i)
{
  id = i;
}

int Aluno::getId()
{
  return id;
}

void Aluno::setDisciplina(Disciplina *d)
{
  pDisciplina = d;
}

Disciplina *Aluno::getDisciplina()
{
  return pDisciplina;
}