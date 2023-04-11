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
    elemento<Universidade> *pElUniAux1, *pElUniAux2;
    pElUniAux1 = pElUniPrimeiro;
    pElUniAux2 = pElUniAux1;
    while (pElUniAux1 != NULL)
    {
        pElUniAux2 = pElUniAux1->getProximo();
        delete pElUniAux1;
        pElUniAux1 = pElUniAux2;
    }

    pElUniPrimeiro = NULL;
    pElUniAtual = NULL;
}

void listaUniversidades::incluiUniversidade(Universidade *pU)
{
    elemento<Universidade> *pElUniAux = new elemento<Universidade>();
    pElUniAux->setInfo(pU);
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
            pElUniAtual->setProximo(pElUniAux);
            pElUniAux->setAnterior(pElUniAtual);
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
    Universidade *pUniAux = NULL;
    elemento<Universidade> *pElUniAux = pElUniPrimeiro;
    while (pElUniAux != NULL)
    {
        pUniAux = pElUniAux->getInfo();
        cout << pUniAux->getNome() << endl;
        pElUniAux = pElUniAux->getProximo();
    }
}

void listaUniversidades::listeUniversidades2()
{
    Universidade *pUniAux = NULL;
    elemento<Universidade> *pElUniAux = pElUniPrimeiro;
    while (pElUniAux != NULL)
    {
        pUniAux = pElUniAux->getInfo();
        cout << pUniAux->getNome() << endl;
        pElUniAux = pElUniAux->getAnterior();
    }
}

Universidade *listaUniversidades::localizar(const char *n)
{
    elemento<Universidade> *pElUniAux = pElUniPrimeiro;
    while (pElUniAux != NULL)
    {
        if (strcmp(n, pElUniAux->getNome()) == 0)
        {
            return pElUniAux->getInfo();
        }
        pElUniAux = pElUniAux->getProximo();
    }
    return NULL;
}