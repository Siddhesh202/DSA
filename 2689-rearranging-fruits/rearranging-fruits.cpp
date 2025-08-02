#define ll long long
class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        unordered_map<int,ll> mp;
        vector<ll> arr;
        int minEl = INT_MAX;
        ll ans = 0;

        // storing freq in mp
        for(auto &x : basket1) {
            mp[x]++;
            minEl = min(minEl, x);
        }

        for(auto &x : basket2) {
            mp[x]--;
            minEl = min(minEl, x);
        }

        // create the vector
        for(auto &p : mp) {
            int num = p.first;
            int freq = abs(p.second);

            if(freq % 2 != 0) return -1;
            for(int i = 1; i <= freq / 2; i++) arr.push_back(num);
        }

        // sort the arr
        sort(arr.begin(), arr.end());

        // compare with min elem as well
        for(int i = 0; i < arr.size() / 2; i++) {
            ans += min((ll) arr[i], (ll) (2 * minEl));
        }

        return ans;
    }
};