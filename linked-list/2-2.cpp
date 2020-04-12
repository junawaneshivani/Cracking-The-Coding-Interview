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
#include <string>
using namespace std;

/*
Return Kth to Last: Implement an algorithm to find the kth to last element of a singly linked list.
Hints:#8, #25, #41, #67, #126
*/

// O(N) time 
// O(N) space

// ask the interviewer
// do we already know the size of the list ?

//  recursive solution
//  int printKthToLast(LinkedlistNode curr, int k) {
//      if (curr == null) {
//          return 0;
//      }
//      int index = printKthToLast(curr->next, k) + 1;
//      if (index == k) {
//          cout << k << "th to last node is " << curr->value;
//      }
//      return index;
//  }

class MySLL: public SLL {
public:
    int kFromLast(int k){

        SLLNode* curr = head;
        string s = "";
        while(curr!=NULL){
            s += to_string(curr->value);
            curr = curr->next;
        }
        while(--k){
            s.pop_back();
        }
        return int(s[s.size()-1]) - 48;
    }
};


int main(){
    
    MySLL ll;
    ll.insertNode(1);
    ll.insertNode(2);
    ll.insertNode(3);
    ll.insertNode(4);
    ll.insertNode(5);
    ll.insertNode(6);

    cout << "3rd element from last is " << ll.kFromLast(3) << endl;
    ll.printList();

    return 0;
}