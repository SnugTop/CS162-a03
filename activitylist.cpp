#include "activitylist.h"
#include "tools.h"


//Constructor
Active_list::Active_list()
{
    cout << "Constructor called" << endl; 
    head = NULL;
    tail = NULL;
    count = 0;


  }
//Deconstructor
Active_list::~Active_list()
{
    Node *curr = head;
    while(curr)
    {
        head = curr->next;
        delete curr;
        curr = head;
    }
    tail = NULL;
  }
//METHODS
int &Active_list::getCount()
{
   return count;
}
void Active_list::Open(char fileName [])
{
  head = NULL;
  tail = NULL;
  count = 0;
  Activity tempActivity;
  ifstream input_stream;
  char Temp_name[51];
  char Temp_location[51];
  char Temp_level[51];
  int Temp_rating;
  int Temp_type;
  
  int size = 0;

  //-----Open--File----------------------------------------------------
   input_stream.open(fileName);

  while(!input_stream.is_open())
  {
    char file_name[51];
    cout << "Error: Unable to open file!" << endl;
    cout <<"Please Enter File name: ";
    cin.getline(file_name,51,'\n');
    input_stream.open(file_name);
    
  }
  format_fun();
 

  
//-----Populate---List---------------------------------------------------
  input_stream.getline(Temp_name, 51, ';');
  while(!input_stream.eof() && size < 30 ) 
  {   
      input_stream.getline(Temp_location, 51,';');
      input_stream.getline(Temp_level, 51,';');
      input_stream>>Temp_rating;
      input_stream.ignore(5, ';');
    
   
      input_stream >>Temp_type;
      input_stream.ignore(5,'\n');
      tempActivity.setName(Temp_name);
      tempActivity.setLocation(Temp_location);
      tempActivity.setLevel(Temp_level);
      tempActivity.setRating(Temp_rating);
      tempActivity.setType(numtoType(Temp_type));
      addToList(tempActivity);
      input_stream.getline(Temp_name, 51,';');  
     
 }
  input_stream.close();
 
}
void Active_list::addActivity()
{
  Activity newActivity;
  char Temp_name[51];
  char Temp_location[51];
  char Temp_level[51];
  int Temp_rating;
  int Temp_type;

      cin.ignore(50,'\n');
      cin.clear();
      
      cout << "Enter Activity Name: ";
      cin.getline(Temp_name, 51, '\n');
      newActivity.setName(Temp_name);
      cout << endl;
  
      cout << "Enter Activity Location: ";
      cin.getline(Temp_location, 51,'\n');
      newActivity.setLocation(Temp_location);
      cout << endl;

      cout << "Enter Activity Level(Easy,Intermidiate,Difficult): ";
      cin.getline(Temp_level, 51, '\n');
      
      newActivity.setLevel(Temp_level);
      cout << endl;

      cout << "Enter Activity Rating(1-10): ";
      cin>>Temp_rating;
      while(Temp_rating < 1 || Temp_rating > 10)
      {
        cin.clear();
        cin.ignore();
        cout << "Please enter a valid rating" << endl;
        cin>>Temp_rating;
      }
        newActivity.setRating(Temp_rating);
        cout<<endl;


   cout << "Enter Activity Type(ATHLETIC=0,FOOD=1,ART=2,GAMES=3, OTHER=4: ";
   cin>>Temp_type;
  
   while(Temp_type < 0 || Temp_type > 4)
   {

    cout << "Please enter a valid type" << endl;
    cin>>Temp_type;
   }
  newActivity.setType(numtoType(Temp_type));
  cout << endl;

  addToList(newActivity);
  
  format_fun();
}
void Active_list::addToList(Activity &tempActivity) 
{

    Node *newNode = NULL; // creating new block to be added to the list with the new activity
    Node *curr = NULL;
    Node *prev = NULL;
    char tempName1[51];
    char tempName2[51];

    newNode = new Node;
    newNode->list = tempActivity;
    newNode->next = NULL;
   
    if(!head)// Checks to see if the list is empty
    {
        head = newNode;
        tail = newNode;
        count++;
        return;
    }
   
    else //if it is not empty it uses a while loop to iterate through the list to find the postion to insert
    {
        curr = head;
        curr->list.getName(tempName1);
        newNode->list.getName(tempName2);
        while(curr && compare(tempName1, tempName2))
        {
            prev = curr;
            curr = curr->next;
            if(curr)
            {
                curr->list.getName(tempName1);
            }
        }
        
        if(!curr)// adds new node to the end of the list after it has been sorted and all names have been checked
        {
            tail->next = newNode;
            tail = newNode;
        }
        
        else if(prev)// if not head or tail this inserts the new node between two nodes already in the list. This was determined in the while loop above
        {
            newNode->next = curr;
            prev->next = newNode;
        }
       
        else //insert at the beginning of the list. This was determeind in the while loop also. 
        {
            newNode->next = curr;
            head = newNode;
        }
    }
    count++;
}


void Active_list::byLocation()
{
    cout << "Search by Location: " << endl;
    cout << "----------------" << endl;
    char name_input[51];
    char nameCompare[51];
    cout << "Enter Name of Location: ";
    cin.ignore();
    cin.clear();
    cin.getline(name_input, 50, '\n');
    format_fun();
    
    bool found = false; 
    for (Node* curr = head; curr; curr = curr->next)// loop to traverse the list.
    {
        curr->list.getLocation(nameCompare);
        if (strstr(nameCompare, name_input) != NULL)
        {
            curr->list.printActivity();
            found = true;
        }
    }

    if (!found)
    {
       cout << "Your input: " << name_input << " Was not found in the list!" << endl;
    }
   
    cout << endl;
    format_fun();
}
  
    
void Active_list::byType()
{
    cout << "Search by Type: "<<endl;
    cout <<"----------------" << endl;
    int type_input;
    cout << "Enter Type of Activity (0=ATHLETIC, 1=FOOD, 2=ART, 3=GAMES, 4=OTHER): ";
    cin >> type_input;
    while(type_input < 0 || type_input > 4)
    {
        cout << "Please enter a valid type" << endl;
        cin >> type_input;
    }
    format_fun();
    for(Node *curr = head; curr; curr = curr->next)
    {
        if(curr->list.getType() == numtoType(type_input))
        {
            curr->list.printActivity();
        }
    }
    cout << endl;
    format_fun();
}
void Active_list::remove()
{
    format_fun();
    cout << 
      "This function is currently undergoing maintance. It will return in assignment 4!" <<endl;
  format_fun();
}
void Active_list::searchByName()
{
  cout << "Search by Name: "<<endl;
  cout <<"----------------" << endl;
  char name_input[51];
  char nameCompare[51];
  bool found = false;
  
    cout << "Enter Name of Activity:";
    cin.ignore();
    cin.clear();
    cin.getline(name_input,50,'\n');
    format_fun();

    for(Node *curr = head; curr; curr = curr->next)
    {
        curr->list.getName(nameCompare);
        if(strstr(nameCompare, name_input) != NULL)
        {
            curr->list.printActivity();
            found = true;
        }
    }

    if (!found) 
    {
        cout << "Your input: " << name_input << " Was not found in the list!" << endl;
    }

  
  cout << endl;
  format_fun();
}

void Active_list::readOut()
{

  ofstream output_stream;
  output_stream.open("activities.txt");
  if(!output_stream.is_open())
  {
    cout << "Error! File not found!" << endl;
    exit(1);
  }   
  else
  {
   
  cout <<"You have chose to Quit!" << endl;
  cout <<"Thank you for using my program!" << endl;
  format_fun();
 
  Node *curr;
    for(curr = head; curr; curr = curr->next)
    {
      curr->list.writeFile(output_stream);
    }
    cout <<"Your file has been populated with the updated list!" 
    << endl;

    }
 
  }
void Active_list::Printlist()
{
  cout << "Activity List:" << endl;
  cout<<"count= " << count << endl;
  cout << "--------------"<< endl;
  int num = 1;
  Node *curr;
  for(curr = head; curr; curr = curr->next)
   {
       cout << num << ".";
       curr->list.printActivity();
       num++;
   }
}
bool Active_list::compare(const char name1[], const char name2[])
{
    if(strcmp(name1, name2) < 0)
        return true;
    return false;
  }
