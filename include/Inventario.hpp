#ifndef INVETARIO_HPP
#define INVENTARIO_HPP

#include <vector>
#include <set>
#include <map>
#include <list>
#include <string>

#include "Produto.hpp"

using std::vector;
using std::set;
using std::map;
using std::list;
using std::string;

class Inventario {
    private:
        vector<Produto> produtos;
        set<string> categorias;
        map<string, int> qtdPorCategoria;
        map<string, double> valorPorCategoria;
        list<string> historicoVendas;
        
    public:
        // Construtor
        Inventario();

        void adicionarProduto(const Produto& p);

        int buscarProduto(const string& nome) const;

        vector<Produto> listarPorCategoria(const string& categoria) const;

        double calcularValorTotal() const;

        bool registrarVenda(const string& nome);

        list<string> getHistorico() const;
        set<string> getCategorias() const;
};

#endif
