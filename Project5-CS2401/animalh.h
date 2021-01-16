/*
Header file: animal.h 
This file contains all of the child animal home classes of the parent home class.
Contains virtual I/O functions and the childs have different attributes.
*/
#include "parent.h"
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>

#ifndef ANIMAL_H
#define ANIMAL_H

class Wolf:public parent{
    public:
        Wolf(int p = 5, bool d = true, int h = 1, bool s = false,  bool pr = true, std::string shab = "Mountain"){
            packnumber = p;
            denLoc = d;
            habitat = h;
            stream = s;
            prey = pr;
            shabitat = shab;
        }
        void set_habitat(int habitat);
        std::string get_habitat(){ return shabitat;}

        void input(std::istream &ins);
        void output(std::ostream &outs);
    private:
        int packnumber; // how many wolfs live in this den
        bool denLoc; // Is the wolf den in the wild? Or false if in the zoo
        int habitat; // What type of habitat does the wolf live in? (1-4)
        std::string shabitat; //sets string version of the int habitat
        bool stream; // Is the wolf live near a stream? True if near false if not
        bool prey; // Is the deer around this den plentiful
        void int_hab_tos(); 
};
class Lion:public parent{
    public:
        Lion(){
            AfricaRegion = 'S';
            season = 'D';
            lionKing = true;
            trees = true;
            foodcount = 100;
            name = "Gerald's Pride";
        }
        void input(std::istream &ins);
        void output(std::ostream &outs);
    private:
        char AfricaRegion; // which region of Africa does the lion live in?
        char season; // Is the location of the den in dry (d) season or rain(f) season?
        bool lionKing; // Is the pride home close or not close to pride rock? True if close false if not
        bool trees; // is the pride home located in a environment with plenty of trees or not? True if tres false if not
        int foodcount; // How much available prey (individial prey) is around the home? 
        std::string name; // what is the pride homes name?
};
class Bear:public parent{
    public:
        Bear(){
            foodMiles = 10;
            denBearType = 'G';
            hibernation = false;
            cubs = true;
            water = false;
            continent = "North America";
        }
        void input(std::istream &ins);
        void output(std::ostream &outs);
    private:
        int foodMiles; // how many miles does the bear  have to travel from then den to find food?
        char denBearType; // What type of bear ben is this home?
        bool hibernation; // Are the bears hibernating at the moment or no?
        bool cubs; // Does the adult bear in this den have cubs?
        bool water; // Is there an abundance of water supply near the den?
        std::string continent; // What continent does the bear live on?

};
class Meerkat:public parent{
    public:
        Meerkat(){
            meerkatManor = false;
            security = true;
            burrowSys = 10;
            hospit = true;
        }
        void input(std::istream &ins);
        void output(std::ostream &outs);
    private:
        bool meerkatManor; // Was this meerkat home featured on Meerkat Manor?
        bool security; // Does this meerkat home protect against predators well? 
        int burrowSys; // How many burrow systems does the meerkat home have?
        bool hospit; // Is this meerkat home prepared for visitors (other meerkfat families)? 
};
class Clownfish:public parent{
    public:
        Clownfish(){
            ocean = "Pacific";
            anenome = true;
            shallowOrHi = true;
            count = 3;
            school = false;
            relative = false;
            length = 3;
        }
        void input(std::istream &ins);
        void output(std::ostream &outs);
    private:
        std::string ocean; // What ocean do the clownfish live in?
        bool anenome; // Does the sea anenome electric or no?
        bool shallowOrHi; // Do the clownfish live shallow (coral reef) or deeper (abyss) into the water?
        int count; // How many clownfish live in this home?
        bool school; // Does the clownfish community have a school for fish?
        bool relative; // Are the clownfish in this home related to Nemo?
        int length; // What is the length in feet of the sea anenome tentacles?
};
#endif
