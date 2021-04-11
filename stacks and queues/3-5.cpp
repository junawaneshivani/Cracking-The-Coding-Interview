/*
Sort Stack: Write a program to sort a stack such that the smallest 
items are on the top. You can use an additional temporary stack, 
but you may not copy the elements into any other data structure 
(such as an array). The stack supports the following operations: 
push, pop, peek, and is Empty.
*/

#include <iostream>
#include <stack>
using namespace std;


class SortStack{
    stack<int> one, two;
    void sort();
public:
    SortStack(){};

    void push(int value);
    void pop();
    int top();

    ~SortStack(){};
};


void SortStack::push(int value){
    one.push(value);
    this->sort();
}

void SortStack::pop(){
    if(!one.empty()){
        one.pop();
    }
}

int SortStack::top(){
    return (!one.empty()) ? one.top() : -999;
}

void SortStack::sort(){

    // insertion sort
    // with new item old stack is already sorted
    if(one.size()==1) return;

    int newValue = one.top();
    one.pop();
    while(!one.empty() && one.top()>newValue){
        two.push(one.top());
        one.pop();
    }
    one.push(newValue);
    while(!two.empty()){
        one.push(two.top());
        two.pop();
    }
    
}


int main(){

    SortStack  ss;

    ss.push(5);
    ss.push(2);
    ss.push(4);
    ss.push(1);
    ss.push(3);
    cout << ss.top() << endl;
    ss.pop();
    cout << ss.top() << endl;
    ss.pop();
    cout << ss.top() << endl;
    ss.pop();
    cout << ss.top() << endl;
    ss.pop();
    cout << ss.top() << endl;
    ss.pop();
    
    return 0;
}