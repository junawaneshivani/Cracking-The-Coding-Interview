/*
Stack of Plates: Imagine a (literal) stack of plates. If the stack gets too high, 
it might topple. Therefore, in real life, we would likely start a new stack when 
the previous stack exceeds some threshold. Implement a data structure SetOfStacks 
that mimics this. SetO-fStacks should be composed of several stacks and should 
create a new stack once the previous one exceeds capacity.  push() and  pop() 
should behave identically to a single stack  (that is, pop () should return 
the same values as it would if there were just a single stack).
FOLLOW UP
Implement a function popAt ( int index) which performs a pop operation on a 
specific sub-stack.
*/

// typically ask followup questions to the interviewer
// - will the user specify stack number for pop() operation ?
// - will the previous stack activate as soon as currect stack is empty() ?


#include <iostream>
#include <stack>
#include <vector>
using namespace std;


class StackOfPlates{
    vector<stack<int> > stacks;
    int threshold;
public:
    StackOfPlates(int threshold): threshold(threshold){}

    bool isEmpty();
    bool isFull();

    void push(int value);
    void pop();
    int top();

    ~StackOfPlates(){}
};


bool StackOfPlates::isEmpty() {
    int stackNumber = stacks.size()-1;
    if (stackNumber==-1) return true;
    return stacks[stackNumber].empty() ? true : false;
}

bool StackOfPlates::isFull(){
    int stackNumber = stacks.size()-1;
    if (stackNumber==-1) return true;
    return stacks[stackNumber].size() == threshold ? true : false;
}

void StackOfPlates::push(int value){
    if (isFull()){
        stack<int> s;
        s.push(value);
        stacks.push_back(s);
    }else{
        int stackNumber = stacks.size()-1;
        stacks[stackNumber].push(value);
    }
    int stackNumber = stacks.size()-1;
    cout << top() << endl;
}

void StackOfPlates::pop(){
    if(isEmpty()){
        if(stacks.size()>0) // http://www.cplusplus.com/reference/vector/vector/pop_back/
            stacks.pop_back();
        else{
            cout << top() << endl;
            return;
        }
    }
    int stackNumber = stacks.size()-1;
    stacks[stackNumber].pop();
    cout << top() << endl;
}

int StackOfPlates::top(){
    int stackNumber = stacks.size()-1;
    if (!isEmpty()){
        return stacks[stackNumber].top();
    }else{ //empty
        if (stackNumber>=0)
            stacks.pop_back();
        --stackNumber;
        return (stackNumber>-1) ? stacks[stackNumber].top() : -999;
    }
}


int main() {

    StackOfPlates sop(2);
    sop.push(1);
    sop.push(2);
    sop.push(3);
    cout << " ------- " << endl;
    sop.pop();
    sop.pop();
    sop.pop();
    sop.pop();
    
    return 0;
}