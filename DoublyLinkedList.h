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

using namespace std;

template<typename T>
class DoublyLinkedList{
    private:
        int curr_size;
        DNode<T>* head;
        DNode<T>* tail;
    public:
        DoublyLinkedList();
        ~DoublyLinkedList();
        DoublyLinkedList(const DoublyLinkedList<T> &obj);
        bool isEmpty();
        DNode<T>*MakeDNode(T value);
        DNode<T>*MakeDNode(DNode<T>*prev,T data,DNode<T>*next);
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
    cout<<"\nDestructing the doubly linked list... ";
    DNode<T>* temp=NULL;
    while(this->head)
    {
        temp=this->head;
        head=head->getNext();
        delete temp;
    }
    this->head=NULL;
    this->tail=NULL;
    this->curr_size=0;
}

//copy constructor
template<typename T>
DoublyLinkedList<T>::DoublyLinkedList(const DoublyLinkedList<T> &obj)
{
    if(obj.curr_size==0)                                //throwing exception if passed list is empty
    {
        throw "Exception Thrown! Can't initialise with an Empty List!";
    }
    cout<<"\nCopy constructor called...Copying the list";
    this->head=NULL;
    this->tail=NULL;
    this->curr_size=0;
    DNode<T>* ptr=obj.head;
    while(ptr!=NULL)
    {
        this->insertAtBack(ptr->getdata());
        ptr=ptr->getNext;
    }
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
    newptr->setPrev(prev);
    newptr->setNext(next);
    return newptr;
}

template<typename T>
void DoublyLinkedList<T>::insertAtFront(T data)
{
    DNode<T>*newNode;
    try{
        newNode=MakeDNode(data);
    }catch(const char* msg)
    {        
        throw;           //rethrowing the exception out of the function
    }
    if(this->isEmpty())
    {
        this->head=newNode;
        this->tail=newNode;
        this->curr_size++;
    }
    else{
        this->head->setPrev(newNode);
        newNode->setNext(this->head);
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
        throw;           //rethrowing the exception out of the function
    }
    if(this->isEmpty())
    {
        this->head=newNode;
        this->tail=newNode;
        this->curr_size++;
    }
    else{
        this->tail->setNext(newNode);
        newNode->setPrev(this->tail);
        this->tail=newNode;
        this->curr_size++;
    }
}

//function for inserting the data before some other data
template<typename T>
bool DoublyLinkedList<T>::insertBefore(T refdata, T data)
{
    bool retval=true;
    if(this->isEmpty())
    {
        retval=false;
        throw "Exception thrown!Insertion Error!List is Empty!";
    }
    else{
            DNode<T>* pos=this->searchNode(refdata);
            DNode<T>* beforeCurr=pos->getPrev();
            DNode<T>*newNode;
            try{
                newNode=MakeDNode(beforeCurr,data,pos);
            }catch(const char* msg)
            {        
                throw;           //rethrowing the exception out of the function
            }
            if(beforeCurr==NULL)           //if reference node is head,then make new node the head
            {
                this->head=newNode;
            }
            else{
                beforeCurr->setNext(newNode);
            }
            pos->setPrev(newNode);
            this->curr_size++;
        }
        
    return retval;
}

template<typename T>
bool DoublyLinkedList<T>::insertAfter(T refdata,T data)
{
    bool retval=true;
    if(this->isEmpty())
    {
        retval=false;
        throw "Exception thrown!Insertion Error!List is Empty!";
    }
    else{
            DNode<T>* pos=this->searchNode(refdata);
            DNode<T>* AfterCurr=pos->getNext();
            DNode<T>*newNode;
            try{
                newNode=MakeDNode(pos,data,AfterCurr);
            }catch(const char* msg)
            {        
                throw;                    //rethrowing the exception out of the function
            }
            if(AfterCurr==NULL)           //if reference node is tail,then make new node the tail
            {
                this->tail=newNode;
            }
            else{
                AfterCurr->setPrev(newNode);
            }
            pos->setNext(newNode);
            this->curr_size++;
        }
        
    return retval;
}

template<typename T>
bool DoublyLinkedList<T>::deleteNode(T data)
{
    bool retval=true;
    if(this->isEmpty())
    {
        retval=false;
        throw "Exception thrown!Delete Error!List is Empty!";
    }
    else{
            DNode<T>*removeNode=this->searchNode(data);
            DNode<T>*beforeRemove=removeNode->getPrev();
            DNode<T>*afterRemove=removeNode->getNext();
            if (afterRemove==NULL) {                    //if node to be deleted is the last node
                this->tail = beforeRemove;
                this->tail->setNext(NULL);
            }
            else {
                afterRemove->setPrev(beforeRemove);
            }
            if (beforeRemove==NULL) {                   //if node to be deleted is the first node
                this->head = afterRemove;
                this->head->setPrev(NULL);
            }
            else {
                beforeRemove->setNext(afterRemove);
            }
            cout<<"\nDeleting node with data= "<<removeNode->getdata();
            delete removeNode;
            this->curr_size--;
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
        throw "Exception thrown!Search Error!List is Empty!";
    }
    else{
        DNode<T>* pos=this->head;
        while(pos!=NULL)
        {
            if(pos->getdata()==data)
            {
                break;
            }
            pos=pos->getNext();
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
            cout<<ptr->getdata()<<" --> ";
            ptr=ptr->getNext();
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
            cout<<ptr->getdata()<<" --> ";
            ptr=ptr->getPrev();
        }
        cout<<"NULL";
    }
}

template<typename T>
int DoublyLinkedList<T>::getCurrSize()
{
    return this->curr_size;
}

#endif
