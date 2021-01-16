/*
Header file: dnode.h
This class is for the definition of the template doubly link list node class. It holds a next and a previous pointer
which gives the ability for th list to be traversed backwards of forwards.

elaborate more above if possible
The invariants: data_field represents the data in that specific code, next represents the 
next node in the list, previous represents the previous node in the list.

Name: Gerald McGee
Class: CS2401
Date: 03/29/20
Professor Dolan
*/
#ifndef DNODE_H
#define DNODE_H


template <class T>
class node{
    public:
        node(const T& data_temp = T(), node* p = NULL, node* n = NULL){
            data_field = data_temp;
            previous_ptr = p;
            next_ptr = n;
        }
        // Data functions, const and non-const
        T& data() {return data_field;}
        const T& data() const{return data_field;}
        // The next functions, const and non-const
        node* next(){ return next_ptr;}
        const node* next() const{return next_ptr;}
        // The previous functions, const and non-const
        node* previous(){return previous_ptr;}
        const node* previous() const {return previous_ptr;}

        void set_data(T Item){data_field = Item;}
        void set_next(node* n){next_ptr = n;}
        void set_previous(node* p){previous_ptr = p;}

    private:
        T data_field;
        node* next_ptr;
        node* previous_ptr;
};
#endif 