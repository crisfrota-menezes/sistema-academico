#include "stdafx.h"
#include "Pessoa.h"
#include <locale.h>

Pessoa::Pessoa(int diaNa, int mesNa, int anoNa, const char *nome)
{
  Inicializa(diaNa, mesNa, anoNa, nome);
}

Pessoa::Pessoa()
{
}

void Pessoa::Inicializa(int diaNa, int mesNa, int anoNa, const char *nome)
{
  diaP = diaNa;
  mesP = mesNa;
  anoP = anoNa;
  // strcpy(nomeP, nome);
  nomeP = nome;
}

void Pessoa::Calc_Idade(int diaAT, int mesAT, int anoAT)
{
  setlocale(LC_ALL, "Portuguese");
  idadeP = anoAT - anoP;
  if (mesP > mesAT)
  {
    idadeP = idadeP - 1;
  }
  else
  {
    if (mesP == mesAT)
    {
      if (diaP > diaAT)
      {
        idadeP = idadeP - 1;
      }
    }
  }
  // printf("\n A idade da Pessoa %s � %d \n", nomeP, idadeP);
  cout << endl
       << " A idade da Pessoa " << nomeP << " é " << idadeP << "." << endl;
}

int Pessoa::informaIdade()
{
  return idadeP;
}

void Pessoa::setNome(const char *n)
{
  // strcpy(nomeP,n);
  nomeP = n;
}

const string Pessoa::getNome()
{
  return nomeP;
}

void Pessoa::informaProventos()
{
  setlocale(LC_ALL, "Portuguese");
  cout << "Nenhuma informação sobre proventos de " << nomeP << "." << endl;
}
