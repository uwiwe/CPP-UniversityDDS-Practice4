template<class T>
class Tree {
    private:
        Node<T>* head = NULL;

    public:
        Tree();
        ~Tree();

        void insertar(T);
        void eliminar(T);

        Node<T>* getHead() {
             return head; // para definir el nodo por el que empieza
            }

        void inorden(Node<T>*);
        void preorden(Node<T>*);
        void postorden(Node<T>*);

        Node<T>* buscar(T);
        int altura(Node<T>*);
        int factorEquilibrio(Node<T>*);
};