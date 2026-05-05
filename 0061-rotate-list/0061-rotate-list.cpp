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
    ListNode* reverse(ListNode* head)
    {
        ListNode* prev = NULL;
        ListNode* curr = head;

        while(curr != NULL)
        {
            ListNode* forw = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forw;
        }

        return prev;
    }
    
    ListNode* rotateRightHelper(ListNode* head, int k, int len) {
        
        if(head == NULL || k == 0 || head->next == NULL)
        {
            return head;
        }
        
        if(len == k)
            return reverse(head);
        
        int x = len-k-1;
        ListNode* temp = head;
        
        while(x--)
        {
            temp = temp->next;
        }
        
        ListNode* newHead = temp->next;
        temp->next = NULL;
        
        ListNode* temp1 = newHead;
        while(temp1->next != NULL)
            temp1 = temp1->next;
        
        temp1->next = head;
        return newHead;
    }
    
    ListNode* rotateRight(ListNode* head, int k)
    {
        int n = 0;
        ListNode* temp = head;
        while(temp != NULL)
        {
            n++;
            temp = temp->next;
        }
        
        if(n == 0)
            return head;
        
        return rotateRightHelper(head, k%n, n);
    }
    
};