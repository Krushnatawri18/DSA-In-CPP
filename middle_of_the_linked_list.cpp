/*
Given the head of a singly linked list, return the middle node of the linked list.

If there are two middle nodes, return the second middle node.

Example 1:
Input: head = [1,2,3,4,5]
Output: [3,4,5]
Explanation: The middle node of the list is node 3.
  
Example 2:
Input: head = [1,2,3,4,5,6]
Output: [4,5,6]
Explanation: Since the list has two middle nodes with values 3 and 4, we return the second one.

Runtime 2ms
Memory 7.1MB
*/ 
  
class Solution {
public:

//     int getLength(ListNode* head){
//         int len=0;
//         while(head != NULL){
//             len++;
//             head=head->next;
//         }
//         return len;
//     }

    ListNode* middleNode(ListNode* head) {
        
        // int len = getLength(head);
        // int ans = len/2;

        // int cnt = 0;
        // ListNode* temp = head;

        // while(cnt < ans){
        //     temp = temp -> next;
        //     cnt++;

        // }

        // return temp;


        if(head==NULL || head->next==NULL){
            return head;
        }

        else if(head->next->next == NULL){
            return head->next;
        }

        ListNode* pro=head->next;    // pro take 2 steps at a time
        ListNode* noob=head;         // noob takes 1 step at a time

        while(pro != NULL){
            pro=pro->next;
            if(pro != NULL){
                pro=pro->next;
            }
            noob=noob->next;
        }
    return noob;
        
    }
};
