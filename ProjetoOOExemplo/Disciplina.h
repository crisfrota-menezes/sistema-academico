#ifndef _DISCIPLINA_H_
#define _DISCIPLINA_H_

#include "Aluno.h"
#include "Departamento.h"
// #include "Lista.h"
#include "stdafx.h"

class Disciplina
{
private:
    int id;
    string nome;
    string area_conhecimento;

    Departamento *DeptoAssociado;
    // Lista<Aluno> ObjLAlunos;
    vector<Aluno *> ObjLAlunos;
    vector<Aluno *>::iterator Iterador;

public:
    Disciplina(int i, int na = 45, const char *ac = "");
    ~Disciplina();

    void setId(int i);
    int getId();

    void setNome(const char *n);
    const string getNome();

    void setDepartamento(Departamento *d);
    Departamento *getDepartamento();

    void setAluno(Aluno *a);
    void listeAlunos();
    void listeAlunos2();
};

#endif
