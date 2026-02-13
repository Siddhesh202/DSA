#define P pair<int,int>
class Solution {
public:
    int n;
    int helper(string s, char c1, char c2) {
        unordered_map<int, int> mp; // store {count1 - count2, idx}
        int count1 = 0, count2 = 0, maxL = 0;

        for(int i = 0; i < n; i++) {
            char ch = s[i];

            if(ch != c1 && ch != c2) {
                mp.clear();
                count1 = 0;
                count2 = 0;
                continue;
            }

            count1 += (ch == c1) ? 1 : 0;
            count2 += (ch == c2) ? 1 : 0;

            if(count1 == count2) {
                maxL = max(count1+count2, maxL);
            }
            else {
                if(mp.count(count1 - count2)) {
                    maxL = max(maxL, i - mp[count1-count2]);
                }
                else mp[count1-count2] = i;
            }
        }

        return maxL;
    }

    int helper2(string s) {
        int count1 = 0, count2 = 0, count3 = 0, maxL = 0;
        map<P,int> mp; // store {[(count1-count2), (count1-count3)], idx}

        for(int i = 0; i < n; i++) {
            char ch = s[i];
            count1 += (ch == 'a') ? 1 : 0;
            count2 += (ch == 'b') ? 1 : 0;
            count3 += (ch == 'c') ? 1 : 0;

            if(count1 == count2 && count1 == count3) {
                maxL = max(maxL, count1+count2+count3);
            }
            else {
                P diff = {count1-count2, count1-count3};

                if(mp.count(diff)) {
                    maxL = max(maxL, i - mp[diff]);
                }
                else mp[diff] = i;
            }
        }

        return maxL;
    }

    int longestBalanced(string s) {
        n = s.length();
        int maxL = 0;

        // Case 1 : single char contributes to ans
        int count = 1;
        for(int i = 1; i < n; i++) {

            if(s[i] == s[i-1]) {
                count++;
            }
            else {
                maxL = max(maxL, count);
                count = 1;
            }
        }
        maxL = max(maxL, count);

        // Case 2 : Any 2 char's contribute to ans
        maxL = max(maxL, helper(s, 'a', 'b'));
        maxL = max(maxL, helper(s, 'a', 'c'));
        maxL = max(maxL, helper(s, 'b', 'c'));

        // Case 3 : Any 3 char's cntribute to ans
        maxL = max(maxL, helper2(s));
        
        return maxL;
    }
};