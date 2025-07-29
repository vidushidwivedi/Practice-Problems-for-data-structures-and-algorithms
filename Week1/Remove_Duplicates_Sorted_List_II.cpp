#include <bits/stdc++.h>
using namespace std;

struct ListNode{
    int val;
    ListNode * next;
    ListNode(): val(0), next(nullptr) {}
    ListNode(int x): val(x), next(nullptr) {}
    ListNode(int x, ListNode *next): val(x), next(next) {}
};

class Solution {
    public:
        ListNode* deleteDuplicates(ListNode* head){
            ListNode* dummy= new ListNode (0, head);
            ListNode* prev= dummy;
            while (head && head->next){//always check the current node and the next node
                if (head-> val== head->next-> val){
                    while (head-> val== head-> next-> val){ //skip all the duplicates
                        head= head-> next;//skip the duplicates
                    }
                    prev->next= head->next;
                    head= head->next;

                }
                else{
                    prev= prev->next; //move the prev pointer
                    head= head->next; //move the head pointer
                }

            }
            return dummy->next; //return the next of dummy node
        }
};
