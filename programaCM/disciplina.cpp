#include "disciplina.hpp"
#include <string.h>

Disciplina::Disciplina(int i, const char *ac) : ObjAlunos()
{
  id = i;
  pDptoAssociado = NULL;
  strcpy(area_conhecimento, ac);
}
Disciplina::~Disciplina()
{
  pDptoAssociado = NULL;
}
void Disciplina::setId(int i) { id = i; }
int Disciplina::getId() { return id; }
void Disciplina::setNome(const char *n) { strcpy(nome, n); }
char *Disciplina::getNome() { return nome; }
void Disciplina::setDepartamento(Departamento *pDpto)
{
  pDptoAssociado = pDpto;
  pDpto->incluiDisciplina(this);
}
Departamento *Disciplina::getDepartamento()
{
  return pDptoAssociado;
}
void Disciplina::incluirAluno(Aluno *pA)
{
  ObjAlunos.incluirInfo(pA);
}
void Disciplina::listarAlunos()
{
  ObjAlunos.listarInfos();
  /*elemento<Aluno> *pAux = ObjAlunos.getPrimeiro();
  if (NULL != pPrimeiro)
  {
    while (pAux != NULL)
    {
      Aluno *pAluno = pAux->getInfo();
      cout << "Presente na lista o elemento: " << pAluno->getNome() << "RA: " << pAluno->getRa() << endl;
      pAux = pAux->getProximo();
    }
  }*/
}
void Disciplina::listarAlunos2()
{
  // ObjAlunos.listarAlunos2();
}