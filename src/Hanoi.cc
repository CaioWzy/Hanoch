#include <iostream>
#include <cmath>
#include "Pilha.h"
#include "Hanoi.h"


int minimoMovimentos(int const n_discos)
{
    return pow(2, n_discos) - 1;
}

void colocaDiscos(Pilha **ptr, int const n_discos)
{
    for (int i = n_discos; i >= 1; --i)
    {
        push(ptr, i);
    }
}

void moveDisco(Pilha **ptr_origem, Pilha **ptr_destino)
{
    /*
    if (!(*ptr_origem)) return;

    if (*ptr_destino && ((*ptr_origem)->n > (*ptr_destino)->n)) return;
    */
    Pilha *topo = *ptr_origem;

    if ((*ptr_origem)->prox)
        *ptr_origem = (*ptr_origem)->prox;
    else
        *ptr_origem = NULL;

    if (!(*ptr_destino))
        topo->prox = NULL;
    else
        topo->prox = *ptr_destino;

    *ptr_destino = topo;
}

void movimentoPermitido(Pilha **ptr_origem, Pilha **ptr_destino)
{
    if (!(*ptr_origem) && !(*ptr_destino))
        return;

    if (!(*ptr_origem))
    {
        moveDisco(ptr_destino, ptr_origem);
        std::cout << " <- ";
    }
    else if (!(*ptr_destino))
    {
        moveDisco(ptr_origem, ptr_destino);
        std::cout << " -> ";
    }
    else if ((*ptr_origem)->n < (*ptr_destino)->n)
    {
        moveDisco(ptr_origem, ptr_destino);
        std::cout << " -> ";
    }
    else
    {
        moveDisco(ptr_destino, ptr_origem);
        std::cout << " <- ";
    }
}

void resolveTorre(int const n_discos,
                  Pilha **torre_inicial,
                  Pilha **torre_auxiliar,
                  Pilha **torre_final)
{
    unsigned long long int const movimentos = minimoMovimentos(n_discos);
    bool const isNDiscosPar = n_discos % 2 == 0;

    for (unsigned long long int i = 1; i <= movimentos; ++i)
    {
        std::cout << i << " | ";
        switch (i % 3)
        {
        case 1:

            if (isNDiscosPar)
            {
                std::cout << "A";
                movimentoPermitido(torre_inicial, torre_auxiliar);
                std::cout << "B" << std::endl;
            }
            else
            {
                std::cout << "A";
                movimentoPermitido(torre_inicial, torre_final);
                std::cout << "C" << std::endl;
            }

            break;

        case 2:

            if (isNDiscosPar)
            {
                std::cout << "A";
                movimentoPermitido(torre_inicial, torre_final);
                std::cout << "C" << std::endl;
            }
            else
            {
                std::cout << "A";
                movimentoPermitido(torre_inicial, torre_auxiliar);
                std::cout << "B" << std::endl;
            }

            break;

        case 0:

            if (isNDiscosPar)
            {
                std::cout << "C";
                movimentoPermitido(torre_final, torre_auxiliar);
                std::cout << "B" << std::endl;
            }
            else
            {
                std::cout << "B";
                movimentoPermitido(torre_auxiliar, torre_final);
                std::cout << "C" << std::endl;
            }

            break;
        }
    }
}
