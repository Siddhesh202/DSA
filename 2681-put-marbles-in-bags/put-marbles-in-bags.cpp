#define ll long long
class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        int n = weights.size();
        ll minSum = 0, maxSum = 0;
        vector<ll> pairSum;

        for(int i = 0; i < n-1; i++) 
            pairSum.push_back(weights[i] + weights[i+1]);
        
        sort(pairSum.begin(), pairSum.end());

        // Get k-1 min sum
        for(int i = 0; i < k-1; i++) 
            minSum += pairSum[i];
        
        for(int i = n-k; i < n-1; i++) 
            maxSum += pairSum[i];

        return maxSum - minSum;
    }
};