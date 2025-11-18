#include <iostream>
#include "Menu.hpp"
using namespace std;

int main() {
    Inventario inv;

    cout << "1) Rodar testes\n2) Modo interativo\n";
    int opcao;
    cin >> opcao;

    if (opcao == 1) rodarTestes(inv);
    else if (opcao == 2) menuPrincipal(inv);

    return 0;
}
