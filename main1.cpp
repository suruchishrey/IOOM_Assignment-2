/*
    ================================================================================================================
    Author - Suruchi Shrey
    Roll no. - BT18CSE014
    ================================================================================================================
*/

#include"Student.h"
#include"StudentArray.h"
using namespace std;

int main()
{
    int rno,i;
    char name[21],branch[10];
    StudentArray studentArray;
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
        studentArray[i].display_data();                 //studentArray[i] is ith student,coz its having an array of students
        i++;
    }

    /*-----------Demo for subscript overloading (can uncomment if want to see,program exits)------------------------
    cout<<"\nTrying to access wrong index(Student[6])\n";
    studentArray[6].display_data();
    */
    
    cout<<"\nQuestion1 ended, Student objects will be deleted at the end of this program when destructor will be called.\n";

    return 0;
}