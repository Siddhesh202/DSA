#define ll long long
class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        ll ans = 0;

        sort(happiness.begin(), happiness.end(), greater<int>());

        for(int i = 0; i < k; i++) {
            int happ = (happiness[i] - i) > 0 ? happiness[i] - i : 0;
            ans += happ;
        }

        return ans;
    }
};