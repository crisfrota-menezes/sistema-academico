#pragma once

#include "listaDepartamento.hpp"

class Universidade
{
private:
  char nomeU[30];
  listaDepartamento *ObjLDepartamentos;

public:
  Universidade();
  ~Universidade();

  void setNome(const char *n);
  char *getNome();

  void incluiDepartamento(Departamento *pd);
  void listeDepartamentos();
  void listeDepartamentos2();
};
