#pragma once

#include "listaDepartamento.hpp"

class Universidade
{
private:
  int id;
  char nomeU[30];
  listaDepartamentos ObjLDepartamentos;

public:
  Universidade();
  ~Universidade();

  void setNome(const char *n);
  char *getNome();

  void incluiDepartamento(Departamento *pd);
  void listeDepartamentos();
  void listeDepartamentos2();
};
