#pragma once

#include "bibliotecasLocais.hpp"

class Principal
{
private:
  int cont_idDisc;
  int cont_idDepart;
  int cont_idAluno;

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

  ListaUniversidade lUniversidades;
  ListaDepartamento lDepartamentos;
  ListaDisciplinas lDisciplinas;
  ListaAlunos lAlunos;

public:
  Principal();
  ~Principal();

  void inicializa();
  void inicializaAlunos();
  void inicializaUniversidades();
  void inicializaDepartamentos();
  void inicializaProfessores();
  void inicializaDisciplinas();

  void infoProfs();
  void listaDiscDeptos();
  void listaAlunosDisc();

  void executar();

  void cadDisciplina();
  void cadDepartamento();
  void cadUniversidade();
  void cadAluno();

  void salvarTudo();
  void salvarUniversidades();
  void salvarDepartamentos();
  void salvarDisciplinas();
  void salvarAlunos();
  void salvarProfessores();

  void carregarTudo();
  void carregarUniversidades();
  void carregarDepartamentos();
  void carregarDisciplinas();
  void carregarAlunos();
  void carregarProfessores();

  void menuCad();
  void menuExe();
  void menuSalvar();
  void menuCarregar();
  void menu();
};