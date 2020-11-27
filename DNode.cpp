/*
    ================================================================================================================
    Author - Suruchi Shrey
    Roll no. - BT18CSE014
    ================================================================================================================
*/

#include"DNode.h"
using namespace std;

template class DNode<float>;
template class DNode<string>;

//default constructor
template<typename T>
DNode<T>::DNode()
{
    this->prev=NULL;
    this->next=NULL;
}

//Destructor
template<typename T>
DNode<T>::~DNode()
{
    cout<<"\nDestructing DLL Node";
}

//parameterized constructor
template<typename T>
DNode<T>::DNode(T data)
{
    this->data=data;
    this->prev=NULL;
    this->next=NULL;
}

//copy constructor, makes a node with same data as passed objects but the links are not copied(as its making a copy of data) 
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

