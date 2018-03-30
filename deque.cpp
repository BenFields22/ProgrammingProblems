//
//  deque.cpp
//  C++Practice
//
//  Created by Benjamin G Fields on 3/29/18.
//  Copyright © 2018 Benjamin G Fields. All rights reserved.
//

#include <iostream>

class Deque{
private:
  int* data;
  int size;
  int capacity;
  int first;
  int last;
public:
  Deque(){
    capacity = 10;//default
    data = new int[capacity];
    for (int i = 0; i<capacity; ++i) {
      data[i] = -9999;
    }
    size = 0;
    first = 0;
    last = 0;
  }
  Deque(int cap){
    if (cap <=0) {
      cap = 10;
    }
    data = new int[cap];
    for (int i = 0; i<cap; ++i) {
      data[i] = -9999;
    }
    size = 0;
    capacity = cap;
    first = 0;
    last = 0;
  }
  void addFront(int val);
  void doubleCapacity();
  void addBack(int val);
  void removeFront();
  void removeBack();
  int front();
  int back();
  int isEmpty();
  void printDeque();
};

void Deque::doubleCapacity(){
  capacity = capacity*2;
  int* newData = new int[capacity];
  for (int i = 0; i<capacity; ++i) {
    newData[i] = -9999;
  }
  int newPos = 0;
  int count = 0;
  int index = first;
  while(count < size){
    newData[newPos] = data[index];
    index++;
    if(index == size){
      index = 0;
    }
    newPos++;
    count++;
  }
  first = 0;
  last = size-1;
  data = newData;
}

void Deque::addFront(int val){
  if(size == 0){
    data[0] = val;
  }
  else if (size == capacity) {
    //resize
    doubleCapacity();
    data[capacity-1] = val;
    first = capacity-1;
  }
  else{
    //add to the position before first and adjust first
    if (first == 0) {
      data[capacity-1] = val;
      first = capacity-1;
    }
    else {
      first = first - 1;
      data[first] = val;
    }
  }
  size++;
}

void Deque::addBack(int val){
  if(size == 0){
    data[0] = val;
  }
  else if (size == capacity) {
    //resize
    doubleCapacity();
    data[size] = val;
    last = size;
  }
  else{
    //add to the position after last and adjust last
    last++;
    if (last == capacity) {
      last=0;
    }
    data[last] = val;
  }
  size++;
}

void Deque::printDeque(){
  std::cout<<"**************DEQUE**************\n";
  std::cout<<"Deque Size: "<<size<<std::endl;
  std::cout<<"Deque Cap: "<<capacity<<std::endl;
  std::cout<<"Deque First: "<<first<<std::endl;
  std::cout<<"Deque Last: "<<last<<std::endl;
  std::cout<<"Deque contents unordered: ";
  for (int i = 0; i<capacity; ++i) {
    if (data[i] != -9999) {
      std::cout<<data[i]<<" ";
    }
    else{
      std::cout<<"?"<<" ";
    }
  }
  std::cout<<"\n";
  std::cout<<"Deque in order: ";
  for (int i = 0; i<size; ++i) {
    int index = (first + i)%capacity;
    std::cout<<data[index]<<" ";
  }
  std::cout<<"\n";
  std::cout<<"*********************************\n";
}

void Deque::removeBack(){
  if (size == 0) {
    return;
  }
  data[last] = -9999;
  if (last == 0) {
    last = capacity-1;
  }
  else {
    last = last -1;
  }
  size--;
}

void Deque::removeFront(){
  if (size == 0) {
    return;
  }
  data[first] = -9999;
  if (first == capacity-1) {
    first = 0;
  }
  else{
    first++;
  }
  size--;
}

int Deque::front(){
  return data[first];
}

int Deque::back(){
  return data[last];
}

int Deque::isEmpty(){
  return (size == 0);
}


int main(int argc, char** argv){
  //implementation of a deque
  
  Deque myDeque(5);
  std::cout<<"Is empty: "<<myDeque.isEmpty()<<std::endl;
  myDeque.addBack(2);
  myDeque.printDeque();
  myDeque.addFront(5);
  myDeque.printDeque();
  myDeque.addBack(6);
  myDeque.printDeque();
  myDeque.addFront(7);
  myDeque.printDeque();
  myDeque.addFront(8);
  myDeque.printDeque();
  myDeque.removeBack();
  myDeque.printDeque();
  myDeque.removeFront();
  myDeque.printDeque();
  myDeque.addFront(9);
  myDeque.printDeque();
  myDeque.addBack(10);
  myDeque.printDeque();
  myDeque.addBack(10);
  myDeque.printDeque();
  myDeque.removeFront();
  myDeque.printDeque();
  std::cout<<"First: "<<myDeque.front()<<std::endl;
  std::cout<<"Last: "<<myDeque.back()<<std::endl;
  std::cout<<"Is empty: "<<myDeque.isEmpty()<<std::endl;
  return 0;
}
