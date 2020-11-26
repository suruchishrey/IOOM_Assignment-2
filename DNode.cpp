/*
    ================================================================================================================
    Author - Suruchi Shrey
    Roll no. - BT18CSE014
    ================================================================================================================
*/

#include"DNode.h"
using namespace std;

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


