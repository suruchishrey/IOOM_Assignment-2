/*
    ================================================================================================================
    Author - Suruchi Shrey
    Roll no. - BT18CSE014
    ================================================================================================================
*/

//Polar class

#ifndef POLAR_H
#define POLAR_H
#include<iostream>
#include<math.h>            //for trigonometric functions and sqrt
using namespace std;

class Polar{
    private:
        float radius;
        float angle;
    public:
        Polar();
        Polar(float radius,float angle);
        // This is automatically called when '+' is used with 
        // between two Polar objects 
        Polar operator+(Polar const &obj);
        void print();
};

#endif