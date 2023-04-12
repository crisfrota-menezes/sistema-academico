#include "principal.hpp"
#include "bibliotecasPadrao.hpp"

Principal::Principal() : //"geradores" de identificação
                         cont_idDisc(0),
                         cont_idDepart(0),
                         cont_idAluno(0),
                         // Construtores dos objetos da classe Departamento
                         ModaUTFPR(cont_idDepart++),
                         TecnologiaUTFPR(cont_idDepart++),
                         DAINF(cont_idDepart++),
                         FisicaPrinceton(cont_idDepart++),
                         MatematicaCambridge(cont_idDepart++),
                         // Construtores dos objetos da classe Disciplina
                         Computacao1_2006(cont_idDisc++),
                         Introd_Alg_2007(cont_idDisc++),
                         Computacao2_2007(cont_idDisc++),
                         Metodos2_2007(cont_idDisc++),
                         // Construtores dos objetos da classe Aluno
                         AAA(cont_idAluno++),
                         BBB(cont_idAluno++),
                         CCC(cont_idAluno++),
                         DDD(cont_idAluno++),
                         EEE(cont_idAluno++)
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
  lAlunos.incluaInfo(&AAA, AAA.getNome());
  BBB.setNome("BBB");
  lAlunos.incluaInfo(&BBB, BBB.getNome());
  CCC.setNome("CCC");
  lAlunos.incluaInfo(&CCC, CCC.getNome());
  DDD.setNome("DDD");
  lAlunos.incluaInfo(&DDD, DDD.getNome());
  EEE.setNome("EEE");
  lAlunos.incluaInfo(&EEE, EEE.getNome());
}
void Principal::inicializaUniversidades()
{
  UTFPR.setNome("UTFPR");
  lUniversidades.incluaInfo(&UTFPR, UTFPR.getNome());
  Princeton.setNome("Princeton");
  lUniversidades.incluaInfo(&Princeton, Princeton.getNome());
  Cambridge.setNome("Cambridge");
  lUniversidades.incluaInfo(&Cambridge, Cambridge.getNome());
}
void Principal::inicializaDepartamentos()
{
  ModaUTFPR.setNome("Moda");
  TecnologiaUTFPR.setNome("Tecnologia da UTFPR");
  DAINF.setNome("Informatica da UTFPR");
  FisicaPrinceton.setNome("Fisica");
  MatematicaCambridge.setNome("Matematica");

  lDepartamentos.incluaInfo(&ModaUTFPR, ModaUTFPR.getNome());
  lDepartamentos.incluaInfo(&TecnologiaUTFPR, TecnologiaUTFPR.getNome());
  lDepartamentos.incluaInfo(&DAINF, DAINF.getNome());
  lDepartamentos.incluaInfo(&FisicaPrinceton, FisicaPrinceton.getNome());
  lDepartamentos.incluaInfo(&MatematicaCambridge, MatematicaCambridge.getNome());

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

  lDisciplinas.incluaInfo(&Computacao1_2006, Computacao1_2006.getNome());
  lDisciplinas.incluaInfo(&Introd_Alg_2007, Introd_Alg_2007.getNome());
  lDisciplinas.incluaInfo(&Computacao2_2007, Computacao2_2007.getNome());
  lDisciplinas.incluaInfo(&Metodos2_2007, Metodos2_2007.getNome());

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
void Principal::executar()
{
  // infoProfs();
  // listaDiscDeptos();
  // listaAlunosDisc();
  menu();
}
void Principal::cadDisciplina()
{
  cout << "Cadastro de Disciplina" << endl;
  char nomeDepartamento[100];
  char nomeDisciplina[100];
  Departamento *pDep;
  Disciplina *pDisc;
  cout << "Informe o nome do departamento: ";
  cin >> nomeDepartamento;
  pDep = lDepartamentos.localizar(nomeDepartamento);
  if (pDep != NULL)
  {
    cout << "Informe o nome da disciplina: ";
    cin >> nomeDisciplina;
    pDisc = new Disciplina(cont_idDisc);
    cont_idDisc++;
    pDisc->setNome(nomeDisciplina);
    pDisc->setDepartamento(pDep);
    lDisciplinas.incluaInfo(pDisc, nomeDisciplina);
    lDepartamentos.incluaInfo(pDep);
    pDep->incluiDisciplina(pDisc);
  }
  else
  {
    cout << "Departamento nao encontrado" << endl;
    cout << "Tente novamente em 3 segundos..." << endl;
    sleep_for(seconds(3));
  }
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
    pDep = new Departamento(cont_idDepart);
    cont_idDepart++;
    pDep->setNome(nomeDepartamento);
    pDep->setUniversidade(pUniv);
    lDepartamentos.incluaInfo(pDep);
    lUniversidades.incluaInfo(pUniv, nomeUniversidade);
    pUniv->incluiDepartamento(pDep);
  }
  else
  {
    cout << "Universidade nao encontrada!" << endl;
    cout << "Tente novamente em 3 segundos..." << endl;
    sleep_for(seconds(3));
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
  lUniversidades.incluaInfo(pUniv, nomeUniversidade);
}
void Principal::cadAluno()
{
  char nomeAluno[50];
  int ra;
  Aluno *al;

  cout << "Informe o nome do aluno: " << endl;
  cin >> nomeAluno;
  cout << "Informe o RA do aluno: " << endl;
  cin >> ra;

  al = new Aluno(cont_idAluno++);
  al->setNome(nomeAluno);
  al->setRa(ra);

  lAlunos.incluaInfo(al, al->getNome());
}
/*Funções de salvar e carregar por enquanto ainda vazias: */
void Principal::salvarTudo() {}
void Principal::salvarUniversidades() {}
void Principal::salvarDepartamentos()
{
  // lDepartamentos.salveDepartamentos();
}
void Principal::salvarDisciplinas()
{
  // lDisciplinas.salveDisciplinas();
}
void Principal::salvarAlunos()
{
  // lAlunos.salveAlunos();
}
void Principal::salvarProfessores() {}
void Principal::carregarTudo() {}
void Principal::carregarUniversidades() {}
void Principal::carregarDepartamentos()
{
  // lDepartamentos.carregueDepartamentos();
}
void Principal::carregarDisciplinas()
{
  // lDisciplinas.carregueDisciplinas();
}
void Principal::carregarAlunos()
{
  // lAlunos.carregueAlunos();
}
void Principal::carregarProfessores() {}
void Principal::menuCad()
{
  int op = -1;
  while (op != 5)
  {
    system("cls");
    cout << "Informe sua opcao: " << endl;
    cout << "1 - Cadastrar Disciplina." << endl;
    cout << "2 - Cadastrar Departamentos." << endl;
    cout << "3 - Cadastrar Universidade" << endl;
    cout << "4 - Cadastrar Aluno" << endl;
    cout << "5 - Voltar" << endl;
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
      cadAluno();
    }
    break;
    case 5:
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
  while (op != 5)
  {
    system("cls");
    cout << "Informe sua opcao: " << endl;
    cout << "1 - Listar Disciplinas." << endl;
    cout << "2 - Listar Departamentos." << endl;
    cout << "3 - Listar Universidade." << endl;
    cout << "4 - Listar Alunos" << endl;
    cout << "5 - Voltar" << endl;
    cin >> op;

    switch (op)
    {
    case 1:
    {
      //lDisciplinas.listarInfos();
      fflush(stdin);
      system("Pause");
    }
    break;
    case 2:
    {
      //lDepartamentos.listarInfos();
      fflush(stdin);
      system("Pause");
    }
    break;
    case 3:
    {
      //lUniversidades.listarInfos();
      fflush(stdin);
      system("Pause");
    }
    break;
    case 4:
    {
      //lAlunos.listeAlunos();
      fflush(stdin);
      system("Pause");
    }
    break;
    case 5:
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
void Principal::menuSalvar()
{
  int op = -1;
  while (op != 6)
  {
    system("cls");
    cout << "  Informe sua opção:			" << endl;
    cout << "  0 - Salvar Tudo.				" << endl;
    cout << "  1 - Salvar Universidades.	" << endl;
    cout << "  2 - Salvar Departamentos.	" << endl;
    cout << "  3 - Salvar Disciplinas.		" << endl;
    cout << "  4 - Salvar Alunos.			" << endl;
    cout << "  5 - Salvar Professores.		" << endl;
    cout << "  6 - Voltar.					" << endl;
    cin >> op;

    switch (op)
    {
    case 0:
    {
      salvarTudo();
    }
    break;
    case 1:
    {
      salvarUniversidades();
    }
    break;
    case 2:
    {
      salvarDepartamentos();
    }
    break;
    case 3:
    {
      salvarDisciplinas();
    }
    break;
    case 4:
    {
      salvarAlunos();
    }
    break;
    case 5:
    {
      salvarProfessores();
    }
    break;
    case 6:
    {
      cout << " Voltando... " << endl;
    }
    break;
    default:
    {
      cout << "Opção Inválida - Pressione uma tecla." << endl;
      getchar();
    }
    }
  }
}
void Principal::menuCarregar()
{
  int op = -1;

  while (op != 6)
  {
    system("cls");

    cout << "  Informe sua opção:			" << endl;
    cout << "  0 - Carregar Tudo.			" << endl;
    cout << "  1 - Carregar Universidades.	" << endl;
    cout << "  2 - Carregar Departamentos.	" << endl;
    cout << "  3 - Carregar Disciplinas.	" << endl;
    cout << "  4 - Carregar Alunos.		" << endl;
    cout << "  5 - Carregar Professores.	" << endl;
    cout << "  6 - Voltar.					" << endl;
    cin >> op;

    switch (op)
    {
    case 0:
    {
      carregarTudo();
    }
    break;
    case 1:
    {
      carregarUniversidades();
    }
    break;
    case 2:
    {
      carregarDepartamentos();
    }
    break;
    case 3:
    {
      carregarDisciplinas();
    }
    break;
    case 4:
    {
      carregarAlunos();
    }
    break;
    case 5:
    {
      carregarProfessores();
    }
    break;
    case 6:
    {
      cout << " Voltando... " << endl;
    }
    break;
    default:
    {
      cout << "Opção Inválida - Pressione uma tecla." << endl;
      getchar();
    }
    }
  }
}
void Principal::menu()
{
  int op = -1;
  while (op != 5)
  {
    system("cls");
    cout << "Informe sua opcao: " << endl;
    cout << "1 - Cadastrar." << endl;
    cout << "2 - Executar" << endl;
    cout << "3 - Salvar." << endl;
    cout << "4 - Carregar." << endl;
    cout << "5 - Sair" << endl;
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
      menuSalvar();
    }
    break;
    case 4:
    {
      menuCarregar();
    }
    break;
    case 5:
    {
      cout << "Saindo..." << endl;
      system("Pause");
    }
    break;
    default:
    {
      cout << "Opcao invalida!" << endl;
    }
    }
  }
}