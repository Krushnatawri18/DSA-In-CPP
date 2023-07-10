/*
Given the head of a linked list, return the node where the cycle begins. If there is no cycle, return null.

There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. 
Internally, pos is used to denote the index of the node that tail's next pointer is connected to (0-indexed). 
It is -1 if there is no cycle. Note that pos is not passed as a parameter.

Do not modify the linked list.

Runtime - 12 ms
Memory - 7.8 MB

TC - O(N)
SC - O(1)
*/

class Solution {
public:
    ListNode *isCycle(ListNode *head) {

        if(head == NULL)
            return NULL;

        ListNode* slow = head;
        ListNode* fast = head;

        while(slow != NULL && fast !=NULL) 
        {
            
            fast = fast -> next;
            if(fast != NULL) 
            {
                fast = fast -> next;
            }

            slow = slow -> next;

            if(slow == fast) 
            {
                return slow;
            }
        }
    return NULL;
    }

    ListNode *detectCycle(ListNode *head) {

        if(head == NULL)
        {
            return NULL;
        }
        ListNode *intersection = isCycle(head);

        if(intersection == NULL)
        {
            return NULL;
        }

        ListNode *slow = head;

        while (slow != intersection)
        {
            slow = slow -> next;
            intersection = intersection -> next;
        }

        return slow;
    
    }
};
