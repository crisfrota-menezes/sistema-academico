#include "principal.hpp"
#include <time.h>

Principal::Principal ()
{
  //Pega a data atual por meio da biblioteca time.h
  struct tm *local;
  time_t segundos;
  time (&segundos);
  local = localtime (&segundos);

  diaAtual = local->tm_mday;

  mesAtual = local->tm_mon + 1;

  anoAtual = local->tm_year + 1900;
  
  inicializa ();
}

Principal::~Principal ()
{
}

void Principal::inicializa()
{ 
  inicializaAlunos();
  inicializaUniversidades ( );
  inicializaDepartamentos ( );
  inicializaProfessores ( );
  inicializaDisciplinas ( );
  executar();
}

void Principal::inicializaAlunos()
{
  AAA.setNome("AAA");
	BBB.setNome("BBB");
	CCC.setNome("CCC");
	DDD.setNome("DDD");
	EEE.setNome("EEE");
}

void Principal::inicializaUniversidades()
{
  UTFPR.setNome ( "UTFPR" );
  Princeton.setNome ( "Princeton" );
  Cambridge.setNome ( "Cambridge" );
}

void Principal::inicializaDepartamentos()
{
  ModaUTFPR.setNome ("Moda");
  TecnologiaUTFPR.setNome ("Tecnologia da UTFPR");
  DAINF.setNome ("Informatica da UTFPR");
  FisicaPrinceton.setNome ("Fisica");
  MatematicaCambridge.setNome ("Matematica");

  UTFPR.setDepartamento (&DAINF, 0);
  UTFPR.setDepartamento (&ModaUTFPR, 1);
  UTFPR.setDepartamento (&TecnologiaUTFPR, 2);
  Princeton.setDepartamento (&FisicaPrinceton, 0);
  Cambridge.setDepartamento (&MatematicaCambridge, 0);

  ModaUTFPR.setUniversidade (&UTFPR);
  TecnologiaUTFPR.setUniversidade (&UTFPR);
  DAINF.setUniversidade (&UTFPR);
  FisicaPrinceton.setUniversidade (&Princeton);
  MatematicaCambridge.setUniversidade (&Cambridge);
}

void Principal::inicializaProfessores()
{
  Cristiano.inicializa (28, 5, 2000, "Cristiano");
  Einstein.inicializa (14, 3, 1879, "Einstein");
  Newton.inicializa (4, 1, 1643, "Newton");

  Cristiano.setUnivFiliado (&UTFPR);
  Einstein.setUnivFiliado (&Princeton);
  Newton.setUnivFiliado (&Cambridge);

  Cristiano.setDepartamento (&DAINF);
  Einstein.setDepartamento (&FisicaPrinceton);
  Newton.setDepartamento (&MatematicaCambridge);
}

void Principal::inicializaDisciplinas()
{
  Computacao1_2006.setNome ( "Computacao I 2006" );
  Introd_Alg_2007.setNome ( "Intro de Algde Programacao 2007" );
  Computacao2_2007.setNome ( "Computao II" );
  Metodos2_2007.setNome ( "Métodos II" );

  Computacao1_2006.setDepartamento(&DAINF);
  Introd_Alg_2007.setDepartamento(&DAINF);
  Computacao2_2007.setDepartamento(&DAINF);
  Metodos2_2007.setDepartamento(&DAINF);

  Metodos2_2007.incluirAluno(&AAA);
  Metodos2_2007.incluirAluno(&BBB);
  Metodos2_2007.incluirAluno(&CCC);
  Metodos2_2007.incluirAluno(&DDD);
  Metodos2_2007.incluirAluno(&EEE);

  Computacao2_2007.incluirAluno(&AAA);
  Computacao2_2007.incluirAluno(&EEE);
}

void Principal::executar ()
{
  infoProfs();
  listaDiscDeptos ( );
  listaAlunosDisc( );
}

void Principal::infoProfs()
{
  Cristiano.calcula_idade (diaAtual, mesAtual, anoAtual);
  Cristiano.ondeTrabalho ();
  Cristiano.departamentoQueTrabalho ();

  Einstein.calcula_idade (diaAtual, mesAtual, anoAtual);
  Einstein.ondeTrabalho ();
  Einstein.departamentoQueTrabalho ();

  Newton.calcula_idade (diaAtual, mesAtual, anoAtual);
  Newton.ondeTrabalho ();
  Newton.departamentoQueTrabalho ();
}

void Principal::listaDiscDeptos()
{
  cout << endl;
  DAINF.listeDisciplinas();
  cout << endl;
}

void Principal::listaAlunosDisc()
{
  Metodos2_2007.listarAlunos();
  cout << endl;
  Metodos2_2007.listarAlunos2();
  cout << endl;
  Computacao2_2007.listarAlunos();
  cout << endl;
}