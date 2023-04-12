/*A classe ListaAlunos armazenará os apontamentos de aluno por meio de uma Lista template parametrizada com Aluno
Os métodos limpar() e incluaAluno() chamam diretamente os métodos da Lista template, visto que o código é generalizado.
Já o algoritmos de listagem para os Alunos são específicos e são definidos nesta classe.
*/
#pragma once

#include "lista.hpp"
#include "aluno.hpp"

class ListaAlunos
{
private:
    lista<Aluno> LTAlunos;

public:
    ListaAlunos();
    ~ListaAlunos();
    void incluaAluno(Aluno *pA);
    void listeAlunos();
    void listeAlunos2();
};