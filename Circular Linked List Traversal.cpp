/*
Given a circular linked list, your task is to complete the method printList() that prints the linked list.

Input:
The printList function takes a single argument as input the reference pointer to the head of the linked list.
There are multiple test cases and for each test, the function will be called separately. 

Runtime - 100 ms

TC - O(N)
SC - O(1)
*/

void printList(struct Node *head)
{
  Node *temp = head;
  
  do
  {
    cout << temp -> data<<" ";  
    temp = temp -> next;
  }while(temp != head);
  
}
