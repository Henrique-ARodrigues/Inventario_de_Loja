#ifndef SEARCH_HPP
#define SEARCH_HPP

#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include "Add_Product.hpp"

using namespace std;

class search {
    private:
        const Add_Product& products;

    public:

        search(const Add_Product& ref)
            : products(ref) {}

        bool FindProduct(const string& name) const{
            const auto& list = products.getList();
            return find(list.begin(), list.end(), name) != list.end();
        }

        void FindAndPrint(const string& name) const{
            if(FindProduct(name)) {
                cout << "Produto " << name << " encontrado no inventário.\n";
            }
            else {
                cout << "Fora de estoque ou não encontrado!\n";
            }
        }


};

#endif
