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

public:
    lista();
    ~lista();
    void inicializa();
    void setPrimeiro(elemento<TIPO> *pP);
    elemento<TIPO> *getPrimeiro();
    bool incluirElemento(elemento<TIPO> *pElemento);
    bool incluirInfo(TIPO *pInfo, const char *nome = "");
    void listarInfos();
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
void lista<TIPO>::setPrimeiro(elemento<TIPO> *pP)
{
    pPrimeiro = pP;
}

template <class TIPO>
elemento<TIPO> *lista<TIPO>::getPrimeiro()
{
    return pPrimeiro;
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