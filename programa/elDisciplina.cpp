#include "elDisciplina.hpp"

elDisciplina::elDisciplina()
{
    pProx = NULL;
    pAnte = NULL;
}
elDisciplina::~elDisciplina()
{
    pProx = NULL;
    pAnte = NULL;
}
void elDisciplina::setDisciplina(Disciplina *pdi)
{
    pDisciplina = pdi;
}
Disciplina *elDisciplina::getDisciplina()
{
    return pDisciplina;
}
char *elDisciplina::getNome()
{
    return pDisciplina->getNome();
}