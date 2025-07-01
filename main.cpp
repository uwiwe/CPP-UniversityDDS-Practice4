// g++ main.cpp -o main
// ./main

#include <iostream>
#include "./tree/tree.cpp"

using namespace std;

int main() {
    Tree<int> tree;

    int cantidad;
    cout << "Ingrese el numero de nodos a insertar: ";
    cin >> cantidad;

    for (int i = 0; i < cantidad; i++) {
        int valor;
        cout << "Ingrese el valor del nodo #" << i+1 << ": ";
        cin >> valor;
        tree.insertar(valor);
    }

    int eliminarValor;
    cout << "Ingrese el valor del nodo a eliminar: ";
    cin >> eliminarValor;
    tree.eliminar(eliminarValor);

    cout << "Arbol Recorrido en inorden: "; // izquierda -> raiz -> derecha
    tree.inorden(tree.getHead());
    cout << endl;

    cout << "Arbol Recorrido en preorden: "; // raiz -> izquierda -> derecha
    tree.preorden(tree.getHead());
    cout << endl;

    cout << "Arbol Recorrido en postorden: "; // izquierda -> derecha -> raiz
    tree.postorden(tree.getHead());
    cout << endl;
    
    int valorAlturaFE;
    cout << "Ingrese el valor del nodo que quiere calcular la altura y factor de equilibrio: ";
    cin >> valorAlturaFE;

    Node<int>* nodo = tree.buscar(valorAlturaFE);
    cout << "Altura del nodo: " << tree.altura(nodo) << endl;
    cout << "Factor de equilibrio del nodo: " << tree.factorEquilibrio(nodo) << endl;

    return 0;
}