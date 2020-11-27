/*
    ================================================================================================================
    Author - Suruchi Shrey
    Roll no. - BT18CSE014
    ================================================================================================================
*/

/*
    This is the driver program for Q3,it has implementations of all the functions of the DoublyLinkedList class.
    It also has the try-catch blocks to handle the exceptions thrown by the functions of that class.
*/

#include"DoublyLinkedList.h"

using namespace std;

int main()
{
    int rno,i,choice_dll,choice,choice2;
    float input_dll1;
    string input_dll2;
    bool status=true,change_dll=true;
    char ch;
    DoublyLinkedList<float> deci_DLL;
    DoublyLinkedList<string> str_DLL;
    //Executing Question3
    cout<<"\nDemonstrating Question3\n";
    while(change_dll){
        cout<<"\nMaking new list!\nEnter datatype for the Doubly Linked List:\n1.decimal numbers\n2.strings";
        cin>>choice_dll;
        status=true;
        while(status)
        {
            bool choice_ip=true;
            cout<<"\nWhat do you want to do?\n1.Insertion\n2.Deletion\n";
            cin>>choice2;
    
            //INSERTION
            if(choice2==1)
            {
                    do{
                            if(choice_dll==1)
                            {
                                cout<<"\nEnter a no.: ";
                                cin>>input_dll1;
                            }else{
                                cout<<"\nEnter a string.: ";
                                cin>>input_dll2;
                            }
                            cout<<"\nWhere do you want to insert it in the list?";
                            cout<<"\n1.At front\n2.At back\n3.Before some data\n4.After some data\n";
                            cin>>choice;
                            switch(choice)
                            {
                                case 1:
                                try{
                                    if(choice_dll==1)
                                    {
                                        deci_DLL.insertAtFront(input_dll1);
                                    }
                                    else
                                    {
                                        str_DLL.insertAtFront(input_dll2);
                                    }
                                    
                                }catch (bad_alloc & ba)                             //for exception when attempting to allocate memory with new. 
                                { 
                                    cerr << "bad_alloc caught: " << ba.what(); 
                                } 
                                catch(const char* msg)                              //for null pointer exception
                                {        
                                    cerr << msg << endl;
                                }                       
                                break;

                                case 2:
                                try{
                                    if(choice_dll==1)
                                    {
                                        deci_DLL.insertAtBack(input_dll1);
                                    }
                                    else
                                    {
                                        str_DLL.insertAtBack(input_dll2);
                                    }
                                }catch (bad_alloc & ba)                             //for exception when attempting to allocate memory with new. 
                                { 
                                    cerr << "bad_alloc caught: " << ba.what(); 
                                } 
                                catch(const char* msg)                              //for null pointer exception
                                {        
                                    cerr << msg << endl;
                                }
                                break;

                                case 3:
                                cout<<"\nBefore what data?";
                                try{
                                    if(choice_dll==1)
                                    {
                                        float temp;
                                        cin>>temp;
                                        deci_DLL.insertBefore(temp,input_dll1);
                                    }
                                    else
                                    {
                                        string temp;
                                        cin>>temp;
                                        str_DLL.insertBefore(temp,input_dll2);
                                    }
                                    
                                }catch (bad_alloc & ba)                             //for exception when attempting to allocate memory with new. 
                                { 
                                    cerr << "bad_alloc caught: " << ba.what(); 
                                } 
                                catch(const char* msg)                              //for null pointer exception
                                {        
                                    cerr << msg << endl;
                                }                       
                                break;

                                case 4:
                                cout<<"\nAfter what data?";
                                try{
                                    if(choice_dll==1)
                                    {
                                        float temp;
                                        cin>>temp;
                                        deci_DLL.insertAfter(temp,input_dll1);
                                    }
                                    else
                                    {
                                        string temp;
                                        cin>>temp;
                                        str_DLL.insertAfter(temp,input_dll2);
                                    }
                                    
                                }catch (bad_alloc & ba)                             //for exception when attempting to allocate memory with new. 
                                { 
                                    cerr << "bad_alloc caught: " << ba.what(); 
                                } 
                                catch(const char* msg)                              //for null pointer exception
                                {        
                                    cerr << msg << endl;
                                }                       
                                break;

                                default:cout<<"\nEnter correct choice(front or back)!";
                                        continue;
                            }
                            cout<<"\nShowing the DLL(from head to tail) - \n";
                            if(choice_dll==1)
                            {
                                deci_DLL.traverseFromHead();
                            }
                            else
                            {
                                str_DLL.traverseFromHead();
                            }
                            cout<<"\nWant to enter more data?(y or n): ";
                            cin>>ch;
                            if(ch=='n')choice_ip=false;
                    }while(choice_ip);
            }
            //DELETION
            else if(choice2==2)
            {
                choice_ip=true;
                do{
                    cout<<"\nShowing the DLL(from head to tail) - \n";
                    if(choice_dll==1)
                    {
                        deci_DLL.traverseFromHead();
                    }
                    else
                    {
                        str_DLL.traverseFromHead();
                    }
                    cout<<"\nEnter data to delete: ";
                    if(choice_dll==1)
                    {
                        cin>>input_dll1;
                    }else{
                        cin>>input_dll2;
                    }
                    try{
                        if(choice_dll==1)
                        {
                            deci_DLL.deleteNode(input_dll1);               //throws exception if data isnt present in the list
                        }
                        else{
                            str_DLL.deleteNode(input_dll2);
                        }
                        cout<<"\nShowing the DLL(from head to tail) - \n";
                        if(choice_dll==1)
                        {
                            deci_DLL.traverseFromHead();
                        }
                        else
                        {
                            str_DLL.traverseFromHead();
                        }
                        cout<<"\nWant to delete more data?(y or n): ";
                        cin>>ch;
                        if(ch=='n')choice_ip=false;
                    }catch(const char* msg)                              //for exception thrown if trying to delete the data which doesn't exist
                    {        
                        cerr << msg << endl;
                        choice_ip=false;
                    }
                    
                }while(choice_ip);     
            }
            else{
                cout<<"\nEnter correct choice!";
            }
            cout<<"\nWant to do more INSERT/DELETE operations with the current list?(y or n): ";
            cin>>ch;
            if(ch=='n')status=false;
        }
        cout<<"\nWanna make a new DLL of different type?(the data which you have entered till now would be stored)";
        cin>>ch;
        if(ch=='n')change_dll=false;
    }

    return 0;
}