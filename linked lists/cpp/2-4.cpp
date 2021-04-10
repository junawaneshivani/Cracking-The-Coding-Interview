/*
Partition: 
Write code to partition a linked list around a value x, such that all nodes 
less than x come before all nodes greater than or equal to x. If x is 
contained within the list, the values of x only need to be after the 
elements less than x (see below). The partition element x can appear 
anywhere in the "right partition"; it does not need to appear between the 
left and right partitions.

EXAMPLE
Input: 
3 -> 5 -> 8 -> 5 -> 10 -> 2 -> 1 [partition= 5]
Output:
3 -> 1 -> 2 -> 10 -> 5 -> 5 -> 8
Hints: #3, #24
*/

// 3 -> 5 -> 8 -> 5 -> 10 -> 2 -> 1
// 3 -> 2 -> 8 -> 5 -> 10 -> 5 -> 1
// 3 -> 5 -> 1 -> 5 -> 10 -> 2 -> 8

#include <iostream>
#include "linked_list.cpp"
using namespace std;


class MySLL: public SLL {
public:

    void partitionList(int partition){
        SLLNode* p1 = head;
        SLLNode* p2 = NULL;
        
        while(true) {
            //this->printList();
            while(p1!=NULL && p1->value < partition)
                p1 = p1->next;
            
            if (p1!=NULL) {
                
                if (p2==NULL) p2 = p1; // for first assignment of p2

                while(p2!=NULL && p2->value >= partition)
                    p2 = p2->next;

                if(p2!=NULL){ // swap
                    int temp = p2->value;
                    p2->value = p1->value;
                    p1->value = temp; 
                }else
                {
                    break;
                }
                
            }
        }
        


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
    ll.partitionList(5);
    ll.printList();

    return 0;
}