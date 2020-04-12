/*
Delete Middle Node: Implement an algorithm to delete a node in the middle (i.e., any node but
the first and last node, not necessarily the exact middle) of a singly linked list, given only 
access to that node.

EXAMPLE
lnput:the node c from the linked lista->b->c->d->e->f
Result: nothing is returned, but the new linked list looks like a->b->d->e->f
Hints:#72
*/

#include <iostream>
#include "linked_list.cpp"
using namespace std;


class MySLL: public SLL {
public:
    
    void deleteMiddleNode(SLLNode* node){

        node->value = node->next->value;
        SLLNode* delNode = node->next;
        node->next = delNode->next;
        delete delNode;

    }

    SLLNode* getNode( int value){
        SLLNode* curr = head;
        while(curr->next!=NULL){
            if (curr->value == value)
                return curr;
            curr = curr->next;
        }
        return NULL;
    }
 
};


int main(){
    
    MySLL ll;
    ll.insertNode(1);
    ll.insertNode(32);
    ll.insertNode(-4);
    ll.insertNode(12);
    ll.insertNode(1);
    ll.insertNode(-4);

    ll.printList();
    SLLNode* node = ll.getNode(-4);
    if (node!=NULL)
        ll.deleteMiddleNode(node);
    else
        cout << " No such node found." << endl;
    ll.printList();

    return 0;
}