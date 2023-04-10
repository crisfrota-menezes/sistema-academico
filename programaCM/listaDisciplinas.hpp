#pragma once

#include "elemento.hpp"
#include "disciplina.hpp"

class listaDisciplinas
{
private:
  int cont_disc;
  int numero_disc;
  char nome[30];

  elemento<Disciplina> *pElDisciplinaPrim;
  elemento<Disciplina> *pElDisciplinaAtual;

public:
  listaDisciplinas(int nd = 1000, const char *n = "");
  ~listaDisciplinas();

  void setNome(const char *n);

  void incluiDisciplina(Disciplina *pDi);
  void listeDisciplinas();
  void listeDisciplinas2();

  void salveDisciplinas();
  void carregueDisciplinas();

  void limpaLista();
};