#pragma once

#include "bibliotecasLocais.hpp"

class Principal
{
private:
  Universidade UTFPR;
  Universidade Princeton;
  Universidade Cambridge;

  Departamento ModaUTFPR;
  Departamento TecnologiaUTFPR;
  Departamento DAINF;
  Departamento FisicaPrinceton;
  Departamento MatematicaCambridge;

  Professor Cristiano;
  Professor Einstein;
  Professor Newton;

  Disciplina Computacao1_2006;
  Disciplina Introd_Alg_2007;
  Disciplina Computacao2_2007;
  Disciplina Metodos2_2007;

  Aluno AAA;
  Aluno BBB;
  Aluno CCC;
  Aluno DDD;
  Aluno EEE;

  int diaAtual;
  int mesAtual;
  int anoAtual;

  listaUniversidades lUniversidades;
  listaDepartamentos lDepartamentos;
  listaDisciplinas lDisciplinas;

public:
  Principal();
  ~Principal();

  void inicializa();
  void inicializaAlunos();
  void inicializaUniversidades();
  void inicializaDepartamentos();
  void inicializaProfessores();
  void inicializaDisciplinas();

  void executar();

  void infoProfs();
  void listaDiscDeptos();
  void listaAlunosDisc();

  void cadDisciplina();
  void cadDepartamento();
  void cadUniversidade();

  void menu();
  void menuCad();
  void menuExe();
};