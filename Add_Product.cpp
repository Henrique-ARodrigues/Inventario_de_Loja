#incude "Add_Product.hpp"

using namespace std;


int main() {
    products p;
    
    // Adicionando produtos a lista
    p.Add("Banana");
    p.Add("Feijão");
    p.Add("Arroz");
    p.Add("Acerola");
    p.Add("Carne");

    // Listando os produtos
    p.List();
    //Removendo o ultimo iten adicionado
    p.Remove_Last();
    p.List();

    // Verificando se esta vazio
    p.Empty();
    // Verificando o tamanho da lista depois do pop
    p.List_Size();

    //Esvaziando todo o estoque
    p.Remove_All();
    p.List_Size();
    p.Empty();



}
