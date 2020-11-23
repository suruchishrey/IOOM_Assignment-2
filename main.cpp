/*
    ================================================================================================================
    Author - Suruchi Shrey
    Roll no. - BT18CSE014
    ================================================================================================================
*/
#include"Student.h"
#include"StudentArray.h"
#include"Polar.h"   
#include"Complex.h"

int main()
{
    int rno,i;
    char name[21],branch[10];
    float radius1,radius2,angle1,angle2,real1,real2,imag1,imag2;
    StudentArray studentArray;
    Polar resultPolar;
    Complex resultComplex;
    bool status=true;

    //Executing Question 1
    cout<<"Demonstrating Question1\n";
    cout<<"Enter the name, roll no and branch of "<<MAX_SIZE<<" students:";
    i=0;
    while(i<MAX_SIZE)
    {
        cout<<"\nEnter name: ";
        cin>>name;
        cout<<"\nEnter roll no: ";
        cin>>rno;
        cout<<"\nEnter branch: ";
        cin>>branch;
        studentArray.insertStudent(name,rno,branch,i);
        i++;
    }
    //Displaying the data
    i=0;
    cout<<"\nDetails you have entered are:";
    while(i<MAX_SIZE)
    {
        cout<<"\nStudent "<<i+1;
        studentArray[i].display_data();
        i++;
    }

    /*-----------Demo for subscript overloading (can uncomment if want to see,program exits)------------------------
    cout<<"\nTrying to access wrong index(Student[6])\n";
    studentArray[6];
    */
    cout<<"\nQuestion1 ended, Student objects will be deleted at the end of this program when destructor will be called.\n";

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
    cout<<"Resultant object";
    resultPolar.print();
    cout<<"\nQuestion2 ended\n";

    cout<<"\nDemonstrating Question4\n";
    while(status)                           //will run until correct division occurs
    {
        cout<<"Division of two Complex numbers\nEnter ";
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
            cout<<"Resultant object";
            resultComplex.print();
            status=false;
        }
        // catch block catches exception thrown by division
        catch(runtime_error& e) { 
    
            // prints that exception has occurred, calls the what function using runtime_error object 
            cout << "Exception occurred" << endl 
                << e.what(); 
                cout<<"\nEnter new values\n";
        } 
    }
    return 0;
}