class Solution {
public:
    bool isPossible(int mountainHeight, long long maxTime, vector<int>& workerTimes)
    {
        long long sum = 0;

        for(auto w : workerTimes)
        {
            long long l = 1, r = mountainHeight + 1, ans = r;

            while(l <= r)
            {
                long long mid = l + (r - l) / 2;

                if(w * ((mid * (mid+1)) / 2) <= maxTime) ans = mid, l = mid+1;
                else r = mid - 1;
            }
            sum += r;
        }
        return sum >= mountainHeight;
    }

    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        long long l = 0;
        long long r = 1e18;
        long long ans = 0;
        while(l <= r)
        {
            long long mid = l + (r - l) / 2;

            if(isPossible(mountainHeight, mid, workerTimes))
            {
                ans = mid;
                r = mid - 1;
            }
            else
                l = mid+1;
        }

        return ans;
    }
};