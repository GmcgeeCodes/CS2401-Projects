/*
 Header File: college.h
This file is for the college class. This class represents a students college course history including 
the classes taken, GPA and grades.
The Invariants: The private member variables of this class
contain a string that is a name , and a head_ptr variable that points to the head
of the linked list being held by this container class.

Name: Gerald McGee
Class: CS 2401
Date: 03/3/20
Professor Dolan
*/
#ifndef COLLEGE_H
#define COLLEGE_H

#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include "node.h"
#include "course.h"

class college{
    public:
    // The Big 3 and Constructor 
    college(std::string n = "", node* head = NULL){name = n; head_ptr = head;}
    ~college();
    college(const college& source);
    void operator =(const college& source);
    // setters 
    void set_name(std::string s){ name = s;}

    // I/O
    void load(std::istream &ins);
    void save(std::ostream &outs);
    void display(std::ostream &outs);


    // Member functions
    void add(const course &tmp);
    void remove(const std::string &coursename); 
    double hours();
    double gpa();

    private:
    //helpers
    node* list_locate(size_t position);
    size_t list_length();
    node* list_search(const std::string& target);
    size_t find_pos(const node* target);
    //

    node *head_ptr;
    std::string name;
};
#endif






