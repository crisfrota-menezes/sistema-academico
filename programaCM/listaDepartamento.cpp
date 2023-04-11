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
    elemento<Departamento> *paux1, *paux2;
    paux1 = pElDepartamentoPrim;
    while (paux1 != NULL)
    {
        paux2 = paux1->getProximo();
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
    elemento<Departamento> *pAux;
    pAux = new elemento<Departamento>();
    // pAux->setNome(pDe->getNome());
    pAux->setInfo(pDe);

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
            pElDepartamentoAtual->setProximo(pAux);
            pAux->setAnterior(pElDepartamentoAtual);
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
    Departamento *pAuxDep = NULL;
    elemento<Departamento> *pAuxElDep = pElDepartamentoPrim;
    while (pAuxElDep != NULL)
    {
        pAuxDep = pAuxElDep->getInfo();
        cout << " Departamento " << pAuxDep->getNome() << " da universidade " << nome << "." << endl;
        pAuxElDep = pAuxElDep->getProximo();
    }
}

void listaDepartamentos::listeDepartamentos2()
{
    Departamento *pAuxDep = NULL;
    elemento<Departamento> *pAuxElDep = pElDepartamentoPrim;
    while (pAuxElDep != NULL)
    {
        pAuxDep = pAuxElDep->getInfo();
        cout << " Departamento " << pAuxDep->getNome() << " da universidade " << nome << "." << endl;
        pAuxElDep = pAuxElDep->getAnterior();
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

    elemento<Departamento> *sauxElDep = NULL;
    Departamento *sauxDep = NULL;
    sauxElDep = pElDepartamentoPrim;
    while (sauxElDep != NULL)
    {
        sauxDep = sauxElDep->getInfo();
        sDepartamento << sauxDep->getId() << ' ' << sauxDep->getNome() << endl;
        sauxElDep = sauxElDep->getProximo();
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
    elemento<Departamento> *pAux;
    pAux = pElDepartamentoPrim;
    while (pAux != NULL)
    {
        if (strcmp(pAux->getNome(), n) == 0)
        {
            return pAux->getInfo();
        }
        pAux = pAux->getProximo();
    }
    return NULL;
}