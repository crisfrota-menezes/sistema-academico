#pragma once
#include <list>
using namespace std;
#include "departamento.hpp"

class Universidade
{
private:
  char nomeU[30];
  list<Departamento *> pDpto;

public:
  Universidade();
  ~Universidade();

  void setNome(const char *n);
  char *getNome();
  void setDepartamento(Departamento *pDep, int ctd);
};
