template<class T>
class Node{
    private:
        T data;
        Node<T> *left = NULL;
        Node<T> *right = NULL;
    public:
        Node(T);
        ~Node();
        T getData();
        void setData(T);
        Node<T>* getLeft();
        void setLeft(Node<T>*);
        Node<T>* getRight();
        void setRight(Node<T>*);
};