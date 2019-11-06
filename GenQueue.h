#include <iostream>
#include "DoublyLinkedList.h"
using namespace std;
template <typename T> class GenQueue
{
  //all queue methods are essentially renamed DoublyLinkedList methods
  public:
    GenQueue();
    GenQueue(int maxSize);
    ~GenQueue();

    void insert(T d);
    T remove();
    T peek();
    bool isFull();
    bool isEmpty();
    T front;
    T rear;
    int size;
    int numElements;
    int GetSize();
    T *myQueue;
    typedef DoublyLinkedList<T> List;
    List list;
};
template <typename T>
GenQueue<T>::GenQueue(){
  //calls DoublyLinkedList to use as base of queue
  typedef DoublyLinkedList<T> List;
  List list;
  numElements=0;
}
template <typename T>
GenQueue<T>::~GenQueue(){
  
}
template <typename T>
void GenQueue<T>::insert(T d){
  list.insertBack(d);
}
template <typename T>
T GenQueue<T>::remove(){
  //error Checking
  if(list.getSize()==0){
    cout<<"Queue is empty"<<endl;
  }
  else{
    T answer=list.removeFront();
    return answer;
    }
}
template <typename T>
T GenQueue<T>::peek(){
  if(list.getSize()==0){
    cout<<"Queue is empty"<<endl;
  }
  else{
    T answer1=list.returnFront();
    return answer1;
  }
}
template <typename T>
bool GenQueue<T>::isEmpty(){
  return (numElements==0);
}
template <typename T>
int GenQueue<T>::GetSize(){
  int answer3=list.getSize();
  return answer3;
}
