/*
Queue via Stacks: Implement a MyQueue class which implements a 
queue using two stacks.
*/

#include <iostream>
#include <stack>
using namespace std;

class MyQueue{
    stack<int> one, two;
public:
    MyQueue(){}

    void enqueue(int value);
    int dequeue();

    ~MyQueue(){}
};


void MyQueue::enqueue(int value){
    one.push(value);
}

int MyQueue::dequeue(){
    int top;
    while(!one.empty()){
        top = one.top();
        two.push(top);
        one.pop();
    }
    two.pop();
    while(!two.empty()){
        one.push(two.top());
        two.pop();
    }
    return top;
}

int main(){

    MyQueue mq;
    mq.enqueue(1);
    mq.enqueue(2);
    mq.enqueue(3);
    cout << mq.dequeue() << endl;
    mq.enqueue(4);
    cout << mq.dequeue() << endl;


    return 0;
}