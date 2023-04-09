#include "disciplina.hpp"
#include <string.h>

Disciplina::Disciplina(int na, const char *ac) : ObjAlunos(na, ac)
{
  pDptoAssociado = NULL;
  pProx = NULL;
  pAnte = NULL;
  strcpy(area_conhecimento, ac);
}

Disciplina::~Disciplina()
{
  pDptoAssociado = NULL;
  pProx = NULL;
  pAnte = NULL;
}

void Disciplina::setId(int i) { id = i; }

int Disciplina::getId() { return id; }

void Disciplina::setNome(const char *n) { strcpy(nome, n); }

char *Disciplina::getNome() { return nome; }

void Disciplina::setDepartamento(Departamento *pDpto)
{
  pDptoAssociado = pDpto;
  pDpto->incluiDisciplina(this);
}

Departamento *Disciplina::getDepartamento()
{
  return pDptoAssociado;
}

void Disciplina::incluirAluno(Aluno *pA)
{
  ObjAlunos.incluirAluno(pA);
}

void Disciplina::listarAlunos() { ObjAlunos.listarAlunos(); }

void Disciplina::listarAlunos2() { ObjAlunos.listarAlunos2(); }