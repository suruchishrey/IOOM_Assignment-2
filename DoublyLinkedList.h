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

//default constructor
template<typename T>
DoublyLinkedList<T>::DoublyLinkedList()
{
    this->curr_size=0;
    this->head=NULL;
    this->tail=NULL;
}

//destructor
template<typename T>
DoublyLinkedList<T>::~DoublyLinkedList()
{
    cout<<"\nDestructing the doubly linked list... ";
    DNode<T>* temp=NULL;
    //deleting the nodes one by one
    while(this->head)
    {
        temp=this->head;
        head=head->getNext();
        delete temp;
    }
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
    cout<<"\nCopy constructor called...Initialiasing the list with passed object";
    this->head=NULL;
    this->tail=NULL;
    this->curr_size=0;
    DNode<T>* ptr=obj.head;                //pointer for iteration
    while(ptr!=NULL)
    {
        this->insertAtBack(ptr->getdata());                 //copying the data one by one       
        ptr=ptr->getNext;
    }
}

//returns true if list is empty
template<typename T>
bool DoublyLinkedList<T>::isEmpty()
{
    return (this->head==NULL);
}

//creates a new node and returns its pointer
template<typename T>
DNode<T>* DoublyLinkedList<T>::MakeDNode(T data)
{
    DNode<T>*newptr=new DNode<T>(data);
    if(newptr==NULL)
    {
        throw "Null Pointer Exception!Memory couldn't be allocated!";                //throw exception if memory couldn't be allocated
    }
    return newptr;
}

//overloaded MakeDNode,creates a new node with data members from passed arguments 
template<typename T>
DNode<T>* DoublyLinkedList<T>::MakeDNode(DNode<T>*prev,T data,DNode<T>*next)
{
    DNode<T>*newptr=new DNode<T>(data);
    if(newptr==NULL)
    {
        throw "Null Pointer Exception!Memory couldn't be allocated!";               //throw exception if memory couldn't be allocated
    }
    newptr->setPrev(prev);
    newptr->setNext(next);
    return newptr;
}

//this method inserts the data(new node) at the front of the dll
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
    if(this->isEmpty())             //if dll is empty make the head and tail point to the newnode 
    {
        this->head=newNode;
        this->tail=newNode;
        this->curr_size++;
    }
    else{
        //inserting at front 
        this->head->setPrev(newNode);
        newNode->setNext(this->head);
        this->head=newNode;
        this->curr_size++;
    }
}

//this method inserts the data(new node) at the back of the dll
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
    if(this->isEmpty())             //if the dll is empty,then the new node would be the only node in the list          
    {
        this->head=newNode;
        this->tail=newNode;
        this->curr_size++;
    }
    else{
        //inserting at back
        this->tail->setNext(newNode);
        newNode->setPrev(this->tail);
        this->tail=newNode;
        this->curr_size++;
    }
}

//function for inserting the data before some other data
template<typename T>
bool DoublyLinkedList<T>::insertBefore(T refdata, T data)       //arguments are the reference data and data to be added
{
    bool retval=true;
    if(this->isEmpty())
    {
        retval=false;
        throw "Exception thrown!Insertion Error!List is Empty!";
    }
    else{
        //Inserting the data before the reference node
            DNode<T>* pos=this->searchNode(refdata);
            DNode<T>* beforeCurr=pos->getPrev();
            DNode<T>*newNode;
            try{
                newNode=MakeDNode(beforeCurr,data,pos);     //as this can throw exception
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

//function for inserting the data before some other data
template<typename T>
bool DoublyLinkedList<T>::insertAfter(T refdata,T data)              //arguments are the reference data and data to be added       
{
    bool retval=true;
    if(this->isEmpty())
    {
        retval=false;
        throw "Exception thrown!Insertion Error!List is Empty!";            //throw exception if list is empty
    }
    else{
        //Inserting the data after the reference node
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

//this method deletes the node containing the passed data
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

//this function returns the position node's pointer and null if data doesn't exist in the DLL
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

//this method traverses the dll from head to tail and prints the data
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

//this method traverses the dll from tail to head and prints the data
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

//this method returns the current size(no. of nodes) in the dll
template<typename T>
int DoublyLinkedList<T>::getCurrSize()
{
    return this->curr_size;
}

#endif
