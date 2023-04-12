#include "ListaUniversidade.h"

ListaUniversidade::ListaUniversidade(int nu, const char *n)
{
    cont_univ = 0;
    numero_univ = nu;
    strcpy(nome, n);
}

ListaUniversidade::~ListaUniversidade()
{
    // dtor
}

void ListaUniversidade::incluaUniversidade(Universidade *pu)
{
    if (
        ((cont_univ < numero_univ) && (pu != NULL)) ||
        ((numero_univ == -1) && (pu != NULL)))
    {
        LTUniversidade.incluaInfo(pu);
        cont_univ++;
    }
    else
    {
        // printf ("Aluno n�o inclu�do. Turma j� lotada em %i alunos \n", numero_alunos );
        cout << "Universidade n�o inclu�da. Sistema j� lotado em " << numero_univ << " universidades." << endl;
    }
}

void ListaUniversidade::listeUniversidades()
{
    elemento<Universidade> *pElAux = NULL;
    Universidade *pUnAux = NULL;
    pElAux = LTUniversidade.getPrimeiro();

    while (pElAux != NULL)
    {
        pUnAux = pElAux->getInfo();
        cout << " Universidade " << pUnAux->getNome() << " no sistema " << nome << "." << endl;
        pElAux = pElAux->getProximo();
    }
}

void ListaUniversidade::listeUniversidades2()
{
}

Universidade *ListaUniversidade::localizar(char *n)
{
    elemento<Universidade> *pElAux = NULL;
    Universidade *pUnAux = NULL;
    pElAux = LTUniversidade.getPrimeiro();

    while (pElAux != NULL)
    {
        pUnAux = pElAux->getInfo();
        if (strcmp(pUnAux->getNome(), n) == 0)
        {
            return pUnAux;
        }
        pElAux = pElAux->getProximo();
    }
    return NULL;
}
