#ifndef LIST_HPP
#define LIST_HPP

#include <cstddef>
#include <vector>
#include <string> 
#include <iostream>
#include "Add_Product.hpp"


using namespace std;

class List_Product {
    private:
        const Add_Product& products;

    public:
        List_Product(const Add_Product& ref)
        : products(ref) {}

        void ListP() const {
            const auto& list = products.getList();

            if(list.empty()) {
                cout << "Estoque vazio!\n";
                return;

            }
            else {
                for(size_t i = 0; i < list.size(); i++) {
                    cout << i + 1 << ". " << list[i] << "\n";
                }
            }

        }

};

#endif
