/*
File: dlist.h
This file is for the template container class. It uses a doubly linked list
to hold its data and accesses and manipulates the list through the head and tail 
pointers. 
elaborate more... 
The invariants: Head and tail pointers that point to the head and tail
of the list

Name: Gerald McGee
Class: CS2401
Date: 03/29/20
Professor Dolan
*/
#ifndef DLIST_H
#define DLIST_H

#include "dnode.h"
#include "iterator.h"
#include "cstdlib"


template <class T>
class dlist{
    public:
    typedef node_iterator<T> iterator;
    // Constructor
    dlist(){head = tail = NULL;}
    
    ~dlist();
    dlist(const dlist<T>& source);
    void operator =(const dlist<T>& source);
    

   // Insert and Remove Functions
   void front_insert(const T &other); 
   void rear_insert(const T &other);
   void front_remove();
   void rear_remove();
   void remove(const iterator& spot);

   // Iterator Functions 
   iterator begin() {return iterator(head);}
   iterator r_begin() {return iterator(tail);}
   iterator end() {return iterator(NULL);}
   iterator r_end() {return iterator(NULL);}
   // Iterator insert and remove
   void insert_before(const iterator &spot,const T& data);
   void insert_after(const iterator &spot, const T& data);
   // Display
   void show();
   void reverse_show();

   int size();

    private: 
        node<T> *head;
        node<T> *tail;
};
#include "dlist.template"
#endif