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
        vector<string> l;

    public:
        search(const vector<string>& product)
            : l(product) {}

        bool FindProduct(const string& name) const{
            return find(l.begin(), l.end(), name) != l.end();
        }

        void FindAndPrint(const string& name) const{
            if(FindAndPrint(name)) {
                cout << "Produto " << name << " encontrado no inventário.\n";
            }
            else {
                cout << "Fora de esto ou não encontrado!\n";
            }
        }

}

#endif
