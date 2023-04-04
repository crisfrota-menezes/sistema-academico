#pragma once

#include "elAluno.hpp"
#include "aluno.hpp"

class ListaAlunos
{
private:
  int numero_alunos;
  int cont_alunos;
  char nome[30];

  elAluno *pElAlunoPrim;
  elAluno *pElAlunoAtual;

public:
  ListaAlunos(int na, const char *n);
  ~ListaAlunos();

  void incluirAluno(Aluno *pA);
  void listarAlunos();
  void listarAlunos2();
};