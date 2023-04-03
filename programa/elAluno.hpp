#pragma once

#include "aluno.hpp"

class Disciplina;

class elAluno
{
private:
  Aluno *pAluno;

public:
  elAluno();
  ~elAluno();

  elAluno *pAnte;
  elAluno *pProx;

  void setAluno(Aluno *pA);
  Aluno *getAluno();
  char *getNome();
  char *getNomeDisciplina();
};