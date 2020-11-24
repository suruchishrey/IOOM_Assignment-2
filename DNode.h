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
    public:
        T data;
        DNode<T>* prev;
        DNode<T>* next;
        DNode();
        DNode(T data);
        DNode(DNode*prev,T data,DNode*next);
};
template<typename T>
DNode<T>::DNode()
{
    this->prev=NULL;
    this->next=NULL;
}

template<typename T>
DNode<T>::DNode(T data)
{
    this->data=data;
    this->prev=NULL;
    this->next=NULL;
}

#endif