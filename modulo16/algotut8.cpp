#include <cstdlib>
#include <iostream>
#include <string>
#include <cstdio>

using namespace std; 

class Node {
    public:
        string bookName;
        int millionsSold;
        Node* next;
        // NEW Refer to node previous
        Node* prev; 
        Node();
        Node(string bName, int mSold);
        void display();
        string toString();
};

class LinkedList{
    private:
        Node *head;
    public:
        LinkedList();
        ~LinkedList();
        bool isEmpty();
        void display();
        void insert(string bName, int mSold);
        void remove();
        // NEW
        void headInfo();
        Node* getNodeByName(string bName);
        void insertAfter(string afterThis, string bName, int mSold);
        void putLast(string bName, int mSold);
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

    // NEW
    temp->prev = NULL;
    if(head != NULL){
        head->prev = temp;
    }
    // Have head point to new node
    head = temp;
}

// NEW Get the heads book name
void LinkedList::headInfo(){
    head->display(); 
}

// NEW Get a Node by bookname
Node* LinkedList::getNodeByName(string bName){
    // Assign temp holding node for cycling
    Node *temp;
    // Node to return if found
    Node *nodeToReturn;
    // Assign head to it to start cycling
    temp = head;
    // Keep getting the next node 
    // assigned to the previous nodes
    // next and display info
    while(temp != NULL){
        if(temp->bookName == bName){
            return temp;
        }
        temp = temp->next; 
    }
    return NULL;
}

// NEW Insert new node after node provided
void LinkedList::insertAfter(string afterThis, string bName, int mSold){
    // Stores pointer to node searched
    // for
    Node* findNodePtr;
    // The node found with matching
    // name
    Node foundNode;
    // Get matching node
    findNodePtr = getNodeByName(afterThis);

    // Check if node provided is valid
    if(findNodePtr == NULL){
        cout << "Provided Node isn't Valid" << endl;
    } else {
        // Create temp node for setup
        Node *temp = new Node(bName, mSold);
        // Set new nodes next to node we 
        // searched fors next
        temp->next = findNodePtr->next;
        // Searched for nodes next is set
        // to our new node
        findNodePtr->next = temp;
        // New nodes previous set to searched
        // for node
        temp->prev = findNodePtr;

        // If new nodes next isn't null set
        // its prev to the new node
        if(temp->next != NULL){
            temp->next->prev = temp;
        }
    }
}

void LinkedList::putLast(string bName, int mSold){
    // Create temp node for setup
    Node *temp = new Node(bName, mSold);
    // Will be last node so make its next NULL
    temp->next = NULL;

    // Set head as last to start
    Node* last = head;

    // If linked list is empty mkae new node
    // the head
    if(head == NULL){
        temp->prev = NULL;
        head = temp;
    } else {
        // Cycle till the last node
        while(last->next != NULL)
            last = last->next;
        
        // Change next of last node
        last->next = temp;
        // Set last node as prev of new node
        temp->prev = last;
    }
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

    // Inserts 
    list.insertAfter("Don Quixote", "The Little Prince", 142);
    list.display();
    cout << endl;

    list.putLast("Dream of the Red Chamber", 100);
    list.display();
    cout << endl;

    return 0;
}
