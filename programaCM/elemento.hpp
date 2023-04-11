#pragma once

#include "bibliotecasPadrao.hpp"
template <class TIPO>
class elemento
{
private:
   elemento<TIPO> *pProximo;
   elemento<TIPO> *pAnterior;
   TIPO *pInfo;

public:
   elemento();
   ~elemento();
   void setProximo(elemento<TIPO> *pP);
   elemento<TIPO> *getProximo();
   void setAnterior(elemento<TIPO> *pA);
   elemento<TIPO> *getAnterior();
   void setInfo(TIPO *pI);
   TIPO *getInfo();
};
template <class TIPO>
elemento<TIPO>::elemento()
{
   pProximo = NULL;
   pAnterior = NULL;
   pInfo = NULL;
}
template <class TIPO>
elemento<TIPO>::~elemento()
{
   pProximo = NULL;
   pAnterior = NULL;
   pInfo = NULL;
}
template <class TIPO>
void elemento<TIPO>::setProximo(elemento<TIPO> *pP)
{
   if (pP == NULL)
      return;
   pProximo = pP;
}
template <class TIPO>
elemento<TIPO> *elemento<TIPO>::getProximo()
{
   return pProximo;
}
template <class TIPO>
void elemento<TIPO>::setAnterior(elemento<TIPO> *pA)
{
   pAnterior = pA;
}
template <class TIPO>
elemento<TIPO> *elemento<TIPO>::getAnterior()
{
   return pProximo;
}
template <class TIPO>
void elemento<TIPO>::setInfo(TIPO *pI)
{
   pInfo = pI;
}
template <class TIPO>
TIPO *elemento<TIPO>::getInfo()
{
   return pInfo;
}