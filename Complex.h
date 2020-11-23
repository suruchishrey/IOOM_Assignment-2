/*
    ================================================================================================================
    Author - Suruchi Shrey
    Roll no. - BT18CSE014
    ================================================================================================================
*/

//Complex class

#ifndef COMPLEX_H
#define COMPLEX_H
#include<iostream>
#include<math.h>            //for pow()
#include<stdexcept>        // To use runtime_error 

using namespace std;

class Complex{
    private:
        float real;
        float imag;
    public:
        Complex();
        Complex(float ,float );
        Complex operator/(Complex const &obj);
        void print();
};
#endif