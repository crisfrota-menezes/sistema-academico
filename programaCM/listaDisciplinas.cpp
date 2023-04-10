#include "listaDisciplinas.hpp"
#include <iostream>
using std::cerr;
using std::ios;
#include <fstream>
using std::ifstream;
using std::ofstream;

listaDisciplinas::listaDisciplinas(int nd, const char *n)
{
  numero_disc = nd;
  cont_disc = 0;
  pElDisciplinaPrim = NULL;
  pElDisciplinaAtual = NULL;
  strcpy(nome, n);
}

listaDisciplinas::~listaDisciplinas()
{
  elDisciplina *paux1, *paux2;
  paux1 = pElDisciplinaPrim;
  paux2 = paux1;
  while (paux1 != NULL)
  {
    paux2 = paux1->pProx;
    delete (paux1);
    paux1 = paux2;
  }
  pElDisciplinaPrim = NULL;
  pElDisciplinaAtual = NULL;
}

void listaDisciplinas::setNome(const char *n)
{
  strcpy(nome, n);
}

void listaDisciplinas::incluiDisciplina(Disciplina *pDi)
{
  if (((cont_disc < numero_disc) && (pDi != NULL)) ||
      ((numero_disc == -1) && (pDi != NULL)))
  {
    // Aqui é criado um ponteiro para LAluno
    elDisciplina *paux;
    // Aqui é criado um objeto LAluno, sendo seu
    // endereço armazenado em aux
    paux = new elDisciplina();
    // Aqui recebe uma cópia do objeto interm.
    paux->setDisciplina(pDi);
    if (pElDisciplinaPrim == NULL)
    {
      pElDisciplinaPrim = paux;
      pElDisciplinaAtual = paux;
    }
    else
    {
      pElDisciplinaAtual->pProx = paux;
      paux->pAnte = pElDisciplinaAtual;
      pElDisciplinaAtual = paux;
    }
    cont_disc++;
  }
  else
  {
    cout << " Disciplina não incluída "
         << " Quantia de disc. já lotada em " << numero_disc << " disciplinas." << endl;
  }
}

void listaDisciplinas::listeDisciplinas()
{
  elDisciplina *pAux;
  pAux = pElDisciplinaPrim;
  while (pAux != NULL)
  {
    cout << "A disciplina " << pAux->getNome() << " pertence ao Departamento " << nome << endl;
    pAux = pAux->pProx;
  }
}

void listaDisciplinas::listeDisciplinas2()
{
  elDisciplina *pAux;
  pAux = pElDisciplinaAtual;
  while (pAux != NULL)
  {
    cout << "A disciplina " << pAux->getNome() << " pertence ao Departamento " << nome << endl;
    pAux = pAux->pAnte;
  }
}

void listaDisciplinas::salveDisciplinas()
{
  ofstream sDisciplina("disciplinas.dat", ios::out);

  if (!sDisciplina)
  {
    cerr << "Arquivo não pode ser aberto" << endl;
    fflush(stdin);
    getchar();
  }

  elDisciplina *sauxElDisc = NULL;
  Disciplina *sauxDisc = NULL;
  sauxElDisc = pElDisciplinaPrim;

  while (sauxElDisc != NULL)
  {
    sauxDisc = sauxElDisc->getDisciplina();
    sDisciplina << sauxDisc->getId() << ' ' << sauxDisc->getNome() << endl;
    sauxElDisc = sauxElDisc->pProx;
  }
  sDisciplina.close();
}

void listaDisciplinas::carregueDisciplinas()
{
  ifstream cDisciplina("disciplinas.dat", ios::in);

  if (!cDisciplina)
  {
    cerr << "Arquivo não pode ser aberto" << endl;
    fflush(stdin);
    getchar();
  }

  Disciplina *cauxDisc = NULL;
  int id;
  char nomeDisc[30];

  while (cDisciplina >> id >> nomeDisc)
  {
    cauxDisc = new Disciplina(id, nomeDisc);
    incluiDisciplina(cauxDisc);
  }
  cDisciplina.close();
}

void listaDisciplinas::limpaLista()
{
  elDisciplina *paux1, *paux2;
  paux1 = pElDisciplinaPrim;
  paux2 = paux1;
  while (paux1 != NULL)
  {
    paux2 = paux1->pProx;
    delete (paux1);
    paux1 = paux2;
  }
  pElDisciplinaPrim = NULL;
  pElDisciplinaAtual = NULL;
}