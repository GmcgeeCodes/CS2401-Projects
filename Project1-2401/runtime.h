/******************************************************
    The declaration of the Runtime class which allows the
    storage of information about a run, using the MyTime 
    class for hours, minutes and seconds, and a double for
    the distance run. Some useful operators are included as 
    well.
 	John Dolan Ohio University Athens, Ohio
		Spring Semester 2020
*******************************************************/
#include<iostream>
#include "MyTime.h"
#ifndef RUNTIME_H
#define RUNTIME_H

class Runtime{
    public: 
	Runtime(); 
	// accessors
	double get_distance()const{return distance;}
	MyTime get_time()const{return rtime;}
	// mutators
	void set_time(const MyTime& myt){rtime = myt;}
	void set_distance(const double& d){distance = d;}
	// average pace
	MyTime pace(){return rtime/distance;}
	// overloaded operators - do the math on both time and distance
	Runtime operator +(const Runtime& rhs)const;
	Runtime operator -(const Runtime& rhs)const;
	Runtime operator *(const double& rhs) const;
	Runtime operator /(const double& rhs) const;

	// Full equality means time and distance are the same
	bool operator == (const Runtime& rhs)const;
	bool operator != (const Runtime& rhs)const;

	// Equality of doubles can be problematic - this returns true if they are
	// within a tenth of a mile
 	bool distance_equal(double d) const;
 	// Input - Output
	void input(std::istream& ins);
	void output(std::ostream& outs)const;
	
    private:
	MyTime rtime;
	double distance;
};
// Non-member functions that work with this class
// This first one reverses the arguments for multiplication
   Runtime operator *(const double& lhs, const Runtime& rhs);
// Stream operators
    std::ostream& operator <<(std::ostream& outs, const Runtime& rhs);
    std::istream& operator >>(std::istream& ins, Runtime& rhs);
	
#endif