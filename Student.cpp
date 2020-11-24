/*
    ================================================================================================================
    Author - Suruchi Shrey
    Roll no. - BT18CSE014
    ================================================================================================================
*/

#include<string.h>
#include"Student.h"

Student::Student(){}

Student::Student(char name[],int rno,char branch[])
{
    strcpy(this->name,name);
    this->roll_no=rno;
    strcpy(this->branch,branch);
}

void* Student::operator new(size_t size)
{
    cout<<"Constructing Student Object\n";
    void*newptr=malloc(size);

    /*reinterpret_cast converts the pointer type,here newptr is being converted to Student*(for the current Student object) and then through 
    newptr,name is being accessed and then malloc is called (memory is allocated) which returns void* which is being converted to char* for name 
    */
    (reinterpret_cast<Student *>(newptr))->name = reinterpret_cast<char *>(malloc(21));     

    /*Similarly here,memory for branch is being allocated*/          
    (reinterpret_cast<Student *>(newptr))->branch = reinterpret_cast<char *>(malloc(10));
    return newptr;
}

void Student::operator delete(void* ptr)
{
    cout<<"\nDestructing Student Object";
    //firstly freeing the memory which was allocated to name and branch arrays 
    free(reinterpret_cast<void *>(reinterpret_cast<Student *>(ptr)->name));        //convert ptr to name to Student*,then Student* to void* for delete
    free(reinterpret_cast<void *>(reinterpret_cast<Student *>(ptr)->branch));      //convert ptr to branch to Student*,then Student* to void* for delete
    //then free the memory allocated to student object
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
