#include "../node/node.cpp"
#include "tree.h"

#include <iostream>
using namespace std;

template<class T>
Tree<T>::Tree() {
    head = NULL;
}

template<class T>
Tree<T>::~Tree() {
    head = NULL;
}

template<class T>
void Tree<T>::insertar(T valor) {
    Node<T>* nuevo = new Node<T>(valor); // nodo que me guarda el valor

    if (head == NULL) {
        head = nuevo;
        return;
    }

    Node<T>* actual = head;
    Node<T>* anterior = NULL;

    while (actual != NULL) {
        anterior = actual;
        if (valor < actual->getData()) {
            actual = actual->getLeft(); // si es menor, se va para la izquierda
        } else {
            actual = actual->getRight(); // se va a la derecha si es mayor
        }
    }

    if (valor < anterior->getData()) { // si es menor al padre, se posiciona como hijo izquierdo
        anterior->setLeft(nuevo);
    } else {
        anterior->setRight(nuevo); // si es mayor es el hijo derecho
    }
}

template<class T>
void Tree<T>::eliminar(T valor) {
    // Si el valor a eliminar es head
    if (head != NULL && head->getData() == valor) {
        delete head;
        head = NULL;
        return;
    }

    // Sino, buscamos el padre del nodo a eliminar
    Node<T>* actual = head;
    while (actual != NULL) {
        if (actual->getLeft() != NULL && actual->getLeft()->getData() == valor) { // se verifica que no sea null, para que no crashee si intenta eliminar un nodo en un arbol donde alguno de los hijos sea null
            delete actual->getLeft();
            actual->setLeft(NULL);
            return;
        }
        if (actual->getRight() != NULL && actual->getRight()->getData() == valor) {
            delete actual->getRight();
            actual->setRight(NULL);
            return;
        }

        // Si no es hijo de actual, se avanza en el arbol
        if (valor < actual->getData()) {
            actual = actual->getLeft();
        } else {
            actual = actual->getRight();
        }
    }
}

template<class T>
void Tree<T>::inorden(Node<T>* nodo) { // izquierda -> raiz -> derecha
    if (nodo == NULL) return; // evita el ciclo infinito, cuando se topa con el final de una raiz
    inorden(nodo->getLeft()); // la funcion se llama a si misma para arrancar su propio recorrido por el lado izquierdo hasta el final
    cout << nodo->getData() << " "; // cuando se recorre la izquierda, imprime el nodo actual
    inorden(nodo->getRight()); // lo mismo, con el lado derecho
}

template<class T>
void Tree<T>::preorden(Node<T>* nodo) { // raiz -> izquierda -> derecha
    if (nodo == NULL) return;
    cout << nodo->getData() << " "; // solo se cambia el orden en el que se imprimen. aca se imprime primero la raiz
    preorden(nodo->getLeft());
    preorden(nodo->getRight());
}

template<class T>
void Tree<T>::postorden(Node<T>* nodo) { // izquierda -> derecha -> raiz
    if (nodo == NULL) return;
    postorden(nodo->getLeft());
    postorden(nodo->getRight());
    cout << nodo->getData() << " "; // aca se imprime de ultimo la raiz
}

template<class T>
Node<T>* Tree<T>::buscar(T valor) {
    Node<T>* actual = head;
    while (actual != NULL) {
        if (valor == actual->getData()) {
            return actual;
        }
        if (valor < actual->getData()) {
            actual = actual->getLeft();
        } else {
            actual = actual->getRight();
        }
    }
    return NULL;
}

template<class T>
int Tree<T>::altura(Node<T>* nodo) {
    if (nodo == NULL) return 0; // final de rama
    int altIzq = altura(nodo->getLeft()); // recorre lado izquierdo y se va contando 
    int altDer = altura(nodo->getRight()); // lo mismo
    return 1 + max(altIzq, altDer); // de adentro hacia afuera va subiendo
}

template<class T>
int Tree<T>::factorEquilibrio(Node<T>* nodo) { // copiar y pegar funcion de altura, pero devuelve la diferencia: factor de equilibrio
    if (nodo == NULL) return 0;
    int altIzq = altura(nodo->getLeft());
    int altDer = altura(nodo->getRight());
    return altDer - altIzq;
}
