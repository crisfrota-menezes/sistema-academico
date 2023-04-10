#pragma once

#include "elemento.hpp"
#include "aluno.hpp"

class listaAlunos
{
private:
  int numero_alunos;
  int cont_alunos;
  char nome[30];

  elemento<Aluno> *pElAlunoPrim;
  elemento<Aluno> *pElAlunoAtual;

public:
  listaAlunos(int na = 45, const char *n = "");
  ~listaAlunos();

  void incluirAluno(Aluno *pA);
  void listarAlunos();
  void listarAlunos2();

  void salveAlunos();
  void carregueAlunos();

  void limpaLista();
};