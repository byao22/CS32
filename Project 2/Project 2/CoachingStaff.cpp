//
//  CoachingStaff.cpp
//  Project 2
//
//  Created by Brian Yao on 7/17/18.
//  Copyright © 2018 Brian Yao. All rights reserved.
//

#include "CoachingStaff.h"
#include <string>
using namespace std;

CoachingStaff::CoachingStaff() // Create an empty CoachingStaff list
{
    head = nullptr;
    tail = nullptr;
    m_size = 0;
};


CoachingStaff::CoachingStaff(const CoachingStaff& rhs) // copy constructor for deep copy
{
    if (rhs.head == nullptr){
        tail = nullptr;
        head = nullptr;
    }
    
    else {
        head = new Node;
        head -> info = rhs.head->info;
        Node *q = head;
        Node *p = rhs.head->next;
        while (p != nullptr) {
            q->next = new Node;
            q->next->info = p->info;
            q->next->next = nullptr;
            p = p->next;
            q = q->next;
        }
    }
}

CoachingStaff& CoachingStaff::operator=(const CoachingStaff& rhs){ // assignment operator
    if(this != &rhs){
        CoachingStaff temp(rhs);
        changeStaff(temp);
    }
    return *this;
}

bool CoachingStaff::noCoaches() const // Return true if the CoachingStaff list is empty, otherwise false.
{
    return (numberOfCoaches() == 0);
}; //ok

int CoachingStaff::numberOfCoaches() const // Return the number of elements in // the CoachingStaff list.
{
    return m_size;
    
}; // ok


// need to work on some more
 
bool CoachingStaff::hireCoach(const std::string& firstName,const std::string& lastName,const IType& value)
// If the full name (both the first and last name) is not equal
// to any full name currently in the list then add it and return true.
//Elements should be added according to their last name. Elements with the same last name should be added according to
// their first names. Otherwise, make no change to the list and
// return false (indicating that the name is already in the list).
{
    // check to see if name is already in list
    Node *start = head;
    for(int i = 0; i < numberOfCoaches(); i++)
    {
        if(firstName == start -> first && lastName == start -> last)
            return false;
        else
            start = start -> next;
    }
    
    // make new node and fill in the info
    Node *p = new Node;
    p -> first = firstName;
    p -> last = lastName;
    p -> info = value;
    if(firstName != "" || lastName != "")
        m_size++;
    
    // for empty list
    if(head == nullptr){
        head = p;
        tail = p; // do i need this
        p -> next = nullptr;
        p -> prev = nullptr; // first one in list so far
        return true;
    }
    
    if(p -> last > tail -> last) // if it needs to go at the back of the list
    {
        p -> next = nullptr;
        tail -> next = p;
        p -> prev = tail;
        tail = p;
        return true;
    }
    
    Node *temp = head; //
    
    while(lastName > temp -> last){
        temp = temp -> next; // moves temp to the position right next to where NewCoach should go
    }
    
    if(lastName == temp -> last) // if last names are equal, check first name
    {
        while( lastName == temp -> last && firstName > temp -> first) // using ASCII?
            temp = temp -> next; // check to see if this works
    }
    // empty list already taken care of
    if(temp -> prev == nullptr) // it goes before head and becomes new head
    {
        p -> next = head;
        p -> prev = nullptr;
        temp -> prev = p;
        head = p;
        return true;
    }
    
    else // somewhere in the middle of the list
    {
        temp -> prev -> next = p;
        temp -> prev = p;
        p -> next = temp; // reallocate the variables for prev and next
        p -> prev = temp -> prev;
        return true;
    }
};


bool CoachingStaff::renameCoach(const std::string& firstName, const std::string& lastName, const IType& value)
// If the full name is equal to a full name currently in the // list, then make that full name no longer map to the value it // currently maps to, but instead map to the value of the third
// parameter; return true in this case. Otherwise, make no // change to the list and return false.
{
    Node *start = head;
    
    if(start == nullptr) // make sure list is not empty
        return false; // if so return false
    
    while(start != nullptr){
        if(firstName == start -> first && lastName == start -> last){
            start -> info = value;
            return true;
        }
        else
            start = start->next;
    }
    return false;
}; //ok
    

bool CoachingStaff::hireOrRename(const std::string& firstName, const std::string& lastName, const IType& value)
// If full name is equal to a name currently in the list, then // make that full name no longer map to the value it currently // maps to, but instead map to the value of the third parameter; // return true in this case. If the full name is not equal to // any full name currently in the list then add it and return // true. In fact, this function always returns true.
{
    Node *count = head;
    while(count != nullptr)
    {
        if( count -> first == firstName && count -> last == lastName)
        {
            count -> info = value; // if the name exists in the list
            return true;
        }
        else
            count = count -> next;
    }
    
    hireCoach(firstName,lastName,value); // if the name does not exist in the list
    return true;
};



bool CoachingStaff::fireCoach(const std::string& firstName, const std::string& lastName)
// If the full name is equal to a full name currently in the
// list, remove the full name and value from the list and return // true. Otherwise, make no change to the list and return
// false.
{
    Node *find = head;
    while(find != nullptr)
    {
        if(find -> first == firstName && find -> last == lastName) // if you find a match in the list
        {
            if(find -> next == nullptr ) // firing the tail coach
            {
                find -> prev -> next = nullptr;
                delete find;
                m_size--;
                return true;
            }
            else if(find -> prev == nullptr) // firing the head coach
            {
                find -> next -> prev = nullptr;
                delete find;
                m_size--;
                return true;
            }
            else // for middle case
            {
                find -> next -> prev = find -> prev; // adjust list
                find -> prev -> next = find -> next;
                delete find; // delete that coach
                m_size--;
                return true;
            }
        }
        else
            find = find -> next; // move on to next one in the list
    }
    return false; // couldnt find anyone in the list with that name
}; // ok


bool CoachingStaff::coachOnStaff(const std::string& firstName, const std::string& lastName) const
// Return true if the full name is equal to a full name
// currently in the list, otherwise false.
{
    Node *find = head;
    while(find != nullptr)
    {
        if( find -> first == firstName && find -> last == lastName)
            return true;
        else
            find = find -> next;
    }
    return false;
}; //ok


bool CoachingStaff::findCoach(const std::string& firstName, const std::string& lastName, IType& value) const
// If the full name is equal to a full name currently in the // list, set value to the value in the list that that full name // maps to, and return true. Otherwise, make no change to the // value parameter of this function and return false.
{
    Node *place = head;
    while(place != nullptr)
    {
        if( place -> first == firstName && place -> last == lastName)
        {
            place -> info = value;
            return true;
        }
        else
            place = place -> next;
    }
    return false;
}; // check with test case



bool CoachingStaff::whichCoach(int i, std::string& firstName, std::string& lastName, IType& value) const
// If 0 <= i < size(), copy into firstName, lastName and value
// parameters the corresponding information of the element at
// position i in the list and return true. Otherwise, leave the // parameters unchanged and return false. (See below for details // about this function.)
{
    
    if(i >= 0 && i < numberOfCoaches()) // less than size of list 
    {
        Node *find = head;
        for(int k = 0; k < i; k++)
        {
            find = find -> next;
        }
        
        firstName = find -> first ;
        lastName = find -> last ;
        value = find -> info ; // ask professor if this is right
        return true;
    }
    else
        return false;
}


void CoachingStaff::changeStaff(CoachingStaff& other)
// Exchange the contents of this list with the other one // swap
{
    // swap the head
    Node *tempHead = head;
    head = other.head;
    other.head = tempHead;
    
    // swap the tail
    Node *tempTail = tail;
    tail = other.tail;
    other.tail = tempTail;
}


CoachingStaff::~CoachingStaff()
{
    Node *del = head;
    Node *temp;
    while(del != nullptr)
    {
        temp = del;
        delete temp;
        del = del -> next;
    }
}


bool mergeStaffs(const CoachingStaff & csOne,const CoachingStaff & csTwo,CoachingStaff & csMerged)
{
    CoachingStaff temp(csMerged);
    
    while(!(temp.numberOfCoaches() == 0)){
        temp.~CoachingStaff();
    }
    
    int size1 = csOne.numberOfCoaches();
    int size2 = csTwo.numberOfCoaches();
    int counter = 0;
    int returnthis = 0;
    
    // for csOne
    string first1, last1;
    IType info1;
    
    // for csTwo
    string first2, last2;
    IType info2;
    
   if(size1 >= size2){
        for(int i = 0; i < size1; i++){ // temp now has all nodes of csOne
            csOne.whichCoach(i, first1, last1, info1);
            temp.hireCoach(first1, last1, info1);
            counter++;
        }
        for(int j = 0; j < size2; j++){
            csTwo.whichCoach(j, first2, last2, info2);
            for(int k = 0; k < size1; k++){
                temp.whichCoach(k, first1, last1, info1);
                if(last2 == last1 && first2 == first1 && info1 == info2)
                    break;
                else if(last2 == last1 && first2 == first1 && info1 != info2){
                    temp.fireCoach(first1, last1);
                    returnthis++;
                    counter--;
                }
                else{
                    temp.hireCoach(first2, last2, info2);
                    counter++;
                }
            }
        }
   }
    else{
        for(int i = 0; i < size2; i++){ // temp now has all nodes of csTwo
            csTwo.whichCoach(i, first2, last2, info2);
            temp.hireCoach(first2, last2, info2);
            counter++;
        }
        for(int j = 0; j < size1; j++){
            csOne.whichCoach(j, first1, last1, info1);
            for(int k = 0; k < size2; k++){
                temp.whichCoach(k, first2, last2, info2);
                if(last2 == last1 && first2 == first1 && info1 == info2)
                    break;
                else if(last2 == last1 && first2 == first1 && info1 != info2){
                    temp.fireCoach(first2, last2);
                    returnthis++;
                    counter--;
                }
                else{
                    temp.hireCoach(first1, last1, info1);
                    counter++;
                }
            }
        }
    }
    
    csMerged = temp;
    return(returnthis == 0);
}

void searchStaff(const std::string& fsearch,const std::string& lsearch,const CoachingStaff& csOne, CoachingStaff& csResult)
{
    CoachingStaff temp(csResult);
    
    while(!(temp.numberOfCoaches() == 0)){
        temp.~CoachingStaff();
    }
    
    string first, last;
    IType info;
    
    if(fsearch == "*" && lsearch == "*") // copy everything from csOne to Result
    {
        for(int i = 0; i < csOne.numberOfCoaches();i++)
        {
            csOne.whichCoach(i, first, last, info);
            temp.hireCoach(first, last, info);
        }
        csResult = temp;
    }
    else if(fsearch == "*" && lsearch != "*") // copy any person with the same last name
    {
        for(int i = 0; i < csOne.numberOfCoaches();i++)
        {
            csOne.whichCoach(i, first, last, info);
            if(lsearch == last){
                temp.hireCoach(first, last, info);
            }
            else
                break;
        }
        csResult = temp;
    }
    else if(fsearch != "*" && lsearch == "*") // copy any person with the same first name
    {
        for(int i = 0; i < csOne.numberOfCoaches();i++)
        {
            csOne.whichCoach(i, first, last, info);
            if(fsearch == first){
                temp.hireCoach(first, last, info);
            }
            else
                break;
        }
        csResult = temp;
    }
    else // copy anyone with exactly matching name
    {
        for(int i = 0; i < csOne.numberOfCoaches();i++)
        {
            csOne.whichCoach(i, first, last, info);
            if(fsearch == first && lsearch == last){
                temp.hireCoach(first, last, info);
            }
            else
                break;
        }
        csResult = temp;
    }
};

