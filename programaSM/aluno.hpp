#pragma once

#include "departamento.hpp"
#include "pessoa.hpp"

class Disciplina;

class Aluno : public Pessoa
{
private:
    int RA;
    int id;
    Departamento *DeptoAssociado;
    Disciplina *pDisciplina;

public:
    Aluno(int diaNa, int mesNa, int anoNa, const char *nome = "");
    Aluno(int i = -1);
    ~Aluno();

    void setRa(int ra);
    int getRa();

    void setDepartamento(Departamento *d);
    Departamento *getDepartamento();

    void setId(int i);
    int getId();

    void setDisciplina(Disciplina *d);
    Disciplina *getDisciplina();
};