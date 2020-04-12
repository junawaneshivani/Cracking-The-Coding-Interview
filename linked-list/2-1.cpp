/*
Remove Dups! Write code to remove duplicates from an unsorted linked list.
FOLLOW UP
How would you solve this problem if a temporary buffer is not allowed?
Hints: #9, #40
*/

// Time complexity - N
// Space complexity - N ( temporary bufer - hashmap)
// We can use 2 pointers to run the code in O(1) space 
// but it will need O(N*N) time.

#include <iostream>
#include "linked_list.cpp"
#include <unordered_map>
using namespace std;


class MySLL: public SLL {
public:
    void removeDuplicates(){
        unordered_map<int, bool> m;
        SLLNode* curr = head;
        SLLNode* prev = head;
        while(curr->next!=NULL){
            if (m.find(curr->value) == m.end()){
                m[curr->value] = true;
                prev = curr;
                curr = curr->next;
            }else{
                prev->next = curr->next;
                delete curr;
                curr = prev->next;
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

    ll.removeDuplicates();
    ll.printList();

    return 0;
}