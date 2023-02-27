/*
Given the head of a singly linked list, reverse the list, and return the reversed list.

Example 1:
Input: head = [1,2,3,4,5]
Output: [5,4,3,2,1]

Example 2:
Input: head = [1,2]
Output: [2,1]

Example 3:
Input: head = []
Output: []

Runtime 5ms
Memory 8.6MB

*/

class Solution {

    ListNode* reversell(ListNode* &head){

        // Base case
        if(head == NULL || head->next == NULL){
            return head;
        }

        ListNode* newhead = reversell(head->next);
        head->next->next=head;
        head->next=NULL;
        return newhead;
    }


public:
    ListNode* reverseList(ListNode* head) {
        return reversell(head);
        
    }
};
