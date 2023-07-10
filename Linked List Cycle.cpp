/*
Given head, the head of a linked list, determine if the linked list has a cycle in it.

There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to. Note that pos is not passed as a parameter.

Return true if there is a cycle in the linked list. Otherwise, return false.

Runtime - 11 ms
Memory - 7.9 MB
  
TC - O(N)
SC - O(1)
*/

class Solution {
public:
    bool hasCycle(ListNode *head) {

        if(head == NULL)
        {
            return false;
        }

        ListNode *slow = head;
        ListNode *fast = head -> next;


        while (fast != NULL)
        {
            fast = fast -> next;
            
            if(fast != NULL)
            {
                fast = fast -> next;
            }
            slow = slow -> next;

            if(slow == fast)
            {
                return true;
                break;
            }
        }
    return false;
    }
};
