// The implementation file for the MyTime class
#include "MyTime.h"
#include <cstdlib>
#include <iostream>
#include <iomanip>
using namespace std;
// Constructor

MyTime::MyTime(int h, int m,int s){
	hours = h;
	minutes = m;
	seconds = s;
}

void MyTime::Reset(int h, int m,int s){
	hours = h;
	minutes = m;
	seconds = s;
}

void MyTime::simplify(){
	minutes += seconds/60;
	seconds = seconds%60;
       	hours += minutes/60;
	minutes = minutes%60;
}

MyTime operator + (const MyTime& t1, const MyTime& t2){
	MyTime tmp;
    tmp.hours = t1.hours + t2.hours;
	tmp.minutes = t1.minutes + t2.minutes;
	tmp.seconds = t1.seconds + t2.seconds;
	tmp.simplify();
	return tmp;
}

MyTime operator - (const MyTime& t1, const MyTime& t2){
	MyTime tmp;
	tmp.seconds = abs((t1.hours*3600+t1.minutes*60+t1.seconds) - (t2.hours*3600+t2.minutes*60+t2.seconds));
	tmp.simplify();
	return tmp;
}

MyTime operator / (const MyTime& t1, double num){
	MyTime tmp;
	tmp.seconds = t1.hours*3600 + t1.minutes*60 + t1.seconds;
	tmp.seconds /= num;
	tmp.simplify();
	return tmp;
}

MyTime operator * (const MyTime& t1, int num){
	MyTime tmp;
    tmp.seconds = t1.hours*3600 + t1.minutes*60 + t1.seconds;
	tmp.seconds *= num;
	tmp.simplify();
	return tmp;
}

//This second multiplication operator is to make the operation commutative
MyTime operator * (int num, const MyTime& t1){
        MyTime tmp;
        tmp.seconds = t1.hours*3600 + t1.minutes*60 + t1.seconds;
        tmp.seconds *= num;
        tmp.simplify();
        return tmp;
}

bool operator == (const MyTime& t1, const MyTime& t2){
	return t1.hours == t2.hours && t1.minutes == t2.minutes
				&&t1.seconds == t2.seconds;
}

bool operator < (const MyTime& t1, const MyTime& t2){
	return (t1.hours*3600 + t1.minutes*60 + t1.seconds) < 
		(t2.hours*3600 + t2.minutes*60 + t2.seconds);
}

bool operator <=(const MyTime& t1, const MyTime& t2){
	return t1 == t2 || t1 < t2;
}

void MyTime::input(istream&ins){
    char junk;
    ins >> hours;
    ins.get(junk);
    ins >> minutes;
    ins.get(junk);
    ins >> seconds;
    simplify();

}

void MyTime::output(ostream& outs)const{
    outs << hours <<':' <<setw(2) << setfill('0') << minutes;
    outs << ':' << setw(2) << setfill('0') << seconds;

}


ostream& operator <<(ostream& outs, const MyTime& t1){
	t1.output(outs);
	return outs;
}

istream& operator >> (istream& ins, MyTime& t1){
	t1.input(ins);
	return ins;
}
