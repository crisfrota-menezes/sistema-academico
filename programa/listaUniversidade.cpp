#include <string.h>
#include "listaUniversidade.hpp"

listaUniversidades::listaUniversidades(int nu, const char *n)
{
    num_univ = nu;
    strcpy(nome, n);
    cont_univ = 0;
    pElUniPrimeiro = NULL;
    pElUniAtual = NULL;
}

listaUniversidades::~listaUniversidades()
{
    elUniversidade *pElUniAux1, *pElUniAux2;
    pElUniAux1 = pElUniPrimeiro;
    pElUniAux2 = pElUniAux1;
    while (pElUniAux1 != NULL)
    {
        pElUniAux2 = pElUniAux1->pProx;
        delete pElUniAux1;
        pElUniAux1 = pElUniAux2;
    }

    pElUniPrimeiro = NULL;
    pElUniAtual = NULL;
}

void listaUniversidades::incluiUniversidade(Universidade *pU)
{
    elUniversidade *pElUniAux = new elUniversidade();
    pElUniAux->setUniversidade(pU);
    pElUniAux->pProx = NULL;
    pElUniAux->pAnte = NULL;
    if (
        ((cont_univ < num_univ) && (pU != NULL)) ||
        ((num_univ == -1) && (pU != NULL)))
    {

        if (pElUniPrimeiro == NULL)
        {
            pElUniPrimeiro = pElUniAux;
            pElUniAtual = pElUniAux;
        }
        else
        {
            pElUniAtual->pProx = pElUniAux;
            pElUniAux->pAnte = pElUniAtual;
            pElUniAtual = pElUniAux;
        }
        cont_univ++;
    }
    else
    {
        cout << "Universidade não incluída. Sistema já lotado em " << num_univ << " universidades." << endl;
    }
}

void listaUniversidades::listeUniversidades()
{
    elUniversidade *pElUniAux = pElUniPrimeiro;
    while (pElUniAux != NULL)
    {
        cout << pElUniAux->getNome() << endl;
        pElUniAux = pElUniAux->pProx;
    }
}

void listaUniversidades::listeUniversidades2()
{
    elUniversidade *pElUniAux = pElUniAtual;
    while (pElUniAux != NULL)
    {
        cout << pElUniAux->getNome() << endl;
        pElUniAux = pElUniAux->pAnte;
    }
}