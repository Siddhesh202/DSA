class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int cnt = 0, ans = 0;

        for(auto &num : arr) {
            if(num % 2 != 0) {
                cnt++;
                if(cnt >= 3) return true;
            }
            else 
                cnt = 0;
        }

        return false;
    }
};