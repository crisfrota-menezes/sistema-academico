#pragma once

class Disciplina;
class Universidade;
class listaDisciplinas;

class Departamento
{
private:
  char nomeD[30];
  Universidade *depUni;
  listaDisciplinas *pObjLDisciplinas;

public:
  Departamento();
  ~Departamento();

  void setNome(const char *n);
  char *getNome();

  void setUniversidade(Universidade *dU);
  Universidade *getUniversidade();

  void incluiDisciplina(Disciplina *dD);
  void listeDisciplinas();
  void listeDisciplinas2();
};
