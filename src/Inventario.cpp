#include "Inventario.hpp"
#include <iostream> 
using std::endl;

//Construtor
Inventario::Inventario() {}

void Inventario::adicionarProduto(const Produto& p) {
    produtos.push_back(p);

    categorias.insert(p.getCategoria());

    qtdPorCategoria[p.getCategoria()]++;

    valorPorCategoria[p.getCategoria()] += 
        p.getPreco() * p.getEstoque();
}

int Inventario::buscarProduto(const string& nome) const {
    for (int i = 0; i < (int)produtos.size(); i++) {
        if (produtos[i].getNome() == nome) {
            return i;
        }
    }
    return -1; // não achou
}

vector<Produto> Inventario::listarPorCategoria(const string& categoria) const {
    vector<Produto> resultado;

    for (const auto& p : produtos) {
        if (p.getCategoria() == categoria) {
            resultado.push_back(p);
        }
    }

    return resultado;
}

double Inventario::calcularValorTotal() const {
    double total = 0.0;

    for (const auto& par : valorPorCategoria) {
        total += par.second;  // soma os valores das categorias
    }

    return total;
}

bool Inventario::registrarVenda(const string& nome) {
    int indice = buscarProduto(nome);

    if (indice == -1) {
        return false; // produto não encontrado
    }

    Produto& p = produtos[indice];

    if (p.getEstoque() <= 0) {
        return false; // sem estoque
    }

    // Diminui do estoque
    p.setEstoque(p.getEstoque() - 1);

    // Atualiza valor total da categoria
    valorPorCategoria[p.getCategoria()] -= p.getPreco();

    // Registra no histórico
    historicoVendas.push_back(nome);

    return true;
}

list<string> Inventario::getHistorico() const {
    return historicoVendas;
}

set<string> Inventario::getCategorias() const {
    return categorias;
}
