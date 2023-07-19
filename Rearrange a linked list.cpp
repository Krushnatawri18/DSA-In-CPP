/*
Given a singly linked list, the task is to rearrange it in a way that all odd position nodes are together and all even positions node are together.
Assume the first element to be at position 1 followed by second element at position 2 and so on.

Example 1:
Input:
LinkedList: 1->2->3->4
Output: 1 3 2 4 
Explanation: Odd elements are 1, 3 and even elements are 2, 4. Hence, resultant linked list is 1->3->2->4.
  
Example 2:
Input:
LinkedList: 1->2->3->4->5
Output: 1 3 5 2 4 
Explanation: Odd elements are 1, 3, 5 and even elements are 2, 4. Hence, resultant linked list is 1->3->5->2->4.

Runtime - 140 ms

TC - O(N)
SC - O(1)
*/

class Solution
{
    public:
    void rearrangeEvenOdd(Node *head)
    {
        // if linked list is empty
        if(head == NULL){
            return;
        }
        
        Node *odd = head;
        Node *even = head -> next;
        // holding first even head node
        Node *firstEven = head -> next;
        
        while(1){
            
            // if even or its next reached to NULL  
            if(even == NULL || even -> next == NULL){
                // adding even linked list head to odd linked list
                odd -> next = firstEven;
                return;
            }
            
            // now just connect odd node to next of even node
            odd -> next = even -> next;
            odd = even -> next;
            
            // now just connect even node to next of odd node
            even -> next = odd -> next;
            even = odd -> next;
        }
    }
};
