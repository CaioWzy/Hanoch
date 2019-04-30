#include <iostream>
#include "Pilha.h"

void push(Pilha **ptr, int const n)
{
    if (!(*ptr))
    {
        *ptr = new Pilha;
        (*ptr)->n = n;
    }
    else
    {
        Pilha *topo = new Pilha;
        topo->n = n;
        topo->prox = *ptr;
        *ptr = topo;
    }
}

int pop(Pilha **ptr)
{
    int n = 0;

    if (!(*ptr))
        return n;

    if ((*ptr)->prox)
    {
        Pilha *topo = *ptr;
        n = (*ptr)->n;
        *ptr = (*ptr)->prox;
        delete topo;
    }
    else
    {
        n = (*ptr)->n;
        *ptr = NULL;
    }
    return n;
}
