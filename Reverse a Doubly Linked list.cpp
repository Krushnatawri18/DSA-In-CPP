/*
Given a doubly linked list of n elements. The task is to reverse the doubly linked list.

Example 1:
Input:
LinkedList: 3 <--> 4 <--> 5
Output: 5 4 3
  
Example 2:
Input:
LinkedList: 75 <--> 122 <--> 59 <--> 196
Output: 196 59 122 75

Runtime - 100 ms

TC - O(N)
SC - O(1)
*/

Node* reverseDLL(Node * head)
{
    if(head == NULL || head -> next == NULL){
        return head;
    }
    
    Node *curr = head;
    Node *temp = NULL;
    
    while(curr != NULL){
        temp = curr -> prev;
        curr -> prev = curr -> next;
        curr -> next = temp;
        curr = curr -> prev;
    }
  
    // temp is on last second node of reverse list 
    if(temp -> prev != NULL){
        head = temp -> prev;
        temp = temp -> prev;
    }
    return head;
}
