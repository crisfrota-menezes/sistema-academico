#include "principal.hpp"
#include <time.h>

Principal::Principal()
{
  // Pega a data atual por meio da biblioteca time.h
  struct tm *local;
  time_t segundos;
  time(&segundos);
  local = localtime(&segundos);

  diaAtual = local->tm_mday;

  mesAtual = local->tm_mon + 1;

  anoAtual = local->tm_year + 1900;

  inicializa();
}

Principal::~Principal()
{
}

void Principal::inicializa()
{
  inicializaAlunos();
  inicializaUniversidades();
  inicializaDepartamentos();
  inicializaProfessores();
  inicializaDisciplinas();
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
  UTFPR.setNome("UTFPR");
  Princeton.setNome("Princeton");
  Cambridge.setNome("Cambridge");
}

void Principal::inicializaDepartamentos()
{
  ModaUTFPR.setNome("Moda");
  TecnologiaUTFPR.setNome("Tecnologia da UTFPR");
  DAINF.setNome("Informatica da UTFPR");
  FisicaPrinceton.setNome("Fisica");
  MatematicaCambridge.setNome("Matematica");

  UTFPR.incluiDepartamento(&DAINF);
  UTFPR.incluiDepartamento(&ModaUTFPR);
  UTFPR.incluiDepartamento(&TecnologiaUTFPR);
  Princeton.incluiDepartamento(&FisicaPrinceton);
  Cambridge.incluiDepartamento(&MatematicaCambridge);
}

void Principal::inicializaProfessores()
{
  Cristiano.inicializa(28, 5, 2000, "Cristiano");
  Einstein.inicializa(14, 3, 1879, "Einstein");
  Newton.inicializa(4, 1, 1643, "Newton");

  Cristiano.setUnivFiliado(&UTFPR);
  Einstein.setUnivFiliado(&Princeton);
  Newton.setUnivFiliado(&Cambridge);

  Cristiano.setDepartamento(&DAINF);
  Einstein.setDepartamento(&FisicaPrinceton);
  Newton.setDepartamento(&MatematicaCambridge);
}

void Principal::inicializaDisciplinas()
{
  Computacao1_2006.setNome("Computacao I 2006");
  Introd_Alg_2007.setNome("Intro de Algde Programacao 2007");
  Computacao2_2007.setNome("Computao II");
  Metodos2_2007.setNome("Metodos II");

  Computacao1_2006.setDepartamento(&DAINF);
  Introd_Alg_2007.setDepartamento(&DAINF);
  Computacao2_2007.setDepartamento(&DAINF);
  Metodos2_2007.setDepartamento(&DAINF);

  Computacao1_2006.incluirAluno(&AAA);
  Computacao1_2006.incluirAluno(&BBB);
  Computacao1_2006.incluirAluno(&CCC);
  Computacao1_2006.incluirAluno(&DDD);
  Computacao1_2006.incluirAluno(&EEE);

  Computacao2_2007.incluirAluno(&AAA);
  Computacao2_2007.incluirAluno(&EEE);
}

void Principal::executar()
{
  infoProfs();
  listaDiscDeptos();
  listaAlunosDisc();
  menu();
}

void Principal::infoProfs()
{
  Cristiano.calcula_idade(diaAtual, mesAtual, anoAtual);
  Cristiano.ondeTrabalho();
  Cristiano.departamentoQueTrabalho();

  Einstein.calcula_idade(diaAtual, mesAtual, anoAtual);
  Einstein.ondeTrabalho();
  Einstein.departamentoQueTrabalho();

  Newton.calcula_idade(diaAtual, mesAtual, anoAtual);
  Newton.ondeTrabalho();
  Newton.departamentoQueTrabalho();
}

void Principal::listaDiscDeptos()
{
  cout << endl;
  DAINF.listeDisciplinas();
  cout << endl;
}

void Principal::listaAlunosDisc()
{
  Computacao1_2006.listarAlunos();
  cout << endl;
  Computacao1_2006.listarAlunos2();
  cout << endl;
  Computacao2_2007.listarAlunos();
  cout << endl;
}

void Principal::menu()
{
  int op = -1;
  while (op != 3)
  {
    system("cls");
    cout << "Informe sua opcao: " << endl;
    cout << "1 - Cadastrar." << endl;
    cout << "2 - Executar" << endl;
    cout << "3 - Sair" << endl;
    cin >> op;

    switch (op)
    {
    case 1:
    {
      menuCad();
    }
    break;
    case 2:
    {
      menuExe();
    }
    break;
    case 3:
    {
      cout << "Saindo..." << endl;
    }
    break;
    default:
    {
      cout << "Opcao invalida!" << endl;
      system("Pause");
    }
    }
  }
}

void Principal::menuCad()
{
  int op = -1;
  while (op != 4)
  {
    system("cls");
    cout << "Informe sua opcao: " << endl;
    cout << "1 - Cadastrar Disciplina." << endl;
    cout << "2 - Cadastrar Departamentos." << endl;
    cout << "3 - Cadastrar Universidade" << endl;
    cout << "4 - Voltar" << endl;
    cin >> op;

    switch (op)
    {
    case 1:
    {
      cadDisciplina();
    }
    break;
    case 2:
    {
      cadDepartamento();
    }
    break;
    case 3:
    {
      cadUniversidade();
    }
    break;
    case 4:
    {
      cout << "Voltando..." << endl;
    }
    break;
    default:
    {
      cout << "Opcao invalida!" << endl;
      system("Pause");
    }
    }
  }
}

void Principal::menuExe()
{
  int op = -1;
  while (op != 4)
  {
    system("cls");
    cout << "Informe sua opcao: " << endl;
    cout << "1 - Listar Disciplinas." << endl;
    cout << "2 - Listar Departamentos." << endl;
    cout << "3 - Listar Universidade." << endl;
    cout << "4 - Voltar" << endl;
    cin >> op;

    switch (op)
    {
    case 1:
    {
      lDisciplinas.listeDisciplinas();
      fflush(stdin);
      system("Pause");
    }
    break;
    case 2:
    {
      lDepartamentos.listeDepartamentos();
      fflush(stdin);
      system("Pause");
    }
    break;
    case 3:
    {
      lUniversidades.listeUniversidades();
      fflush(stdin);
      system("Pause");
    }
    break;
    case 4:
    {
      cout << "Voltando..." << endl;
    }
    break;
    default:
    {
      cout << "Opcao invalida!" << endl;
      system("Pause");
    }
    }
  }
}

void Principal::cadDisciplina()
{
  
}

void Principal::cadDepartamento()
{
  char nomeUniversidade[100];
  char nomeDepartamento[100];
  Universidade *pUniv;
  Departamento *pDep;
  cout << "Informe o nome da universidade: ";
  cin >> nomeUniversidade;
  pUniv = lUniversidades.localizar(nomeUniversidade);
  if (pUniv != NULL)
  {
    cout << "Informe o nome do departamento: ";
    cin >> nomeDepartamento;
    pDep = new Departamento();
    pDep->setNome(nomeDepartamento);
    pDep->setUniversidade(pUniv);
    lDepartamentos.incluiDepartamento(pDep);
    pUniv->incluiDepartamento(pDep);
  }
  else
  {
    cout << "Universidade nao encontrada!" << endl;
    _sleep(200);
  }
}

void Principal::cadUniversidade()
{
  char nomeUniversidade[100];
  Universidade *pUniv = NULL;
  cout << "Informe o nome da universidade: ";
  cin >> nomeUniversidade;
  pUniv = new Universidade();
  pUniv->setNome(nomeUniversidade);
  lUniversidades.incluiUniversidade(pUniv);
}
