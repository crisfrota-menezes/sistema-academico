#include "ListaDisciplina.h"
#include "disciplina.hpp"

ListaDisciplinas::ListaDisciplinas(int nd, const char *n)
{
    numero_disc = nd;
    cont_disc = 0;
    strcpy(nome, n);
}

ListaDisciplinas::~ListaDisciplinas()
{
    LTdisciplinas.limpar();
}

void ListaDisciplinas::setNome(char *n)
{

    strcpy(nome, n);
}

void ListaDisciplinas::incluaDisciplina(Disciplina *pd)
{
    if (
        ((cont_disc < numero_disc) && (pd != NULL)) ||
        ((numero_disc == -1) && (pd != NULL)))
    {

        LTdisciplinas.incluaInfo(pd);
        cont_disc++;
    }
    else
    {
        // printf ("Aluno n�o inclu�do. Turma j� lotada em %i alunos \n", numero_alunos );
        cout << "Disciplina n�o inclu�da. Quantia de disc. j� lotada em " << numero_disc << " disciplinas." << endl;
    }
}

void ListaDisciplinas::listeDisciplinas()
{
    elemento<Disciplina> *pElAux = NULL;
    Disciplina *pDiAux = NULL;
    pElAux = LTdisciplinas.getPrimeiro();

    while (pElAux != NULL)
    {
        pDiAux = pElAux->getInfo();
        cout << " Disciplina " << pDiAux->getNome() << " do departamento " << pDiAux->getDepartamento()->getNome() << "." << endl;
        pElAux = pElAux->getProximo();
    }
}

void ListaDisciplinas::listeDisciplinas2()
{
}
