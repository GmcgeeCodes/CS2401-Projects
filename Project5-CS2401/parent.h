/*
 * Header File: Parent.h
 * This file is for the parent class for the homes of the animals. It does not
 * have any member variables.
 * 
 * Name: Gerald McGee
 * Class: CS2401
 * Date: 04/06/20
 * Professor Dolan
 * 
*/
#ifndef PARENT_H
#define PARENT_H
#include <cstdlib>
#include <iomanip>
#include<iostream>
#include <string> 


class parent{
    public:
        virtual void input(std::istream &ins) = 0;
        virtual void output(std::ostream &outs) = 0;

    private:

    protected: //child classes have direct access 
};
#endif
