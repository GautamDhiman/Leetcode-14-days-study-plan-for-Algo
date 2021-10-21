/*
Merge two sorted linked lists and return it as a sorted list. The list should be made by splicing together the nodes of the first two lists.

 

Example 1:


Input: l1 = [1,2,4], l2 = [1,3,4]
Output: [1,1,2,3,4,4]
Example 2:

Input: l1 = [], l2 = []
Output: []
Example 3:

Input: l1 = [], l2 = [0]
Output: [0]

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
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        
        ListNode *P1 = l1, *P2 = l2;
        ListNode* head = NULL;
        ListNode* ptr = head;
        
        
        if(l1 == NULL)
        {
            return l2;
        }
        else if(l2 == NULL)
        {
            return l1;
        }
        
        while(P1 != NULL && P2 != NULL)
        {
            if(P1->val <= P2->val)
            {
                if(head == NULL)
                {
                    head = P1;
                    P1 = P1->next;
                    ptr = head;
                }
                else
                {
                    ptr->next = P1;
                    P1 = P1->next;
                    ptr = ptr->next;
                }
            }
            
            else if(P1->val > P2->val)
            {
                if(head == NULL)
                {
                    head = P2;
                    P2 = P2->next;
                    ptr = head;
                }
                else
                {
                    ptr->next = P2;
                    P2 = P2->next;
                    ptr = ptr->next;
                }
            }
            
        }
        
        if(P1 == NULL)
        {
            ptr->next = P2;
        }
        else
        {
            ptr->next = P1;
        }
        
        return head;
        
    }
};