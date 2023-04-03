#include "listaAlunos.hpp"
#include "disciplina.hpp"

ListaAlunos::ListaAlunos(int na, const char *n)
{
  cont_alunos = 0;
  numero_alunos = na;
  pElAlunoPrim = NULL;
  pElAlunoAtual = NULL;

  strcpy(nome, n);
}

ListaAlunos::~ListaAlunos()
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

void ListaAlunos::incluirAluno(Aluno *pa)
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

void ListaAlunos::listarAlunos()
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

void ListaAlunos::listarAlunos2()
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