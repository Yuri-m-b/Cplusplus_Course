#include <cstdlib>
#include <iostream>
#include <string>
#include <cstdio>
#include <ctime>
#include <algorithm>
using namespace std;

// Stacks are normally used to complete
// tasks versus utilizing data based on
// real objects

// Stacks & Queues are similar
// 1. Allow only a single item to be added
// or removed at a time
// 2. Stacks allow access to the last item
// inserted (LIFO)
// 3. Queues allow access to the first item
// inserted (FIFO)

class Stack{
    private:
        int data[50];
        int size = 10;
        // Sets stack as empty
        int topOfStack = -1;
    public:
        Stack(int s);
        void display();
        void push(int val);
        int pop();
        int peek();
        void popAll();
};

// Defines max size of stack and fills with
// -1
Stack::Stack(int s){
    size = s;
    // Puts -1 in all 50 spaces 
    fill_n(data, 50, -1);
}

// Will print the stack index and value 
// in boxes
void Stack::display(){
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

// 
void Stack::push(int val){
    if(topOfStack+1 < size){
        topOfStack++;
        data[topOfStack] = val;
    } else {
        cout << "Sorry the stack is full" << endl;
    }
}

// Displays last value entered and
// removes it from the stack
int Stack::pop(){
    if(topOfStack >= 0){
        // Value to return
        int popVal = data[topOfStack];
        // Makes sure value isn't returned
        data[topOfStack] = -1;
        // Keep indexes 0 based
        topOfStack--;
        return popVal;
    } else {
        return -1;
    }
}

// Displays last value entered but doesn't
// remove it from the stack
int Stack::peek(){
    if(topOfStack >= 0){
        return data[topOfStack];
    } else {
        return -1;
    }
    
}

// Pops all values
void Stack::popAll(){
    for(int i = topOfStack; i >= 0; i--){
        pop();
    }
}

int main(){
    Stack myStack = Stack(10);
    myStack.push(10);
    myStack.push(11);
    myStack.display();
    cout << "Pop : " << myStack.pop() << endl;
    cout << "Pop : " << myStack.pop() << endl;
    myStack.push(12);
    myStack.push(13);
    cout << "Peek : " << myStack.peek() << endl;
    myStack.display();
    myStack.popAll();
    myStack.display();

    return 0;
}