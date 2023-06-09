#include "elAluno.hpp"
#include "disciplina.hpp"

elAluno::elAluno()
{
  pProx = NULL;
  pAnte = NULL;
}

elAluno::~elAluno()
{
  pProx = NULL;
  pAnte = NULL;
}

void elAluno::setAluno(Aluno *pA)
{
  pAluno = pA;
}

Aluno *elAluno::getAluno()
{
  return pAluno;
}

char *elAluno::getNome()
{
  return pAluno->getNome();
}

char *elAluno::getNomeDisciplina()
{
  return pAluno->getDisciplina()->getNome(); // retorna o nome da disciplina do aluno
}