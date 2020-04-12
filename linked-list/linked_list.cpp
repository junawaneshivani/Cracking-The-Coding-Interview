/*
Remove Dups! Write code to remove duplicates from an unsorted linked list.
FOLLOW UP
How would you solve this problem if a temporary buffer is not allowed?
*/


#include <iostream>
#include <cstdlib>
using namespace std;

class SLLNode {
public:
    int value;
    SLLNode *next = NULL;
};

class DLLNode {
public:
    int value;
    DLLNode *next = NULL, *prev = NULL;
};

class SLL {
protected:
    SLLNode * head;
public:
    SLL(){
        this->head = NULL;
    }

    void insertNode(int value){
        if (head==NULL){
            head = new SLLNode();
            head->value = value;
            head->next = NULL;
        }else{
            SLLNode *current = head;
            while(current->next!=NULL){
                current = current->next;
            }
            current->next = new SLLNode();
            current->next->value = value;
        }
    }

    bool deleteNode(int value){
        if(head->value == value){
            SLLNode *del_node = head;
            head = head->next;
            delete del_node;
            return true;
        }else{
            SLLNode *current = head;
            while( current->next!=NULL && current->next->value!=value){
                current = current->next;
            }
            cout << current->value;
            if (current->next==NULL){
                return false;
            }
            if (current->next->value==value){
                SLLNode *del_node = current->next;
                current->next = current->next->next;
                delete del_node;
                return true;
            }
            return true;
        }
    }

    void printList(){

        SLLNode *current = head;
        while(current!=NULL){
            cout << current->value << " ";
            current = current->next;
        }
            
    }

};

/*
int main() {
    
    SLL sll;
    for (int i=0; i<10;i++)
        sll.insertNode(rand());
    sll.printList();
    int del_value;
    cout << endl << "Enter number to delete: ";
    cin >> del_value;
    if (sll.deleteNode(del_value))
        cout << endl << "Node deleted";
    else
        cout << endl << "Node not found";
    cout << endl;
    sll.printList();


    return 0;
}*/