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
    int pairSum(ListNode* head) {
        ListNode* temp = head;
        int n = 0, ans = INT_MIN;

        while(temp != NULL) {
            n++;
            temp = temp->next;
        } 

        int firstHalf = (n/2) - 1;
        stack<int> st;
        temp = head;

        for(int i = 0; i <= firstHalf; i++) {
            st.push(temp->val);
            temp = temp->next;
        }

        while(temp != NULL) {
            int val = st.top();
            st.pop();
            ans = max(ans, val + temp->val);
            temp = temp->next;
        }

        return ans;
    }
};