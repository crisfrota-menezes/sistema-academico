#pragma once

#include "departamento.hpp"
#include "lista.hpp"
#include "aluno.hpp"
#include "elemento.hpp"

class Disciplina
{
private:
  int id;
  char nome[50];
  char area_conhecimento[50];
  Departamento *pDptoAssociado;

  lista<Aluno> ObjAlunos;

public:
  Disciplina(int i, const char *ac = "");
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