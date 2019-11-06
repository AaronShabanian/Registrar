#include <iostream>
#include "Student.h"
using namespace std;
class Window{
public:
  Window();
  Window(Student student);
  ~Window();
  int wait;

  int space;
  int occupado=0;
  int getWait();
  int idle;
  //checks if window has someone in it
  bool isNotEmpty();
  //checks if window is takem
  bool isFull();
  //sets student wait time to 9
  void resetWindow();
  //subtrcts one from student wait time
  void timepassed();
};
