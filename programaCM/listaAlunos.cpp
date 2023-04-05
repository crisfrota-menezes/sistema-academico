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
  elAluno *pAux1, *pAux2;

  pAux1 = pElAlunoPrim;
  pAux2 = pAux1;

  while (pAux1 != NULL)
  {
    pAux2 = pAux1->pProx;
    delete (pAux1);
    pAux1 = pAux2;
  }

  pElAlunoPrim = NULL;
  pElAlunoAtual = NULL;
}

void listaAlunos::incluirAluno(Aluno *pa)
{
  // Aqui é criado um ponteiro para LAluno
  elAluno *paux;
  // Aqui é criado um objeto LAluno, sendo seu endereço armazenado em aux
  paux = new elAluno();

  // Aqui recebe uma cópia do objeto interm.
  paux->setAluno(pa);

  paux->pProx = NULL;
  paux->pAnte = NULL;

  if ((cont_alunos < numero_alunos) && (pa != NULL))
  {

    if (pElAlunoPrim == NULL)
    {
      pElAlunoPrim = paux;
      pElAlunoAtual = paux;
    }
    else
    {
      pElAlunoAtual->pProx = paux;
      paux->pAnte = pElAlunoAtual;
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
  if (NULL != pElAlunoPrim)
  {
    elAluno *aux = pElAlunoPrim;
    cout << "Lista de alunos de: " << aux->getNomeDisciplina() << endl;
    while (NULL != aux)
    {
      cout << "Aluno " << aux->getAluno()->getNome() << " matriculado na Disciplina " << aux->getNomeDisciplina() << endl;
      aux = aux->pProx;
    }
  }
}

void listaAlunos::listarAlunos2()
{
  if (NULL != pElAlunoPrim)
  {
    elAluno *aux = pElAlunoAtual;
    cout << "Lista de alunos de: " << aux->getNomeDisciplina() << endl;
    while (NULL != aux)
    {
      cout << "Aluno " << aux->getAluno()->getNome() << " matriculado na Disciplina " << aux->getNomeDisciplina() << endl;
      aux = aux->pAnte;
    }
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

  elAluno *sauxElAluno;
  sauxElAluno = pElAlunoPrim;

  while (sauxElAluno != NULL)
  {
    Aluno *sauxAluno;
    sauxAluno = sauxElAluno->getAluno();
    sAlunos << sauxAluno->getId() << ' ' << sauxAluno->getRa() << ' ' << sauxAluno->getNome() << endl;
    sauxElAluno = sauxElAluno->pProx;
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
  elAluno *aux1, *aux2;
  aux1 = pElAlunoPrim;
  aux2 = aux1;
  while (aux1 != NULL)
  {
    aux2 = aux1->pProx;
    delete (aux1);
    aux1 = aux2;
  }
  pElAlunoPrim = NULL;
  pElAlunoAtual = NULL;
}