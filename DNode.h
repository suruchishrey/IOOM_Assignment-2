/*
    ================================================================================================================
    Author - Suruchi Shrey
    Roll no. - BT18CSE014
    ================================================================================================================
*/

//class DNode(representing a node in the DLL)

#ifndef DNODE_H
#define DNODE_H

#include<iostream>
#include<string> 

template<typename T>  
class DNode{
    private:
        T data;
        DNode<T>* prev;
        DNode<T>* next;
    public:
        DNode();
        ~DNode();
        DNode(T data);
        DNode(DNode<T>*prev,T data,DNode<T>*next);
        DNode(const DNode<T> &obj);
        T getdata();
        DNode<T>* getPrev();
        DNode<T>* getNext();
        void setData(T data);
        void setPrev(DNode<T>*);
        void setNext(DNode<T>*);
};

#endif