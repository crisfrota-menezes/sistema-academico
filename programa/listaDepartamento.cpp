#include "listaDepartamento.hpp"
#include <string.h>

listaDepartamentos::listaDepartamentos()
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
        paux2 = paux1->getElDepartamento();
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
        ((cont_dep < numero_dep) && (pd != NULL)) ||
        ((numero_dep == -1) && (pd != NULL)))
    {

        if (pElDepartamentoPrim == NULL)
        {
            pElDepartamentoPrim = paux;
            pElDepartamentoAtual = paux;
        }
        else
        {
            pElDepartamentoAtual->pProx = paux;
            paux->pAnte = pElDepartamentoAtual;
            pElDepartamentoAtual = paux;
        }
        cont_dep++;
    }
    else
    {
        // printf ("Aluno não incluído. Turma já lotada em %i alunos \n", numero_alunos );
        cout << "Departamento não incluído. Quantia de deps já lotada em " << numero_dep << " departamentos." << endl;
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