#ifndef PRODUTO_HPP
#define PRODUTO_HPP

#include <string>
using std::string;

class Produto {
    private:
        string nome;
        double preco;
        int estoque;
        string categoria;
    
    public:
        //Constructor
        Produto(string nome, double preco, int estoque, string categoria);

        //Getters
        string getNome() const;
        double getPreco() const;
        int getEstoque() const;
        string getCategoria() const;

        //Setters
        void setEstoque(int novoEstoque);

};


#endif