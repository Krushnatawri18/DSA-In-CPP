/*
Given a linked list of size N. The task is to reverse every k nodes (where k is an input to the function) in the linked list. If the number of nodes is not a multiple of k then left-out nodes, in the end, should be considered as a group and must be reversed (See Example 2 for clarification).

Example 1:

Input:
LinkedList: 1->2->2->4->5->6->7->8
K = 4
Output: 4 2 2 1 8 7 6 5 
Explanation: 
The first 4 elements 1,2,2,4 are reversed first and then the next 4 elements 5,6,7,8. Hence, the resultant linked list is 4->2->2->1->8->7->6->5.

Runtime - 6 ms

TC - O(N)
SC - O(N)
*/

class Solution
{
    public:
    struct node *reverse (struct node *head, int k)
    { 
        //base case
        if(head == NULL) 
        {
            return NULL;
        }
        
        // reversing first k nodes iteratively
        node* next = NULL;
        node* curr = head;
        node* prev = NULL;
        int count= 0;
        
        while( curr != NULL && count < k ) 
        {
            next = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = next;
            count++;
        }
        
        // calling reverse function recursively
        if(next != NULL) 
        {
            head -> next = reverse(next,k);
        }
        
        // returning the head of reversed linked list
        return prev;
        
    }
};
