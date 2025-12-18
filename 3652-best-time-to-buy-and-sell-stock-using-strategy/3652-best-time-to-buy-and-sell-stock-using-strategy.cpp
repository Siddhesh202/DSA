#define ll long long
class Solution {
public:
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        int n = prices.size();
        ll ans = 0;
        vector<ll> baseProfit(n), prefSum(n);

        for(int i = 0; i < n; i++) {
            baseProfit[i] = (1LL*prices[i]*strategy[i]) + (i > 0 ? baseProfit[i-1] : 0);
            prefSum[i] = prices[i] + (i > 0 ? prefSum[i-1] : 0);
        } 

        // apply sliding window now
        int i = 0, j = 0;
        ans = baseProfit[n-1];
        while(j < n) {
            
            if(j-i+1 == k) {
                // lsum + rsum
                ll outerBaseProfit = (i > 0 ? baseProfit[i-1] : 0) + (baseProfit[n-1] - baseProfit[j]);
                
                // (i+k/2) -- j
                ll windowSum = prefSum[j] - prefSum[i+(k/2)-1];

                ans = max(ans, outerBaseProfit + windowSum);

                i++;
            }
            j++;
        }
        return ans;
    }
};


// a, b, c, d, e, f, g, h ---> k = 4

// a, b, |c, d, e, f|, g, h
// 0, 1,  2, 3, 4, 5,  6, 7

// total unmodified profit = (a*1) + (b*-1) + (c*-1) + (d*1) + (e*0) + (f*-1) + (g*1) + (h*1)
// (a*1) + (b*-1) + |(c*0) + (d*0)| + |(e*1) + (f*1)| + (g*1) + (h*1) 