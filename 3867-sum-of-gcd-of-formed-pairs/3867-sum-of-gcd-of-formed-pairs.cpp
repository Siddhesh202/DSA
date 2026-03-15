#define ll long long
class Solution {
public:
    ll gcd(ll a, ll b) {
        if(a%b == 0) return b;

        return gcd(b, a%b);
    }

    long long gcdSum(vector<int>& nums) {
        vector<ll> prefixGcd;
        int maxi = INT_MIN;
        ll ans = 0;

        for(auto &num : nums) {
            maxi = max(maxi, num);
            prefixGcd.push_back(gcd(maxi, num));
        }

        sort(prefixGcd.begin(), prefixGcd.end());

        int i = 0, j = prefixGcd.size()-1;

        while(i < j) {
            ans += gcd(prefixGcd[i], prefixGcd[j]);
            i++;
            j--;
        }

        return ans;
    }
};