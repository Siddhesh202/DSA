#define ll long long
class Solution {
public:
    long long isPossible(int n, vector<int>& batteries, ll mid) {
        ll target = mid * n;
        ll sum = 0;

        for(int i = 0; i < batteries.size(); i++) {
            sum += min(batteries[i]*1LL, mid);
        }

        return sum >= target;
    }

    long long maxRunTime(int n, vector<int>& batteries) {
        ll sum = 0, ans = 0;
        sum = accumulate(batteries.begin(), batteries.end(), 0LL);
        ll l = *min_element(batteries.begin(), batteries.end());
        ll r = sum / n;

        while(l <= r) {
            ll mid = l + (r - l) / 2;

            if(isPossible(n, batteries, mid)) {
                ans = mid;
                l = mid + 1;
            }
            else 
                r = mid - 1;
        }

        return ans;
    }
};