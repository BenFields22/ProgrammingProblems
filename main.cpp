//
//  main.cpp
//  C++Practice
//
//  Created by Benjamin G Fields on 3/13/18.
//  Copyright © 2018 Benjamin G Fields. All rights reserved.
//
#include <algorithm>
#include <iostream>

class Heap
{
private:
    int* data;
    int size;
public:
    Heap(int vals[], int size)
    {
        this->size = size;
        this->data = new int[size];
        for (int i =0; i<size; i++) {
            this->data[i] = vals[i];
        }
        for (int i = size / 2 - 1; i >= 0; i--)
            heapify(size, i);
        
    }
    ~Heap()
    {
        delete[] data;
    }
    
    void print()
    {
        for (int i = 0; i<size; i++) {
            std::cout<<data[i]<<" ";
        }
        std::cout<<"\n";
    }
    void add(int v)
    {
        
    }
    
    void sort()
    {
        for (int i=size-1; i>=0; i--)
        {
            // Move current root to end
            std::swap(data[0], data[i]);
            
            // call max heapify on the reduced heap
            heapify(i, 0);
        }
    }
    
    void heapify(int n, int i)
    {
        int largest = i;  // Initialize largest as root
        int l = 2*i + 1;  // left = 2*i + 1
        int r = 2*i + 2;  // right = 2*i + 2
        
        // If left child is larger than root
        if (l < n && this->data[l] > this->data[largest])
            largest = l;
        
        // If right child is larger than largest so far
        if (r < n && this->data[r] > this->data[largest])
            largest = r;
        
        // If largest is not root
        if (largest != i)
        {
            std::swap(this->data[i], this->data[largest]);
            // Recursively heapify the affected sub-tree
            heapify(n, largest);
        }
    }
};


// Driver program
int main()
{
    int nums[] = {9,5,3,7,1};
    Heap H(nums,5);
    H.sort();
    H.print();
    return 0;
}
