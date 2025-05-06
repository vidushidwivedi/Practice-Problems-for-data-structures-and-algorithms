//Problem: 83 Remove Duplicates from Sorted List
// Link: https://leetcode.com/problems/remove-duplicates-from-sorted-list/description/
#include <vector>  // Required for std::vector
#include <unordered_map>  // Required for std::unordered_map
#include <iostream>  // Required for std::cout and std::endl

 //Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 

class Solution {
    public:
        ListNode* deleteDuplicates(ListNode* head) {
            ListNode* res= head;
            while (head && head->next ){
                if(head->val == head->next->val){
                    head->next= head->next->next;
                }else{
                    head= head->next;
                }
            }
            return res;
        }
    };