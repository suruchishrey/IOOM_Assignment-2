/*
    ================================================================================================================
    Author - Suruchi Shrey
    Roll no. - BT18CSE014
    ================================================================================================================
*/

#include"Polar.h"

Polar::Polar(){}

Polar::Polar(float radius,float angle)
{
    this->radius=radius;
    this->angle=angle;
}

Polar Polar::operator+(Polar const &obj)
{
    cout<<"\nExecuting Addition\n";
    Polar result;
    float x1,y1,x2,y2,res_x,res_y,res_radius,res_angle;
    //converting the polar objects into rectangular coordinates
    x1=this->radius*cos(this->angle);
    y1=this->radius*sin(this->angle);
    x2=this->radius*cos(obj.angle);
    y2=this->radius*sin(obj.angle);
    //adding the coordinates
    res_x=x1+x2;
    res_y=y1+y2;
    //converting the resultant coordinates to radius and angle
    res_angle=atan(res_y / res_x); // arc tangent
    res_radius=sqrt(res_x*res_x+res_y*res_y);
    result.radius=res_radius;
    result.angle=res_angle;
    return result;
}

void Polar::print()
{
    cout<<"\nRadius= "<<this->radius<<"\nAngle= "<<this->angle;
}