class Solution {
public:
    bool hasSameDigits(string s) {
        string ans = s;

        while(ans.length() > 2) {
            string temp;
            
            for(int i = 0; i < ans.length()-1; i++) {
                int a = ans[i] - '0';
                int b = ans[i+1] - '0';
                temp += ((a + b) % 10) + '0';
            }

            // cout << temp << endl;
            ans = temp;
        }

        return ans[0] == ans[1];
    }
}; 