/*
Fbfriends implementation file
Name: Gerald McGee 
Date: 02/08/2020
*/
#include "friend.h"
#include "date.h"
#include "fbfriends.h"
#include <iostream>
#include <algorithm>

using namespace std;
// Constructor
FBFriends::FBFriends(){
    used = 0;
    capacity = 5;  
    int current_index = 0;
    data = new Friend[capacity];

}
// Destructor
FBFriends::~FBFriends(){
    delete [] data;
}
// copy constructor
FBFriends::FBFriends(const FBFriends &other){   

    used = other.used;
    capacity = other.capacity;
    current_index = other.current_index;
    data = new Friend[other.capacity];
    copy(other.data, other.data + used, data);
}
// overloaded assignment operator, check for self assign and capacity check
void FBFriends::operator =(const FBFriends& other){
    Friend *tmp;
    if (this == &other)
        return;

    if (capacity < other.capacity){
        tmp = new Friend[other.capacity];
        delete [] data;
        data = tmp;
        capacity = other.capacity;
    }

    used = other.used;
    current_index = other.current_index;
    copy(other.data, other.data + used, data);
}
Friend FBFriends::current(){
    Friend tmp;
    if (!is_item()){ 
        return tmp;
    }
    return data[current_index];
}
void FBFriends::remove_current(){
    size_t displace = used - (current_index + 1);

    if (is_item()){
        for(size_t i = current_index; i < displace; ++i){
            data[i] = data[i + 1];
        }
        --used;
    }
    else {
        cout << "Invalid remove index" << endl;
    }
}
void FBFriends::insert(const Friend& f){
    if (used == capacity)
        resize();
    
    if(!is_item())
        current_index = 0;
    
    for ( size_t i = used; i > current_index; --i)
        data[i] = data[i - 1];

    data[current_index] = f;
    ++used;
}
void FBFriends::attach(const Friend& f){
    if (used == capacity)
        resize ();
    
    if (!is_item()){
        current_index = used;
        data[current_index] = f;
        ++used;

        return;
    }
    for(size_t i = used; i > current_index; --i){
        data[i] = data[i -1];
    }
    
    data[current_index + 1] = f;
    ++used;
}
bool FBFriends::is_item(){ 
    return (current_index >= 0 && current_index < used);
}
void FBFriends::resize(){
    Friend *tmp;
    capacity += 5;

    tmp = new Friend[capacity];
    copy(data, data + used + 1, tmp);
    delete [] data;
    data = tmp;
}
void FBFriends::show_all(ostream& outs)const{
    for (size_t i = 0; i < used; ++i){
        outs << "Friend(" << (i) << "): " << data[i] << endl;
    }
}
void FBFriends::load(istream& ins){
    while (ins.peek() == '\n') ins.ignore();
    ins >> data[used];

    while(!(ins.eof())){
        if (used == capacity - 1){
            resize();
        }
        ++used;
        while(ins.peek() == '\n') ins.ignore();

        ins >> data[used];
    }  
}
void FBFriends::save(ostream& outs){
    cout << "Save called " << endl;
    for (size_t i  = 0; i < used; ++i){
        outs << data[i] << endl;
    }
}
void FBFriends::bday_sort(){
    int minIndex;

    if(used == 0 || used > capacity){
        cout << "Nothing to sort!" << endl;
        return;
    }

    for(size_t i = 0; i < (used -1); ++i){
        minIndex = smallestIndex(i);
        swapFriends(i, minIndex);
    }

}
int FBFriends::smallestIndex(int startIndex) const{
    Friend tmp;
    tmp = data[startIndex];
    int minIndex = startIndex;

    for (size_t i = startIndex; i < used; i++){
        if (data[i].get_bday() < tmp.get_bday()){
            tmp = data[i];
            minIndex = i;
        }
    }
    return minIndex; 
}
void FBFriends::swapFriends(int i, int minIndex){
    Friend tmp;
    tmp = data[i];
    data[i] = data[minIndex];
    data[minIndex] = tmp;
}
Friend FBFriends::find_friend(const string& name)const{
    int foundIndex = search(name);
    if (foundIndex >= 0){
        return data[foundIndex];
    }
    else{
        Friend tmp;
        cout << "Friend not found. Default friend will be given" << endl;
        return tmp;
    }
}
int FBFriends::search(const std::string& name) const{
    for(size_t i = 0; i < used; i++){
        if(name == data[i].get_name()){
            return i;
        }
    }
    return -1;
}
bool FBFriends::is_friend(const Friend& f) const{
    if((search(f.get_name())) >= 0){
        return true;
    }
    return false;
}


