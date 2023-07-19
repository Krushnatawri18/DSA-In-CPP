/*
Given two decimal numbers represented by two linked lists of size N and M respectively. The task is to return a linked list that represents the sum of these two numbers.

For example, the number 190 will be represented by the linked list, 1->9->0->null, similarly 25 by 2->5->null. Sum of these two numbers is 190 + 25 = 215, which will be represented by 2->1->5->null. You are required to return the head of the linked list 2->1->5->null.

Example 1:
Input:
N = 2
valueN[] = {4,5}
M = 3
valueM[] = {3,4,5}
Output: 3 9 0  
Explanation: For the given two linked list (4 5) and (3 4 5), after adding the two linked list resultant linked list will be (3 9 0).

Runtime - 70 ms

TC - O(M + N)
SC - O(MAX(M, N))
*/

class Solution
{
    public:
    
    void insertAtTail(struct Node* &head, struct Node* &tail, int value){
        Node* temp = new Node(value);
        // if linked list is empty
        if(head == NULL){
            head = temp;
            tail = temp;
        }
        
        // if linked list is not empty
        else{
            tail -> next = temp;
            tail = temp;
        }
    }
    
    struct Node* addLists(struct Node* &first, struct Node* &second){
        
        int carry = 0;
        struct Node* oneHead = NULL;
        struct Node* oneTail = NULL;
        
        while(first != NULL || second != NULL || carry != 0){
            
            int sum = 0;
            int val1 = 0;
            // if first linked list is not empty
            if(first != NULL){
                val1 = first -> data;
            }
            
            int val2 = 0;
            // if second linked list is not empty
            if(second != NULL){
                val2 = second -> data;
            }
            
            sum = val1 + val2 + carry;
            
            // taking last digit to put in linked list
            int digit = sum % 10;
            
            // inserting that digit in oneHead linked list
            insertAtTail(oneHead, oneTail, digit);
            
            // finding carry
            carry = sum / 10;
            
            // if first linked list is not empty
            if(first != NULL){
                first = first -> next;
            }
            
            // if second linked list is not empty
            if(second != NULL){
                second = second -> next;
            }
        }
    return oneHead;
    }
    
    struct Node* reverse(struct Node* head){
        
        if(head == NULL){
            return head;
        }
        
        Node* curr = head;
        Node* prev = NULL;
        Node* next = NULL;
        
        while(curr != NULL){
            next = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = next;
        }
    return prev;
    }
    
    //Function to add two numbers represented by linked list.
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        // reversing both the linked lists
        first = reverse(first);
        second = reverse(second);
        
        // returning ans linked list
        struct Node* ans = addLists(first, second);
        
        // reversing the ans linked list
        ans = reverse(ans);
        return ans;
    }
};
  
