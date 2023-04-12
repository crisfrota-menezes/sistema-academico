#include "stdafx.h"
#include "Estagiario.h" 

Estagiario::Estagiario (int diaNa, int mesNa, int anoNa, const char* nome):
Aluno (diaNa, mesNa, anoNa, nome)
{
	inicializa();
}

Estagiario::Estagiario()
:Aluno()
{
	inicializa();
}

Estagiario::~Estagiario()
{
}

void Estagiario::inicializa()
{
	BolsaEstudo = 0;
}

void Estagiario::setBolsaEstudo(float b)
{
   BolsaEstudo = b;
}

float Estagiario::getBolsaEstudo()
{
   return BolsaEstudo;
}

void Estagiario::informaProventos()
{
   cout << "O valor da bolsa de " << nomeP
		<< " � " << BolsaEstudo << "."  << endl;
}
