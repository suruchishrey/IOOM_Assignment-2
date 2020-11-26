/*
    ================================================================================================================
    Author - Suruchi Shrey
    Roll no. - BT18CSE014
    ================================================================================================================
*/

//this file contains the definitions of all the functions declared in "Student.h"

#include"Student.h"
using namespace std;

//default constructor
Student::Student(){
    cout<<"\nConstructor called allocating memory for name and branch";
    //allocating memory in heap
    this->name=::new char[21];
    this->branch=::new char[10];
}

//parameterized constructor
Student::Student(char name[],int rno,char branch[])
{
    cout<<"\nConstructor called allocating memory for name and branch";
    //allocating memory in heap
    this->name=::new char[21];
    this->branch=::new char[10];
    this->setName(name);
    this->setRollNo(rno);
    this->setBranch(branch);
}

//copy constructor
Student::Student(const Student &obj)
{
    cout<<"\nConstructor called allocating memory for name and branch";
    //allocating memory in heap
    this->name=::new char[21];
    this->branch=::new char[10];
    this->setName(obj.name);
    this->setBranch(obj.branch);
    this->setRollNo(obj.roll_no);
}

//Overloading new,Allocating memory for Student object
void* Student::operator new(size_t size)
{
    cout<<"\nConstructing Student Object(new)";
    //allocating memory for student object on stack
    void*newptr=malloc(size);
    return newptr;
}

//Overloading delete
void Student::operator delete(void* ptr)                    //it calls destrutor first so there memory for name and branch are deallocated
{
    cout<<"\nDeleting Student Object";
    //freeing the memory allocated to student object
    free(ptr);
} 

void Student::display_data()
{
     cout<<"\nName    :   "<<this->name<<"\nRoll No :   "<<this->roll_no<<"\nBranch  :   "<<this->branch;
}

char* Student::getName()
{
    return this->name;
}

char* Student::getBranch()
{
    return this->branch;
}

int Student::getRollNo()
{
    return this->roll_no;
}

void Student::setName(char name[])
{
    strcpy(this->name,name);
}

void Student::setBranch(char branch[])
{
    strcpy(this->branch,branch);
}

void Student::setRollNo(int rno)
{
    this->roll_no=rno;
}

//Destructor
Student::~Student()
{
    //freeing the memory which was allocated to name and branch arrays,handling the case when the object goes out of scope
    cout<<"\nDestructor called,freeing memory of name and branch";
    free(this->name);
    free(this->branch);
}