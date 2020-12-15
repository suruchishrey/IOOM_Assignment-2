/*
    ================================================================================================================
    Author - Suruchi Shrey
    Roll no. - BT18CSE014
    ================================================================================================================
*/

/*
    This is the driver program for Q1,it has implementations of all the functions of the Student class and StudentArray class.
    It demonstrates operator overloading for operators new,delete and [].
    It allocates memory for 5 students first at the start of program and then take their details as i/p then deletes them after showing.
*/

#include"Student.h"
#include"StudentArray.h"

using namespace std;

int main()
{
    int rno,i;
    char name[21],branch[10],choice;
    StudentArray studentArray;
    Student*s=new Student;              //for insertion in student db(studentArray)
    //Executing Question 1
    cout<<"\n\n------------------------Demonstrating Question1-----------------------------\n";
    cout<<"Enter the name, roll no and branch of "<<MAX_SIZE<<" students:";
    i=0;
    while(i<MAX_SIZE)
    {
        cout<<"\nEnter for student "<<i+1;
        cout<<"\nEnter name: ";
        cin>>name;
        cout<<"\nEnter roll no: ";
        cin>>rno;
        cout<<"\nEnter branch: ";
        cin>>branch;
        s->setName(name);
        s->setRollNo(rno);
        s->setBranch(branch);
        studentArray.insertStudent(*s,i);
        //cout<<"\nCopy constructor was called for function call\n\n";
        i++;
    }
    
    //Displaying the data
    i=0;
    cout<<"\n\nDetails you have entered are:";
    while(i<MAX_SIZE)
    {
        cout<<"\n\nStudent "<<i+1;
        studentArray[i].display_data();                 //studentArray[i] is ith student,coz its having an array of students
        i++;
    }

    while(1)
    {
        cout<<"\n\nEnter which student's details you want to see?(enter correct index 0-4): ";
        cin>>i;
        try{
            studentArray[i].display_data();
        }catch(const char* msg)                              //for array index out of bound exception
        {        
            cerr << msg << endl;
        } 
        cout<<"\nWant to see more?(y or n): ";
        cin>>choice;
        if(choice=='n')break;
    }

    cout<<"\n\nCreating a random object with new and deleting it with delete(just for demonstration of parameterized constructor)";
    cout<<"\nEnter name: ";
    cin>>name;
    cout<<"\nEnter branch: ";
    cin>>branch;
    cout<<"\nEnter roll no: ";
    cin>>rno;
    Student*sptr=new Student(name,rno,branch);
    cout<<"\n\nNew object is: ";
    sptr->display_data();
    cout<<"\nDeleting object";
    delete sptr;
    cout<<"\n\nDeleting the local object(which was used for insertion in db)";
    delete s;                       //deleting s
    
    cout<<"\n\n-----------Question1 ended, Student objects will be deleted at the end of this program when destructor will be called.----------\n";
    return 0;
}