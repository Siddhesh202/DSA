class Solution {
public:
    string addBinary(string a, string b) {
        string ans = "";
        int carry = 0, i = a.length()-1, j = b.length()-1;

        while(i >= 0 || j >= 0) {
            int num1 = (i >= 0) ? a[i]-'0' : 0;
            int num2 = (j >= 0) ? b[j]-'0' : 0;

            int sum = carry + num1 + num2;
            carry = (sum > 1) ? 1 : 0;
            ans.push_back((sum % 2 == 0) ? '0' : '1');
            i--;
            j--;
        }

        if(carry > 0) ans.push_back('1');
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};