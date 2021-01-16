/*
Implementation for friend class
Friend implementation file
Name: Gerald McGee 
Date: 02/08/2020
*/

#include <iostream>
#include "friend.h"
#include "date.h"
#include <string>
#include <cctype>

using namespace std;

Friend::Friend(){

    name = ""; // Initialize name to empty string 
}
string Friend::get_name() const{
    return name;
}
Date Friend::get_bday() const {
    return bday;
}
void Friend::input(istream& ins){
    if (&ins == &cin)
        cout << "Please enter your first and last name, and then your birthday! Month , Day, and Year" << endl;
    
    while (ins.peek() == '\n' || ins.peek() == 'r' ){
        ins.ignore();
    }
    getline(ins, name);
    ins >> bday;
}
istream& operator >>(istream& ins,Friend& f){
f.input(ins);
return ins;
}
void Friend::output(ostream& outs)const{
    outs <<  name << endl;
    outs  << bday;
}
ostream& operator <<(ostream& outs,const Friend& f){
    f.output(outs);
    return outs;
}
bool Friend::operator == (const Friend& other)const{
    string tmpname = name;
    string tmpTwoname = other.name;

    for(size_t i = 0; i < tmpname.length(); ++i){
        if (isupper(tmpname[i])){
            tmpname[i] = tolower(tmpname[i]);

        }
    }
    for (size_t i = 0; i < tmpTwoname.length(); ++i){
        if (isupper(tmpTwoname[i])){
            tmpTwoname[i] = tolower(tmpTwoname[i]);
        }
    }

    return ((tmpname == tmpTwoname) && (bday == other.bday));
}
bool Friend::operator != (const Friend& other)const{
    string tmpname = name;
    string tmpTwoname = other.name;

    for(size_t i = 0; i < tmpname.length(); ++i){
        if (isupper(tmpname[i])){
            tmpname[i] = tolower(tmpname[i]);

        }
    }

    for (size_t i = 0; i < tmpTwoname.length(); ++i){
        if (isupper(tmpTwoname[i])){
            tmpTwoname[i] = tolower(tmpTwoname[i]);
        }
    }
    return ((tmpname != tmpTwoname) && (bday != other.bday));
}

