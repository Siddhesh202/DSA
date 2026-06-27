class Solution {
public:
    bool isPerfectSquare(int n) { 
        return 1LL * sqrt(n) * sqrt(n) == n;
    }

    int maximumLength(vector<int>& nums) {
        unordered_map<int, int> freq;
        int ans = 1;

        for(auto &num: nums) freq[num]++;

        for(auto &num: nums) {
            if(num == 1) {
                int cnt = freq[1];
                if(cnt%2 == 0) ans = max(ans, cnt-1);
                else ans = max(ans, cnt);
                continue;
            }

            int len = 1;
            int curr = num; // 16

            while(isPerfectSquare(curr)) {
                int root = sqrt(curr);

                if(freq[root] >= 2) {
                    len+=2;
                    curr = root;
                }
                else break;
            }

            ans = max(len, ans);
        }

        return ans;
    }
};