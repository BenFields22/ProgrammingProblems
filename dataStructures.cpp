//
//  dataStructures.cpp
//  C++Practice
//
//  Created by Benjamin G Fields on 3/27/18.
//  Copyright © 2018 Benjamin G Fields. All rights reserved.
//

#include <stdio.h>
#include <iostream>

struct node
{
    int data;
    node *next;
};

class list
{
private:
    node *head, *tail;
public:
    list()
    {
        head=NULL;
        tail=NULL;
    }
    void createnode(int value)
    {
        node *temp=new node;
        temp->data=value;
        temp->next=NULL;
        if(head==NULL)
        {
            head=temp;
            tail=temp;
            temp=NULL;
        }
        else
        {
            tail->next=temp;
            tail=temp;
        }
    }
    void display()
    {
        node *temp=new node;
        temp=head;
        while(temp!=NULL)
        {
            std::cout<<temp->data<<"\t";
            temp=temp->next;
        }
    }
    
    void insert_start(int v)
    {
        node* newFront = new node;
        newFront->data = v;
        newFront->next = head;
        head = newFront;
    }
    
    void insert_position(int pos, int value)
    {
        node *pre=new node;
        node *cur=new node;
        node *temp=new node;
        cur=head;
        for(int i=1;i<pos;i++)
        {
            pre=cur;
            cur=cur->next;
        }
        temp->data=value;
        pre->next=temp;
        temp->next=cur;
    }
    void delete_First()
    {
        node* temp = new node;
        temp = head;
        head = head->next;
        delete temp;
    }
    
    void delete_last()
    {
        node *current=new node;
        node *previous=new node;
        current=head;
        while(current->next!=NULL)
        {
            previous=current;
            current=current->next;
        }
        tail=previous;
        previous->next=NULL;
        delete current;
    }
    
    void delete_position(int pos)
    {
        node *current=new node;
        node *previous=new node;
        current=head;
        for(int i=1;i<pos;i++)
        {
            previous=current;
            current=current->next;
        }
        previous->next=current->next;
    }
};

int main(int argc, char **argv){
    list myList;
    myList.createnode(5);
    myList.createnode(9);
    myList.display();
    myList.delete_First();
    std::cout<<"\n";
    myList.display();
    std::cout<<"\n";
    return 0;
}
