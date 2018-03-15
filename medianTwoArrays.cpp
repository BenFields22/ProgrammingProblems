//
//  medianTwoArrays.cpp
//  C++Practice
//
//  Created by Benjamin G Fields on 3/14/18.
//  Copyright © 2018 Benjamin G Fields. All rights reserved.
//

#include <iostream>


int maxInt(int a, int b)
{
    std::cout<<"Max int with "<<a<<" and "<<b<<std::endl;
    if (a<b) {
        std::cout<<"Returned: "<<b<<std::endl;
        return b;
    }
    else{
        std::cout<<"Returned: "<<a<<std::endl;
        return a;
    }
}

int minInt(int a , int b)
{
    std::cout<<"Min int with "<<a<<" and "<<b<<std::endl;
    if (a>b) {
        std::cout<<"Returned: "<<b<<std::endl;
        return b;
    }
    else{
        std::cout<<"Returned: "<<a<<std::endl;
        return a;
    }
}

double FindMedian(int arr1[],int n,int arr2[], int m)
{
    std::cout<<"n:"<<n<<" and m:"<<m<<std::endl;
    if (n>m) {
        return FindMedian(arr2,m,arr1,n);
    }
    int start = 0;
    int end = n-1;
    int PartitionX = (start + end)/2;
    int PartitionY = ((n+m+1)/2)-PartitionX;
    int notFound = 1;
    int maxLeftX = 0;
    int minRightX = 0;
    
    int maxLeftY = 0;
    int minRightY = 0;
    
    while(notFound)
    {
        PartitionY = ((n+m+1)/2)-PartitionX;
        
        for (int i = 0; i<PartitionX; i++) {
            std::cout<<arr1[i]<<" ";
        }
        std::cout<<"|";
        for (int i = PartitionX; i<n; i++) {
            std::cout<<arr1[i]<<" ";
        }
        std::cout<<"\n";
        for (int i = 0; i<PartitionY; i++) {
            std::cout<<arr2[i]<<" ";
        }
        std::cout<<"|";
        for (int i = PartitionY; i<m; i++) {
            std::cout<<arr2[i]<<" ";
        }
        std::cout<<"\n";
        
        maxLeftX = (PartitionX == 0)? INT_MIN : arr1[PartitionX-1];
        minRightX = (PartitionX == n)? INT_MAX : arr1[PartitionX];
        
        maxLeftY = (PartitionY == 0)? INT_MIN : arr2[PartitionY-1];
        minRightY = (PartitionY == m)? INT_MAX : arr2[PartitionY];

        if (maxLeftX<=minRightY && maxLeftY<=minRightX) {
            notFound = 0;
            std::cout<<"Case found\n";
        }
        else if(arr1[PartitionX-1]>arr2[PartitionY])
        {
            //move towards left in X
            std::cout<<"Move X to left\n";
            PartitionX--;
            if (PartitionX<0) {
                PartitionX=0;
            }
        }
        else
        {
            //move to right in X
            std::cout<<"Move X to right\n";
            PartitionX++;
            if (PartitionX>n) {
                PartitionX=n;
            }
        }
    }
    double med;
    if ((n+m)%2==0) {
        //average
        double min = minInt(minRightX, minRightY);
        double max = maxInt(maxLeftX, maxLeftY);
        med = (min + max)/2.0;
    }
    else
    {
        //take the max on left
        med = maxInt(maxLeftX, maxLeftY);
    }
    return med;
}
int main()
{
    int arr1[] = {78,79,80,333};
    int n = sizeof(arr1)/sizeof(arr1[0]);
    int arr2[] = {75,76,77,97,100};
    int m = sizeof(arr2)/sizeof(arr2[0]);
    
    double median = FindMedian(arr1,n,arr2,m);
    std::cout<<"Median is "<<median<<std::endl;
    
    
    return 0;
}
