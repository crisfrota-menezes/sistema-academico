#include "listaDepartamento.hpp"
#include <string.h>
#include <iostream>
using std::cerr;
using std::ios;
#include <fstream>
using std::ifstream;
using std::ofstream;

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

void listaDepartamentos::salveDepartamentos()
{
    ofstream sDepartamento("departamentos.dat", ios::out);

    if (!sDepartamento)
    {
        cerr << "Arquivo não pode ser aberto" << endl;
        fflush(stdin);
        getchar();
    }

    elDepartamento *sauxElDep = NULL;
    Departamento *sauxDep = NULL;
    sauxElDep = pElDepartamentoPrim;
    while (sauxElDep != NULL)
    {
        sauxDep = sauxElDep->getDepartamento();
        sDepartamento << sauxDep->getId() << ' ' << sauxDep->getNome() << endl;
        sauxElDep = sauxElDep->pProx;
    }
    sDepartamento.close();
}

void listaDepartamentos::carregueDepartamentos()
{
    ifstream cDepartamento("departamentos.dat", ios::in);

    if (!cDepartamento)
    {
        cerr << "Arquivo não pode ser aberto" << endl;
        fflush(stdin);
        getchar();
    }

    int id;
    char nomeDep[30];
    Departamento *cAuxDep = NULL;

    while (cDepartamento >> id >> nomeDep)
    {
        cAuxDep = new Departamento(id);
        incluiDepartamento(cAuxDep);
    }
    cDepartamento.close();
}

Departamento *listaDepartamentos::localizar(const char *n)
{
    elDepartamento *pAux;
    pAux = pElDepartamentoPrim;
    while (pAux != NULL)
    {
        if (strcmp(pAux->getNome(), n) == 0)
        {
            return pAux->getDepartamento();
        }
        pAux = pAux->pProx;
    }
    return NULL;
}