/*
    ================================================================================================================
    Author - Suruchi Shrey
    Roll no. - BT18CSE014
    ================================================================================================================
*/

#include"DoublyLinkedList.h"
using namespace std;

template<typename T>
DoublyLinkedList<T>::DoublyLinkedList()
{
    this->curr_size=0;
    this->head=NULL;
    this->tail=NULL;
}

template<typename T>
DoublyLinkedList<T>::~DoublyLinkedList()
{
    cout<<"\nDestructing the doubly linked list";
    DNode<T>* temp=NULL;
    while(this->head)
    {
        temp=this->head;
        head=head->next;
        delete temp;
    }
    this->head=NULL;
    this->tail=NULL;
    this->curr_size=0;
}

template<typename T>
bool DoublyLinkedList<T>::isEmpty()
{
    return (this->head==NULL);
}

template<typename T>
DNode<T>* DoublyLinkedList<T>::MakeDNode(T data)
{
    DNode<T>*newptr=new DNode<T>(data);
    if(newptr==NULL)
    {
        throw "Null Pointer Exception!";
    }
    return newptr;
}

//overloaded MakeDNode
template<typename T>
DNode<T>* DoublyLinkedList<T>::MakeDNode(DNode<T>*prev,T data,DNode<T>*next)
{
    DNode<T>*newptr=new DNode<T>(data);
    if(newptr==NULL)
    {
        throw "Null Pointer Exception!";
    }
    this->data=data;
    this->prev=prev;
    this->next=next;
    return newptr;
}

template<typename T>
void DoublyLinkedList<T>::insertAtFront(T data)
{
    DNode<T>*newNode;
    newNode=MakeDNode(data);
    
    if(this->isEmpty())
    {
        this->head=newNode;
        this->tail=newNode;
        this->curr_size++;
    }
    else{
        this->head->prev=newNode;
        newNode->next=this->head;
        this->head=newNode;
        this->curr_size++;
    }
}

template<typename T>
void DoublyLinkedList<T>::insertAtBack(T data)
{
    DNode<T>*newNode;
    try{
        newNode=MakeDNode(data);
    }catch(const char* msg)
    {        
        cerr << msg << endl;
    }
    if(this->isEmpty())
    {
        this->head=newNode;
        this->tail=newNode;
        this->curr_size++;
    }
    else{
        this->tail->next=newNode;
        newNode->prev=this->tail;
        this->tail=newNode;
        this->curr_size++;
    }
}

template<typename T>
bool DoublyLinkedList<T>::insertBefore(DNode<T>*curr, T data)
{
    bool retval=true;
    if(this->isEmpty())
    {
        retval=false;
    }
    else{
        DNode<T>* pos=this->head;
        while(pos!=NULL)
        {
            if(pos==curr)
            {
                break;                      //found the reference node
            }
            pos=pos->next;
        }
        if(pos==NULL)                       //coudn't find the reference node return false
        {
            retval=false;
        }
        else
        {
            DNode<T>* beforeCurr=pos->prev;
            DNode<T>*newNode;
            try{
                newNode=MakeDNode(beforeCurr,data,pos);
            }catch(const char* msg)
            {        
                cerr << msg << endl;
            }
            if(beforeCurr==NULL)           //if reference node is head,then make new node the head
            {
                this->head=newNode;
            }
            else{
                beforeCurr->next=newNode;
            }
            curr->prev=newNode;
        }
        
    }
    return retval;
}

template<typename T>
bool DoublyLinkedList<T>::insertAfter(DNode<T>*curr, T data)
{
    bool retval=true;
    if(this->isEmpty())
    {
        retval=false;
    }
    else{
        DNode<T>* pos=this->head;
        while(pos!=NULL)
        {
            if(pos==curr)
            {
                break;                      //found the reference node
            }
            pos=pos->next;
        }
        if(pos==NULL)                       //coudn't find the reference node return false
        {
            retval=false;
        }
        else
        {
            DNode<T>* AfterCurr=pos->next;
            DNode<T>*newNode;
            try{
                newNode=MakeDNode(pos,data,AfterCurr);
            }catch(const char* msg)
            {        
                cerr << msg << endl;
            }
            if(AfterCurr==NULL)           //if reference node is tail,then make new node the tail
            {
                this->tail=newNode;
            }
            else{
                AfterCurr->prev=newNode;
            }
            curr->next=newNode;
        }
        
    }
    return retval;
}

template<typename T>
bool DoublyLinkedList<T>::deleteNode(DNode<T>*delptr)
{
    bool retval=true;
    if(this->isEmpty())
    {
        retval=false;
        throw "Exception thrown!Delete Error!List is Empty!";
    }
    else{
        DNode<T>*removeNode=this->head;
        while(removeNode!=NULL)
        {
            if(removeNode==delptr)
            {
                break;
            }
            removeNode=removeNode->next;
        }
        if(removeNode==NULL)
        {
            retval=false;
            throw "Exception thrown!Delete Error!This data doesnot exist in the List!";
        }
        else{
            DNode<T>*beforeRemove=removeNode->prev;
            DNode<T>*afterRemove=removeNode->next;
            if (afterRemove==NULL) {                    //if node to be deleted is the last node
                this->tail = beforeRemove;
                this->tail->next=NULL;
            }
            else {
                afterRemove->prev = beforeRemove;
            }
            if (beforeRemove==NULL) {                   //if node to be deleted is the first node
                this->head = afterRemove;
                this->head->prev=NULL;
            }
            else {
                beforeRemove->next = afterRemove;
            }
            cout<<"\nDeleting node with data= "<<removeNode->data;
            delete removeNode;
            this->curr_size--;
        }
    }
    return retval;
}

//this function return the position node's pointer and null if data doesn't exist in the DLL
template<typename T>
DNode<T>* DoublyLinkedList<T>::searchNode(T data)
{
    DNode<T>* retval;
    if(this->isEmpty())
    {
        retval=NULL;
    }
    else{
        DNode<T>* pos=this->head;
        while(pos!=NULL)
        {
            if(pos->data==data)
            {
                break;
            }
            pos=pos->next;
        }
        retval=pos;
    }
    if(retval==NULL)
    {
        throw "Exception thrown!This data doesnot exist in the List!";
    }
    return retval;
}

template<typename T>
void DoublyLinkedList<T>::traverseFromHead()
{
    if(isEmpty())
    {
        cout<<"Empty List!!";
    }
    else{
        DNode<T>* ptr=this->head;
        while(ptr!=NULL)
        {
            cout<<ptr->data<<" --> ";
            ptr=ptr->next;
        }
        cout<<"NULL";
    }
}

template<typename T>
void DoublyLinkedList<T>::traverseFromTail()
{
    if(isEmpty())
    {
        cout<<"Empty List!!";
    }
    else{
        DNode<T>* ptr=this->tail;
        while(ptr!=NULL)
        {
            cout<<ptr->data<<" --> ";
            ptr=ptr->prev;
        }
        cout<<"NULL";
    }
}