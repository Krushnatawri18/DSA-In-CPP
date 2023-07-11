/*
Given a singly linked list consisting of N nodes. The task is to remove duplicates (nodes with duplicate values) from the given list (if exists).
Note: Try not to use extra space. Expected time complexity is O(N). The nodes are arranged in a sorted way.

Example 1:
Input:
LinkedList: 2->2->4->5
Output: 2 4 5
Explanation: In the given linked list 2 ->2 -> 4-> 5, only 2 occurs more than 1 time.

Runtime - 100 ms

TC - O(N)
SC - O(1)
*/

Node *removeDuplicates(Node *head)
{
    if(head == NULL || head -> next == NULL)
    {
        return head;
    }
    
    Node *curr = head;
    Node *forward = head -> next;
    
    while(forward != NULL){
        
        if(curr -> data == forward -> data)
        {
            forward = forward -> next;
            curr -> next -> next = NULL;
            delete(curr -> next);
            curr -> next = forward;
            
        }
        
        else
        {
            curr = forward;
            forward = forward -> next;
        }
    }
    return head;
}
