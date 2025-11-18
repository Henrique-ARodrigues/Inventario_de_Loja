# Exercício Final - Unidade 2: Sistema de inventário de loja usando STL

## Discentes: Henrique Rodrigues e Fabrícia Brito

### Classe Produto
Implementação feita baseado no que foi solicitado:
- vector<Produto>: lista de produtos (classe Produto com nome, preço, estoque, categoria)
- set<string>: categorias únicas de produtos
- map<string, int>: contagem de produtos por categoria
- map<string, double>: valor total em estoque por categoria
- list<string>: histórico de produtos vendidos

### Classe Inventário
Feita para manipular a classe de Produtos e realizar ações do sistema:
- Adicionar produtos
- Buscar produto por nome
- Listar produtos de uma categoria
- Calcular valor total do inventário
- Registrar venda (remove do estoque e adiciona ao histórico)

### Classe Menu
Usada para interagir com o sistema, podendo variar entre rodar os testes automáticos e interagir diretamente com o inventário.
Na parte de Menu Interativo, tem um conjunto de loop com as ações.

## Como compilar
```bash
make

\\Gera executável

.\inventario

\\Para limpeza

make clean
```
