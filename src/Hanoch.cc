#include <iostream>
#include "Pilha.h"
#include "Hanoi.h"

using namespace std;


int main(int const argc, char *argv[])
{
    if (argc < 2)
    {
        cerr << "Uso:"
             << " " << argv[0] << " [num_discos]"
             << endl;
        return 1;
    }

    int const discos = stoi(argv[1]);

    if (discos < 1 || discos > 64)
    {
        cerr << "O número de discos deve ser menor ou igual a 64." << endl;
        return 1;
    }

    Pilha *a = NULL,
          *b = NULL,
          *c = NULL;

    cout << "DISCOS: " << discos << endl;
    cout << "MOVIMENTOS: " << minimoMovimentos(discos) << endl;

    cout << endl;

    colocaDiscos(&a, discos);
    resolveTorre(discos, &a, &b, &c);

    cout << endl;
    /*
    for (int i = 0; i < discos; ++i)
    {
        int torre_inicial = pop(&a);
        int torre_auxiliar = pop(&b);
        int torre_final = pop(&c);

        torre_inicial ? cout << "\t" << torre_inicial : cout << "\t|";
        torre_auxiliar ? cout << "\t" << torre_auxiliar : cout << "\t|";
        torre_final ? cout << "\t" << torre_final : cout << "\t|";

        cout << endl;
    }
    cout << "\t" << "A" << "\t" << "B" << "\t" << "C" << endl;
    */
    return 0;
}
