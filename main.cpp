#include "main.h"
#include "tools.h"


int main(){
int capacity2 = 1;
//-------TestingBench---------------------------------
format_fun();
cout << "Test Bench: " << endl;
Activity *newAct = new Activity;
newAct->printActivity();

format_fun();
Activity *newAct2 = new Activity("Fly Fishing","Lochsa River","Intermediate",4, OTHER);
newAct2->printActivity();
delete newAct;
delete newAct2;


format_fun();
Active_list *testList = new Active_list [capacity2];
delete [] testList;
format_fun();

Activity *TestActivity = new Activity;
  
  //--------------------------------- 
  TestActivity->setLevel("Crazy Hard");
  if(strcmp(TestActivity->getLevel(),"Crazy Hard") != 0)
  {
    cout <<"FAILED set/get Level"<< endl;
  }
  //--------------------------------- 
  TestActivity->setRating(999);
  if(TestActivity->getRating() != 999)
  {
    cout <<"FAILED set/get Rating"<< endl;
  }
  //--------------------------------- 
  TestActivity->setType(INVALID);
  if(TestActivity->getType() != INVALID)
  {
    cout <<"FAILED set/get Type"<< endl;
  }
  delete TestActivity;
  
  cout << "End Test Bench" << endl;
  cout << endl;
  cout << endl;
//-------END--TESTING----------------------------------


  

  intro(); 

  Active_list *actList = new Active_list;

  cout << endl;
  cout << "Please Enter the file name: ";
  cin.getline(file,51,'\n');
  actList->Open(file);
  
  actList->Printlist();
  format_fun();
  
  menu(actList);

  delete actList;

  return 0;
  
}


