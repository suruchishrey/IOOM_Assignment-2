/*
    ================================================================================================================
    Author - Suruchi Shrey
    Roll no. - BT18CSE014
    ================================================================================================================
*/
//Student class
#ifndef STUDENT_H    //prevent multiple inclusions
#define STUDENT_H

#include<iostream>

class Student{
    private:
        char *name;
        int roll_no;
        char *branch;
    public:
        Student();
        Student(char name[],int rno,char branch[]);
        Student(const Student &obj);                    //copy constructor
        ~Student();
        void* operator new(size_t size);
        void operator delete(void * ptr);
        void display_data();
        char* getName();
        char* getBranch();
        int getRollNo();
        void setName(char name[]);
        void setBranch(char branch[]);
        void setRollNo(int rno);

};

#endif