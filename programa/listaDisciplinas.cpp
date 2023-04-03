#include "listaDisciplinas.hpp"

listaDisciplinas::listaDisciplinas (int nd, const char* n)
{
  numero_disc = nd;
  cont_disc = 0;
  pElDisciplinaPrim = NULL;
  pElDisciplinaAtual = NULL;
  strcpy ( nome, n );
}

listaDisciplinas::~listaDisciplinas()
{
  elDisciplina *paux1, *paux2;
  paux1 = pElDisciplinaPrim;
  paux2 = paux1;
  while ( paux1 != NULL )
  {
    paux2 = paux1->pProx;
    delete ( paux1 );
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
    elDisciplina* paux;
// Aqui é criado um objeto LAluno, sendo seu
// endereço armazenado em aux
    paux = new elDisciplina ( );
// Aqui recebe uma cópia do objeto interm.
    paux->setDisciplina ( pDi );
    if ( pElDisciplinaPrim == NULL )
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
    cout << " Disciplina não incluída " << " Quantia de disc. já lotada em " << numero_disc << " disciplinas." << endl;
  }
}

void listaDisciplinas::listeDisciplinas()
{
  elDisciplina* pAux;
  pAux = pElDisciplinaPrim;
  while ( pAux != NULL )
  {
    cout << "A disciplina "<< pAux->getNome() << " pertence ao Departamento " << nome << endl;
    pAux = pAux->pProx;
  }
}

void listaDisciplinas::listeDisciplinas2()
{
  elDisciplina* pAux;
  pAux = pElDisciplinaAtual;
  while ( pAux != NULL )
  {
    cout << "A disciplina "<< pAux->getNome() << " pertence ao Departamento " << nome << endl;
    pAux = pAux->pAnte;
  }
}