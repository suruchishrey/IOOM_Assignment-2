/*
    ================================================================================================================
    Author - Suruchi Shrey
    Roll no. - BT18CSE014
    ================================================================================================================
*/
#include"StudentArray.h"
using namespace std;

StudentArray::StudentArray()
{
    cout<<"Constructing Student Database\n";
    for(int i=0;i<MAX_SIZE;++i)
    {
        student[i]=new Student;
    }
    this->curr_size=0;
}

//copy constructor
StudentArray::StudentArray(const StudentArray &obj)
{
    cout<<"Constructing Student Database wid copy constructor\n";
    for(int i=0;i<MAX_SIZE;++i)
    {
        student[i]=new Student(obj.student[i]->getName(),obj.student[i]->getRollNo(),obj.student[i]->getBranch());
    }
    this->curr_size=obj.curr_size;
}

void StudentArray::insertStudent(char name[],int rno,char branch[],int index)
{
    student[index]->setName(name);
    student[index]->setRollNo(rno);
    student[index]->setBranch(branch);
    this->curr_size++;
}

//overloading the subscript operator if index is <0 or >=MAX_SIZE(5 here) then program will exit leaving a msg
Student& StudentArray::operator [](int index)
{
    if(index<0 || index>=MAX_SIZE)
    {
        cout << "Array index out of bound, exiting"; 
        exit(0); 
    }
    else{
        return *(student[index]);
    }
}

//returns the number of students currently in the database
int StudentArray::getCurrSize()
{
    return this->curr_size;
}

//destructor freeing the memory which we had allocated through constructor
StudentArray::~StudentArray()
{
    cout<<"\nDestructing Student Database";
    for(int i=0;i<MAX_SIZE;++i)
    {
        delete student[i];
    }
    cout<<"\nStudent database destructed.\n";
}

