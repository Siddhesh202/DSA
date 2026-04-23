#define ll long long
#define P pair<ll,ll>
class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        int n = nums.size();
        vector<ll> ans(n);

        unordered_map<ll, ll> freq, totalSum;

        for (int i = 0; i < n; i++) {
            freq[nums[i]]++;
            totalSum[nums[i]] += i;
        }

        unordered_map<ll, pair<ll,ll>> prefSums;

        for (int i = 0; i < n; i++) {
            ll num = nums[i];

            ll leftCnt = prefSums[num].first;
            ll leftSum = prefSums[num].second;

            ll totalCnt = freq[num];
            ll total = totalSum[num];

            ll rightCnt = totalCnt - leftCnt - 1;
            ll rightSum = total - leftSum - i;

            ans[i] = (leftCnt * i - leftSum) + (rightSum - rightCnt * i);

            prefSums[num].first++;
            prefSums[num].second += i;
        }

        return ans;
    }
};

// abs(i-j1) + abs(i-j2) + abs(i-j3) + abs(i-j4) + abs(i-j5)
// suppose j1 and j2 are left of i 
// suppose j3 and j4 and j5 are right of i

// then the calculation will be
// (i-j1) + (i-j2) + (j3 - i) + (j4 - i) + (j5 - i)
// 2*i - (j1+j2) + (j3+j4+j5) - (3*i)
// (leftCount * i) - prefixSumOfLeft + prefixSumOfRight - (rightCount * i)

// I will maintain a map of num -> freq in entire nums
// 1 -> 3
// 3 -> 1
// 2 -> 1

// At any particular index I can easily calculate right Sum, if I know left Sum and count

// n*i - (j1 + j2 + j3)