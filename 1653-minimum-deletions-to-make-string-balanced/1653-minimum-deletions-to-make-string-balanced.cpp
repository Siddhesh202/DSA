class Solution {
public:
    // int minimumDeletions(string s) {
    //     stack<int> st;
    //     int count = 0;
    //     for(int i = 0; i < s.length(); i++) {
    //         if(!st.empty() && s[i] == 'a' && st.top() == 'b') {
    //             st.pop();
    //             count++;
    //         }else {
    //             st.push(s[i]);
    //         }
    //     }

    //     return count;
    // }

    int minimumDeletions(string s) {
        int n = s.length();
        vector<int> left_b(n), right_a(n);

        int count_a = 0, count_b = 0, mini = INT_MAX;
        // for(int i = 0; i < n; i++) {
        //     left_b[i] = count_b;
        //     if(s[i] == 'b') 
        //         count_b++;
        // }

        for(int i = n-1; i >= 0; i--) {
            right_a[i] = count_a;
            if(s[i] == 'a')
                count_a++;
        }

        for(int i = 0; i < n; i++) {
            left_b[i] = count_b;
            mini = min(mini, left_b[i] + right_a[i]);

            if(s[i] == 'b')
                count_b++;
        }

        return mini;
    }
};