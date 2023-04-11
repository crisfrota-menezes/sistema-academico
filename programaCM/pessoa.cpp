#include "pessoa.hpp"

Pessoa::Pessoa(int diaNa, int mesNa, int anoNa, const char *nome)
{
  inicializa(diaNa, mesNa, anoNa, nome);
}
Pessoa::Pessoa()
{
}
void Pessoa::inicializa(int diaNa, int mesNa, int anoNa, const char *nome)
{
  idadeP = 0;
  diaP = diaNa;
  mesP = mesNa;
  anoP = anoNa;
  strcpy(nomeP, nome);
  id = -1;
}
void Pessoa::calcula_idade(int diaAT, int mesAT, int anoAT)
{
  idadeP = anoAT - anoP;
  if (mesP > mesAT)
    idadeP--;
  else if (mesP == mesAT)
  {
    if (diaP > diaAT)
    {
      idadeP--;
    }
  }
  cout << "\nA idade de " << nomeP << " seria " << idadeP << endl;
}
int Pessoa::getIdade()
{
  return idadeP;
}