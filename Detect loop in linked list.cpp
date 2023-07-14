/*
Given a linked list of N nodes. The task is to check if the linked list has a loop. Linked list can contain self loop.

Example 1:
Input:
N = 3
value[] = {1,3,4}
x(position at which tail is connected) = 2
Output: True

Runtime - 130 ms

TC - O(N)
SC - O(1)
*/

class Solution
{
    public:
    //Function to check if the linked list has a loop.
    bool detectLoop(Node* head)
    {
        if(head == NULL || head -> next == NULL){
            return false;
        }
        
        Node *slow = head;
        Node *fast = head -> next;
        
        while(fast != NULL && fast -> next != NULL){
            fast = fast -> next -> next;
            slow = slow -> next;
            
            if(slow == fast){
                return true;
            }
        }
        return false;
    }
};
