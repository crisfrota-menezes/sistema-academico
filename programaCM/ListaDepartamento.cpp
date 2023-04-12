#include "ListaDepartamento.h"

ListaDepartamento::ListaDepartamento(int nd, const char *n)
{
    numero_dep = nd;
    cont_dep = 0;
    strcpy(nome, n);
    // ctor
}

ListaDepartamento::~ListaDepartamento()
{
    // dtor
}

void ListaDepartamento::setNome(char *n)
{
    strcpy(nome, n);
}

void ListaDepartamento::incluaDepartamento(Departamento *pd)
{
    if (
        ((cont_dep < numero_dep) && (pd != NULL)) ||
        ((numero_dep == -1) && (pd != NULL)))
    {
        LTDepartamento.incluaInfo(pd);
    }
    else
    {
        // printf ("Aluno n�o inclu�do. Turma j� lotada em %i alunos \n", numero_alunos );
        cout << "Departamento n�o inclu�do. Quantia de deps j� lotada em " << numero_dep << " departamentos." << endl;
    }
}

void ListaDepartamento::listeDepartamentos()
{
    elemento<Departamento> *pElAux = NULL;
    Departamento *pDeAux = NULL;
    pElAux = LTDepartamento.getPrimeiro();

    while (pElAux != NULL)
    {
        pDeAux = pElAux->getInfo();
        cout << " Departamento " << pDeAux->getNome() << " da universidade " << nome << "." << endl;
        pElAux = pElAux->getProximo();
    }
}
void ListaDepartamento::listeDepartamentos2()
{
}

Departamento *ListaDepartamento::localizar(char *n)
{
    elemento<Departamento> *pElAux = NULL;
    Departamento *pDeAux = NULL;
    pElAux = LTDepartamento.getPrimeiro();

    while (pElAux != NULL)
    {
        pDeAux = pElAux->getInfo();
        if (strcmp(pDeAux->getNome(), n) == 0)
        {
            return pDeAux;
        }
        pElAux = pElAux->getProximo();
    }
    return NULL;
}