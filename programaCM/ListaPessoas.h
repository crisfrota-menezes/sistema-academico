#pragma once
#include "lista.hpp"
#include "elemento.hpp"
#include "pessoa.hpp"

class ListaPessoas
{
    public:
        ListaPessoas();
        virtual ~ListaPessoas();
        void incluaPessoa(Pessoa* pa);
        void listePessoas();
        void listaProventos();

    private:
        lista<Pessoa> LTPessoa;

};

