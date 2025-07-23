class Solution {
public:
    int maximumGain(string s, int x, int y) {
        stack<char> st;
        int ans = 0;

        // Helper function to calculate points by removing a specific pattern
        auto removePattern = [&](char first, char second, int points) {
            stack<char> temp;
            while (!st.empty()) {
                char ch = st.top();
                st.pop();
                if (!temp.empty() && temp.top() == first && ch == second) {
                    ans += points;
                    temp.pop();
                } else {
                    temp.push(ch);
                }
            }
            swap(st, temp);
        };

        if (x > y) {
            // First remove "ab" pairs
            for (char ch : s) {
                if (ch == 'b' && !st.empty() && st.top() == 'a') {
                    ans += x;
                    st.pop();
                } else {
                    st.push(ch);
                }
            }
            // Then remove "ba" pairs
            removePattern('a', 'b', y);
        } else {
            // First remove "ba" pairs
            for (char ch : s) {
                if (ch == 'a' && !st.empty() && st.top() == 'b') {
                    ans += y;
                    st.pop();
                } else {
                    st.push(ch);
                }
            }
            // Then remove "ab" pairs
            removePattern('b', 'a', x);
        }

        return ans;
    }

};

// if x > y ---> remove all 'ab' first
// if y > x ---> remove all 'ba' first