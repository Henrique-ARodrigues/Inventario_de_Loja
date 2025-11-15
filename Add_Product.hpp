#ifndef ADD_HPP
#define ADD_HPP

#include <cstddef>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Add_Product {
    private:
        vector<string> list;

    public:

        void Add(const string& product) {
            list.push_back(product);
        }

        void Remove_Last() {
            if(!list.empty()) {
                list.pop_back();
            }
            else {
                cout << "O estoque já está vazio!\n";
            }
        }

        void Remove_All() {
            list.clear();
            cout << "Sem estoque!";
        }

        void List() {
            for(size_t i = 0; i < list.size(); i++) {
                cout << "- " << list[i] << " -" << "\n";
            }
        }

        void List_Size() const {
            cout << "Quantidade de produtos no estoque: " << list.size() << "\n";
        }

        void Empty() const {
            if(!list.empty()) {
                cout << "O estoque está com produtos!\n";
            }
            else {
                cout << "O estoque está vazio!\n";
            }

        }
        //Getter
        const vector<string>& getList() const {
            return list;
        }
};

#endif
