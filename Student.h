#include <iostream>
using namespace std;
class Student{
public:
  Student();
  //creates student object with their waitTime and clocktick
  Student(int waitTime, int clocktick);
  ~Student();
  //gets student wait
  int getWait();
  int wait;
  //gets students clocktick
  int clock;
  int totalWait;
  int getTotalWait();
  int getClock();
};
