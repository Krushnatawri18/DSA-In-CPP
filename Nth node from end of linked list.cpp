/*
Given a linked list consisting of L nodes and given a number N. The task is to find the Nth node from the end of the linked list.

Example 1:
Input:
N = 2
LinkedList: 1->2->3->4->5->6->7->8->9
Output: 8

Example 2:
Input:
N = 5
LinkedList: 10->5->100->5
Output: -1

Runtime - 590 ms

TC - O(N)
SC - O(1)
*/

class Solution{
public:
    int getNthFromLast(Node *head, int n)
    {
        if(head == NULL){
            return -1;
        }
        
        int len = 0;
        Node *temp = head;
        // traversing whole linked list to get the length of linked list
        while(temp != NULL){
            temp = temp -> next;
            len++;
        }
        
        // if n is greater than len then return -1
        if(n > len){
            return -1;
        }
        
        temp = head;
        for(int i = 1; i < len - n + 1; i++){
            temp = temp -> next;
        }
        
    return temp -> data;   
    }
};
