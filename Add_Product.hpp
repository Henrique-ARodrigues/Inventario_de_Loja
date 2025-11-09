#ifndef PRODUTOS_HPP
#define PRODUTOS_HPP

#include <iostream>
#include <vector>
#inlcude <string>

using namespace std;

class products {
    private:
        vector<string> list;

    public:
        void Add(const string& product) {
            list.push_back(product);
        }

        void Remove_Last() const {
            if(!list.empty()) {
                list.pop_back();
            }
            else {
                cout << "O estoque já está vazio!\n";
            }
        }

        void Remove_All() {
            for(int i = 0; i < list.size(); i++) {
                list.pop_back();
            }
            cout << "Sem estoque!"
        }

        void List() {
            for(int i = 0; i < list.size(); i++) {
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
}

#endif
