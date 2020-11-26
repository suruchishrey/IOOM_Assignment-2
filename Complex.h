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

class Complex{
    private:
        float real;
        float imag;
    public:
        Complex();
        Complex(float ,float );
        Complex(const Complex &obj);
        Complex operator/(Complex const &obj);
        float getRealPart();
        float getImagPart();
        void setRealPart(float);
        void setImagPart(float);
        void print();
        ~Complex();
};
#endif