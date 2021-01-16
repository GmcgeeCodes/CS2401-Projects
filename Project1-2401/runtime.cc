// The implementation for runtime.h
#include "runtime.h"
#include "MyTime.h"
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

Runtime::Runtime(){
    distance = 0;
}
void Runtime::input(istream& ins){
   rtime.input(ins);
   ins >> distance;

}
void Runtime::output(ostream& outs) const{
    rtime.output(outs);

    outs.setf(ios::fixed);
    outs.setf(ios::showpoint);
    outs.precision(1);
    outs << " " << distance << endl;
}
istream& operator >>(istream& ins, Runtime& rhs){
    if (&ins == &cin){
        cout << " Please enter the time of your run in hours, minutes, seconds and the distance in miles respectively... " << endl;
    }
    rhs.input(ins);
    return ins;
}
ostream& operator <<(ostream& outs, const Runtime& rhs){
    rhs.output(outs);
    return outs;
}
Runtime Runtime::operator +(const Runtime& rhs)const{
    Runtime tmp;
    tmp.rtime = rtime + rhs.rtime;
    tmp.distance = distance + rhs.distance;

    return tmp;
}
Runtime Runtime::operator -(const Runtime& rhs)const{
    Runtime tmp;
    tmp.rtime = rtime - rhs.rtime;
    tmp.distance = distance - rhs.distance;

    return tmp;
}
Runtime Runtime::operator *(const double& rhs) const{
    Runtime tmp;
    tmp.rtime = rtime * rhs;
    tmp.distance = distance * rhs; 

    return tmp;
}
Runtime operator *(const double& lhs, const Runtime& rhs){
    Runtime tmp;
    tmp = rhs * lhs;
    return tmp;
}

Runtime Runtime::operator /(const double& rhs) const{
    Runtime tmp;
    tmp.rtime = rtime / rhs;
    tmp.distance = distance / rhs;

    return tmp;
}
bool Runtime::operator == (const Runtime& rhs)const{
    if ((rtime == rhs.rtime) && (distance == rhs.distance)){
        return true;
    }
    return false;
}
bool Runtime::operator != (const Runtime& rhs)const{

    return ((rtime == rhs.rtime) && (distance == rhs.distance));

}
bool Runtime::distance_equal(double d) const{
    double tmp = fabs(distance - d);
    if(tmp <= 0.10){
        return true;
    }
    return false;
}