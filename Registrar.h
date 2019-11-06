#include <iostream>
#include "GenQueue.h"
#include "Window.h"
#include <fstream>
using namespace std;
class Registrar{
public:
  Registrar();
  ~Registrar();
  //stores the amount of windows to be used for the duration of the simulation
  int windows;
  //Stores wait time of each student once at a window (array of student objects)
  Window * arr = NULL;
  //MeanW and idle are arrays of ints to gather statistics such as mean time and idle time
  int * meanW = NULL;
  int * idle = NULL;
  int occupied=0;
  /*Prompts for user input of text file and reads through the file creating a queue of Students
  based on what was in the file*/
  void getInLine();
  /* Goes through the queue and checks each students clock time they arrive and places them into an
  array depending if any of the windoes are open and the correct time has arrived. Then gathers the statistics
  and prints them to the user*/
  void sendToWindow();
  //calling the GenQueue classs so I can use it
  typedef GenQueue<Student> StudentQueue;
  StudentQueue queue;
};
