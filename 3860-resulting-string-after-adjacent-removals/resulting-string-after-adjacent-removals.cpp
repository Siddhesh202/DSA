class Solution {
public:
    string resultingString(string s) {
        stack<char> st;
        string ans;
        for(auto &ch : s) {
            if(!st.empty() && (abs(st.top()-ch) == 1 || abs(st.top()-ch) == 25)) {
                st.pop();
            }
            else {
                st.push(ch);
            }
        }

        while(!st.empty()) {
            ans += st.top();
            st.pop();
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};