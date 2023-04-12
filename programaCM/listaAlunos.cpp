#include "listaAlunos.hpp"

ListaAlunos::ListaAlunos()
{
}
ListaAlunos::~ListaAlunos()
{
}
void ListaAlunos::limpaLista()
{
    LTAlunos.limpar();
}
void ListaAlunos::incluaAluno(Aluno *pA)
{
    if(pA != NULL) {
        LTAlunos.incluirInfo(pA);
    }
    else {
        cout << "Erro ao incluir aluno" << endl;
    }
}
void ListaAlunos::listeAlunos()
{
    elemento<Aluno> *pAux = LTAlunos.getPrimeiro();
    Aluno* pAlAux = NULL;
    while (pAux != NULL)
    {
        pAlAux = pAux->getInfo();
        cout << "Aluno: " << pAlAux->getNome() << " com RA " << pAlAux->getRa() << endl;
        pAux = pAux->getProximo();
    }
}
void ListaAlunos::listeAlunos2()
{
    elemento<Aluno> *pAux = LTAlunos.getAtual();
    Aluno* pAlAux = NULL;
    while (pAux != NULL)
    {
        pAlAux = pAux->getInfo();
        cout << "Aluno: " << pAlAux->getNome() << " com RA " << pAlAux->getRa() << endl;
        pAux = pAux->getAnterior();
    }
}

void ListaAlunos::salvarAlunos()
{
    //
}

void ListaAlunos::carregarAlunos()
{
    //
}