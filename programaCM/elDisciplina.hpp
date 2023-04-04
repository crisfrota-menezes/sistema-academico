#pragma once

#include "disciplina.hpp"

class elDisciplina
{
private:
  Disciplina *pDisciplina;

public:
  elDisciplina();
  ~elDisciplina();
  elDisciplina *pProx;
  elDisciplina *pAnte;
  void setDisciplina(Disciplina *pD);
  Disciplina *getDisciplina();
  char *getNome();
};