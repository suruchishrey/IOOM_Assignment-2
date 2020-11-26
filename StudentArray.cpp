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
        //allocating memory to Student object using overloaded new and Constructor(parameterized here)
        student[i]=new Student(obj.student[i]->getName(),obj.student[i]->getRollNo(),obj.student[i]->getBranch());
    }
    this->curr_size=obj.curr_size;
}

//inserts the details of a student into the studentArray at passed index
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
        cout << "Array index out of bound!"; 
        //exit(0); 
    }
    else{
        return *(student[index]);
    }
}

//returns the number of students currently in the database(can't be greater than MAX_SIZE)
int StudentArray::getCurrSize()
{
    return this->curr_size;
}

//destructor freeing the memory which we had allocated through constructor
/*Note:As this is a db class,objects are allocated memory through new in the constructor itself(i.e.,during declaraton of this class's object
not by using explicit new operator in the main()),thats why are being deleted here(in destructor). This is only for this db class whereas the overloaded 
new and delete can be used normally in the main program(for creating a Student ibject and deleting it).
*/
StudentArray::~StudentArray()
{
    cout<<"\nDestructing Student Database";
    for(int i=0;i<MAX_SIZE;++i)
    {
        //using overloaded delete
        delete student[i];
    }
    cout<<"\nStudent database destructed.\n";
}

