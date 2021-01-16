/*
Header file: iterator.h

details of the class....

The invariants: ...


Name: Gerald McGee
Class: CS2401
Date: 03/29/20
Professor Dolan
*/
#ifndef ITERATOR_H
#define ITERATOR_H

#include "dnode.h"
#include "dlist.h"

template <class T>
class dlist; // forward declaration

template <class T>
class node_iterator{
    public:
    friend class dlist<T>;
    // Constructor
    node_iterator(node<T> *init = NULL){current = init;}
    // Equality and Inequality 
    bool operator != (const node_iterator &other){
        return current != other.current;
    }
    bool operator ==(const node_iterator &other){
        return current == other.current;
    }
    T& operator * (){return current -> data();}

    // Unary operators
    node_iterator& operator ++(){ // prefix
        current = current -> next();
        return *this;
    }
    node_iterator operator ++(int){ //postfix
        node_iterator original(current);
        original = current -> next();
        return original;
    }
    node_iterator& operator --(){ // prefix
        current = current -> previous();
        return *this;
    }
    node_iterator operator --(int){ //postfix
        node_iterator original(current);
        original =  current -> previous();
        return original;
    }

    private:   
        node<T> *current;
};
#endif