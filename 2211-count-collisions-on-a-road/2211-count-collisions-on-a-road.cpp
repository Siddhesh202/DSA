class Solution {
public:
    int countCollisions(string directions) {
        stack<char> st;
        int ans = 0;

        for(auto &dir : directions) {

            if(dir == 'R') st.push(dir);

            else if (dir == 'L') {

                if(!st.empty() && st.top() == 'S') ans += 1;

                else if(!st.empty() && st.top() == 'R') {
                    int count = 0;
                    while(!st.empty() && st.top() == 'R') {
                        count++;
                        st.pop();
                    }
                    ans += (count + 1);
                    st.push('S');
                }
            }

            else {
                int count = 0;
                while(!st.empty() && st.top() == 'R') {
                    count++;
                    st.pop();
                }
                ans += count;
                st.push('S');
            }
        }

        return ans;
    }
};

// For R -->
// push into stack

// For L <--
// remove all R's before ans += count(R)+1; and then push S;
// if st.top() == S , ans += 1;

// For S 
// if top == R, remove all R's ans += count(R), and then push S
// else just push S
