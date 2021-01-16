/*
Main function for program letting the user design animal homes.
Name: Gerald McGee
Class: CS2401
Date: 4/7/20
Pro. Dolan
*/
#include <fstream>
#include "animalh.h"
#include "parent.h"
#include <cstdlib>
#include <iostream>
#include <string>
#include <list>

using namespace std;

// function prototype
void menu();

int main(){
    list <parent*> homes;
    int choice, animalNum;
    ifstream inStream;
    ofstream outStream;
    parent* tmp;
    list <parent*>::iterator pit;

    inStream.open("data.txt");
    if(inStream.fail()){
        outStream.open("data.txt");
        outStream.close();
        inStream.open("data.txt");
    } 

    if(!inStream.fail()){
        while(inStream >> animalNum){
            if(animalNum == 1){
                tmp = new Wolf;
                tmp -> input(inStream);
                homes.push_back(tmp);
            }else if (animalNum == 2){
                tmp = new Lion;
                tmp -> input(inStream);
                homes.push_back(tmp);

            }else if(animalNum == 3){
                tmp = new Bear;
                tmp -> input(inStream);
                homes.push_back(tmp);
            }else if(animalNum == 4){
                tmp = new Meerkat;
                tmp -> input(inStream);
                homes.push_back(tmp);

            }else if (animalNum == 5){
                tmp = new Clownfish;
                tmp -> input(inStream);
                homes.push_back(tmp);
            }
        }
    }
    inStream.close();

    menu();
    cin >> choice;
    while( choice != 0){
        switch (choice)
        {
        case 1: // Wolf 
            cout << "Welcome to designing a Wolf home" << endl;
            tmp  = new Wolf;
            tmp -> input(cin);
            homes.push_back(tmp);
            break;
        case 2: // Lion
            cout << "Welcome to designing a Lion home" << endl;
            tmp = new Lion;
            tmp -> input(cin);
            homes.push_back(tmp);

            break;
        case 3: // Bear 
            cout << "Welcome to designing a Bear home" << endl;
            tmp = new Bear;
            tmp -> input(cin);
            homes.push_back(tmp);

            break;
        case 4: // Meerkat 
            cout << "Welcome to designing a Meerkat home" << endl;
            tmp = new Meerkat;
            tmp -> input(cin);
            homes.push_back(tmp);

            break;
        case 5: // Clownfish
            cout << "Welcome to designing a Clownfish home" << endl;
            tmp = new Clownfish;
            tmp -> input(cin);
            homes.push_back(tmp);
            break;
        case 6: // Display with the iterator
            for(pit = homes.begin(); pit != homes.end(); ++pit){
                (*pit) -> output(cout);
            }
        break;

        default:
            cout << "Not a valid option" << endl;
            break;
        }
        menu();
        cin >> choice;
    }

    // output to file
    outStream.open("data.txt");
    list <parent*>::iterator it;
    for(it = homes.begin(); it != homes.end(); ++it){
        (*it) -> output(outStream);
    }
    outStream.close();

return 0;
}
void menu(){
    cout << "Which animal would you like to design a house for?" << endl;
    cout << "Enter the number 1 for a Wolf" << endl;
    cout << "Enter the number 2 for a Lion" << endl;
    cout << "Enter the number 3 for a Bear" << endl;
    cout << "Enter the number 4 for a Meerkat" << endl;
    cout << "Enter the number 5 for a Clownfish" << endl;
    cout << "Enter the number 6 to display all of the homes. " << endl; 
    cout << "Enter 0 if you are done designing animal homes" << endl;

}