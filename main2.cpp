/*
    ================================================================================================================
    Author - Suruchi Shrey
    Roll no. - BT18CSE014
    ================================================================================================================
*/

#include"Polar.h"  
using namespace std;

int main()
{
    float radius1,radius2,angle1,angle2;
    Polar resultPolar;
    //Executing Question2
    cout<<"\nDemonstrating Question2\n";
    cout<<"Addition of two Polar objects\nEnter ";
    cout<<"\nRadius of obj1: ";
    cin>>radius1;
    cout<<"\nAngle of obj1: ";
    cin>>angle1;
    cout<<"\nRadius of obj2: ";
    cin>>radius2;
    cout<<"\nAngle of obj2: ";
    cin>>angle2;

    Polar p1(radius1,angle1);
    Polar p2(radius2,angle2);
    resultPolar=p1+p2;
    cout<<"\nResultant object";
    resultPolar.print();
    cout<<"\nQuestion2 ended\n";
    return 0;
}