#define ll long long
class Solution {
public:
    long long minCost(string s, vector<int>& cost) {
        vector<ll> arr(26, 0);
        ll total = 0;

        for(int i = 0; i < s.length(); i++) {
            total += cost[i];
            arr[s[i]-'a'] += cost[i];
        }

        return total - *max_element(arr.begin(), arr.end());
    }
};

// a --> 8
// b --> 3
// c --> 10
// total --> 21