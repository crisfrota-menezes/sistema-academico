#include "listaDepartamento.hpp"
#include <string.h>

listaDepartamentos::listaDepartamentos(int nd, const char *n)
{
    cont_dep = 0;
    numero_dep = nd;
    pElDepartamentoPrim = NULL;
    pElDepartamentoAtual = NULL;
    strcpy(nome, n);
}

listaDepartamentos::~listaDepartamentos()
{
    elDepartamento *paux1, *paux2;
    paux1 = pElDepartamentoPrim;
    while (paux1 != NULL)
    {
        paux2 = paux1->pProx;
        delete paux1;
        paux1 = paux2;
    }
    pElDepartamentoPrim = NULL;
    pElDepartamentoAtual = NULL;
}

void listaDepartamentos::setNome(const char *n)
{
    strcpy(nome, n);
}

void listaDepartamentos::incluiDepartamento(Departamento *pDe)
{
    elDepartamento *pAux;
    pAux = new elDepartamento;
    pAux->setDepartamento(pDe);
    pAux->pProx = NULL;
    pAux->pAnte = NULL;

    if (
        ((cont_dep < numero_dep) && (pDe != NULL)) ||
        ((numero_dep == -1) && (pDe != NULL)))
    {

        if (pElDepartamentoPrim == NULL)
        {
            pElDepartamentoPrim = pAux;
            pElDepartamentoAtual = pAux;
        }
        else
        {
            pElDepartamentoAtual->pProx = pAux;
            pAux->pAnte = pElDepartamentoAtual;
            pElDepartamentoAtual = pAux;
        }
        cont_dep++;
    }
    else
    {
        cout << "Departamento não incluído. Quantia de deps já lotada em" << numero_dep << " departamentos." << endl;
    }
}

void listaDepartamentos::listeDepartamentos()
{
    elDepartamento *pAux;
    pAux = pElDepartamentoPrim;
    while (pAux != NULL)
    {
        cout << " Departamento " << pAux->getNome() << " da universidade " << nome << "." << endl;
        pAux = pAux->pProx;
    }
}

void listaDepartamentos::listeDepartamentos2()
{
    elDepartamento *pAux;
    pAux = pElDepartamentoAtual;
    while (pAux != NULL)
    {
        cout << " Departamento " << pAux->getNome() << " da universidade " << nome << "." << endl;
        pAux = pAux->pAnte;
    }
}