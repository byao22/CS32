//
//  LinkedList.cpp
//  Homework 1
//
//  Created by Brian Yao on 7/11/18.
//  Copyright © 2018 Brian Yao. All rights reserved.
//

#include <iostream>
#include <string>
#include "LinkedList.h"
using namespace std;


// copy constructor
LinkedList::LinkedList(const LinkedList& rhs)
{
    head = nullptr;
    if(this != &rhs){
        if(rhs.head == nullptr)
            head = nullptr;
        else
        {
            Node *p = rhs.head;
            insertToFront(p->value);
            p = p->next;
            Node *last = head;
            while(p != nullptr)
            {
                Node* temp1 = new Node;
                temp1->next = nullptr;
                temp1->value = p->value;
                last->next = temp1;
                temp1 = temp1->next;
                p = p->next;
            }
    }
    }
}

// Destroys all the dynamically allocated memory
// in the list.
LinkedList::~LinkedList(){
    while(head != nullptr){
        Node *p = head;
        head = head->next;
        delete p;
    }
};


// assignment operator
const LinkedList& LinkedList::operator=(const LinkedList& rhs){
    if(this != &rhs)
    {
        if(rhs.head == nullptr)
            head = nullptr;
    else{
        while(head != nullptr){
            Node *p = head;
            head = head->next;
            delete p;
        }
        
        Node *p = rhs.head;
        insertToFront(p->value);
        p = p->next;
        Node *last = head;
        while(p != nullptr)
        {
            Node* temp1 = new Node; // new node
            temp1->next = nullptr;
            temp1->value = p->value;
            last->next = temp1; // put new node to end of the list
        
            last = last->next;
            p = p->next;
        }
    }
    }
    return *this;
};


// inserts val to front of list
void LinkedList::insertToFront(const ItemType &val){
    Node *p = new Node;
    p->value = val;
    p->next = head; // update
    head = p;
};

// print list
void LinkedList::printList() const{
    if(head == nullptr)
        return;
    Node *p = head;
    while(p != nullptr)
    {
        cout<< p->value << endl; // print values one by one
        p = p->next;
    }
    cout << endl;
};

// Sets item to the value at position i in this
// LinkedList and return true, returns false if
// there is no element i
bool LinkedList::get(int i, ItemType& item) const{
    if(head==nullptr)
        return false;
    int count = 0;
    Node *p = head;
    while(p != nullptr)
    {
        if(count == i)
        {
            item = p->value;
            return true;
        }
        count++;
        p = p->next;
    }
    return false;
};

// Reverses the LinkedList
void LinkedList::reverseList(){
    if(head == nullptr || head->next == nullptr)
        return;
    
    LinkedList copy; // initialize
    Node *p;
    p = head;
    while(p != nullptr)
    {
        copy.insertToFront(p->value);
        p = p->next;
    }
    *this = copy;
};

// Prints the LinkedList in reverse order
void LinkedList::printReverse() const{
    LinkedList start = *this; // initialize
    start.reverseList();
    start.printList();
};

// Appends the values of other onto the end of this
// LinkedList.
void LinkedList::append(const LinkedList &other){
    if(other.head == nullptr)
        return;
    
    LinkedList start = other; // initialize
    Node *p = start.head;
    if(head != nullptr){
        Node *last = head;
        while(last->next != nullptr){
            last = last->next;
        }
        while(p != nullptr)
        {
            Node *temp1 = new Node; // temp node
            temp1->next = nullptr;
            temp1->value = p->value; // assign values
            last->next = temp1;
            last = last->next;
            p = p->next; // update
        }
    }
    else
        *this = start;
};

// Exchange the contents of this LinkedList with the other
// one.
void LinkedList::swap(LinkedList &other){
    LinkedList start = *this; // initialize
    *this = other;
    other = start; // swap
};

// Returns the number of items in the Linked List.
int LinkedList::size() const{
    if(head == nullptr)
        return 0;
    else{
    int count = 0;
    Node *p;
    p = head;
    while(p != nullptr) // to make sure you get to end
    {
        count++;
        p = p->next;
    }
    return count; // answer
    }
};



    


