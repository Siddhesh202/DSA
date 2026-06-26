#define ll long long
class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        ll ans = 0, cumSum = 0, validLeftPoints = 0;
        unordered_map<int,int> mp; // cumSum, count
        mp[0] = 1;

        for(auto &num: nums) {
            if(num == target) {
                validLeftPoints += mp[cumSum];
                cumSum += 1;
            }
            else {
                cumSum -= 1;
                validLeftPoints -= mp[cumSum];
            }

            mp[cumSum] += 1;
            ans += validLeftPoints;
        }

        return ans;
    }
};

// arr =    [-1,1,1,-1] tar = 2
// cumSum = [-1,0,1,0]
// cumSum[j] - cumSum[i-1] > 0
// cumSum[j] > cumSum[i-1]
// iska matlab aisa idx jiska cumSum is less than cumSum[j] wo ek valid subarr hai
// [0,1,2,1], ans = 4