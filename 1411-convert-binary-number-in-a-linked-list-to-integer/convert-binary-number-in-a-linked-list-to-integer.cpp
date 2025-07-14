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
    int getDecimalValue(ListNode* head) {
        ListNode* temp = head;
        string str = "";
        int ans = 0;

        while(temp != NULL) {
            str += to_string(temp->val);
            temp = temp->next;
        }

        reverse(str.begin(), str.end());
        cout << str;
        
        for(int i = 0; i < str.length(); i++) {
            if(str[i] == '1')
            ans += pow(2, i);
        }

        return ans;
    }
};