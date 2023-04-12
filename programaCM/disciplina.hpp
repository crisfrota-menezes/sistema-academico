#pragma once

#include "departamento.hpp"
#include "lista.hpp"
#include "listaAlunos.hpp"
#include "aluno.hpp"
#include "elemento.hpp"

class Disciplina
{
private:
  int id;
  int cont_alunos;
  int numero_alunos;
  char nome[50];
  char area_conhecimento[50];
  Departamento *pDptoAssociado;
  ListaAlunos ObjAlunos;

public:
  Disciplina(int i, int na = 45, const char *ac = "");
  ~Disciplina();
  void setId(int i);
  int getId();
  void setNome(const char *n);
  char *getNome();
  void setDepartamento(Departamento *pDpto);
  Departamento *getDepartamento();
  void incluirAluno(Aluno *pA);
  void listarAlunos();
  void listarAlunos2();
};