#include <cstdlib>
#include <iostream>
#include <string>
#include <cstdio>
#include <ctime>
#include <algorithm>
using namespace std;

// Stacks & Queues are similar
// 1. Allow only a single item to be added
// or removed at a time
// 2. Stacks allow access to the last item
// inserted (LIFO)
// 3. Queues allow access to the first item
// inserted (FIFO)

class Queue{
    private:
        int data[50]; // Array for storage
        int size; // Total storage area
        // Keeps track of the index for the 1st value
        int front = 0; 
        // Number of values stored
        int numOfItems = 0;
        // Stores the next index to store values in
        int rear = 0;
    public:
        Queue(int s);
        void display();
        // Insert in next open position
        void insert(int val);
        // Insert values from largest to smallest
        void priorityInsert(int val);
        // Delete 1st value
        void remove();
        // Display but don't delete 1st value
        void peek();
};

Queue::Queue(int s){
    size = s;
    // Puts -1 in all 50 spaces 
    fill_n(data, 50, -1); 
}

// Will print the stack index and value 
// in boxes
void Queue::display(){
    cout << "----------" << endl;
    for(int i = 0; i < size; i++){
        // If data value is -1 don't print
        if(data[i] != -1){
            cout << "| " << i << " | ";
            cout << data[i] << " |" << endl;
            cout << "----------" << endl;
        }
    }
}

void Queue::insert(int val){
    if(numOfItems + 1 <= size){
        data[rear] = val;
        rear++;
        numOfItems++;
        cout << val << " Added to Queue" << endl;
    } else {
        cout << "Sorry but the Queue is Full" << endl;
    }
}

// Insert values from largest to smallest
void Queue::priorityInsert(int val){
    // Declared here to access the value outside of the for loop
    int i;
    if(numOfItems == 0){
        insert(val);
    } else {
        for(i = numOfItems-1; i >= 0; i--){
            if(val > data[i]){
                data[i+1] = data[i];
            } else break;
        }
        data[i+1] = val;
        rear++;
        numOfItems++;
    }
}

// Deletes the value at the top of the queue
void Queue::remove(){
    // Check that we have values
    if(numOfItems > 0){
        cout << data[front] << " Removed from Queue" << endl;
        data[front] = -1;
        front++;
        numOfItems--;
    } else {
        cout << "Sorry but the Queue is Empty" << endl;
    }
}

void Queue::peek(){
    cout << data[front] << " is the 1st Element" << endl;
}


int main(){
    Queue myQueue = Queue(10);
    // Insert values from largest to smallest
    myQueue.priorityInsert(16);
    myQueue.priorityInsert(25);
    myQueue.priorityInsert(10);
    myQueue.display();

    // Insert in the next available place
    myQueue.insert(11);
    myQueue.display();

    // Display but don't remove the top value
    myQueue.peek();

    // Remove the item at top of Queue
    myQueue.remove();
    myQueue.display();

    return 0;
}