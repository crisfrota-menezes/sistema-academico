#pragma once

#include "elDisciplina.hpp"
#include "disciplina.hpp"

class listaDisciplinas
{
private:
  int cont_disc;
  int numero_disc;
  char nome[30];

  elDisciplina *pElDisciplinaPrim;
  elDisciplina *pElDisciplinaAtual;

public:
  listaDisciplinas(int nd = 1000, const char *n = "");
  ~listaDisciplinas();

  void setNome(const char *n);
  void incluiDisciplina(Disciplina *pDi);
  void listeDisciplinas();
  void listeDisciplinas2();
};