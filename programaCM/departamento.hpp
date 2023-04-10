#pragma once

class Disciplina;
class Universidade;
class listaDisciplinas;

class Departamento
{
private:
  char nomeD[30];
  int id;

  Universidade *depUni;
  listaDisciplinas *pObjLDisciplinas;

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
