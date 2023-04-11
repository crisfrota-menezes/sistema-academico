#pragma once

#include "lista.hpp"
class Disciplina;
class Universidade;

class Departamento
{
private:
  char nomeD[30];
  int id;
  Universidade *depUni;
  lista<Disciplina> *pObjLDisciplinas;

public:
  Departamento();
  Departamento(int i);
  ~Departamento();
  void setId(int i);
  int getId();
  void setNome(const char *n);
  char *getNome();
  void setUniversidade(Universidade *dU);
  Universidade *getUniversidade();
  void incluiDisciplina(Disciplina *dD);
  void listeDisciplinas();
  void listeDisciplinas2();
};
