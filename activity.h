#pragma once
#include <iostream>
#include <cstring>
#include <iomanip>
#include <fstream>


using namespace std;

enum Type{ATHLETIC, FOOD, ART, GAMES, OTHER, INVALID};

class Activity{

  private:
    char* name;
    char* location;
    char* level;
    int rating;
    Type type;


  public:
    //Constructors 
    Activity();
    Activity(char newName [],char newLocation [],char newLevel [] ,int newRating,Type newType);
    //Copy Constructor
    Activity(const Activity &newAct);
    //Destructor
    ~Activity();
    //Mutators
    void setName(char *newName);
    void setLocation(char *newLocation);
    void setLevel(char *newLevel);
    void setRating(int newRating);
    void setType(Type newType);
    //Accessor Functions 
    const char* getName(char*) const;
    const char* getLocation(char*)const;
    const char* getLevel()const;
    void printType(Type, char []);
    int getRating();    
    Type getType();
    void printActivity();
    void writeFile(ofstream &);
    //Assignment Operator Overloading
    const Activity& operator=(const Activity& newAct);
};


