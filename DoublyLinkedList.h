/*
    ================================================================================================================
    Author - Suruchi Shrey
    Roll no. - BT18CSE014
    ================================================================================================================
*/

//class DoublyLinkedList

#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H
#include"DNode.h"

template<typename T>
class DoublyLinkedList{
    private:
        int curr_size;                          //stores number of nodes in the dll currently
        DNode<T>* head;
        DNode<T>* tail;
    public:
        DoublyLinkedList();
        ~DoublyLinkedList();
        DoublyLinkedList(const DoublyLinkedList<T> &obj);
        bool isEmpty();
        DNode<T>*MakeDNode(T value);
        DNode<T>*MakeDNode(DNode<T>*prev,T data,DNode<T>*next);
        void Insert(T data);
        void insertAtFront(T data);
        void insertAtBack(T data);
        bool insertBefore(T refdata,T data);
        bool insertAfter(T refdata,T data);
        bool deleteNode(T data);
        DNode<T>* searchNode(T data);
        void traverseFromHead();
        void traverseFromTail();
        int getCurrSize();
};


#endif
