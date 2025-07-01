#include<iostream>
using namespace std;
#include "node.h"

template <class T>
Node<T>::Node(T data) {
    this->data = data;
    this->left = NULL;
    this->right = NULL;
}

template <class T>
Node<T>::~Node() {
    left = NULL;
    right = NULL;
}

template <class T>
T Node<T>::getData() {
    return this->data;
}

template <class T>
void Node<T>::setData(T data) {
    this->data = data;
}

template <class T>
Node<T>* Node<T>::getLeft() {
    return this->left;
}

template <class T>
void Node<T>::setLeft(Node<T>* node) {
    this->left = node;
}

template <class T>
Node<T>* Node<T>::getRight() {
    return this->right;
}

template <class T>
void Node<T>::setRight(Node<T>* node) {
    this->right = node;
}