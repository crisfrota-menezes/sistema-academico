#pragma once

#include "elemento.hpp"
#include "bibliotecasPadrao.hpp"

template <class TIPO>
class lista
{
private:
    elemento<TIPO> *pPrimeiro;
    elemento<TIPO> *pUltimo;

public:
    lista();
    ~lista();
    void inicializa();
    void limpar();
    bool incluaElemento(elemento<TIPO> *pElemento);
    bool incluaInfo(TIPO *pInfo);
    // void listarInfos();
    /*void setNome(const char *n) { strcpy(nomeL, n); }
    char *getNome() { return nomeL; }*/
    elemento<TIPO> *getPrimeiro() { return pPrimeiro; }
    elemento<TIPO> *getAtual() { return pUltimo; }
};
template <class TIPO>
lista<TIPO>::lista()
{
    inicializa();
}

template <class TIPO>
lista<TIPO>::~lista()
{
    limpar();
}

template <class TIPO>
void lista<TIPO>::inicializa()
{
    pPrimeiro = NULL;
    pUltimo = NULL;
}

template <class TIPO>
void lista<TIPO>::limpar()
{
    elemento<TIPO> *pAux1 = pPrimeiro;
    elemento<TIPO> *pAux2 = pAux1;
    while (pAux1 != NULL)
    {
        pAux2 = pAux1->getProximo();
        delete pAux1;
        pAux1 = pAux2;
    }
    pPrimeiro = NULL;
    pUltimo = NULL;
}

template <class TIPO>
bool lista<TIPO>::incluaElemento(elemento<TIPO> *pElemento)
{
    if (NULL != pElemento)
    {
        if (NULL == pPrimeiro)
        {
            pPrimeiro = pElemento;
            // pPrimeiro->setAnterior ( NULL);
            // pPrimeiro->setProximo ( NULL);
            pUltimo = pPrimeiro;
        }
        else
        {
            pElemento->setAnterior(pUltimo);
            // pElemento->setProximo ( NULL);
            pUltimo->setProximo(pElemento);
            pUltimo = pUltimo->getProximo();
        }
        return true;
    }
    else
    {
        cout << "Erro, elemento nulo na lista." << endl;
        return false;
    }
}

template <class TIPO>
bool lista<TIPO>::incluaInfo(TIPO *pInfo)
{
    if (NULL != pInfo)
    {
        elemento<TIPO> *pElemento = NULL;
        pElemento = new elemento<TIPO>();
        pElemento->setInfo(pInfo);
        incluaElemento(pElemento);
        return true;
    }
    else
    {
        printf("Erro, elemento nulo(a) na lista. \n");
        return false;
    }
}

/*template <class TIPO>
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
}*/

/*template <class TIPO>
void lista<TIPO>::listarInfos()
{
    elemento<TIPO> *pAtual = pPrimeiro;
    while (pAtual != NULL)
    {
        cout << "Elemento na lista " << pAtual->getNome() << endl;
        pAtual = pAtual->getProximo();
    }
}*/