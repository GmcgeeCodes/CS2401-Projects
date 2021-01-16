/*
    File: Runjournal.h
    Name: Gerald McGee
    Date: 02/02/20
    Description: This is the header file for the Runjournal class. A container class to keep track and manage the runs.

    This is the Runjournal class which is a container class designed to store 
    the runs.  It contains methods that will record a run, display them to the user, remove runs
    View them by distance, sort them by time and distance, and view statistics such as the total time,
    distance and the average pace of the runs. A static const is used to store the CAPACITY and we have a 
    save member function that will allow the user to save their runs when the prog. is finished and load
    them up the next time that it is ran.
*/

#include <iostream>
#include "runtime.h"
#include "MyTime.h"

#ifndef RUNJOURNAL_H
#define RUNJOURNAL_H

class Runjournal {
    public:
    // Type Definition of size_type & static constant declaration
    typedef std::size_t size_type;
    static const size_type CAPACITY = 200;

    // Constructor
    Runjournal(){
        used = 0;
    }
    //Member F(x)'s
    void record(const Runtime &newRun); // Records new run for journal
    void display() const; // Displays the run journal to the user
    void find_remove(const Runtime &userRun); // Finds a certain run and removes it from the journal
    void distance_view(double distance) const; // Views runs with a certain distance 
    void time_sort(); // Sort the journal from first to last by time
    void distance_sort(); // Sort the journal from first to last by distance
    MyTime total_time(); // Will return an object of MyTime that is all the runs in the journal
    double total_distance(); // Will return the total distance of all the runs
    MyTime average_pace(); // Returns a MyTime object representing the pace. The average time ran for every mile
    void save(std::ostream &outs) const; // Saves and writes the runs to output file stream runlog

    private:
    Runtime Runs[CAPACITY];
    size_type used;
    int search (const Runtime &targetTime) const; // To search The Runs for a Time 
    void remove_one(const Runtime&remove_run, int index); // Remove a run 
    int smallestIndex(int startIndex, int choice) const; // returns smallest index of the distance or time depending on where the call is coming from (choice)
    void swapRuns(int i, int minIndex); // Swap runs in two positions in the array
};
#endif