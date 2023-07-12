/*
Given a singly linked list of size N of integers. The task is to check if the given linked list is palindrome or not.

Example 1:
Input:
N = 3
value[] = {1,2,1}
Output: 1
Explanation: The given linked list is 1 2 1 , which is a palindrome and Hence, the output is 1.
  
Example 2:
Input:
N = 4
value[] = {1,2,3,4}
Output: 0
Explanation: The given linked list is 1 2 3 4 , which is not a palindrome and Hence, the output is 0.

Runtime - 40 ms

TC - O(N)
SC- O(1)
*/

class Solution{
  private:
  
    Node* getMid(Node* head ) 
    {
        Node* slow = head;
        Node* fast = head -> next;
        
        while(fast != NULL && fast-> next != NULL) 
        {
            fast = fast -> next -> next;
            slow = slow -> next;
        }
        return slow;
    }
    
    Node* reverse(Node* head) 
    {
        Node* curr = head;
        Node* prev = NULL;
        Node* next = NULL;
        
        while(curr != NULL) 
        {
            next = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    
  public:

    bool isPalindrome(Node *head)
    {
        if(head -> next == NULL) 
        {
            return true;
        }
        
        // finding middle node of linked list
        Node* middle = getMid(head);
        
        // reversing linked list ahead of middle node
        Node* temp = middle -> next;
        middle -> next = reverse(temp);
        
        // comparing both the linked lists
        Node* head1 = head;
        Node* head2 = middle -> next;
        
        while(head2 != NULL) 
        {
            if(head2->data != head1->data) 
            {
                return 0;
            }
            head1 = head1 -> next;
            head2 = head2 -> next;
        }
        // reversing again linked list
        temp = middle -> next;
        middle -> next = reverse(temp);
        return true;
    }
};
