#define ll long long
class Solution {
public:
    long long maxSubarrays(int n, vector<vector<int>>& conflictingPairs) {
        ll valid = 0;
        int maxConf = 0;
        int secMaxConf = 0;

        vector<vector<int>> confPoints(n+1);
        // confPoints[i] = {points which conflict with i}

        for(auto &a : conflictingPairs) {
            int start = min(a[0], a[1]);
            int end   = max(a[0], a[1]);
            confPoints[end].push_back(start);   
        }

        vector<ll> extra(n+1, 0);
        // extra[i] = number of extra subarrs by removing the conflicting point i

        // calc valid subarrs ending at end
        for(int end = 1; end <= n; end++) {
            
            // updating maxConf and secMaxConf based on availability
            for(int &u : confPoints[end]) {
                if(u >= maxConf) {
                    secMaxConf = maxConf;
                    maxConf = u;
                }
                else if(u >= secMaxConf) {
                    secMaxConf = u;
                }
            }

            valid += (end - maxConf);
            extra[maxConf] += (maxConf - secMaxConf);
        }

        return valid + *max_element(extra.begin(), extra.end());
    }
};