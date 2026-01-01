class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        vector<int> ans;
        int carry = 1;

        for(int i = n-1; i >= 0; i--) {
            int sum = digits[i] + carry;
            
            if(sum > 9) {
                carry = 1;
                ans.push_back(0);
            }
            else {
                ans.push_back(sum);
                carry = 0;
            }
            
        }

        if(carry > 0) ans.push_back(carry);

        reverse(ans.begin(), ans.end());

        return ans;
    }
};

// 9 9 9 
//     1
// carry digit 
