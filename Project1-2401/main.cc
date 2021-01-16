/*****************************************************************
	This is the main for our first project. Having a uniform menu 
	makes my grading much easier, so please use this for your 
	project. You should also have your data stored in the same 
        format as the sample that I give you.
	    John Dolan	Ohio University EECS 	Spring 2020
 	
	I have provided some numbers to guide you in the step-step development
	of this program. Uncomment each as you write the function.
*******************************************************************/
#include<iostream>
#include<fstream>
#include "runtime.h"
#include "Runjournal.h"

using namespace std;
// Function menu presents menu to user and collects a selection
int menu(); 

int main( ){
	Runtime tmp;

/*

// Test your input and output operators with this:
  	cout << "Enter a run: ";
    cin >> tmp;
    cout << "Here it is: ";
    cout << tmp << endl;
    cout << "Good-bye.\n";
*/

   Runjournal myruns;  //Default constructor 1st

     ifstream ifs;
     ofstream ofs;
     int choice;
     double dist;
//file loading - do last 12th
    ifs.open("runlog.txt");
     if(!ifs.fail()){
		ifs >> tmp;
	while(!ifs.eof()){
	    myruns.record(tmp);
	    ifs >> tmp;
	}
	ifs.close();
     } // if the file is not there we assume this is the first running

    do {	
	choice = menu();
	
	switch(choice){
		
	case 1: 
		cin >> tmp;
		myruns.record(tmp);  //2nd
	break;

	case 2:  
		cin >> tmp;
		myruns.find_remove(tmp);  //4th
	break;

	case 3:	
		myruns.display(); //3rd
	break;

	case 4:
		cout << "Enter a distance to view.\n";
		cin >> dist;
		myruns.distance_view(dist); //5th
	break;

	case 5:
		myruns.time_sort(); //6th
		myruns.display();
	break;

	case 6:
		myruns.distance_sort(); //7th
		myruns.display();
	break;

	case 7: 
		cout << myruns.total_time() << endl; //8th
	break;

	case 8: 
		cout << myruns.total_distance() << endl; // 9th
	break;

	case 9: 
		cout << myruns.average_pace() << endl; //10th
	break;

	case 0:
	 	cout << "Thank you for using our software.\n";
	break;

	default: 
		cout << "Not a valid selection.\n";
	break;		
	} // bottom of the switch

} while(choice != 0);

	ofs.open("runlog.txt");

	if(!ofs.fail()){
	    myruns.save(ofs); //11th
	    ofs.close();
 	}


return 0;
}

int menu( ){
    int selection;

    cout << "Chose from the Following\n";
    cout << "1) RECORD a run\n";
    cout << "2) FIND a run by entering time and distance w option to remove\n";
    cout << "3) VIEW all the runs in the Journal\n";
    cout << "4) DISPLAY runs of a specific distance\n";
    cout << "5) SORT by TIME\n";
    cout << "6) SORT by DISTANCE\n";
    cout << "7) TOTAL TIME\n";
    cout << "8) TOTAL DISTANCE\n";
    cout << "9) AVERAGE PACE\n";
    cout << "0) QUIT\n";

    cin >> selection;
    return selection;
}



