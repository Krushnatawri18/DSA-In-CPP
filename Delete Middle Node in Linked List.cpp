/*
You are given the head of a linked list. Delete the middle node, and return the head of the modified linked list.

The middle node of a linked list of size n is the ⌊n / 2⌋th node from the start using 0-based indexing, where ⌊x⌋ denotes the largest integer less than or equal to x.

For n = 1, 2, 3, 4, and 5, the middle nodes are 0, 1, 1, 2, and 2, respectively.

Runtime - 1058 ms

TC - O(N)
SC - O(1)
*/

class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if(head == NULL){
        return NULL;
    }
    
    if(head -> next == NULL){
        delete(head);
        return NULL;
    }

    ListNode *slow = head;
    ListNode *fast = head;
    ListNode *temp;
    
    while(fast != NULL && fast -> next != NULL){
        fast = fast -> next -> next;  
        temp = slow;
        slow = slow -> next;
    }

    temp -> next = slow -> next;
    delete(slow);
    return head;
    }
};
