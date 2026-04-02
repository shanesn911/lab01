// intlist.cpp
// Implements class IntList
// Shane Nguyen, April 1 2026

#include "intlist.h"

#include <iostream>
using std::cout;

// copy constructor
IntList::IntList(const IntList& source) {
    //IMPLEMENT THIS
    head = nullptr;
    tail = nullptr;
    Node *n = source.head;
    while (n) {
        push_back(n->info);
        n = n->next;
    }
}

// destructor deletes all nodes
IntList::~IntList() {
    //IMPLEMENT THIS
    Node *n = head;
    while (n) {
        Node *temp = n;
        n = n->next;
        delete temp;
    }
}


// return sum of values in list
int IntList::sum() const {
    // REPLACE THIS NON-SOLUTION
    Node *n = head;
    int total = 0;
    while (n) {
        total += n->info;
        n = n->next;
    }
    return total;
}

// returns true if value is in the list; false if not
bool IntList::contains(int value) const {
    // REPLACE THIS NON-SOLUTION
    Node *n = head;
    while (n) {
        if (n->info == value)
            return true;
        n = n->next;
    }
    return false;
}

// returns maximum value in list, or 0 if empty list
int IntList::max() const {
    // REPLACE THIS NON-SOLUTION
    if (!head) return 0;
    Node *n = head;
    int max_val = n->info;
    while (n) {
        if (n->info > max_val)
            max_val = n->info;
        n = n->next;
    }
    return max_val;
}

// returns average (arithmetic mean) of all values, or
// 0 if list is empty
double IntList::average() const {
    // REPLACE THIS NON-SOLUTION
    if (!head) return 0.0;
    Node *n = head;
    int total = 0;
    int count = 0;
    while (n) {
        total += n->info;
        count++;
        n = n->next;
    }
    return static_cast<double>(total) / count;
}

// inserts value as new node at beginning of list
void IntList::push_front(int value) {
    // IMPLEMENT
    Node *new_node = new Node(value);
    new_node->next = head;
    head = new_node;
    if (!tail) {
        tail = new_node;
    }
    
}

// append value at end of list
void IntList::push_back(int value) {
    // IMPLEMENT
    Node *new_node = new Node(value);
    new_node->next = nullptr;
    if (!tail) {
        head = new_node;
    } else {
        tail->next = new_node;
    }
    tail = new_node;
}

// return count of values
int IntList::count() const {
   //IMPLEMENT THIS
   Node *n = head;
   int count = 0;
   while (n) {
       count++;
       n = n->next;
   }
   return count;
}


//Assignment operator should copy the list from the source
//to this list, deleting/replacing any existing nodes
IntList& IntList::operator=(const IntList& source){
    //IMPLEMENT
    if (this == &source) {
        return *this; // handle self-assignment
    }
    // Delete existing nodes
    while (head) {
        Node *temp = head;
        head = head->next;
        delete temp;
    }
    tail = nullptr;
    // Copy nodes from source
    Node *n = source.head;
    while (n) {
        push_back(n->info);
        n = n->next;
    }
    return *this;
}

// constructor sets up empty list
IntList::IntList(){ 
    //IMPLEMENT THIS 
    head = nullptr;
    tail = nullptr;
}


// DO NOT CHANGE ANYTHING BELOW (READ IT THOUGH)

// print values enclose in [], separated by spaces
void IntList::print() const {
    Node *n = head;
    cout << '[';
    while (n) {
        cout << n->info;
        if (n->next)
            cout << " ";
        n = n->next;
    }
    cout << ']';
}

