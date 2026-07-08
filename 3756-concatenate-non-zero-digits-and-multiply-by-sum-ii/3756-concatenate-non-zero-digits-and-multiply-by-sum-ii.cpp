class Solution {
    static constexpr long long MOD = 1000000007LL;

public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n = s.size();

        vector<long long> pow10(n + 1, 1);
        for (int i = 1; i <= n; ++i)
            pow10[i] = (pow10[i - 1] * 10) % MOD;

        vector<int> nzCnt(n + 1, 0);
        vector<long long> digitSum(n + 1, 0), prefVal(n + 1, 0);

        for (int i = 0; i < n; ++i) {
            int d = s[i] - '0';

            nzCnt[i + 1] = nzCnt[i];
            digitSum[i + 1] = digitSum[i] + d;
            prefVal[i + 1] = prefVal[i];

            if (d != 0) {
                ++nzCnt[i + 1];
                prefVal[i + 1] = (prefVal[i] * 10 + d) % MOD;
            }
        }

        vector<int> ans;
        ans.reserve(queries.size());

        for (const auto& q : queries) {
            int l = q[0], r = q[1];

            long long sum = digitSum[r + 1] - digitSum[l];

            int k = nzCnt[r + 1] - nzCnt[l];
            long long leftVal = prefVal[l];
            long long rightVal = prefVal[r + 1];

            long long x = (rightVal - leftVal * pow10[k]) % MOD;
            if (x < 0) x += MOD;

            ans.push_back((x * (sum % MOD)) % MOD);
        }

        return ans;
    }
};