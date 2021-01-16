// Implementation for Runjournal.h
#include "runtime.h"
#include "MyTime.h"
#include "Runjournal.h"
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>

using namespace std;

void Runjournal::record(const Runtime &newRun){
    if (used < CAPACITY){

        Runs[used] = newRun;
        ++used;
    }
    else {
        cout << "Sorry we have ran out of space in the journal! We can not add this Run " << endl;
        
    }
}
void Runjournal::display() const{
    for (size_type i = 0; i < used; i++)
    {
      cout << "Run number(" << (i + 1) << ") " << Runs[i] << endl;;
    }

}
void Runjournal::find_remove(const Runtime &userRun){
    //Search for a run w/ a particular time
    int foundIndex = search(userRun);

    if(foundIndex >= 0 && foundIndex < used){
        // Get pace by dividing time by miles
        MyTime pace; 
        pace = (Runs[foundIndex].get_time()/ Runs[foundIndex].get_distance());
        // Output results
        cout << "Distance: " <<  Runs[foundIndex].get_distance() << " miles "<< endl;
        cout << "Pace: ";
        pace.output(cout); 
        cout << " per mile" << endl; 
    }else
    {
      cout << "Sorry, the run you wished to search for was not found!\n";
    return;  

    }
    // Removal
    char a;
    cout << "Would you like to remove the run displayed? (Y/N): ";
    cin >> a;

    if ( a == 'Y' || a == 'y'){
        remove_one(userRun, foundIndex);
        cout << "The run has been removed!" << endl;

    }
    else if(a == 'N' || a == 'n'){
        cout << "Ok, this run will not be removed." << endl;
    }

}
void Runjournal::remove_one(const Runtime &remove_run, int index){
    size_t displace = used - (index + 1);

    for (size_t i = 0; i < displace; ++i){
        Runs[index] = Runs[index + 1];
        ++index;
    }
    --used;
}
int Runjournal::search(const Runtime &targetTime) const{   
    for (size_t i = 0; i < used; i++){
        if(targetTime.get_time() == Runs[i].get_time()){
            return i;
        }
    }
    return -1;
}
void Runjournal::distance_view(double distance) const{
    for (size_t i = 0; i < used; i++){
        if (distance == Runs[i].get_distance()){
            cout <<  "Run number(" << (i + 1) << ") " << Runs[i];
        }
    }
}
 void Runjournal::time_sort(){
    int minIndex;
    
    if (used == 0 || used > CAPACITY){ // prevent segfault on call with empty array
        cout << "Nothing to sort!" << endl;
        return;
    }
        
    for (size_t i = 0; i < (used -1); ++i){
        minIndex = smallestIndex(i, 1);
        swapRuns(i,minIndex);
    }
 }
 void Runjournal::distance_sort(){
    int minIndex;

    if (used == 0 || used > CAPACITY) { // prevent segfault on sort call with empty array
        cout << "Nothing to sort!" << endl;
        return;
    } 
    
    for(size_t i = 0; i < (used -1); ++i){ 
        minIndex = smallestIndex(i, 2);
        swapRuns(i,minIndex);
    }
 }
 int Runjournal::smallestIndex(int startIndex, int choice) const{
    Runtime minimum;
    minimum = Runs[startIndex];
    int minIndex = startIndex;

    if (choice == 1){
        for (size_t i = startIndex; i < used; i++){ 
            if(Runs[i].get_time() < minimum.get_time()){
                minimum = Runs[i];
                minIndex = i;
            }
        }
    } else if (choice == 2){

        for (size_t i = startIndex; i < used; i++){ 
            if(Runs[i].get_distance() < minimum.get_distance()){
                minimum = Runs[i];
                minIndex = i;
            }
        }
    }
    return minIndex;
 } 
 void Runjournal::swapRuns(int i, int minIndex){
    Runtime tmp;
    tmp = Runs[i];
    Runs[i] = Runs[minIndex];
    Runs[minIndex] = tmp;

 }
MyTime Runjournal::total_time(){
    MyTime total_time;
    for (size_t i = 0; i < used; ++i){
        total_time = total_time + Runs[i].get_time();
    }

    return total_time;
}
double Runjournal::total_distance(){
    double totalDistance;
    for (size_t i = 0; i < used; ++i){
        totalDistance = totalDistance + Runs[i].get_distance();
    }

    return totalDistance;
}
MyTime Runjournal::average_pace(){
    MyTime pace;
    pace = total_time() / total_distance(); // Average pace is the total time of all runs/ total distance. Time per mile

    return pace;
}
void Runjournal::save(ostream &outs) const{ // Output to file
    for (size_t i = 0; i < used; i++) {
      outs << Runs[i];
    }
}
