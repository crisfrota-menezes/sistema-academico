#pragma once

#include "elemento.hpp"
#include <cstddef>
#include <cstring>
#include <iostream>
using std::cout;
using std::endl;

template <class TIPO>
class lista
{
private:
    elemento<TIPO> *pPrimeiro;
    elemento<TIPO> *pAtual;
    char nomeL[50];

public:
    lista();
    ~lista();
    void inicializa();
    bool incluirElemento(elemento<TIPO> *pElemento);
    bool incluirInfo(TIPO *pInfo, const char *nome = "");
    void listarInfos();
    TIPO *localizar(const char *n);
    void setNome(const char *n) { strcpy(nomeL, n); }
    char *getNome() { return nomeL; }
    elemento<TIPO> *getPrimeiro() { return pPrimeiro; }
    elemento<TIPO> *getAtual() { return pAtual; }
};

template <class TIPO>
lista<TIPO>::lista()
{
    inicializa();
}

template <class TIPO>
lista<TIPO>::~lista()
{
    inicializa();
}

template <class TIPO>
void lista<TIPO>::inicializa()
{
    pPrimeiro = NULL;
    pAtual = NULL;
}

template <class TIPO>
bool lista<TIPO>::incluirElemento(elemento<TIPO> *pElemento)
{
    if (NULL != pElemento)
    {
        if (NULL == pPrimeiro)
        {
            pPrimeiro = pElemento;
            pAtual = pElemento;
        }
        else
        {
            pElemento->setProximo(pAtual);
            pAtual->setProximo(pElemento);
            pAtual = pAtual->getProximo();
        }
        return true;
    }
    else
    {
        cout << "Erro: elemento nulo" << endl;
        return false;
    }
}

template <class TIPO>
bool lista<TIPO>::incluirInfo(TIPO *pInfo, const char *nome)
{
    if (NULL != pInfo)
    {
        elemento<TIPO> *pElemento = new elemento<TIPO>();
        pElemento->setInfo(pInfo);
        pElemento->setNome(nome);
        incluirElemento(pElemento);
        return true;
    }
    else
    {
        cout << "Erro: info nula" << endl;
        return false;
    }
}

template <class TIPO>
void lista<TIPO>::listarInfos()
{
    elemento<TIPO> *pAux = pPrimeiro;
    while (pAux != NULL)
    {
        cout << "Elemento na lista " << pAux->getNome() << endl;
        pAux = pAux->getProximo();
    }
}

template <class TIPO>
TIPO *lista<TIPO>::localizar(const char *n)
{
    elemento<TIPO> *pAux = pPrimeiro;
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