/*

Stack Min: 
How would you design a stack which, in addition to push and pop, has a function min
which returns the minimum element? Push, pop and min should all operate in 0(1) time.

*/


#include <iostream>
using namespace std;

class Stack {
    int* arr;
    int size = 0;
    int top = 0;
    int minIndex = -1;
public:
    Stack(int size){
        this->size = size;
        arr = new int[size];
    };

    void push(int item);
    void pop();
    int peek();
    bool isEmpty();
    bool isFull();
    int minimum();

    void printStack();

    ~Stack(){
        delete arr;
    };
};


bool Stack::isFull(){
    return (top==size) ? true : false;
}

bool Stack::isEmpty(){
    return (top==0) ? true : false;
}

void Stack::push(int item){

    if (this->isFull()){
        cout << endl << "Stack is full.";
        return;
    }

    arr[top] = item;
    top++;

    if (minIndex==-1){
        minIndex = 0;
        return;
    }

    if (arr[minIndex] > item)
        minIndex = top-1;
}

void Stack::pop(){
    if (this->isEmpty()){
        cout << endl << "Stack is empty.";
        return;
    }

    if (top-1 == minIndex){
        minIndex = 0;
        for(int i=1; i<top-1; i++){
            if (arr[i] < arr[minIndex])
                minIndex = i;
        }
    }
        
    top--;
}

int Stack::peek(){
    if (this->isEmpty()){
        cout << endl << "Stack is empty.";
        return -999;
    }

    return arr[top];
}

void Stack::printStack(){
    cout << endl;
    for(int i=0; i<top; i++)
        cout << arr[i] << " | ";
    cout << endl;
}

int Stack::minimum(){
    if (this->isEmpty()){
        cout << endl << "Stack is empty.";
        return -999;
    }

    return arr[minIndex];
}


int main(){

    Stack s(5);
    s.push(1);
    s.printStack();
    cout << s.minimum() << endl;
    s.push(0);
    s.push(2);
    s.printStack();
    
    cout << s.minimum() << endl;
    s.pop();
    s.printStack();
    cout << s.minimum() << endl;
    s.pop();
    s.printStack();
    cout << s.minimum() << endl;


    s.printStack();

    return 0;
}