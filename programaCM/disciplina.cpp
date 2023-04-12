#include "disciplina.hpp"
#include "bibliotecasPadrao.hpp"

Disciplina::Disciplina(int i, int na, const char *ac) : ObjAlunos()
{
  id = i;
  cont_alunos = 0;
  numero_alunos = na;
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
  if (NULL != pA)
  {
    if (cont_alunos < numero_alunos || numero_alunos == -1)
    {
      ObjAlunos.incluaAluno(pA);
      cont_alunos++;
    }
    else
    {
      cout << "Numero máximo de alunos atingido!" << endl;
    }
  }
  else
  {
    cout << "Erro! Aluno não incluído!" << endl;
  }
}
void Disciplina::listarAlunos()
{
  cout << "\n\nAlunos matriculados na disciplina " << area_conhecimento << ": " << endl;
  ObjAlunos.listeAlunos();
}
void Disciplina::listarAlunos2()
{
  cout << "\n\nAlunos matriculados na disciplina " << area_conhecimento << ": " << endl;
  ObjAlunos.listeAlunos2();
}