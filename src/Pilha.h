#ifndef PILHA_H
#define PILHA_H

struct Pilha {
    int n;
    Pilha *prox;
};

void push(Pilha **ptr, int const n);
int pop(Pilha **ptr);

#endif