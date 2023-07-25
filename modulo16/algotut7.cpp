#include <cstdlib>
#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

// Linked lists are lists of nodes. A Node
// contains data and a reference pointer to
// the next node in the list. They are
// linked using pointers. The 1st node is
// called the head. If head has a value of
// NULL we know the list is empty.

// Linked Lists are dynamically sized, and are
// easy to add and delete from. 

class Node {
    public:
        string bookName;
        int millionsSold;

        // This is a reference to the next link in 
        // the Linked List
        Node* next;

        Node();
        Node(string bName, int mSold);
        void display();
        string toString();
};

class LinkedList{
    private:
        // Pointers that point to the 1st
        // node
        Node *head;
    public:
        LinkedList();
        ~LinkedList();
        bool isEmpty();
        void display();
        void insert(string bName, int mSold);
        void remove();
};

// LINK FUNCTIONS
// Default constructor
Node::Node(){
    bookName = "No Name";
    millionsSold = 0;
}
// Used if data is passed at creation
Node::Node(string bName, int mSold){
    bookName = bName;
    millionsSold = mSold;
}

// Will print out all data associated with node
void Node::display(){
    cout << bookName << " : " << millionsSold << ",000,000 Sold" << endl;
}

// If we want to print the book name
string Node::toString(){
    return bookName;
}

// LINKED LIST FUNCTIONS
// Set pointer to NULL because there
// are no Nodes
LinkedList::LinkedList(){
    head = NULL;
}

// Delete all nodes
LinkedList::~LinkedList(){
    Node *next = head;
    while(next){
        Node *toDelete = next;
        next = next->next;
        delete toDelete;
    }
}

// Checks if list is empty
bool LinkedList::isEmpty(){
    if(head == NULL){
        return true;
    } else {
        return false;
    }
}

// Display all nodes in the list with
// their information
void LinkedList::display(){
    // Assign temp holding node
    Node *temp;
    // Assign head to it to start cycling
    temp = head;
    // Keep getting the next node 
    // assigned to the previous nodes
    // next and display info
    while(temp != NULL){
        temp->display();
        temp = temp->next; 
    }
}

// Inserts a new node at the beginning of
// the list
void LinkedList::insert(string bName, int mSold){
    // Create temp node for setup
    Node *temp = new Node(bName, mSold);
    temp->next = head;
    head = temp;
}

// Remove the 1st node in list which is the last
// node added
void LinkedList::remove(){
    if(head != NULL){
        Node *temp = head;
        head = head->next;
        delete temp;
    }
}

int main(){
    LinkedList list;
    cout << endl;
    list.insert("Don Quixote", 500);
    list.insert("A Tale of Two Cities", 200);
    list.insert("The Lord of the Rings", 150);
    cout << "Empty : " << list.isEmpty() << endl;
    list.display();
    list.remove();
    list.remove();
    cout << endl;
    list.display();
    cout << endl;

    return 0;
}