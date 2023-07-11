/*
Given a linked list of N nodes where nodes can contain values 0s, 1s, and 2s only. 
The task is to segregate 0s, 1s, and 2s linked list such that all zeros segregate to head side, 2s at the end of the linked list, and 1s in the mid of 0s and 2s.

Example 1:
Input:
N = 8
value[] = {1,2,2,1,2,0,2,2}
Output: 0 1 1 2 2 2 2 2
Explanation: All the 0s are segregated to the left end of the linked list, 2s to the right end of the list, and 1s in between.

Runtime - 110 ms

TC - O(N)
SC - O(N)
*/

class Solution
{
    public:
    Node* segregate(Node *head) {
        Node * temp = head;
        int zeroCount = 0;
        int oneCount = 0;
        int twoCount = 0;
        
        while (temp != NULL){
            
            if(temp -> data == 0){
                zeroCount++;
            }
            
            else if(temp -> data == 1){
                oneCount++;
            }
            
            else if(temp -> data == 2){
                twoCount++;
            }
            temp = temp -> next;
        }
        
        temp = head;
        while(temp != NULL){
            
            if(zeroCount != 0){
                temp -> data = 0;
                zeroCount--;
            }
            
            else if(oneCount != 0){
                temp -> data = 1;
                oneCount--;
            }
            
            else if(twoCount != 0){
                temp -> data = 2;
                twoCount--;
            } 
            temp = temp ->next;
        }
    return head;
    }
};

/*
TC - O(N)
SC - O(N)
*/

class Solution
{
    public:
    
    void insertAtTail(Node* &tail, Node* curr ) {
    tail -> next = curr;
    tail = curr;
    }

Node* segregate(Node *head) {

    Node* zeroHead = new Node(-1);
    Node* zeroTail = zeroHead;
    Node* oneHead = new Node(-1);
    Node* oneTail = oneHead;
    Node* twoHead = new Node(-1);
    Node* twoTail = twoHead;
    
    Node* curr = head;
    
    // creating separate linked list for 0,1 and 2
    while(curr != NULL) {
        
        int value = curr -> data;
        
        if(value == 0) {
            insertAtTail(zeroTail, curr);
        }
        else if(value == 1) {
            insertAtTail(oneTail, curr);
        }
        else if(value == 2) {
            insertAtTail(twoTail, curr);
        }       
        curr = curr -> next;
    }
    
    //merge 3 sublist
    
    // if 1s list is empty
    if(oneHead -> next != NULL) {
        zeroTail -> next = oneHead -> next;
    }
    else {
        zeroTail -> next = twoHead -> next;
    }
    
    oneTail -> next = twoHead -> next;
    twoTail -> next = NULL;

	// setting new head
    head = zeroHead -> next;
    
    // deleting dummy nodes
    delete zeroHead;
    delete oneHead;
    delete twoHead;
    
    return head;
    
    }
};
