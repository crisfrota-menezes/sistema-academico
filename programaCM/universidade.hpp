#pragma once

#include "lista.hpp"
#include "departamento.hpp"

class Universidade
{
private:
  int id;
  char nomeU[30];
  lista<Departamento> ObjLDepartamentos;

public:
  Universidade();
  ~Universidade();
  void setNome(const char *n);
  char *getNome();
  Universidade *localizarUni();
  void incluiDepartamento(Departamento *pd);
  void listeDepartamentos();
  void listeDepartamentos2();
};
