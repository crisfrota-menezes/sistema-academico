#pragma once

#include "elemento.hpp"
#include "bibliotecasPadrao.hpp"

template <class TIPO>
class lista
{
private:
    elemento<TIPO> *pPrimeiro;
    elemento<TIPO> *pUltimo;
    char nomeL[50];

public:
    lista();
    ~lista();
    void incluirInfo(TIPO *pInfo, const char *nome = "");
    void listarInfos();
    TIPO *localizar(const char *n);
    void setNome(const char *n) { strcpy(nomeL, n); }
    char *getNome() { return nomeL; }
    elemento<TIPO> *getPrimeiro() { return pPrimeiro; }
    elemento<TIPO> *getAtual() { return pUltimo; }
};
template <class TIPO>
lista<TIPO>::lista()
{
    pPrimeiro = NULL;
    pUltimo = NULL;
}

template <class TIPO>
lista<TIPO>::~lista()
{
    elemento<TIPO> *pAtua = pPrimeiro;
    elemento<TIPO> *pProxim = NULL;
    while (pAtua != NULL)
    {
        pProxim = pAtua->getProximo();
        delete pAtua;
        pAtua = pProxim;
    }
    pPrimeiro = NULL;
    pUltimo = NULL;
}
template <class TIPO>
void lista<TIPO>::incluirInfo(TIPO *pI, const char *nome)
{
    elemento<TIPO> *pNovo = new elemento<TIPO>;
    pNovo->setInfo(pI);
    pNovo->setNome(nome);
    if (pPrimeiro == NULL)
    {
        pPrimeiro = pNovo;
        pUltimo = pNovo;
    }
    else
    {
        pUltimo->setProximo(pNovo);
        pNovo->setAnterior(pUltimo);
        pUltimo = pNovo;
    }
}

template <class TIPO>
void lista<TIPO>::listarInfos()
{
    elemento<TIPO> *pAtual = pPrimeiro;
    while (pAtual != NULL)
    {
        cout << "Elemento na lista " << pAtual->getNome() << endl;
        pAtual = pAtual->getProximo();
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