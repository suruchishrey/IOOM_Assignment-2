/*
    ================================================================================================================
    Author - Suruchi Shrey
    Roll no. - BT18CSE014
    ================================================================================================================
*/

//This class is for overloading [] as Student class is not having a student Array so this is having one

#ifndef STUDENTARRAY_H    //prevent multiple inclusions
#define STUDENTARRAY_H

#define MAX_SIZE 5
#include"Student.h"

class StudentArray{
    private:
        Student* student[MAX_SIZE];
        int curr_size;
    public:
        StudentArray();                         //parameterized constructor can't be there because both the data members are fixed,can't be altered by the user
        StudentArray(const StudentArray &obj);  //copy constructor
        Student& operator [](int index);
        void insertStudent(char name[],int rno,char branch[],int index);
        int getCurrSize();
        ~StudentArray();
};

#endif