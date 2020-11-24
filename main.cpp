/*
    ================================================================================================================
    Author - Suruchi Shrey
    Roll no. - BT18CSE014
    ================================================================================================================
*/
#include"Student.h"
#include"StudentArray.h"
#include"Polar.h"   
#include"Complex.h"
#include"DoublyLinkedList.h"

int main()
{
    int rno,i,choice_dll,input_dll1,choice,choice2;
    char name[21],branch[10];
    float radius1,radius2,angle1,angle2,real1,real2,imag1,imag2;
    string input_dll2;
    bool status=true,change_dll=true;
    char ch;
    DoublyLinkedList<int> deci_DLL;
    DoublyLinkedList<string> str_DLL;
    StudentArray studentArray;
    Polar resultPolar;
    Complex resultComplex;

    //Executing Question 1
    cout<<"Demonstrating Question1\n";
    cout<<"Enter the name, roll no and branch of "<<MAX_SIZE<<" students:";
    i=0;
    while(i<MAX_SIZE)
    {
        cout<<"\nEnter name: ";
        cin>>name;
        cout<<"\nEnter roll no: ";
        cin>>rno;
        cout<<"\nEnter branch: ";
        cin>>branch;
        studentArray.insertStudent(name,rno,branch,i);
        i++;
    }
    //Displaying the data
    i=0;
    cout<<"\nDetails you have entered are:";
    while(i<MAX_SIZE)
    {
        cout<<"\nStudent "<<i+1;
        studentArray[i].display_data();
        i++;
    }

    /*-----------Demo for subscript overloading (can uncomment if want to see,program exits)------------------------
    cout<<"\nTrying to access wrong index(Student[6])\n";
    studentArray[6];*/
    
    cout<<"\nQuestion1 ended, Student objects will be deleted at the end of this program when destructor will be called.\n";

    //Executing Question2
    cout<<"\nDemonstrating Question2\n";
    cout<<"Addition of two Polar objects\nEnter ";
    cout<<"\nRadius of obj1: ";
    cin>>radius1;
    cout<<"\nAngle of obj1: ";
    cin>>angle1;
    cout<<"\nRadius of obj2: ";
    cin>>radius2;
    cout<<"\nAngle of obj2: ";
    cin>>angle2;

    Polar p1(radius1,angle1);
    Polar p2(radius2,angle2);
    resultPolar=p1+p2;
    cout<<"Resultant object";
    resultPolar.print();
    cout<<"\nQuestion2 ended\n";
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
                            cout<<"\n1.At front\n2.At back\n";
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
                            deci_DLL.deleteNode(deci_DLL.searchNode(input_dll1));               //throws exception if data isnt present in the list
                        }
                        else{
                            str_DLL.deleteNode(str_DLL.searchNode(input_dll2));
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

    //Executing Question4
    cout<<"\nDemonstrating Question4\n";
    while(status)                           //will run until correct division occurs
    {
        cout<<"Division of two Complex numbers\nEnter ";
        cout<<"\nReal part of obj1: ";
        cin>>real1;
        cout<<"\nImaginary part of obj1: ";
        cin>>imag1;
        cout<<"\nReal part of obj2: ";
        cin>>real2;
        cout<<"\nImaginary part of obj2: ";
        cin>>imag2;

        Complex c1(real1,imag1);
        Complex c2(real2,imag2);
        // try block performs the Division  
        try{
            resultComplex=c1/c2;
            cout<<"Resultant object";
            resultComplex.print();
            status=false;
        }
        // catch block catches exception thrown by division
        catch(runtime_error& e) { 
    
            // prints that exception has occurred, calls the what function using runtime_error object 
            cout << "Exception occurred" << endl 
                << e.what(); 
                cout<<"\nEnter new values\n";
        } 
    }

    return 0;
}