/*
    ================================================================================================================
    Author - Suruchi Shrey
    Roll no. - BT18CSE014
    ================================================================================================================
*/

//this file contains the definitions of all the functions declared in "StudentArray.h"

#include"StudentArray.h"
using namespace std;

//Note:parameterized constructor can't be there because both the data members are fixed,can't be altered by the user

//default constructor
StudentArray::StudentArray()
{
    cout<<"\nConstructing Student Database\n";
    this->curr_size=0;
}

//copy constructor
StudentArray::StudentArray(StudentArray &obj)
{
    cout<<"Constructing Student Database wid copy constructor\n";
    for(int i=0;i<MAX_SIZE;++i)
    {
        //copying the object fields
        student[i].setName(obj.student[i].getName());
        student[i].setRollNo(obj.student[i].getRollNo());
        student[i].setBranch(obj.student[i].getBranch());
    }
    this->curr_size=obj.curr_size;
}

//inserts the details of a student into the studentArray at passed index
void StudentArray::insertStudent(Student stu,int index)
{
    student[index].setName(stu.getName());
    student[index].setRollNo(stu.getRollNo());
    student[index].setBranch(stu.getBranch());
    this->curr_size++;
}

//overloading the subscript operator if index is <0 or >=MAX_SIZE(5 here) then program will exit leaving a msg
Student& StudentArray::operator [](int index)
{
    if(index<0 || index>=MAX_SIZE)
    {
        throw "Array index out of bound!"; 
    }
    else{
        return student[index];
    }
}

//returns the number of students currently in the database(can't be greater than MAX_SIZE)
int StudentArray::getCurrSize()
{
    return this->curr_size;
}

//destructor (as memory is in stack no need to free them,destructor for Student would get automatically called)
StudentArray::~StudentArray()
{
    cout<<"\nDestructing Student Database\n";
}

