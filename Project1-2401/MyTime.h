/*****************************************************************
	This is a class that stores time. It stores the time in 
	hours, minutes and seconds, which makes it a little more
	extensive than the one you have used in lab.

	Note: That since all the operators are overloaded, including
	input and output there is NO need to for the application 
	programmer to get directly to the individual components of
	the Time. USE THE OPERATORS!!!
		John Dolan, Associate Professor of Instruction
		Ohio University, Athens, Ohio
		Spring Semester 2020
*************************************************************************/
#include <iostream>
#ifndef MYTIME_H
#define MYTIME_H
    
class MyTime
{   
  public:

    MyTime(int h=0, int m=0, int s=0);   
   
    void Reset(int h, int m, int s);    
   
    friend MyTime operator + (const MyTime& t1, const MyTime& t2);
 
    friend MyTime operator - (const MyTime& t1, const MyTime& t2);
 
    friend MyTime operator * (const MyTime& t1, int num);
    
    friend MyTime operator *(int num, const MyTime& t1);
 
    friend MyTime operator / (const MyTime& t1, double num);

    friend bool operator == (const MyTime& t1, const MyTime& t2);

    friend bool operator < (const MyTime& t1, const MyTime& t2);

    friend bool operator <= (const MyTime& t1, const MyTime& t2);

    void input(std::istream& ins);            

    void output(std::ostream& outs)const;

    int get_hours() const{return hours;}
    int get_minutes() const{return minutes;}
    int get_seconds()const {return seconds;}
   
  private:
      void simplify();
      int hours;      // hours can be > 24
      int minutes;   // 0 <= minutes <= 59
      int seconds;
 };
 std::istream& operator >>(std::istream& fin, MyTime& t);

 std::ostream& operator <<(std::ostream& fout, const MyTime& t);   
 
#endif