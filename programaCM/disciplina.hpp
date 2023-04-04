#pragma once

#include "departamento.hpp"
#include "listaAlunos.hpp"

class Disciplina
{
private:
  int id;
  char nome[50];
  char area_conhecimento[50];
  Departamento *pDptoAssociado;

  ListaAlunos ObjAlunos;

public:
  Disciplina(int na = 45, const char *ac = "");
  ~Disciplina();

  Disciplina *pProx;
  Disciplina *pAnte;

  void setId(int n);
  int getId();

  void setNome(const char *n);
  char *getNome();

  void setDepartamento(Departamento *pDpto);
  Departamento *getDepartamento();

  void incluirAluno(Aluno *pA);
  void listarAlunos();
  void listarAlunos2();
};