#include <iostream>
#include "Registrar.h"
#include <fstream>
#include <bits/stdc++.h>
#include <sstream>
using namespace std;
Registrar::Registrar(){

}
Registrar::~Registrar(){

}
void Registrar::getInLine(){
  cout<<"Enter file name: "<<endl;
  string filename;
  cin>>filename;
  ifstream readfile (filename);
  int length=0;
  int reset =0;
  int studentCounter=0;
  int students=0;
  int time;
  int clock;
  int clocktick=0;
  string line;
  int counter = 0;
  int i=0;
  int j=0;
  //reads through file initially to find length of file so it can be used again to create an array to be checked though
  // for basic variables such as windows and num of students
  while(getline(readfile,line)){
    length++;
  }
  ifstream readfile2 (filename);
  int arr[length];
  //creates the array with every line being on index of it
  while(getline(readfile2,line)){
    arr[i]=std::stoi(line);
    i++;
  }
  // reads through the array to get number of students per clocktick and windows
  while(clocktick<1000){
    students=0;
    studentCounter=0;
    while(counter<length){
      counter++;
      if(reset==0&&clocktick==0){
        windows = arr[j];
        j++;
      }
     if(reset ==1){
        clock=arr[j];
        if (clocktick!=clock){
          clock=-1;
        }
        else{
          j++;
        }
      }
     if(reset==2&&clocktick==clock){
        students= arr[j];
        j++;
        studentCounter=0;
      }
      if(studentCounter<students&& reset>2){
        time=arr[j];
        //creates student object and inserts them into the queue
        Student student(time,clocktick);
        queue.insert(student);
        studentCounter++;
        j++;
      }
      reset++;
    }
    counter=0;
    reset=1;
    clocktick++;
  }
}
void Registrar::sendToWindow(){
  int empty=0;
  //empty is used later on to determine the number of windows that are empty
  int numOfStudents=queue.GetSize();
  //arr will be an array of windows that contain students
  arr=new Window [windows];
  idle=new int [windows];
  //since my program did not account that a window is idle from clocktick 0 to 1, I added a check that adds an idle time if
  //no one comes until after clocktick 0
  int checker=(queue.peek()).getClock();
  for(int i=0;i<windows;i++){
    arr[i].resetWindow();
    idle[i]=0;
  }
  if(checker!=0){
    for(int i=0; i<windows;i++){
      idle[i]=1;
    }
  }
  //array of waitTime per student
    meanW=new int [numOfStudents];
   int clocktick=1;
   int peek=0;
   int prevClockTick=-1;
   int studentNumber=0;
   bool done=false;
   double meanWait;
   for(int i=0; i<numOfStudents; i++){
       meanW[i]=0;
   }
   //this while loop is the main part of the entire program, simulates that time is passing and students are entering the
   //registrars office
    while(queue.GetSize()!=0||done==false){
      if(clocktick!=0){
      prevClockTick=clocktick;
    }
        if(queue.GetSize()!=0){
          //this is for the inital people going into windows, not when windows change students, also
          //determines if clocktick should change or more actions can be done in same minute
          peek=(queue.peek()).getClock();
           if(peek<=clocktick){
             if(occupied<windows){
              //creates windows of students if a student is waiting in line and puts it into an array
              Window window(queue.remove());
              arr[occupied]=window;
              meanW[studentNumber]=0;
              studentNumber++;
              occupied++;
            }
            else{
              clocktick++;
            }
           }
           else{
             clocktick++;
           }
         }
         else{
           clocktick++;
         }
       for(int i=0; i<windows;i++){
         if(arr[i].getWait()>0){
           if(clocktick!=prevClockTick){
             if(arr[i].getWait()>0){
               //calls timepassed function from the window class which lowers each students wait by one to simulate passing time
              arr[i].timepassed();
            }
           }
         }
         //this part is similar but its main purpose is for replacing students in windows when someone is done
         if(occupied>=windows){
           if(arr[i].getWait()==0|| arr[i].getWait()==-9){
               arr[i].resetWindow();
               if(peek<=clocktick){
                 if(queue.GetSize()>0){
                   Window window(queue.remove());
                   meanW[studentNumber]=clocktick-peek;
                   peek=(queue.peek()).getClock();
                   studentNumber++;
                   arr[i]=window;
                 }
               }
           }

      }
      else if(arr[i].getWait()<1){
        //"reset window " sets the student wait time to -9, which I essentially used for my NULL
        arr[i].resetWindow();
      }
       }

       for(int i=0; i<windows; i++){
        if(arr[i].getWait()!=-9){
          empty++;
        }
       }
       if(empty==0){
         done=true;
       }
       empty=0;
       if(done==false){

       if(clocktick!=prevClockTick){

         for(int k=0; k<windows; k++){

           if(arr[k].getWait()==-9&&queue.isEmpty()==false){
             //adds idle time if a window is open
             idle[k]=idle[k]+1;
           }
         }
       }
     }

     }
     //at this point the time simulation has ended and the rest of the program is dedicated to determing the statistics of the
     //line
     int totalWait=0;
     int longestWait=0;
     int overTenMin=0;
     for(int i = 0; i<numOfStudents; i++){
       totalWait+=meanW[i];
       if(meanW[i]>longestWait){
         longestWait=meanW[i];
       }
       if(meanW[i]>10){
         overTenMin++;
       }
     }
     meanWait=(double)totalWait/(double)numOfStudents;
     int n = sizeof(meanW)/sizeof(meanW[0]);
     double medianWait;
     double meanIdle;
     int longIdle=0;
     int mid=0;
     int idleOverFive=0;
     sort(meanW, meanW + numOfStudents);
     //sorts the array of times to help find the median wait
     mid=sizeof(meanW)/2;
     //checking if even or odd
     if(sizeof(meanW)%2==1){
       medianWait=((double)meanW[mid]+(double)meanW[mid+1])/2;
     }
     else{
       medianWait=meanW[mid+1];
     }
     for(int i=0; i<windows; i++){
       meanIdle+=idle[i];
       if(idle[i]>longIdle){
         longIdle=idle[i];
       }
       if(idle[i]>5){
         idleOverFive++;
       }
     }
     meanIdle/=((double)windows);
     //printing results
     cout<<endl<<"1. The mean wait of all the students is: "<<meanWait<<" minutes"<<endl;
     cout<<"2. The median wait of all the students is: "<<medianWait<<" minutes"<<endl;
     cout<<"3. The longest wait of all the students is: "<<longestWait<<" minutes"<<endl;
     cout<<"4. The number of students waiting over 10 min is: "<<overTenMin<<" people"<<endl;
     cout<<"5. The mean idle time of windows is: "<<meanIdle<<" minutes"<<endl;
     cout<<"6. The Longest idle of a window is: "<<longIdle<<" minutes"<<endl;
     cout<<"7. The number of windows idle for more than 5 minutes is: "<<idleOverFive<<endl;



    }
