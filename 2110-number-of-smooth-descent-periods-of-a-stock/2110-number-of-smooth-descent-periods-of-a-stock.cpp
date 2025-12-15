#define ll long long
class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        ll ans = 0;
        int i = 0, j = 0, n = prices.size();

        while(j < n) {

            if(i == j || prices[j] == prices[j-1]-1) 
                ans += (j-i+1);
            else {
                ans++;
                i = j;
            }

            j++;
        }

        return ans;
    }
};