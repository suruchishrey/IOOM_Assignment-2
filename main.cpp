#include"Student.h"
#include"StudentArray.h"
       
int main()
{
    int rno,i;
    char name[21],branch[10];
    StudentArray studentArray;

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

    /*-----------Demo for subscript overloading (can uncomment if want to see)--------------
    cout<<"\nTrying to access wrong index(Student[6])\n";
    studentArray[6];*/
    return 0;
}