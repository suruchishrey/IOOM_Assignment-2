/*
    ================================================================================================================
    Author - Suruchi Shrey
    Roll no. - BT18CSE014
    ================================================================================================================
*/

/*
    This is the driver program for Q4,it has implementations of all the functions of the Complex class.
    It demonstrates operator overloading for operator / and catches exception divide by zero,if denominator is zero in division.
*/
#include"Complex.h"

using namespace std;

int main()
{
    float real1,real2,imag1,imag2;
    bool status=true;
    Complex resultComplex;

    //Executing Question4
    cout<<"\nDemonstrating Question4\n";
    while(status)                           //will run until correct division occurs without any exception
    {
        cout<<"\nDivision of two Complex numbers\nEnter ";
        cout<<"\nReal part of obj1: ";
        cin>>real1;
        cout<<"\nImaginary part of obj1: ";
        cin>>imag1;
        cout<<"\nReal part of obj2: ";
        cin>>real2;
        cout<<"\nImaginary part of obj2: ";
        cin>>imag2;

        Complex c1(real1,imag1);
        Complex c2(real2,imag2);
        // try block performs the Division  
        try{
            resultComplex=c1/c2;
            cout<<"\nResultant object";
            resultComplex.print();
            status=false;
        }
        // catch block catches exception thrown by division
        catch(runtime_error& e) { 
    
            // prints that exception has occurred, calls the what function using runtime_error object 
            cout << "\nException occurred" << endl 
                << e.what(); 
                cout<<"\nEnter new values\n";
        } 
    }
    return 0;
}
