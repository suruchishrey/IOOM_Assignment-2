/*
    ================================================================================================================
    Author - Suruchi Shrey
    Roll no. - BT18CSE014
    ================================================================================================================
*/
#ifndef STUDENTARRAY_H    //prevent multiple inclusions
#define STUDENTARRAY_H

#define MAX_SIZE 5
#include"Student.h"

class StudentArray{
    private:
        Student* student[MAX_SIZE];
        int curr_size;
    public:
        StudentArray();
        Student& operator [](int index);
        void insertStudent(char name[],int rno,char branch[],int index);
        ~StudentArray();
};

#endif