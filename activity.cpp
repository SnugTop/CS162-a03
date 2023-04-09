#include "activity.h"

//Constructors
Activity::Activity()
{
  int size = 10;
   name = new char[size];
   strcpy(name, "Default");
   location = new char[size];
   strcpy(location, "Unknown");
   level = new char[size];
   strcpy(level, "Unknown");
   rating = -1;
   type = INVALID;
}
Activity::Activity(char newName [],char newLocation [],char newLevel [], int newRating, Type newType)
{
  name = new char[strlen(newName)+1];
  strcpy(name, newName);
  location = new char[strlen(newLocation)+1];
  strcpy(location, newLocation);
  level = new char[strlen(newLevel)+1];
  strcpy(level, newLevel);
  rating = newRating;
  type = newType;
}
//Copy Constructor 
Activity::Activity(const Activity &newAct)
{
  name = new char[strlen(newAct.name)+1];
  location = new char[strlen(newAct.location)+1];
  level = new char[strlen(newAct.level)+1];
  
  *this = newAct;
}
//Destructor 
Activity::~Activity()
{
  if(name)
  {
    delete [] name;
    name = nullptr;
  }
  if(location)
  {
    delete [] location;
    location = nullptr;
  }
  if(level)
  {
    delete [] level;
    level = nullptr;
  }
}
//Mutators
void Activity::setName(char *newName)
{
    if(name)
    {
    delete [] name;
    name = nullptr;
    }
  name = new char[strlen(newName)+1];
  strcpy(name, newName);
  }
void Activity::setLocation(char *newLocation)
{
  if(location)
  {
    delete [] location;
    location = nullptr;
  }
  location = new char [strlen(newLocation)+1];
  strcpy(location, newLocation);
  }
void Activity::setLevel(char *newLevel)
{
  if(level)
  {
    delete [] level;
    level = nullptr;
  }
  level = new char[strlen(newLevel)+1];
  strcpy(level, newLevel);
  }
void Activity::setRating(int newRating)
{
  rating = newRating;
  }
void Activity::setType(Type newType)
{
  type = newType;
  }
//Accessors
 const char* Activity::getName(char* returnName) const
{
  strcpy(returnName, name);
  return name;
  
  }
const char* Activity::getLocation(char* returnLoc) const
{
 strcpy(returnLoc, location);
  
  return location;
  
}
const char* Activity::getLevel() const
{

  return level;
}
int Activity::getRating()
{
  return rating;
}
Type Activity::getType()
{
  return type;
}   
void Activity::printType(Type tempType, char type_1 [])
{
  
  switch(tempType)
  {
    case ATHLETIC:
      strcpy(type_1, "Athletic");
      break;
    case FOOD:
      strcpy(type_1, "Food");  
      break;
    case ART:
      strcpy(type_1, "Art");
      break;
    case GAMES:
      strcpy(type_1, "Games");  
    break;
    case OTHER:
      strcpy(type_1, "Other");
    break;
    case INVALID:
      strcpy(type_1, "Invalid");
    break;
    default:
     cout << "ERROR! Invalid input!" << endl;
  }
  return;

}
void Activity::printActivity()
{
    char type_1[50]; 
    printType(type,type_1);
    cout << name <<" ; "<<location <<" ; "<<
      level <<" ; "<<rating <<" ; "<< type_1 <<  endl; 
  
  
}
void Activity :: writeFile(ofstream &output_stream)
{
  output_stream << name <<" ; "<<location <<" ; "<<
      level <<" ; "<<rating <<" ; "<< type <<  endl;
}
const Activity& Activity:: operator=(const Activity& newAct)
{
  if (this == &newAct)
  {
    return *this;
  }

  else
  {
      this->setName(newAct.name);
      this->setLocation(newAct.location);
      this->setLevel(newAct.level);
      this->rating = newAct.rating;
      this->type = newAct.type;

    return *this;
  }
}