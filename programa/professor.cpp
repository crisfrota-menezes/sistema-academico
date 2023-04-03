#include "professor.hpp"

Professor::Professor ( int diaNa, int mesNa, int anoNa, const char* nome) : Pessoa ( diaNa, mesNa, anoNa, nome)
{
pUnivFiliado = NULL; pDptoFiliado = NULL;
}
Professor::Professor ( ) :
Pessoa ( )
{
pUnivFiliado = NULL; pDptoFiliado = NULL;
}
Professor::~Professor ( )
{
pUnivFiliado = NULL; pDptoFiliado = NULL;
}
void Professor::setUnivFiliado ( Universidade* pU)
{
pUnivFiliado = pU;
}
void Professor::setDepartamento ( Departamento* pDep)
{
pDptoFiliado = pDep;
}
void Professor::ondeTrabalho ( )
{
cout << nomeP << " trabalha para a " << pUnivFiliado->getNome();
}
void Professor::departamentoQueTrabalho()
{
cout << " no departamento de " << pDptoFiliado->getNome() << endl;
}