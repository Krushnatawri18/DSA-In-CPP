/*
Given the head of a singly linked list, reverse the list, and return the reversed list.

Example 1:
Input: head = [1,2,3,4,5]
Output: [5,4,3,2,1]

Example 2:
Input: head = [1,2]
Output: [2,1]

Example 3:
Input: head = []
Output: []

*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

/*

Recursion :-
Runtime - 7 ms
Memory - 8.5 MB

TC - O(N)
SC - O(N)

*/

// Approach 1
class Solution {
    private:
    void reversell(ListNode* &head, ListNode * curr, ListNode * prev){

        // Base case
        if(curr == NULL){
            head = prev;
            return;
        }
        
        // recursively
        // just pointing to next of curr so that it can't be lost and 
        ListNode * forword = curr -> next;
        // telling reversell() to reverse all the nodes 
        reversell(head, forword, curr);
        // now solving one case that is connecting first node to NULL
        curr -> next = prev;

    }


public:
    ListNode* reverseList(ListNode* head) {

        ListNode * curr = head;
        ListNode * prev = NULL;
        reversell(head, curr, prev);
        return head;
      
    }
};

/*

Iteration :-
Runtime - 5 ms
Memory - 8.6 MB

TC - O(N)
SC - O(1)

*/

// Approach 2
class Solution {
public:
    
    ListNode* reverseList(ListNode* head) {
        // iteratively 
        if(head == NULL || head->next == NULL)
        {
            return head;
        }

        ListNode * prev = NULL;
        ListNode * curr = head;
        ListNode * forword = NULL;

        while(curr != NULL)
        {
            forword = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = forword;
        }

        return prev;
    }
}
