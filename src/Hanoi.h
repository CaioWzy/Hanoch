#ifndef HANOI_H
#define HANOI_H

#include "Pilha.h"

int minimoMovimentos(int const n_discos);
void colocaDiscos(Pilha **ptr, int const n_discos);
void moveDisco(Pilha **ptr_origem, Pilha **ptr_destino);
void movimentoPermitido(Pilha **ptr_origem, Pilha **ptr_destino);
void resolveTorre(int const n_discos,
                  Pilha **torre_inicial,
                  Pilha **torre_auxiliar,
                  Pilha **torre_final);

#endif