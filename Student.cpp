#include <iostream>
#include "Student.h"
using namespace std;
Student::Student(){

}
Student::Student(int waitTime, int clocktick){
  wait=waitTime;
  clock=clocktick;
  totalWait=wait+clock;

}
Student::~Student(){

}
int Student::getWait(){
  return wait;
}
int Student::getClock(){
  return clock;
}
int Student::getTotalWait(){
  return totalWait;
}
