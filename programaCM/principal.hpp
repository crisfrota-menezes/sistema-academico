#pragma once

#include "bibliotecasLocais.hpp"

class Principal
{
private:
  /*Para cada classe existente no sistema, criar um atributo Id que servirá para identificar de forma única um objeto. Assim sendo, a cada objeto criado/instanciado, atribuir um id único para ele.*/
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

  listaUniversidades lUniversidades;
  listaDepartamentos lDepartamentos;
  listaDisciplinas lDisciplinas;
  listaAlunos lAlunos;

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

  /*Elabore uma solução que permita registrar os “objetos” (i.e.
suas informações em arquivos) de forma a recuperá-los em uma segunda execução do sistema.*/

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