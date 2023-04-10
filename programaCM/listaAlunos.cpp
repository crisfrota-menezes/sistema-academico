#include "listaAlunos.hpp"
#include "disciplina.hpp"
#include <iostream>
using std::cerr;
using std::ios;

#include <fstream>
using std::ifstream;
using std::ofstream;

#include <cstdlib>

listaAlunos::listaAlunos(int na, const char *n)
{
  cont_alunos = 0;
  numero_alunos = na;
  pElAlunoPrim = NULL;
  pElAlunoAtual = NULL;

  strcpy(nome, n);
}

listaAlunos::~listaAlunos()
{
  limpaLista();
}

void listaAlunos::incluirAluno(Aluno *pa)
{
  // Aqui é criado um ponteiro para LAluno
  elemento<Aluno> *paux;
  // Aqui é criado um objeto LAluno, sendo seu endereço armazenado em aux
  paux = new elemento<Aluno>();
  // paux->setNome(pa->getNome());
  //  Aqui recebe uma cópia do objeto interm.
  paux->setInfo(pa);

  paux->setProximo(NULL);
  paux->setAnterior(NULL);

  if ((cont_alunos < numero_alunos) && (pa != NULL))
  {

    if (pElAlunoPrim == NULL)
    {
      pElAlunoPrim = paux;
      pElAlunoAtual = paux;
    }
    else
    {
      pElAlunoAtual->setProximo(paux);
      paux->setAnterior(pElAlunoAtual);
      pElAlunoAtual = paux;
    }
    cont_alunos++;
  }
  else
  {
    if (pa != NULL)
    {
      cout << "Aluno não incluído. Turma já lotada em " << numero_alunos << " alunos." << endl;
    }
    else
    {
      cout << " Ponteiro nulo \n " << endl;
    }
  }
}

void listaAlunos::listarAlunos()
{
  Aluno *pauxAl = NULL;
  elemento<Aluno> *pauxEl = pElAlunoPrim;
  while (NULL != pauxEl)
  {
    pauxAl = pauxEl->getInfo();
    cout << "Aluno " << pauxAl->getNome() << " matriculado na Disciplina " << nome << endl;
    pauxEl = pauxEl->getProximo();
  }
}

void listaAlunos::listarAlunos2()
{
  Aluno *pauxAl = NULL;
  elemento<Aluno> *pauxEl = pElAlunoPrim;
  while (NULL != pauxEl)
  {
    pauxAl = pauxEl->getInfo();
    cout << "Aluno " << pauxAl->getNome() << " matriculado na Disciplina " << nome << endl;
    pauxEl = pauxEl->getAnterior();
  }
}

void listaAlunos::salveAlunos()
{
  ofstream sAlunos("alunos.dat", ios::out);

  if (!sAlunos)
  {
    cerr << "Arquivo não pode ser aberto" << endl;
    fflush(stdin);
    getchar();
  }

  elemento<Aluno> *sauxElAluno = NULL;
  Aluno *sauxAluno = NULL;
  sauxElAluno = pElAlunoPrim;

  while (sauxElAluno != NULL)
  {
    sauxAluno = sauxElAluno->getInfo();
    sAlunos << sauxAluno->getId() << ' ' << sauxAluno->getRa() << ' ' << sauxAluno->getNome() << endl;
    sauxElAluno = sauxElAluno->getProximo();
  }
  sAlunos.close();
}

void listaAlunos::carregueAlunos()
{
  ifstream cAlunos("alunos.dat", ios::in);
  if (!cAlunos)
  {
    cerr << "Arquivo não pode ser aberto." << endl;
    fflush(stdin);
    getchar();
  }
  limpaLista();

  while (!cAlunos.eof())
  {
    Aluno *cauxAluno;
    cauxAluno = new Aluno(-1);
    int id;
    int RA;
    char nomeA[50];
    cAlunos >> id >> RA >> nomeA;
    if (0 != strcmp(nomeA, ""))
    {
      cauxAluno->setId(id);
      cauxAluno->setRa(RA);
      cauxAluno->setNome(nomeA);

      incluirAluno(cauxAluno);
    }
  }
  cAlunos.close();
}

void listaAlunos::limpaLista()
{
  elemento<Aluno> *aux1, *aux2;
  aux1 = pElAlunoPrim;
  aux2 = aux1;
  while (aux1 != NULL)
  {
    aux2 = aux1->getProximo();
    delete (aux1);
    aux1 = aux2;
  }
  pElAlunoPrim = NULL;
  pElAlunoAtual = NULL;
}