#include <iostream>
#include "Window.h"
using namespace std;
Window::Window(){

}
Window::Window(Student student){
  wait=student.getWait();
  occupado++;
}
Window::~Window(){

}


int Window::getWait(){
  return wait;
}
bool Window::isNotEmpty(){
  if(occupado>0){
    return true;
  }
  else{
    return false;
  }
}
void Window::resetWindow(){
  wait=-9;
}

bool Window::isFull(){
  if(occupado==6){
    return true;
  }
  else{
    return false;
  }
}
void Window::timepassed(){
  wait--;
}
