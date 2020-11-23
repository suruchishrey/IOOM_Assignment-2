/*
    ================================================================================================================
    Author - Suruchi Shrey
    Roll no. - BT18CSE014
    ================================================================================================================
*/

#include"Complex.h"

Complex::Complex(){}

Complex::Complex(float real,float imag)
{
    this->real=real;
    this->imag=imag;
}

//Division of two complex numbers-> (a+bi)/(c+di) =(ac+bd)/(c2 + d2) + (bc-ad)/(c2 + d2)i
Complex Complex::operator/(Complex const &obj)
{
    cout<<"\nExecuting division\n";
    Complex result;
    float res_real,res_imag,den;
    den=pow(obj.real,2)+pow(obj.imag,2);
    // If denominator is Zero, throw runtime_error 
    if (den == 0) { 
        throw runtime_error("Math error: Attempted to divide by Zero(change the values)\n"); 
    } 
    // Otherwise return the result of division 
    res_real=(((this->real)*(obj.real))+((this->imag)*(obj.imag)))/(den);
    res_imag=(((obj.real)*(this->imag))-((this->real)*(obj.imag)))/(den);
    result.real=res_real;
    result.imag=res_imag;
    return result;
}

void Complex::print()
{
    cout<<"\nReal= "<<this->real<<" ,Imaginary= "<<this->imag<<" ==> ";
    cout<<this->real<<" + "<<this->imag<<"i";
}