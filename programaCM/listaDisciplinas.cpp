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
  limpaLista();
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
    elemento<Disciplina> *paux;
    // Aqui é criado um objeto LAluno, sendo seu
    // endereço armazenado em aux
    paux = new elemento<Disciplina>();
    // Aqui recebe uma cópia do objeto interm.
    paux->setInfo(pDi);
    if (pElDisciplinaPrim == NULL)
    {
      pElDisciplinaPrim = paux;
      pElDisciplinaAtual = paux;
    }
    else
    {
      pElDisciplinaAtual->setProximo(paux);
      paux->setAnterior(pElDisciplinaAtual);
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
  Disciplina *pauxDisc = NULL;
  elemento<Disciplina> *pauxElDisc = pElDisciplinaPrim;
  while (NULL != pauxElDisc)
  {
    pauxDisc = pauxElDisc->getInfo();
    cout << "A disciplina " << pauxDisc->getNome() << " pertence ao Departamento " << nome << endl;
    pauxElDisc = pauxElDisc->getProximo();
  }
}

void listaDisciplinas::listeDisciplinas2()
{
  Disciplina *pauxDisc = NULL;
  elemento<Disciplina> *pauxElDisc = pElDisciplinaPrim;
  while (NULL != pauxElDisc)
  {
    pauxDisc = pauxElDisc->getInfo();
    cout << "A disciplina " << pauxDisc->getNome() << " pertence ao Departamento " << nome << endl;
    pauxElDisc = pauxElDisc->getAnterior();
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

  elemento<Disciplina> *sauxElDisc = NULL;
  Disciplina *sauxDisc = NULL;
  sauxElDisc = pElDisciplinaPrim;

  while (sauxElDisc != NULL)
  {
    sauxDisc = sauxElDisc->getInfo();
    sDisciplina << sauxDisc->getId() << ' ' << sauxDisc->getNome() << endl;
    sauxElDisc = sauxElDisc->getProximo();
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
  elemento<Disciplina> *paux1, *paux2;
  paux1 = pElDisciplinaPrim;
  paux2 = paux1;
  while (paux1 != NULL)
  {
    paux2 = paux1->getProximo();
    delete (paux1);
    paux1 = paux2;
  }
  pElDisciplinaPrim = NULL;
  pElDisciplinaAtual = NULL;
}