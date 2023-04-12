#include "ListaPessoas.h"

ListaPessoas::ListaPessoas()
{
    //ctor
}

ListaPessoas::~ListaPessoas()
{
    //dtor
}

void ListaPessoas::incluaPessoa(Pessoa* pa)
{
    LTPessoa.incluaInfo(pa);
}

void ListaPessoas::listePessoas()
{
    elemento<Pessoa>* pElAux = NULL;
	Pessoa* pPeAux = NULL;
	pElAux = LTPessoa.getPrimeiro();

    while (pElAux != NULL)
    {
		pPeAux = pElAux->getInfo();
		cout << " Nome da pessoa:  " << pPeAux->getNome() << "." << endl;
		pElAux = pElAux->getProximo();
    }
}
void ListaPessoas::listaProventos()
{

    elemento<Pessoa>*	ponteiroElementoPessoa;
	Pessoa*				ponteiroPessoa;

	ponteiroElementoPessoa  = LTPessoa.getPrimeiro();

	while ( ponteiroElementoPessoa != NULL )
	{
		ponteiroPessoa = ponteiroElementoPessoa->getInfo();

		ponteiroPessoa->informaProventos();

		ponteiroElementoPessoa = ponteiroElementoPessoa->getProximo();
	}
}
