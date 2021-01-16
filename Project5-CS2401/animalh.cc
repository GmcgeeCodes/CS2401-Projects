/*
Implementation for the animal.h class file

*/
#include "parent.h"
#include "animalh.h"
using namespace std;

void Wolf::int_hab_tos(){
     if (habitat == 1){
        shabitat = "Mountain";

    } else if (habitat == 2){
        shabitat = "Tundra";

    }else if(habitat == 3){
        shabitat = "Grasslands";

    }else if(habitat == 4){
        shabitat = "Forests ";
    }
}
void Wolf::set_habitat(int h){
    if(h >= 1 && h <= 4){
        habitat = h;
        int_hab_tos();
    }
    else {
        cout << "Invalid habitat" << endl;
    }
}
void Wolf::input(istream &ins){
    if (&ins == &cin){
        //
        cout << "How many wolfs can live in the wolf den?: " << endl;
        ins >> packnumber;
        // 
        char v2;
        cout <<"Is this wolf den in the wild or is it in the zoo? w - wild or z - zoo" << endl;
        ins >> v2;
        if((v2 != 'z') && (v2 != 'Z') && (v2 != 'w') && (v2 != 'W')){
            while((v2 != 'z') && (v2 != 'Z') && (v2 != 'w') && (v2 != 'W')){
                cout << "Please enter a correct option" << endl;
                ins >> v2;
            }
        }
        if ( v2 == 'w' || v2 == 'W'){
            denLoc = true;

        }else{
            denLoc = false;
        }
        // 
        int v3;
        cout << "What type of habitat does the wolf live in?" << endl;
        cout << " Enter the number one: Mountain" << endl;;
        cout << "Enter the number two: Tundra" << endl;
        cout << "Enter the number three: Grasslands" << endl;
        cout << "Enter the number four: Forests" << endl;
        ins >> v3;
        if ((v3 != 1) && (v3 != 2) && (v3 != 3) && (v3 != 4)){
            while((v3 != 1) && (v3 != 2) && (v3 != 3) && (v3 != 4)){
                cout << "Please enter a correct option" << endl;
                ins >> v3;
            }
        }
        set_habitat(v3);
        // 
        char v4;
        cout <<"Is the wolf home near a stream? Type Y if it is or N if it is not" << endl;
        ins >> v4;

        if ((v4 != 'y') && (v4 != 'Y') && (v4 != 'n') && (v4 != 'N')){
            while((v4 != 'y') && (v4 != 'Y') && (v4 != 'n') && (v4 != 'N')){
                cout << "Please enter a correct option" << endl;
                ins >> v4;
            }
        }

        if ( v4 == 'y' || v4 == 'Y'){
            stream = true;

        } else{
            stream = false;
        }
        // 
        char v5;
        cout <<"Is the deer around this den plentiful? Type Y if it is or N if it is not" << endl;
        ins >> v5;

        if ((v5 !='y') && (v5 != 'Y') && (v5 != 'n') && (v5 != 'N')){
            while((v5 !='y') && (v5 != 'Y') && (v5 != 'n') && (v5 != 'N')){
                cout << "Please enter a correct option" << endl;
                ins >> v5;
            }
        }
        if ( v5 == 'y' || v5 == 'Y'){
            prey = true;

        }else{
            prey = false;
        }
    } // end pf cin else
    else{ // File 
        ins >> packnumber;
        ins >> denLoc;
        ins >> habitat;
        int_hab_tos();
        ins >> stream;
        ins >> prey;
    }

} // end of function
void Wolf::output(ostream& outs){
    if (&outs == &cout){
        //
        outs << "Pack Number: " << packnumber << endl;
        // 
        if (denLoc == true){
            outs << "Wolf den is located in the wild" << endl;
        }else{
            outs << "Wolf den is located in the zoo" << endl;
        }
        // Print 
        outs << "Habitat Type: " << get_habitat() << endl;
        // 
        if (stream == true){
            outs << "Wolf den is located near a stream" << endl;
        }else{
            outs << "Wolf den is not located near a stream" << endl;
        }
        // 
         if (prey == true){
            outs << "Prey is plentiful" << endl;
        }else{
            outs << "Prey is not plentiful" << endl;
        }
        outs << endl;
    } else { // File 
        outs << 1 << endl;
        outs << packnumber << endl; 
        outs << denLoc << endl;
        outs << habitat << endl;
        outs << stream << endl;
        outs << prey << endl;
    }
}
void Lion::input(istream &ins){
    if(&ins == &cin){
        //
        char tmp;
        cout << "What region of Africa does the home of the lion live in?" << endl;
        cout <<"N - North Africa" << endl;
        cout <<"S - South Africa" << endl;
        cout <<"W - West Africa" << endl;
        cout <<"E - East Africa" << endl;
        cin >> tmp;
        if((tmp != 'N') && (tmp != 'n') && (tmp !=  'S') && (tmp != 's') && (tmp != 'W') && (tmp != 'w') && (tmp !=  'E') && (tmp != 'e')){
            while((tmp != 'N') && (tmp != 'n') && (tmp !=  'S') && (tmp != 's') && (tmp != 'W') && (tmp != 'w') && (tmp !=  'E') && (tmp != 'e')){
                cout << "Please enter a correct option" << endl;
                ins >> tmp;
            }
        }
        AfricaRegion = tmp;
        // 
        char v2;
        cout << "Is the location of the pride home in dry season weather or monsoon season weather?" << endl;
        cout <<" Enter D for dry season weather and W for monsoon season weather" << endl;
        cin >> v2; 
        if((v2 != 'D') && (v2 != 'd') && (v2 !=  'W') && ( v2 != 'w')){
            while((v2 != 'D') && (v2 != 'd') && (v2 !=  'W') && ( v2 != 'w')){
                cout << "Please enter a correct option" << endl;
                ins >> v2;
            }
        }
        season = v2;
        // 
        char btmp;
        cout << "Is the pride home close to pride rock?" << endl;
        cout << "Enter the number 1 if it is close to pride rock and 0 if it is not close to pride rock." << endl;
        cin >> btmp;
        if((btmp != '1') && (btmp != '0')){
            while((btmp != '1') && (btmp != '0')){
                cout << "Please enter a correct option" << endl;
                ins >> btmp;
            }
        }
        if(btmp == '1')
            lionKing = true;
        else 
            lionKing = false;
        //
        char v4;
        cout << "Is the pride home in an area with plenty of trees??" << endl;
        cout << "Enter the number 1 if we have plenty of trees rock and 0 if we do not have many trees." << endl;
        ins >> v4;
        if((v4 != '1') && (v4 != '0')){
            while((v4 != '1') && (v4 != '0')){
                cout << "Please enter a correct option" << endl;
                ins >> v4;
            }
        }
         if(v4 == '1')
            trees = true;
        else 
            trees = false;
        //
        cout <<"How many individual prey is present within a reachable distance from the home?" << endl;
        ins >> foodcount;
        //
        cout << "What is the pride homes name? " << endl;
        while(ins.peek() == '\n') ins.ignore();
        getline(ins, name);
    } else {
        ins >> AfricaRegion;
        ins >> season;
        ins >> lionKing;
        ins >> trees;
        ins >> foodcount;
        while(ins.peek() == '\n') ins.ignore();
        getline(ins, name);
    }
}
void Lion::output(ostream &outs){
    if(&outs == &cout){
    // Region of Africa
    if(AfricaRegion == 'N' || AfricaRegion == 'n'){
        outs << "The lion home is located in North Africa" << endl;
    }
    else if(AfricaRegion == 'W' || AfricaRegion == 'w'){
        outs << "The lion home is located in West Africa" << endl;

    } else if(AfricaRegion == 'S' || AfricaRegion == 's'){
        outs << "The lion home is located in South Africa" << endl;

    }else if(AfricaRegion == 'E' || AfricaRegion == 'e'){
        outs << "The lion home is located in East Africa" << endl;

    }
    // Season
    if(season == 'D' || season == 'd'){
        outs <<"The pride home weather is in the middle of dry season" << endl;
    } else {
        outs <<"The pride home weather is in the middle of monsoon season" << endl;
    }
    // pride rock
    if (lionKing == 1){
        outs << "The pride home is close to the pride rock" << endl;
    }else{
        outs << "The lion home is not close to Pride rock" << endl;
    }
    // trees 
     if (trees == 1){
        outs << "The pride home has plenty of trees." << endl;

    }else{
        outs << "The pride home does not have plenty of trees." << endl;
    }
    // foodcount
    outs << "Individual prey available: " << foodcount << endl;
    //
    outs << "Pride home name: " << name << endl;
    outs << endl;
}
    else{ // for file 
        outs << 2 << endl;
        outs << AfricaRegion << endl;
        outs << season << endl;
        outs << lionKing << endl;
        outs << trees << endl;
        outs << foodcount << endl;
        outs << name << endl;
    }
}
void Bear::input(istream &ins){
    if (&ins == &cin){
         // miles for food
        cout << "How many miles must the bear travel for food?" << endl;
        ins >> foodMiles;
        // What type of bear live in this home?
        char v2;
        cout << "What type of bear will live in this home? " << endl;
        cout << "Polar Bear: Type P " << endl;
        cout << "Grizzly Bear: Type G " << endl;
        cout << "Black Bear: Type B " << endl;
        cout << "Brown Bear: Type R " << endl;
        cin >> v2;
        if((v2 != 'P') && (v2 != 'p') && (v2 !=  'G') && (v2 != 'g') && (v2 != 'B') && (v2 != 'b') && (v2 !=  'R') && (v2 != 'r')){
            while((v2 != 'P') && (v2 != 'p') && (v2 !=  'G') && (v2 != 'g') && (v2 != 'B') && (v2 != 'b') && (v2 !=  'R') && (v2 != 'r')){
                cout << "Please enter a correct option" << endl;
                ins >> v2;
            }
        }
        denBearType = v2;
        // Hibernation
        char v3;
        cout << "Are the bears hibernating at the moment or no?" << endl;
        cout << "Enter the number 1 if the bears are hibernating and 0 if not." << endl;
        ins >> v3;
        if((v3 != '1') && (v3 != '0')){
            while((v3 != '1') && (v3 != '0')){
                cout << "Please enter a correct option" << endl;
                ins >> v3;
            }
        }
        if (v3 == '1')
            hibernation = true;
        else
            hibernation = false;
        // Cubs 
        char v4;
        cout << "Does the adult bear of the home have any cubs or no?" << endl;
        cout << "Enter the number 1 if the adult bear has cubs and 0 if not." << endl;
        ins >> v4;
        if((v4 != '1') && (v4 != '0')){
            while((v4 != '1') && (v4 != '0')){
                cout << "Please enter a correct option" << endl;
                ins >> v4;
            }
        }
        if (v4 == '1')
            cubs = true;
        else
            cubs = false;
        // Water
        char v5;
        cout << "Is the home close to an abundance of water or no?" << endl;
        cout << "Enter the number 1 if the home is by plenty of water and 0 if not." << endl;
        ins >> v5;
        if((v5 != '1') && (v5 != '0')){
            while((v5 != '1') && (v5 != '0')){
                cout << "Please enter a correct option" << endl;
                ins >> v5;
            }
        }
        if(v5 == '1')
            water = true;
        else 
            water = false;  
        // Continent 
        cout <<"What continent are is the bear home located in?" << endl;
        while(ins.peek() == '\n')ins.ignore();
        getline(ins, continent);
    }
    else {
        ins >> foodMiles;
        ins >> denBearType;
        ins >> hibernation;
        ins >> cubs;
        ins >> water;
        while(ins.peek() == '\n')ins.ignore();
        getline(ins, continent);
    }
}
void Bear::output(ostream &outs){
    if(&outs == &cout){
        // Food miles 
        outs << "Miles from Bear home to find food: " << foodMiles << endl;
        // Bear Type 
        if(denBearType == 'G' || denBearType == 'g'){
            outs << "This home is a home built for Grizzly Bears" << endl;
        }
        else if(denBearType == 'P' || denBearType == 'p'){
            outs << "This home is a home built for Polar Bears" << endl;

        } 
        else if(denBearType == 'B' || denBearType == 'b'){
            outs << "This home is a home built for Black Bears" << endl;

        }
        else if(denBearType == 'R' || denBearType == 'r'){
            outs << "This home is a home built for Brown Bears" << endl;
        }
        // Hibernation
        if (hibernation == 1){
            outs << "The Bear/s living in the bear home are in hibernation." << endl;

        }else{
            outs << "The Bear/s living in the bear home are not in hibernation." << endl;
        }
        // Cubs
        if (cubs == 1){
            outs << "The Bear/s living in the bear home have cubs." << endl;
        }else{
            outs << "The Bear/s living in the bear home do not have cubs."  << endl;
        }
        //Water
        if (water == 1){
            outs << "The Bear/s living in the bear home live near an abundance of water" << endl;
        }else{
            outs << "The Bear/s living in the bear home do not live near an abundance of water"  << endl;
        }
        // Continent
        outs <<"The continent of this bear home: " << continent << endl;
        outs << endl;
    }else{
        outs << 3 << endl;
        outs << foodMiles << endl;
        outs << denBearType << endl;
        outs << hibernation << endl;
        outs << cubs << endl;
        outs << water << endl;
        outs << continent << endl;
    }
}
void Meerkat::input(istream &ins){
    if(&cin == &ins){
        // meerkat manor
        cout << "Was this home featured on Meerkat Manor?" << endl;
        char v1;
        cout << "Enter the number 1 if the home was featured and 0 if not." << endl;
        ins >> v1;
        if((v1 != '1') && (v1 != '0')){
            while((v1 != '1') && (v1 != '0')){
                cout << "Please enter a correct option" << endl;
                ins >> v1;
            }
        }
        if (v1 == '1')
            meerkatManor = true;
        else 
            meerkatManor = false;
        // security 
         char v2;
        cout << "Does the Meerkat Home have good security against predators?" << endl;
        cout << "Enter the number 1 if we have advanced security and 0 if not." << endl;
        ins >> v2;
        if((v2 != '1') && (v2 != '0')){
            while((v2 != '1') && (v2 != '0')){
                cout << "Please enter a correct option" << endl;
                ins >> v2;
            }
        }
        if (v2 == '1')
            security = true;
        else 
            security = false;
        // burrow systems 
        cout << "How many burrow systems does the Meerkat home have?" << endl;
        cin >> burrowSys;
        // hospitality 
        char v4;
        cout << "Does the Meerkat Home have good hospitality?" << endl;
        cout << "Enter the number 1 if the meerkat home can be hospitable and 0 if not." << endl;
        ins >> v4;
        if((v4 != '1') && (v4 != '0')){
            while((v4 != '1') && (v4 != '0')){
                cout << "Please enter a correct option" << endl;
                ins >> v4;
            }
        }
        if(v4 == '1')
            hospit = true;
        else 
            hospit = false;
        
    }else {
        ins >> meerkatManor;
        ins >> security;
        ins >> burrowSys;
        ins >> hospit;
    }
}
void Meerkat::output(ostream &outs){
    if(&cout == &outs){
        // meerkat manor
        if (meerkatManor == 1)
            outs << "This meerkat home was featured in Meerkat Manor!" << endl;
        else
            outs << "This meerkat home was not featured in Meerkat Manor." << endl;
        // security 
        if (security == 1)
            outs << "This meerkat home has advanced security!" << endl;
        else
            outs << "This meerkat home does not have advanced security." << endl;
        //
        outs << "The home has " << burrowSys << " burrow systems." << endl;
        // hospitality 
        if(hospit == 1)
            outs << "The meerkat home has excellent hospitality." << endl;
        else 
            outs << "The meerkat home does not have hospitality, can not have family over." << endl;
        outs << endl;
    } else{
        outs << 4 << endl;
        outs << meerkatManor << endl;;
        outs << security << endl;
        outs << burrowSys << endl;
        outs << hospit << endl;
    }
}
void Clownfish::input(istream &ins){
    if(&ins == &cin){
        // which ocean?
        cout << "Where is the clownfish sea anenome located?" << endl;
        cout << " Pacific Ocean, Atlantic Ocean, Indian Ocean, or Arctic Ocean" << endl;
        while(ins.peek() == '\n') ins.ignore();
        getline(ins, ocean);
        // 
        char v2;
        cout << "Is the sea anenome home electric or no?" << endl;
        cout << "Enter the number 1 if the anenome is electric and 0 if not." << endl;
        ins >> v2;
        if((v2 != '1') && (v2 != '0')){
            while((v2 != '1') && (v2 != '0')){
                cout << "Please enter a correct option" << endl;
                ins >> v2;
            }
        }
        if (v2 == '1')
            anenome = true;
        else
            anenome = false;
        
        // 
        char v3;
        cout << "Is the sea anenome home in shallow water or deeper water?" << endl;
        cout << "Enter the number 1 if the sea anenome clownfish home is in shallow water and 0 if not." << endl;
        ins >> v3;
        if((v3 != '1') && (v3 != '0')){
            while((v3 != '1') && (v3 != '0')){
                cout << "Please enter a correct option" << endl;
                ins >> v3;
            }
        }
        if (v3 == '1')
            shallowOrHi = true;
        else 
            shallowOrHi = false;
        // 
        cout << "How many clownfish can reside within the tentacles of the sea anemone?" << endl;
        ins >> count;
        // school 
        char v4;
        cout << "Does the clownfish community have a school for fish?" << endl;
        cout << "Enter the number 1 if the clownfish community has a school of fish and 0 if not." << endl;
        ins >> v4;
        if((v4 != '1') && (v4 != '0')){
            while((v4 != '1') && (v4 != '0')){
                cout << "Please enter a correct option" << endl;
                ins >> v4;
            }
        }
        if (v4 == '1')
            school = true;
        else 
            school = false;
        
        // 
        char v5;
        cout << "Are the clownfish living in this home related to nemo?" << endl;
        cout << "Enter the number 1 if the clownfish are related and 0 if not." << endl;
        ins >> v5;
        if((v5 != '1') && (v5 != '0')){
            while((v5 != '1') && (v5 != '0')){
                cout << "Please enter a correct option" << endl;
                ins >> v5;
            }
        }
        if(v5 == '1')
            relative = true;
        else 
            relative = false;
        //
        cout << "What is the length of the sea anenome tentacles?" << endl;
        ins >> length;

    }else{
        while(ins.peek() == '\n') ins.ignore();
        getline(ins, ocean);
        ins >> anenome;
        ins >> shallowOrHi;
        ins >> count;
        ins >> school;
        ins >> relative;
        ins >> length;
    }

}
void Clownfish::output(ostream &outs){
    if(&cout == &outs){
        outs << "The ocean the clownfish sea anenome is in the " << ocean << endl;
        //  anenome
        if (anenome == 1){
            outs << "The sea anenome is electric." << endl;
        }else{
            outs << "The sea anenome is not electric." << endl;
        }
        //
        if (shallowOrHi == 1){
            outs << "The sea anenome is in shallow water." << endl;
        }else{
            outs << "The sea anenome is in deep water." << endl;
        }
        // 
        cout << "The clownfish capacity of this home: " << count << endl;
        //
        if (school == 1){
            outs << "The clownfish community has a school for fish." << endl;
        }else{
            outs << "The clownfish community does not have a school for fish." << endl;
        }
        // 
        if (relative == 1)
            cout << "The clownfish in this home are related to nemo!" << endl;
        else 
            cout << "The clownfish in this home are not related to nemo. " << endl;
        //
        cout << "Anenome Tentacle Length: " << length <<"ft " << endl;
        outs << endl;
    }else{
        outs << 5 << endl;
        outs << ocean << endl;
        outs << anenome << endl;
        outs << shallowOrHi << endl;
        outs << count << endl;
        outs << school << endl;
        outs << relative << endl;
        outs << length << endl;
    }
}


