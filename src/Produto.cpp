#include "Produto.hpp"

//Construtor
Produto::Produto(string nome, double preco, int estoque, string categoria)
    : nome(nome), preco(preco), estoque(estoque), categoria(categoria) {}

//Getters
string Produto::getNome() const {
    return nome;
}

double Produto::getPreco() const {
    return preco;
}

int Produto::getEstoque() const {
    return estoque;
}

string Produto:: getCategoria() const {
    return categoria;
}

//Setters

void Produto::setEstoque(int novoEstoque) {
    if (novoEstoque >= 0){
        estoque = novoEstoque;
    }
}