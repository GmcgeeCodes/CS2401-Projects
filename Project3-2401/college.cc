/*
 * Implementation file for college class, this class describes a students collegiate academic history.
 *  Name: Gerald McGee
 *  Date: 03/3/2020
 *  CS 2401, Professor Dolan 
 *  
*/

#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include "node.h"
#include "course.h"
#include "college.h"

using namespace std;

void college::load(istream& ins){
    course tmp;
    getline(ins,name);

    while(ins >> tmp){
        add(tmp);
        while(ins.peek() == '\n') ins.ignore();
    }
}
void college::save(ostream& outs){
    outs << name << endl;
    const node* cursor;
    for(cursor = head_ptr; cursor != NULL; cursor = cursor -> link()){
        outs << cursor -> data();
    }
}
college::~college(){
    node* remove_ptr;
    while(head_ptr != NULL){
        remove_ptr = head_ptr;
        head_ptr = head_ptr -> link();
        delete remove_ptr;
    }
}
college::college(const college& source){
    if(source.head_ptr == NULL){
        head_ptr = NULL;
        return;
    }
    name = source.name;

    node* source_ptr;
    node* dest_ptr;
    head_ptr = new node (source.head_ptr -> data());
    dest_ptr = head_ptr;
    source_ptr = source.head_ptr -> link();

    while (source_ptr != NULL){
        dest_ptr -> set_link(new node(source_ptr -> data()));
        dest_ptr = dest_ptr -> link();
        source_ptr = source_ptr -> link();
    }
}
void college::operator =(const college& source){
    if(this == &source) return;
    name = source.name;

    node* remove_ptr;
    while(head_ptr != NULL){
        remove_ptr = head_ptr;
        head_ptr = head_ptr -> link();
        delete remove_ptr;
    }

    node* source_ptr;
    node* dest_ptr;
    head_ptr = new node (source.head_ptr -> data());
    dest_ptr = head_ptr;
    source_ptr = source.head_ptr -> link();

    while (source_ptr != NULL){
        dest_ptr -> set_link(new node(source_ptr -> data()));
        dest_ptr = dest_ptr -> link();
        source_ptr = source_ptr -> link();
    }
}
void college::add(const course &tmp){
    if (head_ptr == NULL){
        head_ptr = new node(tmp);
    } 
    else{
        node* insert_ptr = new node(tmp);
        node* cursor = head_ptr; 
        size_t prevpos = 0;

        while((cursor != NULL) && ((insert_ptr -> data()) > (cursor -> data()))){
            cursor = cursor -> link();
            ++prevpos;
        }

        if(prevpos == 0){
            insert_ptr -> set_link(head_ptr);
            head_ptr = insert_ptr;
            return;
        }
        else{
            node* previous_ptr = list_locate(prevpos);
            if (previous_ptr == NULL) return; 
            insert_ptr -> set_link(previous_ptr -> link());
            previous_ptr -> set_link(insert_ptr);
        }
    }
}
void college::remove(const string &coursename){
    node* previous_ptr, *cursor, *rem_ptr;
    size_t posrmptr , posprevious_ptr;


    if (head_ptr == NULL){ // empty list
        cout << "List is already empty, can't remove" << endl;
        return;
    }
    if(list_length() == 1){ // one node list 
        rem_ptr = head_ptr;
        head_ptr = NULL;
        delete rem_ptr;
    } 
    else{ 
        rem_ptr = list_search(coursename);
        if(rem_ptr == NULL){ // check to be sure the search worked correctly
            cout << "Error: We can not find what you would like removed." << endl;
            return;
        }

        posrmptr = find_pos(rem_ptr);
        if(posrmptr == 0){ // check to make sure we found the position
            cout << "Error: Position of remove failed" << endl;
            return;
        }

        if(posrmptr == 1){ // remove pointer is at the head
            head_ptr = head_ptr -> link();
            delete rem_ptr;
        } else{
            posprevious_ptr = posrmptr - 1;
            previous_ptr = list_locate(posprevious_ptr);
            previous_ptr -> set_link(rem_ptr -> link());
            delete rem_ptr;

        }
    }
}
size_t college::find_pos(const node* target){
    size_t position = 1;
    const node* cursor;
    for(cursor = head_ptr; cursor != NULL; cursor = cursor -> link()){
        if (target == cursor)
            return position;
        ++position;
    }
    return 0; // not found
}
node* college::list_search(const string& target){
    node* cursor;
    for(cursor = head_ptr; cursor != NULL; cursor = cursor -> link()){
        if (cursor -> data().get_course_number() == target){
            return cursor;
        }
    }
    return NULL; // not found 
}
node* college::list_locate(size_t position){
    node *cursor;

    if(0 >= position){
        cout << "Invalid position" << endl;
        cursor = NULL;
        return cursor;
    }

    cursor = head_ptr;
    for(size_t i = 1; (i < position) && (cursor != NULL); ++i){
        cursor = cursor -> link();
    }
    return cursor;
}
void college::display(ostream &outs){
    const node *cursor;
    for(cursor = head_ptr; cursor != NULL; cursor = cursor -> link()){
        outs << cursor -> data() << endl;
    }
}
size_t college::list_length(){
    const node* cursor;
    size_t answer;
    for(cursor = head_ptr; cursor != NULL; cursor = cursor -> link()) answer++;

    return answer;
}
double college::hours(){
    int sum = 0;
    node* cursor;

    for(cursor = head_ptr; cursor != NULL; cursor = cursor -> link())
        sum = sum  + (cursor -> data().get_hours());
    return sum;
}
double college::gpa(){
    const node *cursor;
    double grade_points = 0, gpa = 0;

    for(cursor = head_ptr; cursor != NULL; cursor = cursor -> link()){
        grade_points = grade_points + (cursor -> data().get_number_grade() * cursor -> data().get_hours());
    }
    gpa = grade_points/hours();
    return gpa;
}

