#include "Menu.hpp"
#include <iostream>
#include <limits>

using namespace std;

void limparEntrada() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void rodarTestes(Inventario& inv) {
    cout << "\nRODANDO TESTES AUTOMÁTICOS\n";

    cout << "\n[1] Adicionando produtos...\n";
    inv.adicionarProduto(Produto("Arroz", 15.0, 10, "Alimentos"));
    inv.adicionarProduto(Produto("Feijão", 8.0, 5, "Alimentos"));
    inv.adicionarProduto(Produto("Sabonete", 3.5, 20, "Higiene"));
    inv.adicionarProduto(Produto("Shampoo", 12.0, 12, "Higiene"));

    cout << "Produtos adicionados.\n";

    cout << "\n[2] Buscando produto 'Arroz'...\n";
    int index = inv.buscarProduto("Arroz");
    cout << (index != -1 ? "Encontrado!\n" : "Não encontrado!\n");

    cout << "\n[3] Listando produtos da categoria 'Higiene':\n";
    auto higiene = inv.listarPorCategoria("Higiene");
    for (auto& p : higiene) {
        cout << "- " << p.getNome() << " (" << p.getEstoque() << " un)\n";
    }

    cout << "\n[4] Registrando venda de Sabonete...\n";
    bool venda = inv.registrarVenda("Sabonete");
    cout << (venda ? "Venda realizada!\n" : "Falha na venda.\n");

    cout << "\n[5] Valor total do inventário:\n";
    cout << "R$ " << inv.calcularValorTotal() << endl;

    cout << "\n[6] Histórico de vendas:\n";
    for (auto& nome : inv.getHistorico()) {
        cout << "- " << nome << endl;
    }

    cout << "\nFIM DOS TESTES\n\n";
}

void menuPrincipal(Inventario& inv) {
    while (true) {
        cout << "\nMENU DO INVENTÁRIO\n";
        cout << "1) Adicionar produto\n";
        cout << "2) Buscar produto\n";
        cout << "3) Listar por categoria\n";
        cout << "4) Registrar venda\n";
        cout << "5) Valor total do inventário\n";
        cout << "6) Mostrar histórico de vendas\n";
        cout << "0) Sair\n";
        cout << "Escolha: ";

        int opcao;
        cin >> opcao;

        if (!cin) { limparEntrada(); continue; }

        if (opcao == 0) {
            cout << "\nEncerrando o programa...\n";
            break;
        }

        switch (opcao) {

            case 1: {
                string nome, categoria;
                double preco;
                int estoque;

                cout << "Nome do produto: ";
                limparEntrada();
                getline(cin, nome);

                cout << "Preço: ";
                cin >> preco;

                cout << "Estoque inicial: ";
                cin >> estoque;

                cout << "Categoria: ";
                limparEntrada();
                getline(cin, categoria);

                inv.adicionarProduto(Produto(nome, preco, estoque, categoria));
                cout << "Produto adicionado!\n";
                break;
            }

            case 2: {
                string nome;
                cout << "Nome do produto para buscar: ";
                limparEntrada();
                getline(cin, nome);

                int idx = inv.buscarProduto(nome);
                if (idx != -1) cout << "Produto encontrado!\n";
                else cout << "Produto não encontrado.\n";

                break;
            }

            case 3: {
                string categoria;
                cout << "Categoria: ";
                limparEntrada();
                getline(cin, categoria);

                auto lista = inv.listarPorCategoria(categoria);
                if (lista.empty()) {
                    cout << "Nenhum produto nessa categoria.\n";
                } else {
                    cout << "Produtos em " << categoria << ":\n";
                    for (auto& p : lista) {
                        cout << "- " << p.getNome()
                             << " (" << p.getEstoque() << " unidades)\n";
                    }
                }
                break;
            }

            case 4: {
                string nome;
                cout << "Produto a vender: ";
                limparEntrada();
                getline(cin, nome);

                bool ok = inv.registrarVenda(nome);
                cout << (ok ? "Venda registrada!\n" : "Falha na venda.\n");
                break;
            }

            case 5: {
                cout << "Valor total do inventário: R$ "
                     << inv.calcularValorTotal() << "\n";
                break;
            }

            case 6: {
                cout << "Histórico de vendas:\n";
                for (auto& nome : inv.getHistorico()) {
                    cout << "- " << nome << endl;
                }
                break;
            }

            default:
                cout << "Opção inválida!\n";
        }
    }
}
