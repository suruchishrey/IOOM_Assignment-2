/*
    ================================================================================================================
    Author - Suruchi Shrey
    Roll no. - BT18CSE014
    ================================================================================================================
*/

//class DNode

#ifndef DNODE_H
#define DNODE_H

#include<iostream>
#include<string> 

using namespace std;

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

template<typename T>
DNode<T>::DNode()
{
    this->prev=NULL;
    this->next=NULL;
}

template<typename T>
DNode<T>::~DNode()
{
    cout<<"\nDestructing DLL Node";
}

template<typename T>
DNode<T>::DNode(T data)
{
    this->data=data;
    this->prev=NULL;
    this->next=NULL;
}

//copy constructor, makes a node with same data as passed objects but the links are set to null 
template<typename T>
DNode<T>::DNode(const DNode<T> &obj)
{
    this->data=obj.data;
    this->prev=NULL;
    this->next=NULL;
}

template<typename T>
T DNode<T>::getdata()
{
    return this->data;
}

template<typename T>
DNode<T>* DNode<T>::getPrev()
{
    return this->prev;
}

template<typename T>
DNode<T>* DNode<T>::getNext()
{
    return this->next;
}

template<typename T>
void DNode<T>::setData(T data)
{
    this->data=data;
}

template<typename T>
void DNode<T>::setPrev(DNode<T>*prev)
{
    this->prev=prev;
}

template<typename T>
void DNode<T>::setNext(DNode<T>*next)
{
    this->next=next;
}
#endif