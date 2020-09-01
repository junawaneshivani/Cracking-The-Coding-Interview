/*

Three in One: 
Describe how you could use a single array to implement three stacks.

*/


#include <iostream>
using namespace std;

class Stack {
    int arr[15] = {0};
    int indent = 5;
    int top[3] = {-1, 4, 9};

    bool checkStack(int stack){
        return (stack>=0 && stack<=2) ? true : false;
    }
public:
    Stack(){};

    void push(int item, int stack);
    void pop(int stack);
    int peek(int stack);
    bool isEmpty(int stack);
    bool isFull(int stack);

    void printAllStacks();

    ~Stack(){};
};


bool Stack::isFull(int stack){

    if (!checkStack(stack)){
        cout << endl << "Stack number invalid";
        return false;
    }

    //cout << top[0] << " " << top[1] << " " << top[2] << endl;
    return (top[stack]!=(stack+1)*5-1) ? false : true;
}

bool Stack::isEmpty(int stack){

    if (!checkStack(stack)){
        cout << endl << "Stack number invalid";
        return false;
    }

    return (top[stack]!=(stack*5)-1) ? false : true;
}

void Stack::push(int item, int stack){

    if (!checkStack(stack)){
        cout << endl << "Stack number invalid";
        return;
    }    

    if (this->isFull(stack)){
        cout << endl << "Stack is full.";
        return;
    }

    top[stack]++;
    arr[top[stack]] = item;
}

void Stack::pop(int stack){

    if (!checkStack(stack)){
        cout << endl << "Stack number invalid";
        return;
    }    

    if (this->isEmpty(stack)){
        cout << endl << "Stack is empty.";
        return;
    }

    top[stack]--;
}

int Stack::peek(int stack){
 
    if (!checkStack(stack)){
        cout << endl << "Stack number invalid";
        return -999;
    }    

    if (this->isEmpty(stack)){
        cout << endl << "Stack is empty.";
        return -999;
    }

    return top[stack];
}

void Stack::printAllStacks(){
    cout << endl;
    for(auto a:this->arr)
        cout << a << " | ";
    cout << endl;
}


int main(){

    Stack s;
    s.push(1, 0);
    s.push(1, 0);
    s.push(2, 2);
    s.push(2, 2);
    s.push(2, 2);
    s.push(2, 2);
    s.push(2, 2);
    s.push(2, 2);
    s.pop(2);
    s.push(2, 2);    
    s.push(3, 1);


    s.printAllStacks();


    return 0;
}
