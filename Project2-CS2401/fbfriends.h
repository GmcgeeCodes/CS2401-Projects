/*****************************************************
   This class is a container that holds Friends of the 
   class Friend. It uses an internal iterator to give the
   application the ability to order the container as well
   as access to the elements in the container.
   Because it uses dynamic memory it needs to have the Big3.
     John Dolan		Spring 2014	Ohio University
*********************************************************/
#include<iostream>
#include<string>
#include<fstream>
#include "friend.h"
#ifndef FBFRIENDS_H
#define FBFRIENDS_H

class FBFriends{
    public:
	FBFriends();   

	//The functions known as the Big 3
	~FBFriends(); 
	FBFriends(const FBFriends& other); 
	void operator =(const FBFriends& other); 

	// Functions for the internal iterator
	void start(){current_index = 0;} 
	void advance(){current_index++;} 
	Friend current(); 
	void remove_current(); 
	bool is_item();
	void insert(const Friend& f); 
	void attach(const Friend& f); 
	void show_all(std::ostream& outs)const; 

	
	void bday_sort(); 
	Friend find_friend(const std::string& name)const; 
	bool is_friend(const Friend& f) const; 
	void load(std::istream& ins); 
	void save(std::ostream& outs); 
	
    private:
	void resize(); // complete
	int smallestIndex(int startIndex) const;  // minIndex for sort
	void swapFriends(int i, int minIndex); // swap for sort
	int search(const std::string& name) const; // for the find friend
	Friend *data;
	int used;
	int capacity;
	int current_index;
};

#endif


